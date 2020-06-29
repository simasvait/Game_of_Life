#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    Ui::MainWindow *ui;
    QTimer *myTimer = nullptr;
    uint timerInterval;
    int timeElapsed;

private slots:
    void        on_pushB_updateGrid_clicked     ();
    void        on_pushB_Progress1_clicked      ();
    void        on_pushB_ProgressX_clicked      ();
    void        on_pushB_Run_clicked            ();
    void        on_pushB_Stop_clicked           ();
    void        on_pushB_resetGrid_clicked      ();
    void        on_pushB_loadBMP_clicked        ();
    void        on_slider_Zoom_sliderMoved      (int position);
    void        on_slider_Speed_sliderMoved     (int position);
    void        on_edit_stepSize_textChanged    ();
    void        on_Screen_CellCount_overflow    ();
    void        updateTimerLabel                (int steps);
    void        on_check_Constrain_stateChanged (int state);
    void        on_edit_seed_editingFinished    ();
    void        on_pushB_RndSeed_clicked        ();

public slots:
    void        update_Grid_labels              (int x, int y);


signals:
    void        GridEdited                      (int newX, int newY);
    void        UpdateReq                       (uint steps);
    void        ResetGrid                       ();
    void        SeedChanged                     (quint32 seed);
    void        ImageLoaded                     (QImage image);
    void        ConstrainGrid                   (int state);

};
#endif // MAINWINDOW_H
