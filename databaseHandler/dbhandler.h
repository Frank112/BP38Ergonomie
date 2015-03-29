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
#include "dbconstants.h"

/**
 * @brief The DBHandler class is an abstract way to access an SQLite database in the local filesystem.
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
     * on that table and returns this maximum value plus one. If the operation failed an error gets reported.
     *
     * Error information can be retrieved with getLastError().
     *
     * <b>Note:</b> The return value is might not be a valid ID due to the fact of shared primary keys or
     * the filter which has been applied on the table, such that not the whole content was taken into consideration for the computation of the value.
     *
     * @see getLastError()
     * @param tbl The table name as specified in the underlying database.
     *
     * <b>Note:</b> The table has to be registered with registerTable(const QString &tblName).
     * @param colName The column name as specified in the table of the underlying database.
     *
     * <b>Note:</b> The column type has to be of the type Integer, otherwise a error gets reported.
     * @param filter The filter is an SQL WHERE clause without the keyword WHERE.
     * @see <a href="http://doc.qt.io/qt-4.8/qsqltablemodel.html#setFilter">QSqlTableModel::setFilter(const QString &filter)</a>
     *
     * @return The next higher number of the given column in the given table after appling the given filter on that table.
     *
     * <b>Note:</b> Whenever an error is detected -1 is returned.
     */
    int getNextID(const QString &tbl, const QString &colName, const QString &filter = "");

    /**
     * @brief select Returns all entries in the given order of the given table in the underlying database,
     *  after the given filter has been applied on that table.
     *
     * The function is an abstract way to execute the SQL SELECT statement.
     * The function returns all entries in the given sort order that match the given filter
     * in the given <i>registered</i> table of the underlying database.
     * If the satement could not be executed an error gets reported.
     *
     * Error information can be retrieved with getLastError().
     *
     * @param tbl The table name as specified in the underlying database.
     *
     * <b>Note:</b> The table has to be registered with registerTable(const QString &tblName).
     *
     * @param filter The filter is an SQL WHERE clause without the keyword WHERE.
     * @see <a href="http://doc.qt.io/qt-4.8/qsqltablemodel.html#setFilter">QSqlTableModel::setFilter(const QString &filter)</a>
     *
     * @param order The order for the selected entries.
     *
     * @return A list of all entries in the table that match the given filter
     *  as <a href="http://doc.qt.io/qt-4.8/qhash.html">QHash</a> consisting of the column name and the value
     * as a <a href="http://doc.qt.io/qt-4.8/qvariant.html">QVariant</a>.
     *
     * <b>Note:</b> If the error occurs during the execution, the function returns an empty list.
     *
     * @see <a href="http://doc.qt.io/qt-5/qvariant.html">QVariant</a>
     * @see <a href="http://doc.qt.io/qt-5/qhash.html">QHash</a>
     * @see <a href="http://doc.qt.io/qt-5/qlist.html">QList</a>
     */
    QList<QHash<QString, QVariant> > select(const QString &tbl, const QString &filter = "", Qt::SortOrder order = Qt::AscendingOrder);

    /**
     * @brief selectFirst Returns the first entry in the given order of the given table in the underlying database,
     * after the given filter has been applied on that table
     *
     * The function behaves similar to select(const QString &tbl, const QString &filter, Qt::SortOrder order), but
     * returns only the first row of the table after executing the select statement.
     * If the statement could not be executed an error gets reported.
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
     * @param filter The filter is an SQL WHERE clause without the keyword WHERE.
     * @see <a href="http://doc.qt.io/qt-4.8/qsqltablemodel.html#setFilter">QSqlTableModel::setFilter(const QString &filter)</a>
     *
     * @param order The order for the selected entries.
     *
     * @return The first entry according to the given order in the table that matches the given filter as
     * a <a href="http://doc.qt.io/qt-4.8/qhash.html">QHash</a> consisting of the column name and the value
     * as a <a href="http://doc.qt.io/qt-4.8/qvariant.html">QVariant</a>.
     *
     * <b>Note:</b> If the error occurs during the execution, the function returns an empty <a href="http://doc.qt.io/qt-4.8/qhash.html">QHash</a>.
     * @see <a href="http://doc.qt.io/qt-5/qvariant.html">QVariant</a>
     * @see <a href="http://doc.qt.io/qt-5/qhash.html">QHash</a>
     */
    QHash<QString, QVariant> selectFirst(const QString &tbl, const QString &filter = "", Qt::SortOrder order = Qt::AscendingOrder);

    /**
     * @brief selectCount Returns the count of rows in the given table that match the given filter.
     *
     * Calculates the count of row in the given table, after the given filter has been applied on that table.
     * If the statement could not be executed an error gets reported.
     *
     * Error information can be retrieved with getLastError()
     *
     * @see getLastError()
     * @param tbl The table name as specified in the underlying database.
     *
     * <b>Note:</b> The table has to be registered with registerTable(const QString &tblName).
     *
     * @param filter The filter is an SQL WHERE clause without the keyword WHERE.
     * @see <a href="http://doc.qt.io/qt-4.8/qsqltablemodel.html#setFilter">QSqlTableModel::setFilter(const QString &filter)</a>
     *
     * @return The count of all rows in the given table that match the given filter.
     *
     * <b>Note:</b> If an error occured during the execution, the function returns -1.
     */
    int selectCount(const QString &tbl, const QString &filter = "");

    /**
     * @brief isSelectEmpty Indicates whether a select on the given table with the given filter matches no rows.
     *
     * This function uses selectCount(const QString &tbl, const QString &filter) for the row count computation and
     * returns true iff the row count equals 0, false otherwise.
     *
     * @see selectCount(const QString &tbl, const QString &filter)
     * @param tbl The table name as specified in the underlying database.
     *
     * <b>Note:</b> The table has to be registered with registerTable(const QString &tblName).
     *
     * @param filter The filter is an SQL WHERE clause without the keyword WHERE.
     * @see <a href="http://doc.qt.io/qt-4.8/qsqltablemodel.html#setFilter">QSqlTableModel::setFilter(const QString &filter)</a>
     *
     * @return true, iff the count of selected rows equals 0, false otherwise.
     */
    bool isSelectEmpty(const QString &tbl, const QString &filter = "");

    /**
     * @brief insert Inserts a new row into the given table with given types and values for each column.
     *
     * This function is an abstract way to execute the SQL INSERT statement. It inserts a new row at the end of the given table,
     * therefor it uses the given types and values for each column in the given <a href="http://doc.qt.io/qt-4.8/qhash.html">QHash</a>
     * and returns the ID of the given identification column of the created row.
     *
     * If the statement could not be executed an error is reported.
     *
     * Error information can be retrieved with getLastError().
     *
     * @param tbl The table name as specified in the underlying database.
     *
     * <b>Note:</b> The table has to be registered with registerTable(const QString &tblName).
     * @param colMapNameType Maps the column names of the given table in the underlying database to the corresponding type.
     * @param colMapNameValue Maps the column names of the given table in the underlying database to
     * the corresponding value to be inserted in the column of the new row.
     *
     * <b>Note:</b> This parameter specifies which columns in the given table are affected.
     * @param colID If the column is already in the <a href="http://doc.qt.io/qt-4.8/qhash.html">QHash</a> of the column values,
     * the values are not affected, otherwise the function getNextID(const QString &tbl, const QString &colName) is called to generate
     * a new unique ID for the given column and is inserted in the colMapNameValue.
     *
     * <b>Note:</b> If the type of the column is not of the type integer an error will occur.
     * @return Returns the value of the given column by colID iff the insert was successful, -1 otherwise.
     */
    int insert(const QString &tbl, const QHash<QString, QVariant::Type> &colMapNameType, QHash<QString, QVariant> &colMapNameValue, const QString &colID = "");

    /**
     * @brief update Updates all rows in the given table that match the given filter with the given columns and values.
     *
     * This function is an abstract way of execute the SQL UPDATE statement. It updates all rows in the given table that match
     * the given filter. It only updates the columns that values are provided for by the colMapNameValue <a href="http://doc.qt.io/qt-4.8/qhash.html">QHash</a>.
     * If the statement could not be executed, an error is reported.
     *
     * Error information can be retrieved with getLastError().
     *
     * <b>Note:</b> The update is successful iff all rows in the given table
     * that match the given filter could be updated successfully.
     *
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
     * <b>Note:</b> This parameter specifies which columns in the given table are affected.
     *
     * @param filter The filter is an SQL WHERE clause without the keyword WHERE.
     * @see <a href="http://doc.qt.io/qt-4.8/qsqltablemodel.html#setFilter">QSqlTableModel::setFilter(const QString &filter)</a>
     *
     * @param colID The column name in the given table which is used as the identifier of a row.
     *
     * @return Returns the value of the given column by colID of the first updated row, iff the update was successful, -1 otherwise.
     */
    int update(const QString &tbl, const QHash<QString, QVariant::Type> &colMapNameType, QHash<QString, QVariant> &colMapNameValue, const QString &filter = "", const QString &colID = "");

    /**
     * @brief save Saves the given values as new or updated rows in the given table.
     *
     * If there is a row that matches the given filter, update() is called, otherwise insert() is called.
     *
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
     * @param filter The filter is an SQL WHERE clause without the keyword WHERE.
     * @see <a href="http://doc.qt.io/qt-4.8/qsqltablemodel.html#setFilter">QSqlTableModel::setFilter(const QString &filter)</a>
     *
     * @param colID The column name in the given table which is used as the identifier of a row.
     *
     * @return Returns the value of the given column by colID, iff the insert was successful,
     * the value of the given column by colID of the first updated row, iff the update was successful, -1 otherwise.
     *
     * @see insert()
     * @see update()
     */
    int save(const QString &tbl, const QHash<QString, QVariant::Type> &colMapNameType, QHash<QString, QVariant> &colMapNameValue, const QString &filter = "", const QString &colID = "");

    /**
     * @brief remove Deletes all rows in the given table that match the given filter.
     *
     * This function is an abstract way to execute the SQL DELETE statement. It removes all rows in the given table of
     * the underlying database that match the given filter.
     * If the statement could not be executed an error is reported.
     *
     * Error information can be retrieved with getLastError().
     *
     * @param tbl The table name as specified in the underlying database.
     *
     * <b>Note:</b> The table has to be registered with registerTable(const QString &tblName).
     *
     * @param filter The filter is an SQL WHERE clause without the keyword WHERE.
     * @see <a href="http://doc.qt.io/qt-4.8/qsqltablemodel.html#setFilter">QSqlTableModel::setFilter(const QString &filter)</a>
     *
     * @return true iff all rows in the given table that match the given filter could successfully be removed, false otherwise.
     *
     * @warning The function is not atomic, if it returns false, it does not mean that no row was removed.
     * It only means, that there is at least one row, that could not be removed.
     *
     */
    bool remove(const QString &tbl, const QString &filter = "");

    /**
     * @brief hasError Indicates whether the DBHandler has an unrecognized error.
     * @return true, iff there is an error which was not recognized with getLastError() yet, false otherwise.
     */
    bool hasError() const;

    /**
     * @brief getLastError Returns the error message of the last error that has occured.
     * @param resetHasError Indicates whether the error should be marked as recognized.
     *
     * <b>Note:</b> If the parameter's value is <i>false</i>, hasError() will return true, iff there is an unrecognized error,
     * this means it will not be reset.
     *
     * @return The error message of the last error. If there has never been a reported error it will return an empty string.
     */
    QString getLastError(bool resetHasError = true);

