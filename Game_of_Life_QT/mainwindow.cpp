// ---------------------------------------------------------------------------------------------------------
//
// Filename: mainwindow.cpp
//
// Description:
// This source file contains MainWinow class for handling UI interactions and emitting
// appropriate signals.
//
// Change Hisory:
//
//  VER          DATE            AUTHOR          DESCRIPTION
//  1.0          18-Jun-2020     Simas V.        Initial single-threaded version.
//  1.0.1-DEV    08-Jul-2020     Simas V.        Updated to add multi-threading capabilities:
//                                                  - Moved calculations from MyGrid to ProcessThread
//                                                  - Added stepSize as a private variable
//                                                  - Added comments and formatting
//
// ---------------------------------------------------------------------------------------------------------
#include <QRandomGenerator>
#include <QTimer>
#include <QDateTime>
#include <QFileDialog>
#include <QStandardPaths>

#include "ui_mainwindow.h"
#include "../Game_of_Life_QT/mainwindow.h"

// Enforced grid dimension limits
#define MAX_GRID_DIMENSION 10000
#define MIN_GRID_DIMENSION 1

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Initial values
    timerInterval = 200;
    timeElapsed   = 0;
    stepSize      = 1;

} // end of MainWindow



MainWindow::~MainWindow()
{
    if (myTimer)
    {
        delete myTimer;
    }
    delete ui;

} // end of ~MainWindow



void MainWindow::on_pushB_updateGrid_clicked()
{
    int x = ui->edit_gridSize_X->text().toInt();
    int y = ui->edit_gridSize_Y->text().toInt();

    // Limit lower grid values to [1; 1]
    //
    if (MIN_GRID_DIMENSION > x)
    {
        ui->edit_gridSize_X->setText(QString::number(MIN_GRID_DIMENSION));
        x = MIN_GRID_DIMENSION;
    }
    else if (MAX_GRID_DIMENSION < x)
    {
        ui->edit_gridSize_X->setText(QString::number(MAX_GRID_DIMENSION));
        x = MAX_GRID_DIMENSION;
    }

    // Limit upper grid values to [10,000; 10,000]
    //
    if (MIN_GRID_DIMENSION > y)
    {
        ui->edit_gridSize_Y->setText(QString::number(MIN_GRID_DIMENSION));
        y = MIN_GRID_DIMENSION;
    }
    else if (MAX_GRID_DIMENSION < y)
    {
        ui->edit_gridSize_Y->setText(QString::number(MAX_GRID_DIMENSION));
        y = MAX_GRID_DIMENSION;
    }

    emit UpdateGridDim(x, y);

} // end of on_pushB_updateGrid_clicked



void MainWindow::update_Grid_labels(int x, int y)
{
    ui->edit_gridSize_X->setText(QVariant(x).toString());
    ui->edit_gridSize_Y->setText(QVariant(y).toString());

} // end of update_Grid_labels



void MainWindow::on_pushB_Progress1_clicked()
{
    emit SetGUIState(ProcessThread::Running);
    emit UpdateReq(1);
    updateTimerLabel(1);

} // end of on_pushB_Progress1_clicked



void MainWindow::on_pushB_ProgressX_clicked()
{
    emit SetGUIState(ProcessThread::Running);
    emit UpdateReq(stepSize);
    updateTimerLabel(stepSize);

} // end of on_pushB_ProgressX_clicked



void MainWindow::on_pushB_Run_clicked()
{
    // Create a new timer object (if one doesn't exist) and start it
    //
    if(nullptr == myTimer)
    {
        myTimer = new QTimer();
        connect(myTimer, &QTimer::timeout, this, &MainWindow::on_pushB_ProgressX_clicked);
    }
    if (!myTimer->isActive())
    {
        myTimer->start(timerInterval);
        ui->pushB_Run->setStyleSheet("background-color: rgb(181,230,29)"); //temporary
    }

} // end of on_pushB_Run_clicked



