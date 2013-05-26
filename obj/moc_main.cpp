/****************************************************************************
** Meta object code from reading C++ file 'main.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/main.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UnitConvert_t {
    QByteArrayData data[8];
    char stringdata[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_UnitConvert_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_UnitConvert_t qt_meta_stringdata_UnitConvert = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 18),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 20),
QT_MOC_LITERAL(4, 53, 5),
QT_MOC_LITERAL(5, 59, 4),
QT_MOC_LITERAL(6, 64, 18),
QT_MOC_LITERAL(7, 83, 8)
    },
    "UnitConvert\0convertEditChanged\0\0"
    "specialtxtFeetEdited\0about\0quit\0"
    "focusChangeHandler\0QWidget*\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UnitConvert[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a,
       3,    1,   42,    2, 0x0a,
       4,    0,   45,    2, 0x0a,
       5,    0,   46,    2, 0x0a,
       6,    2,   47,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7,    2,    2,

       0        // eod
};

void UnitConvert::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UnitConvert *_t = static_cast<UnitConvert *>(_o);
        switch (_id) {
        case 0: _t->convertEditChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->specialtxtFeetEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->about(); break;
        case 3: _t->quit(); break;
        case 4: _t->focusChangeHandler((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    }
}

const QMetaObject UnitConvert::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_UnitConvert.data,
      qt_meta_data_UnitConvert,  qt_static_metacall, 0, 0}
};


const QMetaObject *UnitConvert::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UnitConvert::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UnitConvert.stringdata))
        return static_cast<void*>(const_cast< UnitConvert*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int UnitConvert::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
