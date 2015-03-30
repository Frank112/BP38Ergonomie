/****************************************************************************
** Meta object code from reading C++ file 'tst_dbhandlertest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ErgonomieappTest/tst_dbhandlertest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tst_dbhandlertest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DBHandlerTest_t {
    QByteArrayData data[51];
    char stringdata[1201];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DBHandlerTest_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DBHandlerTest_t qt_meta_stringdata_DBHandlerTest = {
    {
QT_MOC_LITERAL(0, 0, 13), // "DBHandlerTest"
QT_MOC_LITERAL(1, 14, 12), // "initTestCase"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 7), // "cleanup"
QT_MOC_LITERAL(4, 36, 16), // "hasErrorTrueTest"
QT_MOC_LITERAL(5, 53, 17), // "hasErrorFalseTest"
QT_MOC_LITERAL(6, 71, 25), // "getLastErrorWithResetTest"
QT_MOC_LITERAL(7, 97, 28), // "getLastErrorWithoutResetTest"
QT_MOC_LITERAL(8, 126, 17), // "registerTableTest"
QT_MOC_LITERAL(9, 144, 24), // "registerUnknownTableTest"
QT_MOC_LITERAL(10, 169, 22), // "registerTableTwiceTest"
QT_MOC_LITERAL(11, 192, 26), // "getNextIDWithoutFilterTest"
QT_MOC_LITERAL(12, 219, 23), // "getNextIDWithFilterTest"
QT_MOC_LITERAL(13, 243, 30), // "getNextIDWithInvalidFilterTest"
QT_MOC_LITERAL(14, 274, 29), // "getNextIDFromUnknownTableTest"
QT_MOC_LITERAL(15, 304, 30), // "getNextIDFromInvalidColumnTest"
QT_MOC_LITERAL(16, 335, 20), // "selectWithFilterTest"
QT_MOC_LITERAL(17, 356, 23), // "selectWithoutFilterTest"
QT_MOC_LITERAL(18, 380, 15), // "selectEmptyTest"
QT_MOC_LITERAL(19, 396, 26), // "selectFromUnknownTableTest"
QT_MOC_LITERAL(20, 423, 27), // "selectWithInvalidFilterTest"
QT_MOC_LITERAL(21, 451, 25), // "selectFirstWithFilterTest"
QT_MOC_LITERAL(22, 477, 28), // "selectFirstWithoutFilterTest"
QT_MOC_LITERAL(23, 506, 20), // "selectFirstEmptyTest"
QT_MOC_LITERAL(24, 527, 31), // "selectFirstFromUnknownTableTest"
QT_MOC_LITERAL(25, 559, 32), // "selectFirstWithInvalidFilterTest"
QT_MOC_LITERAL(26, 592, 25), // "selectCountWithFilterTest"
QT_MOC_LITERAL(27, 618, 28), // "selectCountWithoutFilterTest"
QT_MOC_LITERAL(28, 647, 16), // "selectCountEmpty"
QT_MOC_LITERAL(29, 664, 31), // "selectCountFromUnknownTableTest"
QT_MOC_LITERAL(30, 696, 32), // "selectCountWithInvalidFilterTest"
QT_MOC_LITERAL(31, 729, 21), // "isSelectEmptyTrueTest"
QT_MOC_LITERAL(32, 751, 22), // "isSelectEmptyFalseTest"
QT_MOC_LITERAL(33, 774, 33), // "isSelectEmptyFromUnknownTable..."
QT_MOC_LITERAL(34, 808, 34), // "isSelectEmptyWithInvalidFilte..."
QT_MOC_LITERAL(35, 843, 22), // "insertWithoutCOLIDTest"
QT_MOC_LITERAL(36, 866, 19), // "insertWithCOLIDTest"
QT_MOC_LITERAL(37, 886, 26), // "insertIntoUnknownTableTest"
QT_MOC_LITERAL(38, 913, 23), // "insertInvalidValuesTest"
QT_MOC_LITERAL(39, 937, 19), // "updateWithCOLIDTest"
QT_MOC_LITERAL(40, 957, 22), // "updateWithoutCOLIDTest"
QT_MOC_LITERAL(41, 980, 23), // "updateWithoutFilterTest"
QT_MOC_LITERAL(42, 1004, 26), // "updateIntoUnknownTableTest"
QT_MOC_LITERAL(43, 1031, 23), // "updateInvalidValuesTest"
QT_MOC_LITERAL(44, 1055, 14), // "saveInsertTest"
QT_MOC_LITERAL(45, 1070, 14), // "saveUpdateTest"
QT_MOC_LITERAL(46, 1085, 20), // "removeWithFilterTest"
QT_MOC_LITERAL(47, 1106, 23), // "removeWithoutFilterTest"
QT_MOC_LITERAL(48, 1130, 26), // "removeFromUnknownTableTest"
QT_MOC_LITERAL(49, 1157, 27), // "removeWithInvalidFilterTest"
QT_MOC_LITERAL(50, 1185, 15) // "cleanupTestCase"

    },
    "DBHandlerTest\0initTestCase\0\0cleanup\0"
    "hasErrorTrueTest\0hasErrorFalseTest\0"
    "getLastErrorWithResetTest\0"
    "getLastErrorWithoutResetTest\0"
    "registerTableTest\0registerUnknownTableTest\0"
    "registerTableTwiceTest\0"
    "getNextIDWithoutFilterTest\0"
    "getNextIDWithFilterTest\0"
    "getNextIDWithInvalidFilterTest\0"
    "getNextIDFromUnknownTableTest\0"
    "getNextIDFromInvalidColumnTest\0"
    "selectWithFilterTest\0selectWithoutFilterTest\0"
    "selectEmptyTest\0selectFromUnknownTableTest\0"
    "selectWithInvalidFilterTest\0"
    "selectFirstWithFilterTest\0"
    "selectFirstWithoutFilterTest\0"
    "selectFirstEmptyTest\0"
    "selectFirstFromUnknownTableTest\0"
    "selectFirstWithInvalidFilterTest\0"
    "selectCountWithFilterTest\0"
    "selectCountWithoutFilterTest\0"
    "selectCountEmpty\0selectCountFromUnknownTableTest\0"
    "selectCountWithInvalidFilterTest\0"
    "isSelectEmptyTrueTest\0isSelectEmptyFalseTest\0"
    "isSelectEmptyFromUnknownTableTest\0"
    "isSelectEmptyWithInvalidFilterTest\0"
    "insertWithoutCOLIDTest\0insertWithCOLIDTest\0"
    "insertIntoUnknownTableTest\0"
    "insertInvalidValuesTest\0updateWithCOLIDTest\0"
    "updateWithoutCOLIDTest\0updateWithoutFilterTest\0"
    "updateIntoUnknownTableTest\0"
    "updateInvalidValuesTest\0saveInsertTest\0"
    "saveUpdateTest\0removeWithFilterTest\0"
    "removeWithoutFilterTest\0"
    "removeFromUnknownTableTest\0"
    "removeWithInvalidFilterTest\0cleanupTestCase"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DBHandlerTest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      49,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  259,    2, 0x08 /* Private */,
       3,    0,  260,    2, 0x08 /* Private */,
       4,    0,  261,    2, 0x08 /* Private */,
       5,    0,  262,    2, 0x08 /* Private */,
       6,    0,  263,    2, 0x08 /* Private */,
       7,    0,  264,    2, 0x08 /* Private */,
       8,    0,  265,    2, 0x08 /* Private */,
       9,    0,  266,    2, 0x08 /* Private */,
      10,    0,  267,    2, 0x08 /* Private */,
      11,    0,  268,    2, 0x08 /* Private */,
      12,    0,  269,    2, 0x08 /* Private */,
      13,    0,  270,    2, 0x08 /* Private */,
      14,    0,  271,    2, 0x08 /* Private */,
      15,    0,  272,    2, 0x08 /* Private */,
      16,    0,  273,    2, 0x08 /* Private */,
      17,    0,  274,    2, 0x08 /* Private */,
      18,    0,  275,    2, 0x08 /* Private */,
      19,    0,  276,    2, 0x08 /* Private */,
      20,    0,  277,    2, 0x08 /* Private */,
      21,    0,  278,    2, 0x08 /* Private */,
      22,    0,  279,    2, 0x08 /* Private */,
      23,    0,  280,    2, 0x08 /* Private */,
      24,    0,  281,    2, 0x08 /* Private */,
      25,    0,  282,    2, 0x08 /* Private */,
      26,    0,  283,    2, 0x08 /* Private */,
      27,    0,  284,    2, 0x08 /* Private */,
      28,    0,  285,    2, 0x08 /* Private */,
      29,    0,  286,    2, 0x08 /* Private */,
      30,    0,  287,    2, 0x08 /* Private */,
      31,    0,  288,    2, 0x08 /* Private */,
      32,    0,  289,    2, 0x08 /* Private */,
      33,    0,  290,    2, 0x08 /* Private */,
      34,    0,  291,    2, 0x08 /* Private */,
      35,    0,  292,    2, 0x08 /* Private */,
      36,    0,  293,    2, 0x08 /* Private */,
      37,    0,  294,    2, 0x08 /* Private */,
      38,    0,  295,    2, 0x08 /* Private */,
      39,    0,  296,    2, 0x08 /* Private */,
      40,    0,  297,    2, 0x08 /* Private */,
      41,    0,  298,    2, 0x08 /* Private */,
      42,    0,  299,    2, 0x08 /* Private */,
      43,    0,  300,    2, 0x08 /* Private */,
      44,    0,  301,    2, 0x08 /* Private */,
      45,    0,  302,    2, 0x08 /* Private */,
      46,    0,  303,    2, 0x08 /* Private */,
      47,    0,  304,    2, 0x08 /* Private */,
      48,    0,  305,    2, 0x08 /* Private */,
      49,    0,  306,    2, 0x08 /* Private */,
      50,    0,  307,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DBHandlerTest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DBHandlerTest *_t = static_cast<DBHandlerTest *>(_o);
        switch (_id) {
        case 0: _t->initTestCase(); break;
        case 1: _t->cleanup(); break;
        case 2: _t->hasErrorTrueTest(); break;
        case 3: _t->hasErrorFalseTest(); break;
        case 4: _t->getLastErrorWithResetTest(); break;
        case 5: _t->getLastErrorWithoutResetTest(); break;
        case 6: _t->registerTableTest(); break;
        case 7: _t->registerUnknownTableTest(); break;
        case 8: _t->registerTableTwiceTest(); break;
        case 9: _t->getNextIDWithoutFilterTest(); break;
        case 10: _t->getNextIDWithFilterTest(); break;
        case 11: _t->getNextIDWithInvalidFilterTest(); break;
        case 12: _t->getNextIDFromUnknownTableTest(); break;
        case 13: _t->getNextIDFromInvalidColumnTest(); break;
        case 14: _t->selectWithFilterTest(); break;
        case 15: _t->selectWithoutFilterTest(); break;
        case 16: _t->selectEmptyTest(); break;
        case 17: _t->selectFromUnknownTableTest(); break;
        case 18: _t->selectWithInvalidFilterTest(); break;
        case 19: _t->selectFirstWithFilterTest(); break;
        case 20: _t->selectFirstWithoutFilterTest(); break;
        case 21: _t->selectFirstEmptyTest(); break;
        case 22: _t->selectFirstFromUnknownTableTest(); break;
        case 23: _t->selectFirstWithInvalidFilterTest(); break;
        case 24: _t->selectCountWithFilterTest(); break;
        case 25: _t->selectCountWithoutFilterTest(); break;
        case 26: _t->selectCountEmpty(); break;
        case 27: _t->selectCountFromUnknownTableTest(); break;
        case 28: _t->selectCountWithInvalidFilterTest(); break;
        case 29: _t->isSelectEmptyTrueTest(); break;
        case 30: _t->isSelectEmptyFalseTest(); break;
        case 31: _t->isSelectEmptyFromUnknownTableTest(); break;
        case 32: _t->isSelectEmptyWithInvalidFilterTest(); break;
        case 33: _t->insertWithoutCOLIDTest(); break;
        case 34: _t->insertWithCOLIDTest(); break;
        case 35: _t->insertIntoUnknownTableTest(); break;
        case 36: _t->insertInvalidValuesTest(); break;
        case 37: _t->updateWithCOLIDTest(); break;
        case 38: _t->updateWithoutCOLIDTest(); break;
        case 39: _t->updateWithoutFilterTest(); break;
        case 40: _t->updateIntoUnknownTableTest(); break;
        case 41: _t->updateInvalidValuesTest(); break;
        case 42: _t->saveInsertTest(); break;
        case 43: _t->saveUpdateTest(); break;
        case 44: _t->removeWithFilterTest(); break;
        case 45: _t->removeWithoutFilterTest(); break;
        case 46: _t->removeFromUnknownTableTest(); break;
        case 47: _t->removeWithInvalidFilterTest(); break;
        case 48: _t->cleanupTestCase(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject DBHandlerTest::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DBHandlerTest.data,
      qt_meta_data_DBHandlerTest,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DBHandlerTest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DBHandlerTest::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DBHandlerTest.stringdata))
        return static_cast<void*>(const_cast< DBHandlerTest*>(this));
    return QObject::qt_metacast(_clname);
}

int DBHandlerTest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 49)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 49;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 49)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 49;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