void MainWindow::on_pushB_Stop_clicked()
{
    emit SetGUIState(ProcessThread::Stopped);

    // Delete the timer object if one already exists
    //
    if (myTimer)
    {
        disconnect(myTimer, &QTimer::timeout, this, &MainWindow::on_pushB_ProgressX_clicked);
        delete myTimer;
        myTimer = nullptr;
    }
    ui->pushB_Run->setStyleSheet("background-color: rgb(225,225,225)"); //temporary

} // end of on_pushB_Stop_clicked



void MainWindow::on_slider_Zoom_valueChanged(int position)
{
    ui->myTableView->horizontalHeader()->setDefaultSectionSize(position);
    ui->myTableView->verticalHeader()->setDefaultSectionSize(position);

} // end of on_slider_Zoom_sliderMoved



void MainWindow::on_slider_Speed_valueChanged(int position)
{

    timerInterval = position;
    if ((nullptr != myTimer) && (myTimer->isActive()))
    {
        myTimer->start(timerInterval);
    }

} // end of on_slider_Speed_sliderMoved



void MainWindow::on_Screen_CellCount_overflow()
{
    ui->Screen_CellCount->display(-1);

} // end of on_Screen_CellCount_overflow



void MainWindow::on_pushB_resetGrid_clicked()
{
    // Stop the game and emit reset request
    //
    on_pushB_Stop_clicked();
    emit ResetGrid();

    // Reset timer label
    //
    timeElapsed = -1;
    updateTimerLabel(1);

} // end of on_pushB_resetGrid_clicked



void MainWindow::updateTimerLabel(int steps)
{
    // Protect against overflow
    //
    if (timeElapsed <= INT_MAX - steps)
    {
        timeElapsed += steps;
    }
    QString text = "Time elapsed (ticks): ";
    text.append(QString::number(timeElapsed));
    ui->label_TimeElapsed->setText(text);

} // end of updateTimerLabel



void MainWindow::on_edit_seed_editingFinished()
{
    // Reset the game and announce that the seed has changed
    //
    on_pushB_resetGrid_clicked();
    emit SeedChanged(ui->edit_seed->text().toUInt());

} // end of on_edit_seed_editingFinished



void MainWindow::on_pushB_RndSeed_clicked()
{
    // Generate new seed based on current time
    //
    QRandomGenerator rng(QDateTime::currentMSecsSinceEpoch() / 1000);
    quint32 new_seed = rng.generate();

    on_pushB_resetGrid_clicked();
    ui->edit_seed->setText(QString::number(new_seed));
    emit SeedChanged(new_seed);

} // end of on_pushB_RndSeed_clicked



void MainWindow::on_edit_stepSize_editingFinished()
{
    int newSize = ui->edit_stepSize->text().toInt();

    // If new step size is non-zero and changed, stop the game and update the size
    //
    if ((0 < newSize) && (newSize != stepSize))
    {
        on_pushB_Stop_clicked();
        stepSize = newSize;
    }

} // end of on_edit_stepSize_textChanged



void MainWindow::on_check_Constrain_stateChanged(int state)
{
    emit ConstrainGrid(state);

} // end of on_check_ConstrainToGrid_stateChanged



void MainWindow::on_pushB_loadBMP_clicked()
{
    // Load user selected image
    //
    QString file = QFileDialog::getOpenFileName(
                this,
                "Select Image",
                QStandardPaths::writableLocation(QStandardPaths::PicturesLocation),
                "Images (*.jpg *.png *.bmp *.gif)");

    // Return if action was cancelled
    //
    if (file.isEmpty())
        return;

    QImage myPicture(file);

    // constrain images to 500x500 pixels
    //
    if ((myPicture.width() > 500) || (myPicture.height() > 500))
    {
        myPicture = myPicture.scaled(QSize(500,500),
                                     Qt::KeepAspectRatio,
                                     Qt::FastTransformation);
    }
    myPicture = myPicture.convertToFormat(QImage::Format_MonoLSB);

    on_pushB_Stop_clicked();

    // Update grid size to match picture dimensions
    //
    UpdateGridDim(myPicture.width(), myPicture.height());
    emit ImageLoaded(myPicture);

} // end of on_pushB_loadBMP_clicked
