#include <QString>
#include <QtTest>
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

//Static constants
const QString DBHandlerTest::TBL_ENTRY = QString("Entry");
const QString DBHandlerTest::COL_ENTRY_ID = QString("entry_ID");
const QString DBHandlerTest::COL_ENTRY_DESCRIPTION = QString("description");
const QString DBHandlerTest::COL_ENTRY_AMOUNT = QString("amount");
const QHash<QString, QVariant::Type> DBHandlerTest::HASH_ENTRY_TYPES = QHashBuilder<QString, QVariant::Type>()
.add(DBHandlerTest::COL_ENTRY_ID, QVariant::Int)
.add(DBHandlerTest::COL_ENTRY_DESCRIPTION, QVariant::String)
.add(DBHandlerTest::COL_ENTRY_AMOUNT, QVariant::Int)
.build();

const QString DBHandlerTest::TBL_SHOPPING_LIST = QString("ShoppingList");
const QString DBHandlerTest::COL_SHOPPING_LIST_ID = QString("list_ID");
const QString DBHandlerTest::COL_SHOPPING_LIST_ORDER = QString("order_number");
const QString DBHandlerTest::COL_SHOPPING_LIST_ENTRY_ID = QString("entry_ID");
const QHash<QString, QVariant::Type> DBHandlerTest::HASH_SHOPPING_LIST_TYPES = QHashBuilder<QString, QVariant::Type>()
.add(COL_SHOPPING_LIST_ID, QVariant::Int)
.add(COL_SHOPPING_LIST_ORDER, QVariant::Int)
.add(COL_SHOPPING_LIST_ENTRY_ID, QVariant::Int)
.build();

DBHandlerTest::DBHandlerTest()
{
}

void DBHandlerTest::initTestCase(){
    QFileInfo databaseFileInfo = QFileInfo(StandardPaths::testDatabasePath());
    QString databaseOriginPath = StandardPaths::originTestDatabasePath();
    QString databasePath = databaseFileInfo.absoluteFilePath();

    if(databaseFileInfo.exists()){
        QFile file(databasePath);
        if(file.open(QIODevice::WriteOnly)){
            file.remove();
            file.close();
        }
        else
            QVERIFY(false);
    }
    bool copySuccess = QFile::copy( databaseOriginPath, databasePath );
    if ( !copySuccess )
        QVERIFY(false);

    if(!QFile::setPermissions(databasePath,QFile::WriteOwner | QFile::ReadOwner))
        QVERIFY(false);

    dbHandler = new DBHandler(databasePath);
    QVERIFY(!dbHandler->hasError());
}

void DBHandlerTest::cleanup(){
    if(dbHandler->hasError())
        dbHandler->getLastError();
    QVERIFY(!dbHandler->hasError());
}

void DBHandlerTest::registerTableTest(){
    dbHandler->registerTable(TBL_ENTRY);
    QVERIFY(!dbHandler->hasError());

    dbHandler->registerTable(TBL_SHOPPING_LIST);
    QVERIFY(!dbHandler->hasError());
}

void DBHandlerTest::registerUnknownTableTest(){
    dbHandler->getLastError();
    dbHandler->registerTable("Test");

    QVERIFY(dbHandler->hasError());
}

void DBHandlerTest::registerTableTwiceTest(){
    dbHandler->registerTable(TBL_ENTRY);
    dbHandler->registerTable(TBL_ENTRY);
    QVERIFY(!dbHandler->hasError());
}

void DBHandlerTest::getNextIDWithoutFilterTest(){
    int id = dbHandler->getNextID(TBL_ENTRY, COL_ENTRY_ID);
    QCOMPARE(id, 4);
    QVERIFY(!dbHandler->hasError());
}

void DBHandlerTest::getNextIDWithFilterTest(){
    QString filter = QString("%1 = %2")
            .arg(COL_ENTRY_ID);

    int id = dbHandler->getNextID(TBL_ENTRY, COL_ENTRY_ID, filter.arg(1));
    QCOMPARE(id, 2);
    QVERIFY(!dbHandler->hasError());

    id = dbHandler->getNextID(TBL_ENTRY, COL_ENTRY_ID, filter.arg(3));
    QCOMPARE(id, 4);
    QVERIFY(!dbHandler->hasError());
}

