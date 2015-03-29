/****************************************************************************
** Meta object code from reading C++ file 'xmlparser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../xmlHandler/xmlparser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'xmlparser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_XMLParser_t {
    QByteArrayData data[15];
    char stringdata[234];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XMLParser_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XMLParser_t qt_meta_stringdata_XMLParser = {
    {
QT_MOC_LITERAL(0, 0, 9), // "XMLParser"
QT_MOC_LITERAL(1, 10, 20), // "createTransportation"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 6), // "values"
QT_MOC_LITERAL(4, 39, 15), // "createEquipment"
QT_MOC_LITERAL(5, 55, 13), // "createProduct"
QT_MOC_LITERAL(6, 69, 14), // "createEmployee"
QT_MOC_LITERAL(7, 84, 21), // "bodyMeasurementValues"
QT_MOC_LITERAL(8, 106, 15), // "createWorkplace"
QT_MOC_LITERAL(9, 122, 31), // "QList<QHash<QString,QVariant> >"
QT_MOC_LITERAL(10, 154, 14), // "activityValues"
QT_MOC_LITERAL(11, 169, 21), // "createWorkprocessList"
QT_MOC_LITERAL(12, 191, 13), // "workplaceName"
QT_MOC_LITERAL(13, 205, 12), // "activityName"
QT_MOC_LITERAL(14, 218, 15) // "workprocessList"

    },
    "XMLParser\0createTransportation\0\0values\0"
    "createEquipment\0createProduct\0"
    "createEmployee\0bodyMeasurementValues\0"
    "createWorkplace\0QList<QHash<QString,QVariant> >\0"
    "activityValues\0createWorkprocessList\0"
    "workplaceName\0activityName\0workprocessList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XMLParser[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       5,    1,   50,    2, 0x06 /* Public */,
       6,    2,   53,    2, 0x06 /* Public */,
       8,    2,   58,    2, 0x06 /* Public */,
      11,    3,   63,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariantHash,    3,
    QMetaType::Void, QMetaType::QVariantHash,    3,
    QMetaType::Void, QMetaType::QVariantHash,    3,
    QMetaType::Void, QMetaType::QVariantHash, QMetaType::QVariantHash,    3,    7,
    QMetaType::Void, QMetaType::QVariantHash, 0x80000000 | 9,    3,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 9,   12,   13,   14,

       0        // eod
};

void XMLParser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        XMLParser *_t = static_cast<XMLParser *>(_o);
        switch (_id) {
        case 0: _t->createTransportation((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 1: _t->createEquipment((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 2: _t->createProduct((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1]))); break;
        case 3: _t->createEmployee((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1])),(*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[2]))); break;
        case 4: _t->createWorkplace((*reinterpret_cast< QHash<QString,QVariant>(*)>(_a[1])),(*reinterpret_cast< QList<QHash<QString,QVariant> >(*)>(_a[2]))); break;
        case 5: _t->createWorkprocessList((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QList<QHash<QString,QVariant> >(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QHash<QString,QVariant> > >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QHash<QString,QVariant> > >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (XMLParser::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XMLParser::createTransportation)) {
                *result = 0;
            }
        }
        {
            typedef void (XMLParser::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XMLParser::createEquipment)) {
                *result = 1;
            }
        }
        {
            typedef void (XMLParser::*_t)(QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XMLParser::createProduct)) {
                *result = 2;
            }
        }
        {
            typedef void (XMLParser::*_t)(QHash<QString,QVariant> , QHash<QString,QVariant> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XMLParser::createEmployee)) {
                *result = 3;
            }
        }
        {
            typedef void (XMLParser::*_t)(QHash<QString,QVariant> , QList<QHash<QString,QVariant>> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XMLParser::createWorkplace)) {
                *result = 4;
            }
        }
        {
            typedef void (XMLParser::*_t)(QString , QString , QList<QHash<QString,QVariant>> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XMLParser::createWorkprocessList)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject XMLParser::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_XMLParser.data,
      qt_meta_data_XMLParser,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *XMLParser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XMLParser::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_XMLParser.stringdata))
        return static_cast<void*>(const_cast< XMLParser*>(this));
    if (!strcmp(_clname, "IImportDataParser"))
        return static_cast< IImportDataParser*>(const_cast< XMLParser*>(this));
    if (!strcmp(_clname, "IImportDataParser"))
        return static_cast< IImportDataParser*>(const_cast< XMLParser*>(this));
    return QObject::qt_metacast(_clname);
}

int XMLParser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void XMLParser::createTransportation(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void XMLParser::createEquipment(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void XMLParser::createProduct(QHash<QString,QVariant> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void XMLParser::createEmployee(QHash<QString,QVariant> _t1, QHash<QString,QVariant> _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void XMLParser::createWorkplace(QHash<QString,QVariant> _t1, QList<QHash<QString,QVariant>> _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void XMLParser::createWorkprocessList(QString _t1, QString _t2, QList<QHash<QString,QVariant>> _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
