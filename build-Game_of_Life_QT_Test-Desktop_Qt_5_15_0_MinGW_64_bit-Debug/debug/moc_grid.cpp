/****************************************************************************
** Meta object code from reading C++ file 'grid.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Game_of_Life_QT/grid.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'grid.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyGrid_t {
    QByteArrayData data[14];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyGrid_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyGrid_t qt_meta_stringdata_MyGrid = {
    {
QT_MOC_LITERAL(0, 0, 6), // "MyGrid"
QT_MOC_LITERAL(1, 7, 11), // "GridChanged"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 4), // "newX"
QT_MOC_LITERAL(4, 25, 4), // "newY"
QT_MOC_LITERAL(5, 30, 16), // "ReinitialiseData"
QT_MOC_LITERAL(6, 47, 11), // "setGridSize"
QT_MOC_LITERAL(7, 59, 1), // "x"
QT_MOC_LITERAL(8, 61, 1), // "y"
QT_MOC_LITERAL(9, 63, 15), // "UpdateTableData"
QT_MOC_LITERAL(10, 79, 22), // "QList<QPair<int,int> >"
QT_MOC_LITERAL(11, 102, 7), // "xy_list"
QT_MOC_LITERAL(12, 110, 22), // "ProcessThread::CellOps"
QT_MOC_LITERAL(13, 133, 6) // "action"

    },
    "MyGrid\0GridChanged\0\0newX\0newY\0"
    "ReinitialiseData\0setGridSize\0x\0y\0"
    "UpdateTableData\0QList<QPair<int,int> >\0"
    "xy_list\0ProcessThread::CellOps\0action"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyGrid[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       5,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   40,    2, 0x0a /* Public */,
       9,    2,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 12,   11,   13,

       0        // eod
};

void MyGrid::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyGrid *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->GridChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->ReinitialiseData(); break;
        case 2: _t->setGridSize((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->UpdateTableData((*reinterpret_cast< const QList<QPair<int,int> >(*)>(_a[1])),(*reinterpret_cast< ProcessThread::CellOps(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyGrid::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGrid::GridChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyGrid::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGrid::ReinitialiseData)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyGrid::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractTableModel::staticMetaObject>(),
    qt_meta_stringdata_MyGrid.data,
    qt_meta_data_MyGrid,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyGrid::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyGrid::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyGrid.stringdata0))
        return static_cast<void*>(this);
    return QAbstractTableModel::qt_metacast(_clname);
}

int MyGrid::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void MyGrid::GridChanged(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyGrid::ReinitialiseData()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
