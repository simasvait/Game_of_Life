#include <QApplication>
#include <QTableView>
//#include <QSizePolicy>
//#include <QObject>
//#include <QHash>
#include <QLCDNumber>
#include "mainwindow.h"
#include "grid.h"
#include <iostream>                                             // temp

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QSizePolicy sizePolicy(QSizePolicy::Preferred,
                           QSizePolicy::Preferred);

    sizePolicy.setHeightForWidth(true);                         // Set tableview to keep aspect ratio
    w.setSizePolicy(sizePolicy);
    w.show();                                                   // Show main widget


    QTableView *newTable = w.findChild<QTableView *>("myTableView");
    QLCDNumber *lcd      = w.findChild<QLCDNumber *>("Screen_CellCount");
    MyGrid myGame;

    newTable->setModel(&myGame);
    newTable->setStyleSheet("gridline-color: black;");

    QObject::connect(&w,        &MainWindow::GridEdited,        &myGame,    &MyGrid::setGridSize);
    QObject::connect(&myGame,   &MyGrid::GridChanged,           &w,         &MainWindow::update_Grid_labels);
    QObject::connect(&w,        &MainWindow::UpdateReq,         &myGame,    &MyGrid::progressGeneration);
    QObject::connect(newTable,  &QAbstractItemView::clicked,    &myGame,    &MyGrid::toggleCell);
    QObject::connect(&myGame,   SIGNAL(UpdateCellCount(int)),   lcd,        SLOT(display(int)));
    QObject::connect(&w,        &MainWindow::ResetGrid,         &myGame,    &MyGrid::clearCells);
    QObject::connect(&w,        &MainWindow::SeedChanged,       &myGame,    &MyGrid::initialiseSeed);
    QObject::connect(&w,        &MainWindow::ImageLoaded,       &myGame,    &MyGrid::initialisePattern);
    QObject::connect(&w,        &MainWindow::ConstrainGrid,     &myGame,    &MyGrid::UpdateConstraints);

    // Temporary intialisation
    QList<QPair<int, int>> startingCellPositions;  

    int offset_X = 10;
    int offset_Y = 3;

    startingCellPositions.append(qMakePair(offset_Y + 0, offset_X + 4));
    startingCellPositions.append(qMakePair(offset_Y + 1, offset_X + 2));
    startingCellPositions.append(qMakePair(offset_Y + 1, offset_X + 4));
    startingCellPositions.append(qMakePair(offset_Y + 1, offset_X + 6));
    startingCellPositions.append(qMakePair(offset_Y + 2, offset_X + 1));
    startingCellPositions.append(qMakePair(offset_Y + 2, offset_X + 4));
    startingCellPositions.append(qMakePair(offset_Y + 2, offset_X + 7));
    startingCellPositions.append(qMakePair(offset_Y + 4, offset_X + 0));
    startingCellPositions.append(qMakePair(offset_Y + 4, offset_X + 1));
    startingCellPositions.append(qMakePair(offset_Y + 4, offset_X + 2));
    startingCellPositions.append(qMakePair(offset_Y + 4, offset_X + 6));
    startingCellPositions.append(qMakePair(offset_Y + 4, offset_X + 7));
    startingCellPositions.append(qMakePair(offset_Y + 4, offset_X + 8));
    startingCellPositions.append(qMakePair(offset_Y + 6, offset_X + 1));
    startingCellPositions.append(qMakePair(offset_Y + 6, offset_X + 4));
    startingCellPositions.append(qMakePair(offset_Y + 6, offset_X + 7));
    startingCellPositions.append(qMakePair(offset_Y + 7, offset_X + 2));
    startingCellPositions.append(qMakePair(offset_Y + 7, offset_X + 4));
    startingCellPositions.append(qMakePair(offset_Y + 7, offset_X + 6));
    startingCellPositions.append(qMakePair(offset_Y + 8, offset_X + 4));



    // newTable->setUpdatesEnabled(false);

    myGame.initialiseGame(startingCellPositions);


     return a.exec();
}
