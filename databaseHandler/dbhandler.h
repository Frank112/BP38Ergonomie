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
 * @brief The DBHandler class is a abstract way to access a SQLite database in the local filesystem.
 *
 * An instance of DBHandler provides functions that model the basic SQL operations SELECT, INSERT, UPDATE, DELETE on
 * an SQLite database.
 *
 * <b>Note:</b> Different plattforms have different system paths for locations with writable access
 * permissions thus the database has to be located in a directory with write permissions for the application.
 *
 * If an error is occurs getLastError() will return information about it. hasError() signals if
 * there is an error that has not been retrieved yet.
 *
 * <b>Note:</b> You should not try to change this class into a subclass of QObject with a Q_OBJECT macro. This might
 * lead to a failure while loading the database driver.
 *
 * @author Frank Loeffler
 *
 */
class DBHandler
{

public:    
    /**
     * @brief DBHandler Creates a DBHandler object with that database stored at the given path.
     *
     * <b>Note:</b> The database has to be an SQLite database. For the file representing this database read
     * and write permissions are required.
     *
     * Error information can be retrieved with getLastError().
     *
     * @param databasePath The absolute path to the database file in the local filesystem.
     *
     * <b>Note:</b> If the specified database does not exsist or can not be accessed due to a lock of permissions,
     * an error gets reported.
     *
     * @see getLastError()
     * @see hasError()
     * @see <a href="http://doc.qt.io/qt-5/qsqldatabase.html">QSqlDatabase</a>
     */
    DBHandler(const QString &databasePath);

    ~DBHandler();

    /**
     * @brief registerTable Registers an exsisting table from the database at the DBHandler object,
     * to be able to apply the provided operations on this table.
     *
     * If the table does not exist in the database an error is reported. If table has already been registered nothing happens.
     *
     * Error information can be retrieved with getLastError().
     *
     * <b>Note:</b> Registering a table requires the successful creation of a DBHandler object.
     *
     * @param tblName The name of the table to register. It has to be provided as named in the underlying database.
     *
     *
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
