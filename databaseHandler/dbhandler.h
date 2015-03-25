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
 * @brief The DBHandler class
 *
 */
class DBHandler
{

public:
    /**
     * @brief DBHandler
     * @param databasePath
     */
    DBHandler(const QString &databasePath);

    ~DBHandler();

    /**
     * @brief registerTable
     * @param tblName
     */
    void registerTable(const QString &tblName);

    /**
     * @brief getNextID
     * @param tbl
     * @param colName
     * @param filter
     * @return
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
