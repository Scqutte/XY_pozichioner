/****************************************************************************
** Meta object code from reading C++ file 'serialscanner.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../serialscanner.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialscanner.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SerialScanner_t {
    QByteArrayData data[13];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialScanner_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialScanner_t qt_meta_stringdata_SerialScanner = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SerialScanner"
QT_MOC_LITERAL(1, 14, 16), // "portsListChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 5), // "ports"
QT_MOC_LITERAL(4, 38, 22), // "connectionStateChanged"
QT_MOC_LITERAL(5, 61, 9), // "connected"
QT_MOC_LITERAL(6, 71, 8), // "portName"
QT_MOC_LITERAL(7, 80, 12), // "lineReceived"
QT_MOC_LITERAL(8, 93, 4), // "line"
QT_MOC_LITERAL(9, 98, 11), // "commandSent"
QT_MOC_LITERAL(10, 110, 16), // "errorTextChanged"
QT_MOC_LITERAL(11, 127, 9), // "errorText"
QT_MOC_LITERAL(12, 137, 12) // "refreshPorts"

    },
    "SerialScanner\0portsListChanged\0\0ports\0"
    "connectionStateChanged\0connected\0"
    "portName\0lineReceived\0line\0commandSent\0"
    "errorTextChanged\0errorText\0refreshPorts"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialScanner[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    2,   47,    2, 0x06 /* Public */,
       7,    1,   52,    2, 0x06 /* Public */,
       9,    1,   55,    2, 0x06 /* Public */,
      10,    1,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList,    3,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    5,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   11,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void SerialScanner::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SerialScanner *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->portsListChanged((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 1: _t->connectionStateChanged((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->lineReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->commandSent((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->errorTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->refreshPorts(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SerialScanner::*)(const QStringList & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialScanner::portsListChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SerialScanner::*)(bool , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialScanner::connectionStateChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SerialScanner::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialScanner::lineReceived)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SerialScanner::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialScanner::commandSent)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SerialScanner::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialScanner::errorTextChanged)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SerialScanner::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SerialScanner.data,
    qt_meta_data_SerialScanner,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SerialScanner::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialScanner::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SerialScanner.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SerialScanner::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void SerialScanner::portsListChanged(const QStringList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SerialScanner::connectionStateChanged(bool _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SerialScanner::lineReceived(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SerialScanner::commandSent(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SerialScanner::errorTextChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
