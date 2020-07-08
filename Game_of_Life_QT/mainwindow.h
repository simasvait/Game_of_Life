// ---------------------------------------------------------------------------------------------------------
//
// Filename: mainwindow.h
//
// Description:
// This header file defines MainWinow class for handling UI interactions and emitting
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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "processThread.h"      // added for GUIStates enum definition

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Constructor and destructor
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    // Private variables
    Ui::MainWindow *ui;
    QTimer *myTimer = nullptr;
    uint timerInterval;
    int timeElapsed;
    int stepSize;

private slots:
    void        on_pushB_updateGrid_clicked     ();
    void        on_pushB_Progress1_clicked      ();
    void        on_pushB_ProgressX_clicked      ();
    void        on_pushB_Run_clicked            ();
    void        on_pushB_Stop_clicked           ();
    void        on_pushB_resetGrid_clicked      ();
    void        on_pushB_loadBMP_clicked        ();
    void        on_pushB_RndSeed_clicked        ();
    void        on_slider_Zoom_valueChanged     (int position);
    void        on_slider_Speed_valueChanged    (int position);
    void        on_edit_stepSize_editingFinished();
    void        on_edit_seed_editingFinished    ();
    void        on_Screen_CellCount_overflow    ();
    void        on_check_Constrain_stateChanged (int state);
    void        updateTimerLabel                (int steps);

public slots:
    void        update_Grid_labels              (int x, int y);

signals:
    void        UpdateGridDim                   (int newX, int newY);
    void        UpdateReq                       (uint steps);
    void        ResetGrid                       ();
    void        SeedChanged                     (quint32 seed);
    void        ImageLoaded                     (QImage image);
    void        ConstrainGrid                   (int state);
    void        SetGUIState                     (ProcessThread::GUIStates newstate);

};
#endif // MAINWINDOW_H
