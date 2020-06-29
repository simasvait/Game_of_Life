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
    QByteArrayData data[25];
    char stringdata0[252];
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
QT_MOC_LITERAL(5, 30, 15), // "UpdateCellCount"
QT_MOC_LITERAL(6, 46, 6), // "number"
QT_MOC_LITERAL(7, 53, 14), // "initialiseGame"
QT_MOC_LITERAL(8, 68, 22), // "QList<QPair<int,int> >"
QT_MOC_LITERAL(9, 91, 7), // "entries"
QT_MOC_LITERAL(10, 99, 17), // "initialisePattern"
QT_MOC_LITERAL(11, 117, 5), // "image"
QT_MOC_LITERAL(12, 123, 14), // "initialiseSeed"
QT_MOC_LITERAL(13, 138, 8), // "rng_seed"
QT_MOC_LITERAL(14, 147, 18), // "progressGeneration"
QT_MOC_LITERAL(15, 166, 5), // "steps"
QT_MOC_LITERAL(16, 172, 11), // "setGridSize"
QT_MOC_LITERAL(17, 184, 1), // "x"
QT_MOC_LITERAL(18, 186, 1), // "y"
QT_MOC_LITERAL(19, 188, 10), // "toggleCell"
QT_MOC_LITERAL(20, 199, 11), // "QModelIndex"
QT_MOC_LITERAL(21, 211, 5), // "index"
QT_MOC_LITERAL(22, 217, 10), // "clearCells"
QT_MOC_LITERAL(23, 228, 17), // "UpdateConstraints"
QT_MOC_LITERAL(24, 246, 5) // "state"

    },
    "MyGrid\0GridChanged\0\0newX\0newY\0"
    "UpdateCellCount\0number\0initialiseGame\0"
    "QList<QPair<int,int> >\0entries\0"
    "initialisePattern\0image\0initialiseSeed\0"
    "rng_seed\0progressGeneration\0steps\0"
    "setGridSize\0x\0y\0toggleCell\0QModelIndex\0"
    "index\0clearCells\0UpdateConstraints\0"
    "state"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyGrid[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,
       5,    1,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   72,    2, 0x0a /* Public */,
      10,    1,   75,    2, 0x0a /* Public */,
      12,    1,   78,    2, 0x0a /* Public */,
      14,    1,   81,    2, 0x0a /* Public */,
      16,    2,   84,    2, 0x0a /* Public */,
      19,    1,   89,    2, 0x0a /* Public */,
      22,    0,   92,    2, 0x0a /* Public */,
      23,    1,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QImage,   11,
    QMetaType::Void, QMetaType::UInt,   13,
    QMetaType::Void, QMetaType::UInt,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   17,   18,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   24,

       0        // eod
};

void MyGrid::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyGrid *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->GridChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->UpdateCellCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->initialiseGame((*reinterpret_cast< const QList<QPair<int,int> >(*)>(_a[1]))); break;
        case 3: _t->initialisePattern((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 4: _t->initialiseSeed((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 5: _t->progressGeneration((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 6: _t->setGridSize((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->toggleCell((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->clearCells(); break;
        case 9: _t->UpdateConstraints((*reinterpret_cast< int(*)>(_a[1]))); break;
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
            using _t = void (MyGrid::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGrid::UpdateCellCount)) {
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
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
void MyGrid::UpdateCellCount(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
