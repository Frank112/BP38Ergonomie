#ifndef TST_DBHANDLERTEST
#define TST_DBHANDLERTEST

#include <QObject>
#include <QtTest/QtTest>
#include <QFileInfo>
#include <QFile>
#include "../databaseHandler/dbhandler.h"
#include "../databaseHandler/qhashbuilder.h"
#include "../standardpaths.h"

class DBHandlerTest : public QObject
{
    Q_OBJECT

public:
    DBHandlerTest();

private Q_SLOTS:
    void initTestCase();

    void cleanup();

    void initInvalidDatabaseTest();

    void hasErrorTrueTest();
    void hasErrorFalseTest();

    void getLastErrorWithResetTest();
    void getLastErrorWithoutResetTest();

    void registerTableTest();
    void registerUnknownTableTest();
    void registerTableTwiceTest();

    void getNextIDWithoutFilterTest();
    void getNextIDWithFilterTest();
    void getNextIDWithInvalidFilterTest();
    void getNextIDFromUnknownTableTest();
    void getNextIDFromInvalidColumnTest();

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

    void insertWithoutCOLIDTest();
    void insertWithCOLIDTest();
    void insertIntoUnknownTableTest();
    void insertInvalidValuesTest();

    void updateWithCOLIDTest();
    void updateWithoutCOLIDTest();
    void updateWithoutFilterTest();
    void updateIntoUnknownTableTest();
    void updateInvalidValuesTest();

    void saveInsertTest();
    void saveUpdateTest();

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

#endif // TST_DBHANDLERTEST

