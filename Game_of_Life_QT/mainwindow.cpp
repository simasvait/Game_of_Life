#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRandomGenerator>
#include <QTimer>
//#include <QtWidgets>          // could be used instead of individual includes
#include <QDateTime>
#include <QFileDialog>
#include <QStandardPaths>
#include <iostream>             //temp

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timerInterval = 200;
    timeElapsed = 0;

} // end of MainWindow



MainWindow::~MainWindow()
{
    delete ui;

} // end of ~MainWindow



void MainWindow::on_pushB_updateGrid_clicked()
{
    int x = ui->edit_gridSize_X->text().toInt();
    int y = ui->edit_gridSize_Y->text().toInt();
    emit GridEdited(x, y);

} // end of on_pushB_updateGrid_clicked



void MainWindow::update_Grid_labels(int x, int y)
{
    ui->edit_gridSize_X->setText(QVariant(x).toString());
    ui->edit_gridSize_Y->setText(QVariant(y).toString());

} // end of update_Grid_labels



void MainWindow::on_pushB_Progress1_clicked()
{
    emit UpdateReq(1);
    updateTimerLabel(1);

} // end of on_pushB_Progress1_clicked



void MainWindow::on_pushB_ProgressX_clicked()
{
    int steps = ui->edit_stepSize->text().toInt();

    emit UpdateReq(steps);
    updateTimerLabel(steps);

} // end of on_pushB_ProgressX_clicked



void MainWindow::on_pushB_Run_clicked()
{

    if(myTimer == nullptr)
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
    if (myTimer)
    {
        disconnect(myTimer, &QTimer::timeout, this, &MainWindow::on_pushB_ProgressX_clicked);
        delete myTimer;
        myTimer = nullptr;
    }
    ui->pushB_Run->setStyleSheet("background-color: rgb(225,225,225)"); //temporary

} // end of on_pushB_Stop_clicked



void MainWindow::on_slider_Zoom_sliderMoved(int position)
{
    ui->myTableView->horizontalHeader()->setDefaultSectionSize(position);
    ui->myTableView->verticalHeader()->setDefaultSectionSize(position);

} // end of on_slider_Zoom_sliderMoved



void MainWindow::on_slider_Speed_sliderMoved(int position)
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
    on_pushB_Stop_clicked();
    emit ResetGrid();
    timeElapsed = -1;
    updateTimerLabel(1);

} // end of on_pushB_resetGrid_clicked



void MainWindow::updateTimerLabel(int steps)
{
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
    on_pushB_resetGrid_clicked();
    emit SeedChanged(ui->edit_seed->text().toUInt());

} // end of on_edit_seed_editingFinished



void MainWindow::on_pushB_RndSeed_clicked()
{
    QRandomGenerator rng(QDateTime::currentMSecsSinceEpoch() / 1000);
    quint32 new_seed = rng.generate();

    on_pushB_resetGrid_clicked();
    ui->edit_seed->setText(QString::number(new_seed));
    emit SeedChanged(new_seed);

} // end of on_pushB_RndSeed_clicked



void MainWindow::on_edit_stepSize_textChanged()
{
    on_pushB_Stop_clicked();

} // end of on_edit_stepSize_textChanged



void MainWindow::on_check_Constrain_stateChanged(int state)
{
    emit ConstrainGrid(state);

} // end of on_check_ConstrainToGrid_stateChanged



void MainWindow::on_pushB_loadBMP_clicked()
{
    QString file = QFileDialog::getOpenFileName(
                this,
                "Select Image",
                QStandardPaths::writableLocation(QStandardPaths::PicturesLocation),
                "Images (*.jpg *.png *.bmp *.gif)");

    if (file.isEmpty())
        return;

    QImage myPicture(file);

    // constrain images to 500x500 pixels
    if ((myPicture.width() > 500) || (myPicture.height() > 500))
    {
        myPicture = myPicture.scaled(QSize(500,500),
                                     Qt::KeepAspectRatio,
                                     Qt::FastTransformation);
    }
    myPicture = myPicture.convertToFormat(QImage::Format_MonoLSB);

    on_pushB_Stop_clicked();
    GridEdited(myPicture.width(), myPicture.height());
    emit ImageLoaded(myPicture);

} // end of on_pushB_loadBMP_clicked


