#include "dbhandlertest.h"
#include "../standardpaths.h"

DBHandlerTest::DBHandlerTest(QObject *parent) : QObject(parent)
{

}

DBHandlerTest::~DBHandlerTest()
{

}

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

//PRIVATE SLOTS
void DBHandlerTest::initTestCase(){
    QFileInfo databaseFileInfo = QFileInfo(StandardPaths::testDatabasePath());
    QString databaseOriginPath = StandardPaths::originTestDatabasePath();
    QString databasePath = databaseFileInfo.absoluteFilePath();

    //Copy database from the readOnly location to the writeable location,
    //if the database does not exsist yet.
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

void DBHandlerTest::getNextIDWithoutFilterTest(){

}

void DBHandlerTest::getNextIDWithFilterTest(){

}

void DBHandlerTest::getNextIDWithInvalidFilterTest(){

}

void DBHandlerTest::getNextIDFromUnknownTableTest(){

}

void DBHandlerTest::getNextIDFromInvalidColumnTest(){

}

void DBHandlerTest::insertWithoutCOLIDTest(){

}

void DBHandlerTest::insertWithCOLIDTest(){

}

void DBHandlerTest::insertIntoUnknownTableTest(){

}

void DBHandlerTest::insertInvalidValuesTest(){

}

void DBHandlerTest::selectWithFilterTest(){

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

}

void DBHandlerTest::selectFirstWithoutFilterTest(){

}

void DBHandlerTest::selectFirstEmptyTest(){

}

void DBHandlerTest::selectFirstFromUnknownTableTest(){

}

void DBHandlerTest::selectFirstWithInvalidFilterTest(){

}

void DBHandlerTest::selectCountWithFilterTest(){

}

void DBHandlerTest::selectCountWithoutFilterTest(){

}

void DBHandlerTest::selectCountEmpty(){

}

void DBHandlerTest::selectCountFromUnknownTableTest(){

}

void DBHandlerTest::selectCountWithInvalidFilterTest(){

}

void DBHandlerTest::isSelectEmptyTrueTest(){

}

void DBHandlerTest::isSelectEmptyFalseTest(){

}

void DBHandlerTest::isSelectEmptyFromUnknownTableTest(){

}

void DBHandlerTest::isSelectEmptyWithInvalidFilterTest(){

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

