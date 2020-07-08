// ---------------------------------------------------------------------------------------------------------
//
// Filename: processThread.h
//
// Description:
// This header file defines ProcessThread class which performs all the "Game of Life" rule calculations
// and cell updates. It also provides methods to synchronise liveCell data with TableData within MyGrid.
//
// Change Hisory:
//
//  VER          DATE            AUTHOR          DESCRIPTION
//  1.0          18-Jun-2020     Simas V.        Initial single-threaded version.
//  1.0.1-DEV    08-Jul-2020     Simas V.        Updated to add multi-threading capabilities:
//                                                  - Moved calculations from MyGrid to ProcessThread
//                                                  - Added QtConcurrent operations to parallelise
//                                                    some heavy calculations
//                                                  - Added helper functions
//
// ---------------------------------------------------------------------------------------------------------
#ifndef PROCESSTHREAD_H
#define PROCESSTHREAD_H

#include <QImage>
#include <QModelIndex>
#include <QReadWriteLock>

// Struct for holding cell state history
struct CellStates{
    bool last_state;
    bool current_state;
};

// Type definitions
typedef QPair<int, int> PairInt;
typedef QHash<PairInt, CellStates> CellType;


class ProcessThread : public QObject
{
    // enables meta-object features, such as dynamic properties, signals, and slots
    Q_OBJECT

public:

    // Constructor and destructor
    ProcessThread(QObject *parent = nullptr);
    ~ProcessThread();

    // Enumerations
    enum CellOps {
        Kill,
        Resurrect,
        KillAll
    };
    enum GUIStates {
        Running,
        Stopped,
        InitiateReset
    };
    Q_ENUM(CellOps);
    Q_ENUM(GUIStates);


    // Public methods
    int             getCellCount        () const;

private:
    // Private variables
    int             grid_X;
    int             grid_Y;
    bool            constrainToGrid;
    bool            resetReady;
    GUIStates       state;
    QReadWriteLock  RWlock;

    // liveCells Hash Map
    // -------------------
    // Key:   <int x, int y>
    // Value: <bool last_state, bool current_stage>
    CellType        liveCells;

    // Private methods
    void            CheckLiveCells      (const PairInt &xy);
    CellType        CheckDeadCells      (const PairInt &xy);
    QSet<PairInt>   FindSurroundingDead (const PairInt &xy);
    void            EmitConstrained     (const PairInt &xy, CellOps action) const;
    int             CountNeighbours     (const PairInt &xy);

public slots:
    void            initialiseGame      (const QList<PairInt> &entries);
    void            initialisePattern   (QImage image);
    void            initialiseSeed      (quint32 rng_seed);
    void            progressGeneration  (uint steps);
    void            toggleCell          (const QModelIndex &index);
    void            clearCells          ();
    void            UpdateConstraints   (int state);
    void            UpdateTableDim      (const int x, const int y);
    void            TransmitLiveCoords  () const;
    void            ChangeState         (GUIStates newState);
    void            TerminateObject     () const;

signals:
    void            GridChanged         (int newX, int newY);
    void            UpdateCellCount     (int number);
    void            UpdateGUI           (const QList<PairInt> xy_list, CellOps action) const;
    void            finished            () const;
};

#endif // PROCESSTHREAD_H
