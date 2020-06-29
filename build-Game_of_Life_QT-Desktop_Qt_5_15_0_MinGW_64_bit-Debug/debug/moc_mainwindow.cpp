/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Game_of_Life_QT/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[33];
    char stringdata0[539];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 10), // "GridEdited"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 4), // "newX"
QT_MOC_LITERAL(4, 28, 4), // "newY"
QT_MOC_LITERAL(5, 33, 9), // "UpdateReq"
QT_MOC_LITERAL(6, 43, 5), // "steps"
QT_MOC_LITERAL(7, 49, 9), // "ResetGrid"
QT_MOC_LITERAL(8, 59, 11), // "SeedChanged"
QT_MOC_LITERAL(9, 71, 4), // "seed"
QT_MOC_LITERAL(10, 76, 11), // "ImageLoaded"
QT_MOC_LITERAL(11, 88, 5), // "image"
QT_MOC_LITERAL(12, 94, 13), // "ConstrainGrid"
QT_MOC_LITERAL(13, 108, 5), // "state"
QT_MOC_LITERAL(14, 114, 27), // "on_pushB_updateGrid_clicked"
QT_MOC_LITERAL(15, 142, 26), // "on_pushB_Progress1_clicked"
QT_MOC_LITERAL(16, 169, 26), // "on_pushB_ProgressX_clicked"
QT_MOC_LITERAL(17, 196, 20), // "on_pushB_Run_clicked"
QT_MOC_LITERAL(18, 217, 21), // "on_pushB_Stop_clicked"
QT_MOC_LITERAL(19, 239, 26), // "on_pushB_resetGrid_clicked"
QT_MOC_LITERAL(20, 266, 24), // "on_pushB_loadBMP_clicked"
QT_MOC_LITERAL(21, 291, 26), // "on_slider_Zoom_sliderMoved"
QT_MOC_LITERAL(22, 318, 8), // "position"
QT_MOC_LITERAL(23, 327, 27), // "on_slider_Speed_sliderMoved"
QT_MOC_LITERAL(24, 355, 28), // "on_edit_stepSize_textChanged"
QT_MOC_LITERAL(25, 384, 28), // "on_Screen_CellCount_overflow"
QT_MOC_LITERAL(26, 413, 16), // "updateTimerLabel"
QT_MOC_LITERAL(27, 430, 31), // "on_check_Constrain_stateChanged"
QT_MOC_LITERAL(28, 462, 28), // "on_edit_seed_editingFinished"
QT_MOC_LITERAL(29, 491, 24), // "on_pushB_RndSeed_clicked"
QT_MOC_LITERAL(30, 516, 18), // "update_Grid_labels"
QT_MOC_LITERAL(31, 535, 1), // "x"
QT_MOC_LITERAL(32, 537, 1) // "y"

    },
    "MainWindow\0GridEdited\0\0newX\0newY\0"
    "UpdateReq\0steps\0ResetGrid\0SeedChanged\0"
    "seed\0ImageLoaded\0image\0ConstrainGrid\0"
    "state\0on_pushB_updateGrid_clicked\0"
    "on_pushB_Progress1_clicked\0"
    "on_pushB_ProgressX_clicked\0"
    "on_pushB_Run_clicked\0on_pushB_Stop_clicked\0"
    "on_pushB_resetGrid_clicked\0"
    "on_pushB_loadBMP_clicked\0"
    "on_slider_Zoom_sliderMoved\0position\0"
    "on_slider_Speed_sliderMoved\0"
    "on_edit_stepSize_textChanged\0"
    "on_Screen_CellCount_overflow\0"
    "updateTimerLabel\0on_check_Constrain_stateChanged\0"
    "on_edit_seed_editingFinished\0"
    "on_pushB_RndSeed_clicked\0update_Grid_labels\0"
    "x\0y"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  124,    2, 0x06 /* Public */,
       5,    1,  129,    2, 0x06 /* Public */,
       7,    0,  132,    2, 0x06 /* Public */,
       8,    1,  133,    2, 0x06 /* Public */,
      10,    1,  136,    2, 0x06 /* Public */,
      12,    1,  139,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,  142,    2, 0x08 /* Private */,
      15,    0,  143,    2, 0x08 /* Private */,
      16,    0,  144,    2, 0x08 /* Private */,
      17,    0,  145,    2, 0x08 /* Private */,
      18,    0,  146,    2, 0x08 /* Private */,
      19,    0,  147,    2, 0x08 /* Private */,
      20,    0,  148,    2, 0x08 /* Private */,
      21,    1,  149,    2, 0x08 /* Private */,
      23,    1,  152,    2, 0x08 /* Private */,
      24,    0,  155,    2, 0x08 /* Private */,
      25,    0,  156,    2, 0x08 /* Private */,
      26,    1,  157,    2, 0x08 /* Private */,
      27,    1,  160,    2, 0x08 /* Private */,
      28,    0,  163,    2, 0x08 /* Private */,
      29,    0,  164,    2, 0x08 /* Private */,
      30,    2,  165,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::UInt,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,    9,
    QMetaType::Void, QMetaType::QImage,   11,
    QMetaType::Void, QMetaType::Int,   13,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   31,   32,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->GridEdited((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->UpdateReq((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 2: _t->ResetGrid(); break;
        case 3: _t->SeedChanged((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 4: _t->ImageLoaded((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 5: _t->ConstrainGrid((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_pushB_updateGrid_clicked(); break;
        case 7: _t->on_pushB_Progress1_clicked(); break;
        case 8: _t->on_pushB_ProgressX_clicked(); break;
        case 9: _t->on_pushB_Run_clicked(); break;
        case 10: _t->on_pushB_Stop_clicked(); break;
        case 11: _t->on_pushB_resetGrid_clicked(); break;
        case 12: _t->on_pushB_loadBMP_clicked(); break;
        case 13: _t->on_slider_Zoom_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_slider_Speed_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_edit_stepSize_textChanged(); break;
        case 16: _t->on_Screen_CellCount_overflow(); break;
        case 17: _t->updateTimerLabel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->on_check_Constrain_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->on_edit_seed_editingFinished(); break;
        case 20: _t->on_pushB_RndSeed_clicked(); break;
        case 21: _t->update_Grid_labels((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::GridEdited)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(uint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::UpdateReq)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::ResetGrid)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SeedChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QImage );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::ImageLoaded)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::ConstrainGrid)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::GridEdited(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::UpdateReq(uint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::ResetGrid()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::SeedChanged(quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::ImageLoaded(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::ConstrainGrid(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
