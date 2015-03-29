#include "tst_dbhandlertest.h"

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
.add(DBHandlerTest::COL_SHOPPING_LIST_ID, QVariant::Int)
.add(DBHandlerTest::COL_SHOPPING_LIST_ORDER, QVariant::Int)
.add(DBHandlerTest::COL_SHOPPING_LIST_ENTRY_ID, QVariant::Int)
.build();

DBHandlerTest::DBHandlerTest(){
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

void DBHandlerTest::initInvalidDatabaseTest(){
    DBHandler *test = new DBHandler("/hier/koennte/ihre/werbung/stehen.sqlite");
    QVERIFY(test->hasError());
}

void DBHandlerTest::hasErrorTrueTest(){
    dbHandler->registerTable("Test");
    QVERIFY(dbHandler->hasError());
}

void DBHandlerTest::hasErrorFalseTest(){
    dbHandler->registerTable(TBL_ENTRY);
    QVERIFY(!dbHandler->hasError());
}

void DBHandlerTest::getLastErrorWithResetTest(){
    dbHandler->registerTable("Test");
    QVERIFY(dbHandler->hasError());
    dbHandler->getLastError(true);
    QVERIFY(!dbHandler->hasError());
}

void DBHandlerTest::getLastErrorWithoutResetTest(){
    dbHandler->registerTable("Test");
    QVERIFY(dbHandler->hasError());
    dbHandler->getLastError(false);
    QVERIFY(dbHandler->hasError());
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
    QList<QHash<QString, QVariant>> entries = dbHandler->select(TBL_ENTRY);

    QVERIFY(!dbHandler->hasError());
    QCOMPARE(entries.size(), 3);

    QHash<QString, QVariant> entry0 = entries.at(0);
    QCOMPARE(entry0.value(COL_ENTRY_ID).toInt(), 1);
    QCOMPARE(entry0.value(COL_ENTRY_DESCRIPTION).toString(), QString("Bread"));
    QCOMPARE(entry0.value(COL_ENTRY_AMOUNT).toInt(), 1);

    QHash<QString, QVariant> entry1 = entries.at(1);
    QCOMPARE(entry1.value(COL_ENTRY_ID).toInt(), 2);
    QCOMPARE(entry1.value(COL_ENTRY_DESCRIPTION).toString(), QString("Milk"));
    QCOMPARE(entry1.value(COL_ENTRY_AMOUNT).toInt(), 3);

    QHash<QString, QVariant> entry2 = entries.at(2);
    QCOMPARE(entry2.value(COL_ENTRY_ID).toInt(), 3);
    QCOMPARE(entry2.value(COL_ENTRY_DESCRIPTION).toString(), QString("Applewoi"));
    QCOMPARE(entry2.value(COL_ENTRY_AMOUNT).toInt(), 42);
}

void DBHandlerTest::selectEmptyTest(){
    QList<QHash<QString, QVariant>> entries = dbHandler->select(TBL_SHOPPING_LIST);
    QVERIFY(!dbHandler->hasError());
    QVERIFY(entries.isEmpty());
}

void DBHandlerTest::selectFromUnknownTableTest(){
    QList<QHash<QString, QVariant>> entries = dbHandler->select("Test");
    QVERIFY(dbHandler->hasError());
    QVERIFY(entries.isEmpty());
}

void DBHandlerTest::selectWithInvalidFilterTest(){
    QList<QHash<QString, QVariant>> entries = dbHandler->select(TBL_ENTRY, "Test = 'test'");
    QVERIFY(dbHandler->hasError());
    QVERIFY(entries.isEmpty());
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
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(COL_ENTRY_DESCRIPTION, "Tequilla");
    values.insert(COL_ENTRY_AMOUNT, 5);

    int ret_ID = dbHandler->insert(TBL_ENTRY, HASH_ENTRY_TYPES, values, COL_ENTRY_ID);
    QCOMPARE(ret_ID, 5);
    QVERIFY(!dbHandler->hasError());

    QString filter = QString("%1 = %2").arg(COL_ENTRY_ID).arg(ret_ID);
    values = dbHandler->selectFirst(TBL_ENTRY, filter);

    QCOMPARE(values.value(COL_ENTRY_ID).toInt(), ret_ID);
    QCOMPARE(values.value(COL_ENTRY_DESCRIPTION).toString(), QString("Tequilla"));
    QCOMPARE(values.value(COL_ENTRY_AMOUNT).toInt(), 5);
    QVERIFY(!dbHandler->hasError());
}

void DBHandlerTest::insertIntoUnknownTableTest(){
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    int ret_ID = dbHandler->insert("Test", HASH_ENTRY_TYPES, values, COL_ENTRY_ID);

    QVERIFY(dbHandler->hasError());
    QCOMPARE(ret_ID, -1);
}

void DBHandlerTest::insertInvalidValuesTest(){
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(COL_ENTRY_DESCRIPTION, "Test");
    values.insert(COL_SHOPPING_LIST_ORDER, 3);
    int ret_ID = dbHandler->insert(TBL_ENTRY, HASH_ENTRY_TYPES, values, COL_ENTRY_ID);

    QVERIFY(dbHandler->hasError());
    QCOMPARE(ret_ID, -1);
    QCOMPARE(dbHandler->selectCount(TBL_ENTRY), 5);
}

void DBHandlerTest::updateWithCOLIDTest(){
    QString filter = QString("%1 = %2").arg(COL_ENTRY_ID).arg(1);
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(COL_ENTRY_AMOUNT, 10);
    int id = dbHandler->update(TBL_ENTRY, HASH_ENTRY_TYPES, values, filter, COL_ENTRY_ID);

    QVERIFY(!dbHandler->hasError());
    QCOMPARE(id, 1);
    QList<QHash<QString, QVariant>> entries = dbHandler->select(TBL_ENTRY, filter);

    QVERIFY(!dbHandler->hasError());
    QCOMPARE(entries.size(), 1);
    QHash<QString, QVariant> entry = entries.at(0);

    QCOMPARE(entry.value(COL_ENTRY_ID).toInt(), 1);
    QCOMPARE(entry.value(COL_ENTRY_DESCRIPTION).toString(), QString("Bread"));
    QCOMPARE(entry.value(COL_ENTRY_AMOUNT).toInt(), 10);
}

void DBHandlerTest::updateWithoutCOLIDTest(){
    QString filter = QString("%1 = %2").arg(COL_ENTRY_ID).arg(2);
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(COL_ENTRY_DESCRIPTION, "lime");
    int id = dbHandler->update(TBL_ENTRY, HASH_ENTRY_TYPES, values, filter);

    QVERIFY(!dbHandler->hasError());
    QCOMPARE(id, 0);
    QList<QHash<QString, QVariant>> entries = dbHandler->select(TBL_ENTRY, filter);

    QVERIFY(!dbHandler->hasError());
    QCOMPARE(entries.size(), 1);
    QHash<QString, QVariant> entry = entries.at(0);

    QCOMPARE(entry.value(COL_ENTRY_ID).toInt(), 2);
    QCOMPARE(entry.value(COL_ENTRY_DESCRIPTION).toString(), QString("lime"));
    QCOMPARE(entry.value(COL_ENTRY_AMOUNT).toInt(), 3);
}

void DBHandlerTest::updateWithoutFilterTest(){
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(COL_ENTRY_AMOUNT, 42);
    int id = dbHandler->update(TBL_ENTRY, HASH_ENTRY_TYPES, values);

    QVERIFY(!dbHandler->hasError());
    QCOMPARE(id, 0);

    QList<QHash<QString, QVariant>> entries = dbHandler->select(TBL_ENTRY);
    QVERIFY(!dbHandler->hasError());
    QCOMPARE(entries.size(), 5);
    for(int i = 0; i < entries.size(); ++i)
        QCOMPARE(entries.at(i).value(COL_ENTRY_AMOUNT).toInt(), 42);
}

void DBHandlerTest::updateIntoUnknownTableTest(){
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    int id = dbHandler->update("Test", HASH_ENTRY_TYPES, values);

    QVERIFY(dbHandler->hasError());
    QCOMPARE(id, -1);
}

void DBHandlerTest::updateInvalidValuesTest(){
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(COL_SHOPPING_LIST_ORDER, 5);
    int id = dbHandler->update(TBL_ENTRY, HASH_ENTRY_TYPES, values);

    QVERIFY(dbHandler->hasError());
    QCOMPARE(id, -1);
}

void DBHandlerTest::saveInsertTest(){
    QString filter = QString("%1 = %2").arg(COL_ENTRY_ID);
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(COL_ENTRY_DESCRIPTION, "wine");
    values.insert(COL_ENTRY_AMOUNT, 18);
    int id = dbHandler->save(TBL_ENTRY, HASH_ENTRY_TYPES, values, filter.arg(0), COL_ENTRY_ID);

    QVERIFY(!dbHandler->hasError());
    QCOMPARE(id, 6);

    QHash<QString, QVariant> entry = dbHandler->selectFirst(TBL_ENTRY, filter.arg(id));
    QVERIFY(!dbHandler->hasError());
    QVERIFY(!entry.isEmpty());
    QCOMPARE(entry.value(COL_ENTRY_ID).toInt(), 6);
    QCOMPARE(entry.value(COL_ENTRY_AMOUNT).toInt(), 18);
    QCOMPARE(entry.value(COL_ENTRY_DESCRIPTION).toString(), QString("wine"));
}

void DBHandlerTest::saveUpdateTest(){
    QString filter = QString("%1 > %2").arg(COL_ENTRY_ID).arg(3);
    QHash<QString, QVariant> values = QHash<QString, QVariant>();
    values.insert(COL_ENTRY_DESCRIPTION, "test");
    int id = dbHandler->save(TBL_ENTRY, HASH_ENTRY_TYPES, values, filter, COL_ENTRY_ID);

    QVERIFY(!dbHandler->hasError());
    QCOMPARE(id, 4);

    QList<QHash<QString, QVariant>> entries = dbHandler->select(TBL_ENTRY, filter);
    QVERIFY(!dbHandler->hasError());
    QCOMPARE(entries.size(), 3);
    for(int i = 0; i < entries.size(); ++i)
        QCOMPARE(entries.at(i).value(COL_ENTRY_DESCRIPTION).toString(), QString("test"));
}

void DBHandlerTest::removeWithFilterTest(){
    QString filter = QString("%1 > %2").arg(COL_ENTRY_ID).arg(3);
    bool success = dbHandler->remove(TBL_ENTRY, filter);

    QVERIFY(success && !dbHandler->hasError());
    QList<QHash<QString, QVariant>> entries = dbHandler->select(TBL_ENTRY);

    QVERIFY(!dbHandler->hasError());
    QCOMPARE(entries.size(), 3);
    for(int i = 0; i < entries.size(); ++i)
        QVERIFY(entries.at(i).value(COL_ENTRY_ID).toInt() <= 3);
}

void DBHandlerTest::removeWithoutFilterTest(){
    bool success = dbHandler->remove(TBL_ENTRY, "");

    QVERIFY(success && !dbHandler->hasError());
    int count = dbHandler->selectCount(TBL_ENTRY);
    QVERIFY(!dbHandler->hasError());
    QCOMPARE(count, 0);
}

void DBHandlerTest::removeFromUnknownTableTest(){
    bool success = dbHandler->remove("Test");
    QVERIFY(!success && dbHandler->hasError());
}

void DBHandlerTest::removeWithInvalidFilterTest(){
    bool success = dbHandler->remove(TBL_ENTRY, "Test = test");
    QVERIFY(!success && dbHandler->hasError());
}

void DBHandlerTest::cleanupTestCase(){
    delete dbHandler;
}

