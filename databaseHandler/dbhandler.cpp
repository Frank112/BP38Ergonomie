#include "dbhandler.h"
#include "standardpaths.h"


DBHandler::DBHandler(const QString &databasePath)
{
    lastError = "";
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(databasePath);
    if(!database.open())
        lastError = "Could not open database!";

    htSqlTableModels = QHash<const QString, QSqlTableModel*>();
}

DBHandler::~DBHandler(){

    QHash<const QString, QSqlTableModel*>::iterator i;
    for(i = htSqlTableModels.begin(); i != htSqlTableModels.end(); ++i){
        delete htSqlTableModels.value(i.key());
    }
    database.close();
}


void DBHandler::registerTable(const QString &tblName){
    QSqlTableModel *tbl = new QSqlTableModel(0, database);
    tbl->setTable(tblName);
    tbl->setEditStrategy(QSqlTableModel::OnRowChange);
    if(tbl->lastError().type() != QSqlError::NoError)
        lastError = tbl->lastError().text();

    htSqlTableModels.insert(tblName, tbl);
}


int DBHandler::insert(const QString &tbl, const QHash<QString, QVariant::Type> &colMapNameType, QHash<QString, QVariant> &colMapNameValue, const QString &colID){
    QSqlRecord record;
    int id;
    if(colID != "" && !colMapNameValue.contains(colID)){
        id = getNextID(tbl, colID);
        colMapNameValue.insert(colID, id);
    }
    else
        id = colMapNameValue.value(colID).toInt();

    QHash<QString, QVariant>::iterator i;
    for(i = colMapNameValue.begin(); i != colMapNameValue.end(); ++i){
        record.append(QSqlField(i.key(), colMapNameType.value(i.key())));
        record.setValue(i.key(), colMapNameValue.value(i.key()));
    }

    QSqlTableModel *tblModel = getSqlTableModel(tbl);
    bool success = tblModel->insertRecord(-1, record);
    if(!success)
        lastError = tblModel->lastError().text();
    return success ? id : -1;
}

int DBHandler::update(const QString &tbl, const QHash<QString, QVariant::Type> &colMapNameType, QHash<QString, QVariant> &colMapNameValue, const QString &filter, const QString &colID){
    QSqlRecord record;

    int id = -1;
    int count = selectCount(tbl, filter);
    if(count > 0) {
        QHash<QString, QVariant>::iterator i;
        for(i = colMapNameValue.begin(); i != colMapNameValue.end(); ++i){
            record.append(QSqlField(i.key(), colMapNameType.value(i.key())));
            record.setValue(i.key(), colMapNameValue.value(i.key()));
        }
        bool success = true;
        QSqlTableModel *tblModel = getSqlTableModel(tbl);
        for(int i = 0; i < count; ++i)
            success &= tblModel->setRecord(i, record);
        if(success)
            id = tblModel->record(0).value(colID).toInt();
        else
            lastError = tblModel->lastError().text();
    }

    return id;
}

int DBHandler::save(const QString &tbl, const QHash<QString, QVariant::Type> &colMapNameType, QHash<QString, QVariant> &colMapNameValue, const QString &filter, const QString &colID){
    if(isSelectEmpty(tbl, filter)){
        return insert(tbl, colMapNameType, colMapNameValue, colID);
    }
    else {
        return update(tbl, colMapNameType, colMapNameValue, filter, colID);
    }
}

QList<QHash<QString, QVariant>> DBHandler::select(const QString &tbl, const QString &filter, Qt::SortOrder order){
    QList<QHash<QString, QVariant>> selectValues = QList<QHash<QString, QVariant>>();
    QSqlTableModel *model = getSqlTableModel(tbl);
    model->setFilter(filter);
    model->setSort(0, order);
    if(model->select()) {
        for(int i = 0; i < model->rowCount(); ++i){
            QSqlRecord record = model->record(i);
            QHash<QString, QVariant> rowValues = QHash<QString, QVariant>();
            for(int k = 0; k < record.count(); ++k)
                rowValues.insert(record.fieldName(k), record.value(k));
            selectValues.append(rowValues);
        }
    }
    else
        lastError = model->lastError().text();

    return selectValues;
}

QHash<QString, QVariant> DBHandler::selectFirst(const QString &tbl, const QString &filter, Qt::SortOrder order){
    QSqlTableModel *model = getSqlTableModel(tbl);
    model->setFilter(filter);
    model->setSort(0, order);
    QHash<QString, QVariant> rowValues = QHash<QString, QVariant>();
    if(model->select()) {
        if(model->rowCount() > 0){
            QSqlRecord record = model->record(0);
            for(int k = 0; k < record.count(); ++k)
                rowValues.insert(record.fieldName(k), record.value(k));
        }
    }
    else
        lastError = model->lastError().text();

    return rowValues;
}

int DBHandler::selectCount(const QString &tbl, const QString &filter, Qt::SortOrder order){
    QSqlTableModel *model = getSqlTableModel(tbl);
    model->setFilter(filter);
    model->setSort(0, order);
    if(model->select())
        return model->rowCount();
    else
        lastError = model->lastError().text();
    return 0;
}

bool DBHandler::isSelectEmpty(const QString &tbl, const QString &filter, Qt::SortOrder order){
    return selectCount(tbl, filter, order) == 0;
}

bool DBHandler::deleteAll(const QString &tbl, const QString &filter){
    bool success = true;
    QSqlTableModel* tblModel = getSqlTableModel(tbl);
    for(int i = selectCount(tbl, filter) - 1; i >= 0; --i)
        success &= tblModel->removeRow(i);
    if(!success)
        lastError = tblModel->lastError().text();
    return success;
}

int DBHandler::getNextID(const QString &tbl, const QString &colName, const QString &filter){
    QSqlQuery query;
    QString _filter("");
    if(!filter.isEmpty())
        _filter = QString("WHERE %1").arg(filter);
    QString strQuery = QString("SELECT MAX(%1) AS max_ID FROM %2 %3;").arg(colName)
            .arg(getSqlTableModel(tbl)->tableName()).arg(_filter);
    if (query.prepare(strQuery) && query.exec()){
        query.next();
        return query.value("max_ID").toInt() + 1;
    }
    else
        lastError = query.lastError().text();
    return -1;
}

bool DBHandler::hasError() const {
    return lastError != "";
}

QString DBHandler::getLastError(bool reset) {
    QString currentError = lastError;
    if(reset)
        lastError = "";
    return currentError;
}


//PRIVATE METHODS
QSqlTableModel *DBHandler::getSqlTableModel(const QString &tblName){
    if(existsSqlTableModel(tblName))
        return htSqlTableModels.value(tblName);
    else
        lastError = QString("Table \"%1\" was never registered").arg(tblName);
    return 0;
}

bool DBHandler::existsSqlTableModel(const QString &tblName){
    return htSqlTableModels.contains(tblName);
}
