/****************************************************************************
** Meta object code from reading C++ file 'processThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Game_of_Life_QT/processThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'processThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProcessThread_t {
    QByteArrayData data[41];
    char stringdata0[415];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProcessThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProcessThread_t qt_meta_stringdata_ProcessThread = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ProcessThread"
QT_MOC_LITERAL(1, 14, 11), // "GridChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 4), // "newX"
QT_MOC_LITERAL(4, 32, 4), // "newY"
QT_MOC_LITERAL(5, 37, 15), // "UpdateCellCount"
QT_MOC_LITERAL(6, 53, 6), // "number"
QT_MOC_LITERAL(7, 60, 9), // "UpdateGUI"
QT_MOC_LITERAL(8, 70, 14), // "QList<PairInt>"
QT_MOC_LITERAL(9, 85, 7), // "xy_list"
QT_MOC_LITERAL(10, 93, 7), // "CellOps"
QT_MOC_LITERAL(11, 101, 6), // "action"
QT_MOC_LITERAL(12, 108, 8), // "finished"
QT_MOC_LITERAL(13, 117, 14), // "initialiseGame"
QT_MOC_LITERAL(14, 132, 7), // "entries"
QT_MOC_LITERAL(15, 140, 17), // "initialisePattern"
QT_MOC_LITERAL(16, 158, 5), // "image"
QT_MOC_LITERAL(17, 164, 14), // "initialiseSeed"
QT_MOC_LITERAL(18, 179, 8), // "rng_seed"
QT_MOC_LITERAL(19, 188, 18), // "progressGeneration"
QT_MOC_LITERAL(20, 207, 5), // "steps"
QT_MOC_LITERAL(21, 213, 10), // "toggleCell"
QT_MOC_LITERAL(22, 224, 11), // "QModelIndex"
QT_MOC_LITERAL(23, 236, 5), // "index"
QT_MOC_LITERAL(24, 242, 10), // "clearCells"
QT_MOC_LITERAL(25, 253, 17), // "UpdateConstraints"
QT_MOC_LITERAL(26, 271, 5), // "state"
QT_MOC_LITERAL(27, 277, 14), // "UpdateTableDim"
QT_MOC_LITERAL(28, 292, 1), // "x"
QT_MOC_LITERAL(29, 294, 1), // "y"
QT_MOC_LITERAL(30, 296, 18), // "TransmitLiveCoords"
QT_MOC_LITERAL(31, 315, 11), // "ChangeState"
QT_MOC_LITERAL(32, 327, 9), // "GUIStates"
QT_MOC_LITERAL(33, 337, 8), // "newState"
QT_MOC_LITERAL(34, 346, 15), // "TerminateObject"
QT_MOC_LITERAL(35, 362, 4), // "Kill"
QT_MOC_LITERAL(36, 367, 9), // "Resurrect"
QT_MOC_LITERAL(37, 377, 7), // "KillAll"
QT_MOC_LITERAL(38, 385, 7), // "Running"
QT_MOC_LITERAL(39, 393, 7), // "Stopped"
QT_MOC_LITERAL(40, 401, 13) // "InitiateReset"

    },
    "ProcessThread\0GridChanged\0\0newX\0newY\0"
    "UpdateCellCount\0number\0UpdateGUI\0"
    "QList<PairInt>\0xy_list\0CellOps\0action\0"
    "finished\0initialiseGame\0entries\0"
    "initialisePattern\0image\0initialiseSeed\0"
    "rng_seed\0progressGeneration\0steps\0"
    "toggleCell\0QModelIndex\0index\0clearCells\0"
    "UpdateConstraints\0state\0UpdateTableDim\0"
    "x\0y\0TransmitLiveCoords\0ChangeState\0"
    "GUIStates\0newState\0TerminateObject\0"
    "Kill\0Resurrect\0KillAll\0Running\0Stopped\0"
    "InitiateReset"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProcessThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       2,  132, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   89,    2, 0x06 /* Public */,
       5,    1,   94,    2, 0x06 /* Public */,
       7,    2,   97,    2, 0x06 /* Public */,
      12,    0,  102,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,  103,    2, 0x0a /* Public */,
      15,    1,  106,    2, 0x0a /* Public */,
      17,    1,  109,    2, 0x0a /* Public */,
      19,    1,  112,    2, 0x0a /* Public */,
      21,    1,  115,    2, 0x0a /* Public */,
      24,    0,  118,    2, 0x0a /* Public */,
      25,    1,  119,    2, 0x0a /* Public */,
      27,    2,  122,    2, 0x0a /* Public */,
      30,    0,  127,    2, 0x0a /* Public */,
      31,    1,  128,    2, 0x0a /* Public */,
      34,    0,  131,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 10,    9,   11,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,   14,
    QMetaType::Void, QMetaType::QImage,   16,
    QMetaType::Void, QMetaType::UInt,   18,
    QMetaType::Void, QMetaType::UInt,   20,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   28,   29,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 32,   33,
    QMetaType::Void,

 // enums: name, alias, flags, count, data
      10,   10, 0x0,    3,  142,
      32,   32, 0x0,    3,  148,

 // enum data: key, value
      35, uint(ProcessThread::Kill),
      36, uint(ProcessThread::Resurrect),
      37, uint(ProcessThread::KillAll),
      38, uint(ProcessThread::Running),
      39, uint(ProcessThread::Stopped),
      40, uint(ProcessThread::InitiateReset),

       0        // eod
};

void ProcessThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProcessThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->GridChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->UpdateCellCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->UpdateGUI((*reinterpret_cast< const QList<PairInt>(*)>(_a[1])),(*reinterpret_cast< CellOps(*)>(_a[2]))); break;
        case 3: _t->finished(); break;
        case 4: _t->initialiseGame((*reinterpret_cast< const QList<PairInt>(*)>(_a[1]))); break;
        case 5: _t->initialisePattern((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 6: _t->initialiseSeed((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 7: _t->progressGeneration((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 8: _t->toggleCell((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 9: _t->clearCells(); break;
        case 10: _t->UpdateConstraints((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->UpdateTableDim((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 12: _t->TransmitLiveCoords(); break;
        case 13: _t->ChangeState((*reinterpret_cast< GUIStates(*)>(_a[1]))); break;
        case 14: _t->TerminateObject(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ProcessThread::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProcessThread::GridChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ProcessThread::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProcessThread::UpdateCellCount)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ProcessThread::*)(const QList<PairInt> , CellOps ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProcessThread::UpdateGUI)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ProcessThread::*)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProcessThread::finished)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ProcessThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ProcessThread.data,
    qt_meta_data_ProcessThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ProcessThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProcessThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProcessThread.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ProcessThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void ProcessThread::GridChanged(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ProcessThread::UpdateCellCount(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ProcessThread::UpdateGUI(const QList<PairInt> _t1, CellOps _t2)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(const_cast< ProcessThread *>(this), &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ProcessThread::finished()const
{
    QMetaObject::activate(const_cast< ProcessThread *>(this), &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