void DBHandlerTest::getNextIDWithInvalidFilterTest(){
    QString filter = QString("id = 3");
    int id = dbHandler->getNextID(TBL_ENTRY, COL_ENTRY_ID, filter);
    QCOMPARE(id, -1);
    QVERIFY(dbHandler->hasError());
}

void DBHandlerTest::getNextIDFromUnknownTableTest(){
    int id = dbHandler->getNextID("Test", COL_ENTRY_ID);
    QCOMPARE(id, -1);
    QVERIFY(dbHandler->hasError());
}

void DBHandlerTest::getNextIDFromInvalidColumnTest(){
    int id = dbHandler->getNextID(TBL_ENTRY, COL_ENTRY_DESCRIPTION);
    QCOMPARE(id, 1);
    QVERIFY(!dbHandler->hasError());
}

void DBHandlerTest::selectWithFilterTest(){
    QString filter = QString("%1 >= %2").arg(COL_ENTRY_AMOUNT).arg(3);
    QList<QHash<QString, QVariant>> entries = dbHandler->select(TBL_ENTRY, filter);

    QVERIFY(!dbHandler->hasError());
    QCOMPARE(entries.size(), 2);

    QHash<QString, QVariant> entry1 = entries.at(0);
    QCOMPARE(entry1.value(COL_ENTRY_ID).toInt(), 2);
    QCOMPARE(entry1.value(COL_ENTRY_DESCRIPTION).toString(), QString("Milk"));
    QCOMPARE(entry1.value(COL_ENTRY_AMOUNT).toInt(), 3);

    QHash<QString, QVariant> entry2 = entries.at(1);
    QCOMPARE(entry2.value(COL_ENTRY_ID).toInt(), 3);
    QCOMPARE(entry2.value(COL_ENTRY_DESCRIPTION).toString(), QString("Applewoi"));
    QCOMPARE(entry2.value(COL_ENTRY_AMOUNT).toInt(), 42);
}

void DBHandlerTest::selectWithoutFilterTest(){

}

void DBHandlerTest::selectEmptyTest(){

}

void DBHandlerTest::selectFromUnknownTableTest(){

}

void DBHandlerTest::selectWithInvalidFilterTest(){

}

void DBHandlerTest::selectFirstWithFilterTest(){
    QString filter = QString("%1 > %2").arg(COL_ENTRY_AMOUNT).arg(2);
    QHash<QString, QVariant> values = dbHandler->selectFirst(TBL_ENTRY, filter);
    QVERIFY(!dbHandler->hasError());
    QCOMPARE(values.value(COL_ENTRY_ID).toInt(), 2);
    QCOMPARE(values.value(COL_ENTRY_DESCRIPTION).toString(), QString("Milk"));
    QCOMPARE(values.value(COL_ENTRY_AMOUNT).toInt(), 3);
}

void DBHandlerTest::selectFirstWithoutFilterTest(){
    QHash<QString, QVariant> values = dbHandler->selectFirst(TBL_ENTRY);
    QVERIFY(!dbHandler->hasError());
    QCOMPARE(values.value(COL_ENTRY_ID).toInt(), 1);
    QCOMPARE(values.value(COL_ENTRY_DESCRIPTION).toString(), QString("Bread"));
    QCOMPARE(values.value(COL_ENTRY_AMOUNT).toInt(), 1);
}

void DBHandlerTest::selectFirstEmptyTest(){
    QHash<QString, QVariant> values = dbHandler->selectFirst(TBL_SHOPPING_LIST);
    QVERIFY(!dbHandler->hasError());
    QVERIFY(values.isEmpty());
}

void DBHandlerTest::selectFirstFromUnknownTableTest(){
    QHash<QString, QVariant> values = dbHandler->selectFirst("Test");
    QVERIFY(dbHandler->hasError());
    QVERIFY(values.isEmpty());
}

void DBHandlerTest::selectFirstWithInvalidFilterTest(){
    QHash<QString, QVariant> values = dbHandler->selectFirst(TBL_ENTRY, "entrie_ID == 2");
    QVERIFY(dbHandler->hasError());
    QVERIFY(values.isEmpty());
}

void DBHandlerTest::selectCountWithFilterTest(){
    QString filter = QString("%1 = '%2'").arg(COL_ENTRY_DESCRIPTION).arg("Applewoi");
    int count = dbHandler->selectCount(TBL_ENTRY, filter);
    QCOMPARE(count, 1);
    QVERIFY(!dbHandler->hasError());
}

