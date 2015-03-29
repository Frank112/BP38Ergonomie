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
     * @see getLastError()
     * @param tblName The name of the table to register. It has to be provided as named in the underlying database.
     *
     *
     */
    void registerTable(const QString &tblName);


    /**
     * @brief getNextID Calculates the next greater ID for the given table and column, after the filter has been applied on the table
     *
     * This function calculates the maximum value for the given column name in the given table, <b>after</b> the filter has been applied
     * on that table and returns this maximum value plus one. If the operation faild a error gets reported.
     *
     * Error information can be retrieved with getLastError().
     *
     * <b>Note:</b> The return value is maybe not a valid ID due to the fact of shared primary keys or
     * the filter which has been applied on the table, such that not the whole content was taken into consideration for the computation of the value.
     *
     * @see getLastError()
     * @param tbl The table name as specified in the underlying database.
     *
     * <b>Note:</b> The table has to be registered with registerTable(const QString &tblName).
     * @param colName The column name as specified in the table of the underlying database.
     *
     * <b>Note:</b> The column type has to be of the type Integer, otherwise a error gets reported.
     * @param filter The filter is a SQL WHERE clause without the keyword WHERE.
     * @see <a href="http://doc.qt.io/qt-4.8/qsqltablemodel.html#setFilter">QSqlTableModel::setFilter(const QString &filter)</a>
     *
     * @return The next higher number of the given column in the given table after appling the given filter on that table.
     *
     * <b>Note:</b> In case of an error the return value is always -1.
     */
    int getNextID(const QString &tbl, const QString &colName, const QString &filter = "");

    /**
     * @brief select Returns all entries in the given order of the given table in the underlying database,
     *  after the given filter has been applied on that table.
     *
     * The function is the abstract way of the SQL SELECT statement.
     * The function returns all entries in the given sort order that match the given filter
     * in the given registered table of the underlying database.
     * If the satement could not be executed a error gets reported.
     *
     * Error information can be retrieved with getLastError().
     *
     * @see getLastError()
     *
     * @param tbl The table name as specified in the underlying database.
     *
     * <b>Note:</b> The table has to be registered with registerTable(const QString &tblName).
     *
     * @param filter The filter is a SQL WHERE clause without the keyword WHERE.
     * @see <a href="http://doc.qt.io/qt-4.8/qsqltablemodel.html#setFilter">QSqlTableModel::setFilter(const QString &filter)</a>
     *
     * @param order The order for the selected entries.
     *
     * @return A list of all entries in the table that match the given filter
     *  as HashMap consisting of the column name and the value as a QVariant.
     *
     * <b>Note:</b> If the error occured durring the execution of the function you always get a empty list.
     * @see <a href="http://doc.qt.io/qt-5/qvariant.html">QVariant</a>
     * @see <a href="http://doc.qt.io/qt-5/qhash.html">QHash</a>
     * @see <a href="http://doc.qt.io/qt-5/qlist.html">QList</a>
     */
    QList<QHash<QString, QVariant>> select(const QString &tbl, const QString &filter = "", Qt::SortOrder order = Qt::SortOrder::AscendingOrder);

    /**
     * @brief selectFirst Returns the first entrie in the given order of the given table in the underlying database,
     * after the given filter has been applied on that table
     *
     * The function is basically the same as select(const QString &tbl, const QString &filter, Qt::SortOrder order), but
     * returns only the first row after performing the select statement.
     * If the statement could not be executed a error gets reported.
     *
     * Error information can be retrieved with getLastError().
     *
     * @see getLastError()
     * @see select()
     *
     * @param tbl The table name as specified in the underlying database.
     *
     * <b>Note:</b> The table has to be registered with registerTable(const QString &tblName).
     *
     * @param filter The filter is a SQL WHERE clause without the keyword WHERE.
     * @see <a href="http://doc.qt.io/qt-4.8/qsqltablemodel.html#setFilter">QSqlTableModel::setFilter(const QString &filter)</a>
     *
     * @param order The order for the selected entries.
     *
     * @return The first entrie according to the given order in the table that matches the given filter as
     * a HashMap consisting of the column name and the value as a QVariant.
     *
     * <b>Note:</b> If a error occured durring the execution of the function you always get a empty HashMap.
     * @see <a href="http://doc.qt.io/qt-5/qvariant.html">QVariant</a>
     * @see <a href="http://doc.qt.io/qt-5/qhash.html">QHash</a>
     */
    QHash<QString, QVariant> selectFirst(const QString &tbl, const QString &filter = "", Qt::SortOrder order = Qt::SortOrder::AscendingOrder);

    /**
     * @brief selectCount Returns the count of rows in the given table that matches the given filter.
     *
     * Calculates the count of row in the given table, after the given filter has been applied on that table.
     * If the statement could not be executed a error gets reported.
     *
     * Error information can be retrieved with getLastError()
     *
     * @see getLastError()
     * @param tbl The table name as specified in the underlying database.
     *
     * <b>Note:</b> The table has to be registered with registerTable(const QString &tblName).
     *
     * @param filter The filter is a SQL WHERE clause without the keyword WHERE.
     * @see <a href="http://doc.qt.io/qt-4.8/qsqltablemodel.html#setFilter">QSqlTableModel::setFilter(const QString &filter)</a>
     *
     * @return The count of all rows in the given table that matches the given filter.
     *
     * <b>Note:</b> If a error occured durring the execution of the function it returns -1 as the count.
     */
    int selectCount(const QString &tbl, const QString &filter = "");

    /**
     * @brief isSelectEmpty Indicates whether a select on the given table with the given filter affect no rows.
     *
     * This function uses selectCount(const QString &tbl, const QString &filter) for the row count computation and
     * returns true if the row count equals 0, otherwise false.
     *
     * @see selectCount(const QString &tbl, const QString &filter)
     * @param tbl The table name as specified in the underlying database.
     *
     * <b>Note:</b> The table has to be registered with registerTable(const QString &tblName).
     *
     * @param filter The filter is a SQL WHERE clause without the keyword WHERE.
     * @see <a href="http://doc.qt.io/qt-4.8/qsqltablemodel.html#setFilter">QSqlTableModel::setFilter(const QString &filter)</a>
     *
     * @return true iff the count of selected rows equals 0, otherwise false
     */
    bool isSelectEmpty(const QString &tbl, const QString &filter = "");

    /**
     * @brief insert Inserts a new row into the given tbl with given types and values for the single columns.
     *
     * This function is the abstract way of the SQL INSERT Statement. It inserts a new row at the end of the given table,
     * there for it uses the given types and values for the single columns in the given HashMaps and returns the ID of the
     * given identification column of the created row.
     *
     * If the statement could not be executed a error is reported and the error information can be retrieved with getLastError().
     *
     * @see getLastError()
     * @param tbl The table name as specified in the underlying database.
     *
     * <b>Note:</b> The table has to be registered with registerTable(const QString &tblName).
     * @param colMapNameType Maps the column names of the given table in the underlying database to the type.
     * @param colMapNameValue Maps the column names of the given table in the underlying database to
     * the value, which should be inserted in the column of the new row.
     *
     * <b>Note:</b> This parameter specifies which columns in the given table are effected.
     * @param colID If the column is already in the HashMap of the column values the values are not effected, otherwise
     * the function getNextID(const QString &tbl, const QString &colName) is called to generate a new unique ID for the
     * given column and gets inserted in the colMapNameValue
     *
     * <b>Note:</b> If the type of the column is not integer this will lead to an error.
     * @return Returns either the value of the given column by colID iff the insert was successful, otherwise
     * it returns -1
     */
    int insert(const QString &tbl, const QHash<QString, QVariant::Type> &colMapNameType, QHash<QString, QVariant> &colMapNameValue, const QString &colID = "");

    /**
     * @brief update Updates all rows in the given table which matches the given filter with the given columns and values.
     *
     * This function is the abstact way of the SQL UPDATE statement. It updates all rows in the given table which matches
     * the given filter. It updates only the columns where values are provided for by the colMapNameValue HashMap.
     * If the satement could not be executed a error is reported and the error information can be retrieved with getLastError().
     *
     * <b>Note:</b> the update is only successfull iff all rows in the given table
     * which matches the given filter could be updated successfully.
     *
     * @see getLastError()
     *
     * @param tbl The table name as specified in the underlying database.
     *
     * <b>Note:</b> The table has to be registered with registerTable(const QString &tblName).
     *
     * @param colMapNameType Maps the column names of the given table in the underlying database to the type.
     *
     * @param colMapNameValue Maps the column names of the given table in the underlying database to
     * the value to be updated to.
     *
     * <b>Note:</b> This parameter specifies which columns in the given table are effected.
     *
     * @param filter The filter is a SQL WHERE clause without the keyword WHERE.
     * @see <a href="http://doc.qt.io/qt-4.8/qsqltablemodel.html#setFilter">QSqlTableModel::setFilter(const QString &filter)</a>
     *
     * @param colID The column name in the given table which is used as the identifier of a row.
     *
     * @return Returns either the value of the given column by colID of the first updated row iff the update was successful, otherwise
     * it returns -1
     */
    int update(const QString &tbl, const QHash<QString, QVariant::Type> &colMapNameType, QHash<QString, QVariant> &colMapNameValue, const QString &filter = "", const QString &colID = "");

    /**
     * @brief save Saves the given values as new row or updated rows in the given table, either there is a
     * row which matches the given filter then update is called otherwise insert.
     *
     * @see insert()
     * @see update()
     * @param tbl The table name as specified in the underlying database.
     *
     * <b>Note:</b> The table has to be registered with registerTable(const QString &tblName).
     *
     * @param colMapNameType Maps the column names of the given table in the underlying database to the type.
     *
     * @param colMapNameValue Maps the column names of the given table in the underlying database to
     * the value.
     *
     * <b>Note:</b> This parameter specifies which columns in the given table are effected.
     *
     * @param filter The filter is a SQL WHERE clause without the keyword WHERE.
     * @see <a href="http://doc.qt.io/qt-4.8/qsqltablemodel.html#setFilter">QSqlTableModel::setFilter(const QString &filter)</a>
     *
     * @param colID The column name in the given table which is used as the identifier of a row.
     *
     * @return Einfach auf die Funktionen verweisen ??
     */
    int save(const QString &tbl, const QHash<QString, QVariant::Type> &colMapNameType, QHash<QString, QVariant> &colMapNameValue, const QString &filter = "", const QString &colID = "");

    /**
     * @brief remove Deletes all rows in the given table that matches the given filter.
     *
     * This function is the abstract way of the SQL DELETE statement. It removes all rows in the given table of
     * the underlying database that matches the given filter.
     * If the statement could not be executed a error is reported.
     *
     * Error information can be retrieved with getLastError().
     *
     * <b>Note:</b> If the satement could not be executed completely, in the way that not all rows that has to be removed
     * could be removed. The function is not atomic, so the rows that could be removed are removed and the rows which could
     * be not removed yeah ... 42
     * @param tbl The table name as specified in the underlying database.
     *
     * <b>Note:</b> The table has to be registered with registerTable(const QString &tblName).
     *
     * @param filter The filter is a SQL WHERE clause without the keyword WHERE.
     * @see <a href="http://doc.qt.io/qt-4.8/qsqltablemodel.html#setFilter">QSqlTableModel::setFilter(const QString &filter)</a>
     *
     * @return true iff all rows in the given table that matches the given filter could be successfully removed,
     *  otherwise false
     */
    bool remove(const QString &tbl, const QString &filter);

    /**
     * @brief hasError Indicates whether the DBHandler has a unrecognized error.
     * @return true iff there is a error which was not recognized with getLastError(), otherwise false.
     */
    bool hasError() const;

    /**
     * @brief getLastError Returns the error message of the last error that has occured.
     * @param resetHasError Indicates whether the error should be marked as recognized.
     *
     * <b>Note:</b> If the parameter is set to false hasError() will return true iff there is an unrecognized error.
     *
     * @see hasError()
     * @return The error message of the last error. If there has never been a reported error it will return a empty string.
     */
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
