#include "dbhandler.h"
#include "standardpaths.h"
#include "../errorreporter.h"


DBHandler::DBHandler(const QString &databasePath)
{
    m_hasError = false;
    lastError = "";
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(databasePath);
    if(!database.open())
        reportError("Could not open database!");

    htSqlTableModels = QHash<const QString, QSqlTableModel*>();
}

DBHandler::~DBHandler(){

    QHash<const QString, QSqlTableModel*>::iterator i;
    for(i = htSqlTableModels.begin(); i != htSqlTableModels.end(); ++i){
        delete htSqlTableModels.value(i.key());
    }
    database.close();
}

//PUBLIC METHODS
void DBHandler::registerTable(const QString &tblName){
    if(!existsSqlTableModel(tblName)){
        QSqlTableModel *tblModel = new QSqlTableModel(0, database);
        tblModel->setTable(tblName);
        tblModel->setEditStrategy(QSqlTableModel::OnRowChange);
        if(tblModel->lastError().type() != QSqlError::NoError)
            reportError(tblModel->lastError().text());

        htSqlTableModels.insert(tblName, tblModel);
    }
}

int DBHandler::getNextID(const QString &tbl, const QString &colName, const QString &filter){
    QSqlQuery query;
    QString _filter = QString("");

    if(!filter.isEmpty())
        _filter = QString("WHERE %1").arg(filter);

    QString strQuery = QString("SELECT MAX(%1) AS max_ID FROM %2 %3;").arg(colName)
            .arg(getSqlTableModel(tbl)->tableName()).arg(_filter);

    if (query.prepare(strQuery) && query.exec()){
        query.next();
        return query.value("max_ID").toInt() + 1;
    }

    reportError(query.lastError().text());
    return -1;
}

QList<QHash<QString, QVariant>> DBHandler::select(const QString &tbl, const QString &filter, Qt::SortOrder order){
    QList<QHash<QString, QVariant>> selectValues = QList<QHash<QString, QVariant>>();
    QSqlTableModel *tblModel = getSqlTableModel(tbl);
    tblModel->setFilter(filter);
    tblModel->setSort(0, order);
    if(tblModel->select()) {
        for(int i = 0; i < tblModel->rowCount(); ++i){
            QSqlRecord record = tblModel->record(i);
            QHash<QString, QVariant> rowValues = QHash<QString, QVariant>();
            for(int k = 0; k < record.count(); ++k)
                rowValues.insert(record.fieldName(k), record.value(k));
            selectValues.append(rowValues);
        }
    }
    else
        reportError(tblModel->lastError().text());

    return selectValues;
}

QHash<QString, QVariant> DBHandler::selectFirst(const QString &tbl, const QString &filter, Qt::SortOrder order){
    QSqlTableModel *tblModel = getSqlTableModel(tbl);
    tblModel->setFilter(filter);
    tblModel->setSort(0, order);
    QHash<QString, QVariant> rowValues = QHash<QString, QVariant>();

    if(tblModel->select()) {
        if(tblModel->rowCount() > 0){
            QSqlRecord record = tblModel->record(0);
            for(int k = 0; k < record.count(); ++k)
                rowValues.insert(record.fieldName(k), record.value(k));
        }
    }
    else
        reportError(tblModel->lastError().text());

    return rowValues;
}

int DBHandler::selectCount(const QString &tbl, const QString &filter){
    QSqlTableModel *tblModel = getSqlTableModel(tbl);
    tblModel->setFilter(filter);

    if(tblModel->select())
        return tblModel->rowCount();


    reportError(tblModel->lastError().text());
    return -1;
}

bool DBHandler::isSelectEmpty(const QString &tbl, const QString &filter){
    return selectCount(tbl, filter) == 0;
}

int DBHandler::insert(const QString &tbl, const QHash<QString, QVariant::Type> &colMapNameType, QHash<QString, QVariant> &colMapNameValue, const QString &colID){
    QSqlRecord record;
    int id = -1;

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
    if(success)
        return id;


    reportError(tblModel->lastError().text());
    return -1;
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
            reportError(tblModel->lastError().text());
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


bool DBHandler::remove(const QString &tbl, const QString &filter){
    bool success = true;
    QSqlTableModel* tblModel = getSqlTableModel(tbl);
    for(int i = selectCount(tbl, filter) - 1; i >= 0; --i)
        success &= tblModel->removeRow(i);
    if(!success)
        reportError(tblModel->lastError().text());
    return success;
}


bool DBHandler::hasError() const {
    return m_hasError;
}

QString DBHandler::getLastError(bool resetHasError) {
    if(resetHasError)
        m_hasError = false;
    return lastError;
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

void DBHandler::reportError(const QString &errorMessage){
    m_hasError = true;
    lastError = errorMessage;
    ErrorReporter::reportError(errorMessage);
}