void DBHandlerTest::selectCountWithoutFilterTest(){
    int count = dbHandler->selectCount(TBL_ENTRY);
    QCOMPARE(count, 3);
    QVERIFY(!dbHandler->hasError());
}

void DBHandlerTest::selectCountEmpty(){
    QString filter = QString("%1 > %2").arg(COL_ENTRY_AMOUNT).arg(42);
    int count = dbHandler->selectCount(TBL_ENTRY, filter);
    QCOMPARE(count, 0);
    QVERIFY(!dbHandler->hasError());
}

void DBHandlerTest::selectCountFromUnknownTableTest(){
    int count = dbHandler->selectCount("Test");
    QCOMPARE(count, -1);
    QVERIFY(dbHandler->hasError());
}

void DBHandlerTest::selectCountWithInvalidFilterTest(){
    QString filter = QString("test_ID = 'bla'");
    int count = dbHandler->selectCount(TBL_SHOPPING_LIST, filter);
    QCOMPARE(count, -1);
    QVERIFY(dbHandler->hasError());
}

void DBHandlerTest::isSelectEmptyTrueTest(){
    bool isEmpty = dbHandler->isSelectEmpty(TBL_SHOPPING_LIST);
    QVERIFY(isEmpty);
    QVERIFY(!dbHandler->hasError());
}

void DBHandlerTest::isSelectEmptyFalseTest(){
    bool isEmpty = dbHandler->isSelectEmpty(TBL_ENTRY);
    QVERIFY(!isEmpty);
    QVERIFY(!dbHandler->hasError());
}

void DBHandlerTest::isSelectEmptyFromUnknownTableTest(){
    bool isEmpty = dbHandler->isSelectEmpty("Test");
    QVERIFY(!isEmpty);
    QVERIFY(dbHandler->hasError());
}

void DBHandlerTest::isSelectEmptyWithInvalidFilterTest(){
    bool isEmpty = dbHandler->isSelectEmpty(TBL_ENTRY, "HkiWs = 42");
    QVERIFY(!isEmpty);
    QVERIFY(dbHandler->hasError());
}

void DBHandlerTest::insertWithoutCOLIDTest(){
    int next_ID = dbHandler->getNextID(TBL_ENTRY, COL_ENTRY_ID);
    QCOMPARE(next_ID, 4);
    QVERIFY(!dbHandler->hasError());

    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(COL_ENTRY_ID, next_ID);
    values.insert(COL_ENTRY_DESCRIPTION, "Beer");
    values.insert(COL_ENTRY_AMOUNT, 12);

    int ret_ID = dbHandler->insert(TBL_ENTRY, HASH_ENTRY_TYPES, values);
    QCOMPARE(ret_ID, 0);
    QVERIFY(!dbHandler->hasError());

    QString filter = QString("%1 = %2").arg(COL_ENTRY_ID).arg(next_ID);
    values = dbHandler->selectFirst(TBL_ENTRY, filter);

    QCOMPARE(values.value(COL_ENTRY_ID).toInt(), 4);
    QCOMPARE(values.value(COL_ENTRY_DESCRIPTION).toString(), QString("Beer"));
    QCOMPARE(values.value(COL_ENTRY_AMOUNT).toInt(), 12);
    QVERIFY(!dbHandler->hasError());
}

void DBHandlerTest::insertWithCOLIDTest(){

}

void DBHandlerTest::insertIntoUnknownTableTest(){

}

void DBHandlerTest::insertInvalidValuesTest(){

}

void DBHandlerTest::updateWithCOLIDTest(){

}

void DBHandlerTest::updateWithoutCOLIDTest(){

}

void DBHandlerTest::updateWithFilterTest(){

}

void DBHandlerTest::updateWithoutFilterTest(){

}

void DBHandlerTest::updateIntoUnknownTableTest(){

}

void DBHandlerTest::updateInvalidValuesTest(){

}

void DBHandlerTest::updateExactlyOneRowTest(){

}

void DBHandlerTest::removeWithFilterTest(){

}

void DBHandlerTest::removeWithoutFilterTest(){

}

void DBHandlerTest::removeFromUnknownTableTest(){

}

void DBHandlerTest::removeWithInvalidFilterTest(){

}

void DBHandlerTest::cleanupTestCase(){
    delete dbHandler;
}

QTEST_APPLESS_MAIN(DBHandlerTest)

#include "tst_dbhandlertest.moc"
