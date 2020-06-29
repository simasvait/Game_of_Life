/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label_Seed;
    QLabel *label_CellCount;
    QLabel *label_Speed;
    QLineEdit *edit_gridSize_X;
    QLineEdit *edit_seed;
    QLabel *label_StaticY;
    QLineEdit *edit_gridSize_Y;
    QLabel *label_GridSize;
    QCheckBox *check_Constrain;
    QLabel *label_Zoom;
    QSlider *slider_Zoom;
    QPushButton *pushB_loadBMP;
    QLabel *label_StaticX;
    QPushButton *pushB_updateGrid;
    QPushButton *pushB_Stop;
    QPushButton *pushB_Run;
    QPushButton *pushB_RndSeed;
    QPushButton *pushB_ProgressX;
    QPushButton *pushB_resetGrid;
    QPushButton *pushB_Progress1;
    QTableView *myTableView;
    QLabel *label_TimeElapsed;
    QLineEdit *edit_stepSize;
    QLCDNumber *Screen_CellCount;
    QSlider *slider_Speed;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(719, 499);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_Seed = new QLabel(centralwidget);
        label_Seed->setObjectName(QString::fromUtf8("label_Seed"));

        gridLayout->addWidget(label_Seed, 3, 5, 1, 1);

        label_CellCount = new QLabel(centralwidget);
        label_CellCount->setObjectName(QString::fromUtf8("label_CellCount"));
        label_CellCount->setLayoutDirection(Qt::LeftToRight);
        label_CellCount->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_CellCount, 6, 4, 1, 1);

        label_Speed = new QLabel(centralwidget);
        label_Speed->setObjectName(QString::fromUtf8("label_Speed"));

        gridLayout->addWidget(label_Speed, 2, 8, 1, 1);

        edit_gridSize_X = new QLineEdit(centralwidget);
        edit_gridSize_X->setObjectName(QString::fromUtf8("edit_gridSize_X"));

        gridLayout->addWidget(edit_gridSize_X, 4, 1, 1, 2);

        edit_seed = new QLineEdit(centralwidget);
        edit_seed->setObjectName(QString::fromUtf8("edit_seed"));

        gridLayout->addWidget(edit_seed, 3, 6, 1, 1);

        label_StaticY = new QLabel(centralwidget);
        label_StaticY->setObjectName(QString::fromUtf8("label_StaticY"));

        gridLayout->addWidget(label_StaticY, 5, 0, 1, 1);

        edit_gridSize_Y = new QLineEdit(centralwidget);
        edit_gridSize_Y->setObjectName(QString::fromUtf8("edit_gridSize_Y"));

        gridLayout->addWidget(edit_gridSize_Y, 5, 1, 1, 2);

        label_GridSize = new QLabel(centralwidget);
        label_GridSize->setObjectName(QString::fromUtf8("label_GridSize"));

        gridLayout->addWidget(label_GridSize, 3, 0, 1, 2);

        check_Constrain = new QCheckBox(centralwidget);
        check_Constrain->setObjectName(QString::fromUtf8("check_Constrain"));
        check_Constrain->setTristate(false);

        gridLayout->addWidget(check_Constrain, 6, 0, 1, 3);

        label_Zoom = new QLabel(centralwidget);
        label_Zoom->setObjectName(QString::fromUtf8("label_Zoom"));

        gridLayout->addWidget(label_Zoom, 0, 8, 1, 1);

        slider_Zoom = new QSlider(centralwidget);
        slider_Zoom->setObjectName(QString::fromUtf8("slider_Zoom"));
        slider_Zoom->setMinimum(3);
        slider_Zoom->setValue(20);
        slider_Zoom->setOrientation(Qt::Vertical);
        slider_Zoom->setInvertedAppearance(false);

        gridLayout->addWidget(slider_Zoom, 1, 8, 1, 1, Qt::AlignHCenter);

        pushB_loadBMP = new QPushButton(centralwidget);
        pushB_loadBMP->setObjectName(QString::fromUtf8("pushB_loadBMP"));

        gridLayout->addWidget(pushB_loadBMP, 3, 4, 1, 1);

        label_StaticX = new QLabel(centralwidget);
        label_StaticX->setObjectName(QString::fromUtf8("label_StaticX"));

        gridLayout->addWidget(label_StaticX, 4, 0, 1, 1);

        pushB_updateGrid = new QPushButton(centralwidget);
        pushB_updateGrid->setObjectName(QString::fromUtf8("pushB_updateGrid"));

        gridLayout->addWidget(pushB_updateGrid, 3, 2, 1, 1);

        pushB_Stop = new QPushButton(centralwidget);
        pushB_Stop->setObjectName(QString::fromUtf8("pushB_Stop"));

        gridLayout->addWidget(pushB_Stop, 4, 4, 1, 1);

        pushB_Run = new QPushButton(centralwidget);
        pushB_Run->setObjectName(QString::fromUtf8("pushB_Run"));

        gridLayout->addWidget(pushB_Run, 4, 3, 1, 1);

        pushB_RndSeed = new QPushButton(centralwidget);
        pushB_RndSeed->setObjectName(QString::fromUtf8("pushB_RndSeed"));

        gridLayout->addWidget(pushB_RndSeed, 3, 3, 1, 1);

        pushB_ProgressX = new QPushButton(centralwidget);
        pushB_ProgressX->setObjectName(QString::fromUtf8("pushB_ProgressX"));

        gridLayout->addWidget(pushB_ProgressX, 5, 4, 1, 1);

        pushB_resetGrid = new QPushButton(centralwidget);
        pushB_resetGrid->setObjectName(QString::fromUtf8("pushB_resetGrid"));

        gridLayout->addWidget(pushB_resetGrid, 6, 3, 1, 1);

        pushB_Progress1 = new QPushButton(centralwidget);
        pushB_Progress1->setObjectName(QString::fromUtf8("pushB_Progress1"));

        gridLayout->addWidget(pushB_Progress1, 5, 3, 1, 1);

        myTableView = new QTableView(centralwidget);
        myTableView->setObjectName(QString::fromUtf8("myTableView"));
        myTableView->setAutoFillBackground(false);
        myTableView->setFrameShape(QFrame::StyledPanel);
        myTableView->setFrameShadow(QFrame::Sunken);
        myTableView->setEditTriggers(QAbstractItemView::SelectedClicked);
        myTableView->setTabKeyNavigation(false);
        myTableView->setSelectionMode(QAbstractItemView::NoSelection);
        myTableView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        myTableView->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        myTableView->setShowGrid(true);
        myTableView->setCornerButtonEnabled(false);
        myTableView->horizontalHeader()->setVisible(false);
        myTableView->horizontalHeader()->setCascadingSectionResizes(false);
        myTableView->horizontalHeader()->setMinimumSectionSize(1);
        myTableView->horizontalHeader()->setDefaultSectionSize(20);
        myTableView->horizontalHeader()->setHighlightSections(false);
        myTableView->verticalHeader()->setVisible(false);
        myTableView->verticalHeader()->setCascadingSectionResizes(false);
        myTableView->verticalHeader()->setMinimumSectionSize(1);
        myTableView->verticalHeader()->setDefaultSectionSize(20);
        myTableView->verticalHeader()->setHighlightSections(false);

        gridLayout->addWidget(myTableView, 0, 0, 3, 8);

        label_TimeElapsed = new QLabel(centralwidget);
        label_TimeElapsed->setObjectName(QString::fromUtf8("label_TimeElapsed"));

        gridLayout->addWidget(label_TimeElapsed, 4, 5, 1, 3);

        edit_stepSize = new QLineEdit(centralwidget);
        edit_stepSize->setObjectName(QString::fromUtf8("edit_stepSize"));

        gridLayout->addWidget(edit_stepSize, 5, 5, 1, 3);

        Screen_CellCount = new QLCDNumber(centralwidget);
        Screen_CellCount->setObjectName(QString::fromUtf8("Screen_CellCount"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(85, 170, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(213, 234, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(149, 202, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(42, 85, 127, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(56, 113, 170, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(170, 212, 255, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush9(QColor(0, 0, 0, 128));
        brush9.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        Screen_CellCount->setPalette(palette);
        Screen_CellCount->setAutoFillBackground(false);
        Screen_CellCount->setFrameShape(QFrame::StyledPanel);
        Screen_CellCount->setFrameShadow(QFrame::Raised);
        Screen_CellCount->setDigitCount(11);
        Screen_CellCount->setMode(QLCDNumber::Dec);
        Screen_CellCount->setSegmentStyle(QLCDNumber::Flat);
        Screen_CellCount->setProperty("intValue", QVariant(0));

        gridLayout->addWidget(Screen_CellCount, 6, 5, 1, 3);

        slider_Speed = new QSlider(centralwidget);
        slider_Speed->setObjectName(QString::fromUtf8("slider_Speed"));
        slider_Speed->setMinimum(80);
        slider_Speed->setMaximum(500);
        slider_Speed->setSingleStep(1);
        slider_Speed->setValue(150);
        slider_Speed->setOrientation(Qt::Vertical);
        slider_Speed->setInvertedAppearance(true);

        gridLayout->addWidget(slider_Speed, 3, 8, 4, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 719, 26));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        menubar->setFont(font);
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_Seed->setText(QCoreApplication::translate("MainWindow", "Seed:", nullptr));
        label_CellCount->setText(QCoreApplication::translate("MainWindow", "Alive cells:", nullptr));
        label_Speed->setText(QCoreApplication::translate("MainWindow", "Speed", nullptr));
        edit_gridSize_X->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        edit_seed->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        label_StaticY->setText(QCoreApplication::translate("MainWindow", "Y:", nullptr));
        edit_gridSize_Y->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        label_GridSize->setText(QCoreApplication::translate("MainWindow", "Grid Size", nullptr));
        check_Constrain->setText(QCoreApplication::translate("MainWindow", "Constrain to Grid", nullptr));
        label_Zoom->setText(QCoreApplication::translate("MainWindow", "Zoom", nullptr));
        pushB_loadBMP->setText(QCoreApplication::translate("MainWindow", "Load bitmap", nullptr));
        label_StaticX->setText(QCoreApplication::translate("MainWindow", "X:", nullptr));
        pushB_updateGrid->setText(QCoreApplication::translate("MainWindow", "Update Grid", nullptr));
        pushB_Stop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        pushB_Run->setText(QCoreApplication::translate("MainWindow", "Run", nullptr));
        pushB_RndSeed->setText(QCoreApplication::translate("MainWindow", "Random seed", nullptr));
        pushB_ProgressX->setText(QCoreApplication::translate("MainWindow", "Progress by x ticks", nullptr));
        pushB_resetGrid->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        pushB_Progress1->setText(QCoreApplication::translate("MainWindow", "Progress by 1 tick", nullptr));
        label_TimeElapsed->setText(QCoreApplication::translate("MainWindow", "Time elapsed (ticks): 0", nullptr));
        edit_stepSize->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
