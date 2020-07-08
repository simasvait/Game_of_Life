// ---------------------------------------------------------------------------------------------------------
//
// Filename: main.cpp
//
// Description:
// Main function for starting and initialising the application.
//
// Change Hisory:
//
//  VER          DATE            AUTHOR          DESCRIPTION
//  1.0          18-Jun-2020     Simas V.        Initial single-threaded version.
//  1.0.1-DEV    08-Jul-2020     Simas V.        Updated to add multi-threading capabilities:
//                                                  - Moved calculations from MyGrid to ProcessThread
//                                                  - Added myThread and moved worker object to it
//                                                  - Updated includes to reflect new structure
//
// ---------------------------------------------------------------------------------------------------------
#include <QApplication>
#include <QTableView>
#include <QLCDNumber>
#include <QThread>

#include "../Game_of_Life_QT/mainwindow.h"
#include "../Game_of_Life_QT/grid.h"
#include "../Game_of_Life_QT/processThread.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow myWindow;
    QSizePolicy sizePolicy(QSizePolicy::Preferred,
                           QSizePolicy::Preferred);

    sizePolicy.setHeightForWidth(true);                         // Set tableview to keep aspect ratio
    myWindow.setSizePolicy(sizePolicy);
    myWindow.show();                                                   // Show main widget


    QTableView *newTable = myWindow.findChild<QTableView *>("myTableView");
    QLCDNumber *lcd      = myWindow.findChild<QLCDNumber *>("Screen_CellCount");
    MyGrid myGame(10,10);

    newTable->setModel(&myGame);
    newTable->setStyleSheet("gridline-color: black;");

    QThread myThread;
    ProcessThread worker;

    worker.moveToThread(&myThread);

//    // Test that worker has moved to new thread
//    QThread::currentThread()->setObjectName("mainThread");
//    myThread.setObjectName("myThread");

//    qDebug() << "hello from GUI      thread " << QThread::currentThread()->objectName();
//    qDebug() << "hello from myThread thread " << myThread.thread()->objectName();
//    qDebug() << "hello from Worker   thread " << worker.thread()->objectName();



    // Reset grid size signals
    QObject::connect(&myWindow, &MainWindow::UpdateGridDim,     &myGame,    &MyGrid::setGridSize                ,Qt::DirectConnection); // Reset [X;Y] dims
    QObject::connect(&myGame,   &MyGrid::GridChanged,           &myWindow,  &MainWindow::update_Grid_labels     ,Qt::DirectConnection); // Update GUI labels
    QObject::connect(&myGame,   &MyGrid::GridChanged,           &worker,    &ProcessThread::UpdateTableDim      ,Qt::QueuedConnection); // Sync [X;Y] dims
    QObject::connect(&myGame,   &MyGrid::ReinitialiseData,      &worker,    &ProcessThread::TransmitLiveCoords  ,Qt::QueuedConnection); // Send all liveCells

    // Update tableview grid and display
    QObject::connect(&worker,   &ProcessThread::UpdateGUI,      &myGame,    &MyGrid::UpdateTableData            ,Qt::QueuedConnection); // Sync TableData
    QObject::connect(&worker,   SIGNAL(UpdateCellCount(int)),   lcd,        SLOT(display(int))                  ,Qt::DirectConnection);



    // Handle UI user commands
    QObject::connect(newTable,  &QAbstractItemView::clicked,    &worker,    &ProcessThread::toggleCell          ,Qt::QueuedConnection);
    QObject::connect(&myWindow, &MainWindow::UpdateReq,         &worker,    &ProcessThread::progressGeneration  ,Qt::QueuedConnection);
    QObject::connect(&myWindow, &MainWindow::SeedChanged,       &worker,    &ProcessThread::initialiseSeed      ,Qt::QueuedConnection);
    QObject::connect(&myWindow, &MainWindow::ImageLoaded,       &worker,    &ProcessThread::initialisePattern   ,Qt::QueuedConnection);
    QObject::connect(&myWindow, &MainWindow::ConstrainGrid,     &worker,    &ProcessThread::UpdateConstraints   ,Qt::QueuedConnection);
    QObject::connect(&myWindow, &MainWindow::ResetGrid,         &worker,    &ProcessThread::clearCells          ,Qt::QueuedConnection);

    // Update GUI state
    QObject::connect(&myWindow, &MainWindow::SetGUIState,       &worker,    &ProcessThread::ChangeState         ,Qt::QueuedConnection);


    // Application closeout signals
    QObject::connect(&app,      &QCoreApplication::aboutToQuit, &worker,    &ProcessThread::TerminateObject     ,Qt::DirectConnection);
    QObject::connect(&worker,   &ProcessThread::finished,       &myThread,  &QThread::quit                      ,Qt::DirectConnection);
    QObject::connect(&myThread, &QThread::finished,             &myThread,  &QObject::deleteLater               ,Qt::DirectConnection);





    // Start processing thread
    myThread.start();


    // Temporary intialisation
    QList<QPair<int, int>> startingCellPositions;  

    int offset_Y = 3;
    int offset_X = 10;

    startingCellPositions.append(qMakePair(offset_X + 0, offset_Y + 4));
    startingCellPositions.append(qMakePair(offset_X + 1, offset_Y + 2));
    startingCellPositions.append(qMakePair(offset_X + 1, offset_Y + 4));
    startingCellPositions.append(qMakePair(offset_X + 1, offset_Y + 6));
    startingCellPositions.append(qMakePair(offset_X + 2, offset_Y + 1));
    startingCellPositions.append(qMakePair(offset_X + 2, offset_Y + 4));
    startingCellPositions.append(qMakePair(offset_X + 2, offset_Y + 7));
    startingCellPositions.append(qMakePair(offset_X + 4, offset_Y + 0));
    startingCellPositions.append(qMakePair(offset_X + 4, offset_Y + 1));
    startingCellPositions.append(qMakePair(offset_X + 4, offset_Y + 2));
    startingCellPositions.append(qMakePair(offset_X + 4, offset_Y + 6));
    startingCellPositions.append(qMakePair(offset_X + 4, offset_Y + 7));
    startingCellPositions.append(qMakePair(offset_X + 4, offset_Y + 8));
    startingCellPositions.append(qMakePair(offset_X + 6, offset_Y + 1));
    startingCellPositions.append(qMakePair(offset_X + 6, offset_Y + 4));
    startingCellPositions.append(qMakePair(offset_X + 6, offset_Y + 7));
    startingCellPositions.append(qMakePair(offset_X + 7, offset_Y + 2));
    startingCellPositions.append(qMakePair(offset_X + 7, offset_Y + 4));
    startingCellPositions.append(qMakePair(offset_X + 7, offset_Y + 6));
    startingCellPositions.append(qMakePair(offset_X + 8, offset_Y + 4));



    // Initialise starting pattern
    worker.initialiseGame(startingCellPositions);


     return app.exec();
}
