#ifndef DBHANDLERTEST_H
#define DBHANDLERTEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "../databaseHandler/dbhandler.h"
#include "../databaseHandler/qhashbuilder.h"

class DBHandlerTest : public QObject
{   
    Q_OBJECT
public:
    explicit DBHandlerTest(QObject *parent = 0);
    ~DBHandlerTest();

private slots:
    void initTestCase();

    void registerTableTest();
    void registerUnknownTableTest();
    void registerTableTwiceTest();

    void getNextIDWithoutFilterTest();
    void getNextIDWithFilterTest();
    void getNextIDWithInvalidFilterTest();
    void getNextIDFromUnknownTableTest();
    void getNextIDFromInvalidColumnTest();

    void insertWithoutCOLIDTest();
    void insertWithCOLIDTest();
    void insertIntoUnknownTableTest();
    void insertInvalidValuesTest();

    void selectWithFilterTest();
    void selectWithoutFilterTest();
    void selectEmptyTest();
    void selectFromUnknownTableTest();
    void selectWithInvalidFilterTest();

    void selectFirstWithFilterTest();
    void selectFirstWithoutFilterTest();
    void selectFirstEmptyTest();
    void selectFirstFromUnknownTableTest();
    void selectFirstWithInvalidFilterTest();

    void selectCountWithFilterTest();
    void selectCountWithoutFilterTest();
    void selectCountEmpty();
    void selectCountFromUnknownTableTest();
    void selectCountWithInvalidFilterTest();

    void isSelectEmptyTrueTest();
    void isSelectEmptyFalseTest();
    void isSelectEmptyFromUnknownTableTest();
    void isSelectEmptyWithInvalidFilterTest();

    void updateWithCOLIDTest();
    void updateWithoutCOLIDTest();
    void updateWithFilterTest();
    void updateWithoutFilterTest();
    void updateIntoUnknownTableTest();
    void updateInvalidValuesTest();
    void updateExactlyOneRowTest();

    void removeWithFilterTest();
    void removeWithoutFilterTest();
    void removeFromUnknownTableTest();
    void removeWithInvalidFilterTest();

    void cleanupTestCase();

private:
    static const QString TBL_ENTRY;
    static const QString COL_ENTRY_ID;
    static const QString COL_ENTRY_DESCRIPTION;
    static const QString COL_ENTRY_AMOUNT;
    static const QHash<QString, QVariant::Type> HASH_ENTRY_TYPES;

    static const QString TBL_SHOPPING_LIST;
    static const QString COL_SHOPPING_LIST_ID;
    static const QString COL_SHOPPING_LIST_ORDER;
    static const QString COL_SHOPPING_LIST_ENTRY_ID;
    static const QHash<QString, QVariant::Type> HASH_SHOPPING_LIST_TYPES;

    DBHandler *dbHandler;
};

#endif // DBHANDLERTEST_H
