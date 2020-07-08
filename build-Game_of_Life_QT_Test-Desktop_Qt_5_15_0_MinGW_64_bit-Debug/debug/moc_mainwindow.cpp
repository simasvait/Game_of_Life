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
    QByteArrayData data[36];
    char stringdata0[594];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "UpdateGridDim"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "newX"
QT_MOC_LITERAL(4, 31, 4), // "newY"
QT_MOC_LITERAL(5, 36, 9), // "UpdateReq"
QT_MOC_LITERAL(6, 46, 5), // "steps"
QT_MOC_LITERAL(7, 52, 9), // "ResetGrid"
QT_MOC_LITERAL(8, 62, 11), // "SeedChanged"
QT_MOC_LITERAL(9, 74, 4), // "seed"
QT_MOC_LITERAL(10, 79, 11), // "ImageLoaded"
QT_MOC_LITERAL(11, 91, 5), // "image"
QT_MOC_LITERAL(12, 97, 13), // "ConstrainGrid"
QT_MOC_LITERAL(13, 111, 5), // "state"
QT_MOC_LITERAL(14, 117, 11), // "SetGUIState"
QT_MOC_LITERAL(15, 129, 24), // "ProcessThread::GUIStates"
QT_MOC_LITERAL(16, 154, 8), // "newstate"
QT_MOC_LITERAL(17, 163, 27), // "on_pushB_updateGrid_clicked"
QT_MOC_LITERAL(18, 191, 26), // "on_pushB_Progress1_clicked"
QT_MOC_LITERAL(19, 218, 26), // "on_pushB_ProgressX_clicked"
QT_MOC_LITERAL(20, 245, 20), // "on_pushB_Run_clicked"
QT_MOC_LITERAL(21, 266, 21), // "on_pushB_Stop_clicked"
QT_MOC_LITERAL(22, 288, 26), // "on_pushB_resetGrid_clicked"
QT_MOC_LITERAL(23, 315, 24), // "on_pushB_loadBMP_clicked"
QT_MOC_LITERAL(24, 340, 24), // "on_pushB_RndSeed_clicked"
QT_MOC_LITERAL(25, 365, 27), // "on_slider_Zoom_valueChanged"
QT_MOC_LITERAL(26, 393, 8), // "position"
QT_MOC_LITERAL(27, 402, 28), // "on_slider_Speed_valueChanged"
QT_MOC_LITERAL(28, 431, 32), // "on_edit_stepSize_editingFinished"
QT_MOC_LITERAL(29, 464, 28), // "on_edit_seed_editingFinished"
QT_MOC_LITERAL(30, 493, 28), // "on_Screen_CellCount_overflow"
QT_MOC_LITERAL(31, 522, 31), // "on_check_Constrain_stateChanged"
QT_MOC_LITERAL(32, 554, 16), // "updateTimerLabel"
QT_MOC_LITERAL(33, 571, 18), // "update_Grid_labels"
QT_MOC_LITERAL(34, 590, 1), // "x"
QT_MOC_LITERAL(35, 592, 1) // "y"

    },
    "MainWindow\0UpdateGridDim\0\0newX\0newY\0"
    "UpdateReq\0steps\0ResetGrid\0SeedChanged\0"
    "seed\0ImageLoaded\0image\0ConstrainGrid\0"
    "state\0SetGUIState\0ProcessThread::GUIStates\0"
    "newstate\0on_pushB_updateGrid_clicked\0"
    "on_pushB_Progress1_clicked\0"
    "on_pushB_ProgressX_clicked\0"
    "on_pushB_Run_clicked\0on_pushB_Stop_clicked\0"
    "on_pushB_resetGrid_clicked\0"
    "on_pushB_loadBMP_clicked\0"
    "on_pushB_RndSeed_clicked\0"
    "on_slider_Zoom_valueChanged\0position\0"
    "on_slider_Speed_valueChanged\0"
    "on_edit_stepSize_editingFinished\0"
    "on_edit_seed_editingFinished\0"
    "on_Screen_CellCount_overflow\0"
    "on_check_Constrain_stateChanged\0"
    "updateTimerLabel\0update_Grid_labels\0"
    "x\0y"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  129,    2, 0x06 /* Public */,
       5,    1,  134,    2, 0x06 /* Public */,
       7,    0,  137,    2, 0x06 /* Public */,
       8,    1,  138,    2, 0x06 /* Public */,
      10,    1,  141,    2, 0x06 /* Public */,
      12,    1,  144,    2, 0x06 /* Public */,
      14,    1,  147,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    0,  150,    2, 0x08 /* Private */,
      18,    0,  151,    2, 0x08 /* Private */,
      19,    0,  152,    2, 0x08 /* Private */,
      20,    0,  153,    2, 0x08 /* Private */,
      21,    0,  154,    2, 0x08 /* Private */,
      22,    0,  155,    2, 0x08 /* Private */,
      23,    0,  156,    2, 0x08 /* Private */,
      24,    0,  157,    2, 0x08 /* Private */,
      25,    1,  158,    2, 0x08 /* Private */,
      27,    1,  161,    2, 0x08 /* Private */,
      28,    0,  164,    2, 0x08 /* Private */,
      29,    0,  165,    2, 0x08 /* Private */,
      30,    0,  166,    2, 0x08 /* Private */,
      31,    1,  167,    2, 0x08 /* Private */,
      32,    1,  170,    2, 0x08 /* Private */,
      33,    2,  173,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::UInt,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,    9,
    QMetaType::Void, QMetaType::QImage,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, 0x80000000 | 15,   16,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   34,   35,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->UpdateGridDim((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->UpdateReq((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 2: _t->ResetGrid(); break;
        case 3: _t->SeedChanged((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 4: _t->ImageLoaded((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 5: _t->ConstrainGrid((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->SetGUIState((*reinterpret_cast< ProcessThread::GUIStates(*)>(_a[1]))); break;
        case 7: _t->on_pushB_updateGrid_clicked(); break;
        case 8: _t->on_pushB_Progress1_clicked(); break;
        case 9: _t->on_pushB_ProgressX_clicked(); break;
        case 10: _t->on_pushB_Run_clicked(); break;
        case 11: _t->on_pushB_Stop_clicked(); break;
        case 12: _t->on_pushB_resetGrid_clicked(); break;
        case 13: _t->on_pushB_loadBMP_clicked(); break;
        case 14: _t->on_pushB_RndSeed_clicked(); break;
        case 15: _t->on_slider_Zoom_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->on_slider_Speed_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->on_edit_stepSize_editingFinished(); break;
        case 18: _t->on_edit_seed_editingFinished(); break;
        case 19: _t->on_Screen_CellCount_overflow(); break;
        case 20: _t->on_check_Constrain_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->updateTimerLabel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->update_Grid_labels((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::UpdateGridDim)) {
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
        {
            using _t = void (MainWindow::*)(ProcessThread::GUIStates );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::SetGUIState)) {
                *result = 6;
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
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 23;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::UpdateGridDim(int _t1, int _t2)
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

// SIGNAL 6
void MainWindow::SetGUIState(ProcessThread::GUIStates _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
