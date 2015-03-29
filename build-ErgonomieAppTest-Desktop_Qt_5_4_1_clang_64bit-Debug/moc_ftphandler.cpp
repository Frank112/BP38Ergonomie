/****************************************************************************
** Meta object code from reading C++ file 'ftphandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ftpHandler/ftphandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ftphandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FtpHandler_t {
    QByteArrayData data[12];
    char stringdata[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FtpHandler_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FtpHandler_t qt_meta_stringdata_FtpHandler = {
    {
QT_MOC_LITERAL(0, 0, 10), // "FtpHandler"
QT_MOC_LITERAL(1, 11, 8), // "progress"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 7), // "started"
QT_MOC_LITERAL(4, 29, 8), // "finished"
QT_MOC_LITERAL(5, 38, 8), // "filename"
QT_MOC_LITERAL(6, 47, 5), // "error"
QT_MOC_LITERAL(7, 53, 15), // "managerFinished"
QT_MOC_LITERAL(8, 69, 14), // "QNetworkReply*"
QT_MOC_LITERAL(9, 84, 5), // "reply"
QT_MOC_LITERAL(10, 90, 9), // "bytesSend"
QT_MOC_LITERAL(11, 100, 10) // "totalBytes"

    },
    "FtpHandler\0progress\0\0started\0finished\0"
    "filename\0error\0managerFinished\0"
    "QNetworkReply*\0reply\0bytesSend\0"
    "totalBytes"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FtpHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       3,    0,   47,    2, 0x06 /* Public */,
       4,    1,   48,    2, 0x06 /* Public */,
       6,    1,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   54,    2, 0x08 /* Private */,
       1,    2,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    1,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,   10,   11,

       0        // eod
};

void FtpHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FtpHandler *_t = static_cast<FtpHandler *>(_o);
        switch (_id) {
        case 0: _t->progress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->started(); break;
        case 2: _t->finished((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->managerFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 5: _t->progress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FtpHandler::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FtpHandler::progress)) {
                *result = 0;
            }
        }
        {
            typedef void (FtpHandler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FtpHandler::started)) {
                *result = 1;
            }
        }
        {
            typedef void (FtpHandler::*_t)(const QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FtpHandler::finished)) {
                *result = 2;
            }
        }
        {
            typedef void (FtpHandler::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FtpHandler::error)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject FtpHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FtpHandler.data,
      qt_meta_data_FtpHandler,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FtpHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FtpHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FtpHandler.stringdata))
        return static_cast<void*>(const_cast< FtpHandler*>(this));
    return QObject::qt_metacast(_clname);
}

int FtpHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void FtpHandler::progress(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FtpHandler::started()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void FtpHandler::finished(const QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FtpHandler::error(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
