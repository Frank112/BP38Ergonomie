#include "dbhandler.h"
#include "standardpaths.h"


DBHandler::DBHandler(const QString &databasePath)
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(databasePath);
    if(!database.open())
        QMessageBox::critical(0, "Error:", "Could not open database!");

    htSqlTableModels = QHash<const QString, QSqlTableModel*>();
}

DBHandler::~DBHandler(){
    database.close();
}


void DBHandler::registerTable(const QString &tblName){
    QSqlTableModel *tbl = new QSqlTableModel(0, database);
    tbl->setTable(tblName);
    tbl->setEditStrategy(QSqlTableModel::OnRowChange);

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

    foreach(QString key, colMapNameValue.keys()){
        record.append(QSqlField(key, colMapNameType.value(key)));
        record.setValue(key, colMapNameValue.value(key));
    }

    bool success = getSqlTableModel(tbl)->insertRecord(-1, record);
    return success ? id : -1;
}

int DBHandler::update(const QString &tbl, const QHash<QString, QVariant::Type> &colMapNameType, QHash<QString, QVariant> &colMapNameValue, const QString &filter, const QString &colID){
    QSqlRecord record;

    int id = -1;
    int count = selectCount(tbl, filter);
    if(count > 0) {
        foreach(QString colName, colMapNameValue.keys()){
            record.append(QSqlField(colName, colMapNameType.value(colName)));
            record.setValue(colName, colMapNameValue.value(colName));
        }
        bool success = true;
        QSqlTableModel *tblModel = getSqlTableModel(tbl);
        for(int i = 0; i < count; ++i)
            success &= tblModel->setRecord(i, record);
        if(success)
            id = tblModel->record(0).value(colID).toInt();
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

    return selectValues;
}

QHash<QString, QVariant> DBHandler::selectFirst(const QString &tbl, const QString &filter, Qt::SortOrder order){
    QList<QHash<QString, QVariant>> selectValues = select(tbl, filter, order);
    if(selectValues.isEmpty())
        return QHash<QString, QVariant>();
    return selectValues.at(0);
}

int DBHandler::selectCount(const QString &tbl, const QString &filter, Qt::SortOrder order){
    QSqlTableModel *model = getSqlTableModel(tbl);
    model->setFilter(filter);
    model->setSort(0, order);
    if(model->select())
        return model->rowCount();
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
    return success;
}

int DBHandler::getNextID(const QString &tbl, const QString &colName, const QString &filter){
    QSqlQuery query;
    QString _filter("");
    if(!filter.isEmpty())
        _filter = QString("WHERE %1").arg(filter);
    QString strQuery = QString("SELECT MAX(%1) AS max_ID FROM %2 %3;").arg(colName)
            .arg(getSqlTableModel(tbl)->tableName()).arg(_filter);
    if (query.prepare(strQuery)){
        if(query.exec()){
           query.next();
           return query.value("max_ID").toInt() + 1;
        }
    }
    return -1;
}

//PRIVATE METHODS
QSqlTableModel *DBHandler::getSqlTableModel(const QString &tbl){
    return htSqlTableModels.value(tbl);
}




