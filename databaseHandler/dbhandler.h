#ifndef DBHANDLER_H
#define DBHANDLER_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlField>
#include <QSqlRecord>
#include <QFile>
#include <QFileInfo>
#include <QMessageBox>
#include "dbconstants.h"

/**
 * @author Frank Loeffler
 * @brief The DBHandler class is a abstract way to access a database in the local filesystem.
 * Note that the different plattforms have different system paths for locations with writable access
 * permissions and the database have to be located in a folder with permissions to write for the application.
 *
 * If an error is spotted durring the execution the last occured error is always reported and the message of the
 * error can be eingesehen werden mit der Funktionn getLastError() and hasError() signals an unrecognized error.
 *
 */
class DBHandler
{

public:
    /**
     * @brief DBHandler Constructor for a new dbHandler object.
     * Note that if the specified database does not exsist or can not be access due to a lock of permissions
     * than a error gets reported and the message can be access via @see getLastError()
     * @param databasePath absolute path to the database in the local filesystem
     */
    DBHandler(const QString &databasePath);

    ~DBHandler();

    /**
     * @brief registerTable registers a exsisting table in the database, for later operations/manipulations.
     * Note that if a table is already registered nothing happens and if a table does not exsists in the database
     * there is a error
     * @param tblName origin table name in the database to register
     */
    void registerTable(const QString &tblName);

    /**
     * @brief getNextID Calculates a new valid ID for the specified column in the specified table, after applying the filter on the table.
     * Note that the next ID for a column is the maximum value of the column after applying the filter on the table + 1;
     * @param tbl table name in the database, if there is no table in the database the operation will report an database error the error message can be accessed via @see getLastError()
     * @param colName the name of the column in the database if there is no such column in the table of the database the error
     * @param filter the filter-operation in the style of a SQL WHERE condition without the WHERE @see ... if the filter could not be applied for the table in the database
     * the error get reported as a database error and the error message can be access with getLastError @see getLastError()
     * @return The next unused id or -1 if the operation failed the error is than documentated in the error log and in the last error of the database
     */
    int getNextID(const QString &tbl, const QString &colName, const QString &filter = "");

    QList<QHash<QString, QVariant>> select(const QString &tbl, const QString &filter = "", Qt::SortOrder order = Qt::SortOrder::AscendingOrder);
    QHash<QString, QVariant> selectFirst(const QString &tbl, const QString &filter = "", Qt::SortOrder order = Qt::SortOrder::AscendingOrder);
    int selectCount(const QString &tbl, const QString &filter = "", Qt::SortOrder order = Qt::SortOrder::AscendingOrder);
    bool isSelectEmpty(const QString &tbl, const QString &filter = "", Qt::SortOrder order = Qt::SortOrder::AscendingOrder);

    int insert(const QString &tbl, const QHash<QString, QVariant::Type> &colMapNameType, QHash<QString, QVariant> &colMapNameValue, const QString &colID = "");
    int update(const QString &tbl, const QHash<QString, QVariant::Type> &colMapNameType, QHash<QString, QVariant> &colMapNameValue, const QString &filter = "", const QString &colID = "");
    int save(const QString &tbl, const QHash<QString, QVariant::Type> &colMapNameType, QHash<QString, QVariant> &colMapNameValue, const QString &filter = "", const QString &colID = "");
    bool remove(const QString &tbl, const QString &filter);

    bool hasError() const;
    QString getLastError(bool resetHasError = true);

private:
    QSqlTableModel* getSqlTableModel(const QString &tblName);

    bool existsSqlTableModel(const QString &tblName);

    void reportError(const QString &errorMessage);

    bool m_hasError;
    QString lastError;
    QSqlDatabase database;
    QHash<const QString, QSqlTableModel*> htSqlTableModels;

};

#endif // DBHANDLER_H