private:

    /**
     * @brief getSqlTableModel Returns a reference to the <a href="http://doc.qt.io/qt-4.8/QSqlTableModel.html">QSqlTableModel</a> as registered with the given name.
     *
     * If there is no table registered with the given name, an error is reported.
     *
     * Error information can be retrieved with getLastError().
     *
     * @see registerTable()
     *
     * @param tblName The name of the table as registered.
     * @return the table model reference of the corresponding name iff it was registered, 0 otherwise.
     */
    QSqlTableModel* getSqlTableModel(const QString &tblName);

    /**
     * @brief existsSqlTableModel Indicates whether the given table name was registered.
     * @param tblName The name of the table to check.
     * @return <i>true</i> iff the table has been registered, <i>false</i> otherwise.
     *
     * @see registerTable()
     */
    bool existsSqlTableModel(const QString &tblName);

    /**
     * @brief reportError Reports a database error with the given error message.
     *
     * Reporting an error means setting the given error message as the last error message. hasError() will then
     * return <i>true</i>, the error message is accessible via getLastError().
     * Furthermore the error gets logged by reporting it to the applications error log.
     *
     * @see ErrorReporter::reportError()
     *
     * @param errorMessage The error message, that describes the error.
     */
    void reportError(const QString &errorMessage);

    bool m_hasError;
    QString lastError;
    QSqlDatabase database;
    QHash<const QString, QSqlTableModel*> htSqlTableModels;

};

#endif // DBHANDLER_H
