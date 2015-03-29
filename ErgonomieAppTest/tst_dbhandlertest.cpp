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

    void registerTableTest();
    void registerUnknownTableTest();
    void registerTableTwiceTest();

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

    if ( !databaseFileInfo.exists() ){
       bool copySuccess = QFile::copy( databaseOriginPath, databasePath );
       if ( !copySuccess ){
           QVERIFY(false);
       }
       else{
            if(!QFile::setPermissions(databasePath,QFile::WriteOwner | QFile::ReadOwner)){
                QVERIFY(false);
            }
       }
    }
    dbHandler = new DBHandler(databasePath);
    QVERIFY(!dbHandler->hasError());
}

void DBHandlerTest::registerTableTest(){
    if(dbHandler->hasError())
        dbHandler->getLastError();
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
    if(dbHandler->hasError())
        dbHandler->getLastError();
    dbHandler->registerTable(TBL_ENTRY);
    dbHandler->registerTable(TBL_ENTRY);
    QVERIFY(!dbHandler->hasError());
}

void DBHandlerTest::cleanupTestCase(){
    delete dbHandler;
}

QTEST_APPLESS_MAIN(DBHandlerTest)

#include "tst_dbhandlertest.moc"
