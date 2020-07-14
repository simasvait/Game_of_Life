// ---------------------------------------------------------------------------------------------------------
//
// Filename: processThread.cpp
//
// Description:
// This source file contains ProcessThread class which performs all the "Game of Life" rule calculations
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
//  1.0.2-DEV    14-Jul-2020     Simas V.        Added access methods for testing
//
// ---------------------------------------------------------------------------------------------------------
#include <QtWidgets>
#include <QtConcurrent>

#include "../Game_of_Life_QT/processThread.h"

ProcessThread::ProcessThread(QObject *parent) : QObject(parent)
{
    grid_X = 50;
    grid_Y = 50;
    constrainToGrid = false;
    liveCells.clear();
    resetReady = true;

} // end of constructor



ProcessThread::~ProcessThread()
{
    // default

} // end of ~ProcessThread



void ProcessThread::TerminateObject() const
{
    emit finished();

} // end of TerminateObject



int ProcessThread::CountNeighbours(const PairInt &xy)
{
    PairInt Neighbour_XY;   // Neighbour coordinates
    int neighbours = 0;

    for (int x_axis = -1; x_axis <= 1; ++x_axis)
    {
        for (int y_axis = -1; y_axis <=1; ++y_axis)
        {
            // Skip own cell
            //
            if ((0 == x_axis) && (0 == y_axis))
            {
                continue;
            }

            Neighbour_XY = {xy.first+x_axis, xy.second+y_axis};

            // Check to see if cell exists in hash map
            //
            RWlock.lockForRead();
            if (liveCells.contains(Neighbour_XY) && (liveCells[Neighbour_XY].last_state))
            {
                    ++neighbours;
            }
            RWlock.unlock();

        } // end of y_axis

    } // end of x_axis

    return neighbours;

} // end of CountNeighbours



void ProcessThread::CheckLiveCells(const PairInt &xy)
{
    int neighbours = CountNeighbours(xy);

    // If cell is underpopulated or overpopulated, it dies
    //
    if ((neighbours < 2) || (neighbours > 3))
    {
        RWlock.lockForWrite();
        liveCells[xy].current_state = false;
        RWlock.unlock();
    }

} // end of CheckLiveCells



CellType ProcessThread::CheckDeadCells(const PairInt &xy)
{
    CellType local_liveCells;
    int neighbours = CountNeighbours(xy);

    if (3 == neighbours)
    {
        local_liveCells.insert(xy,{false, true});
    }

    return local_liveCells;

} // end of CheckDeadCells



QSet<PairInt> ProcessThread::FindSurroundingDead(const PairInt &xy)
{
    PairInt Neighbour_XY;   // Neighbour coordinates
    QSet<PairInt> local_deadCells;

    for (int x_axis = -1; x_axis <= 1; ++x_axis)
    {
        for (int y_axis = -1; y_axis <=1; ++y_axis)
        {
            Neighbour_XY = {xy.first+x_axis, xy.second+y_axis};

            // Check to see if cell exists in hash map
            // If not, add it to checklist
            //
            RWlock.lockForRead();
            if (!liveCells.contains(Neighbour_XY))
            {
                local_deadCells.insert(Neighbour_XY);
            }
            RWlock.unlock();

        } // end of y_axis

    } // end of x_axis

    return local_deadCells;

} // end of FindSurroundingDead



// Placed as a local function - issue with member functions in QtConcurrent::mappedReduced
void insertHash(CellType &res, const CellType &newitem)
{
    res.insert(newitem);

} // end of insertHash



void ProcessThread::progressGeneration(uint steps)
{
    // Local variable definitions
    QFuture<void> status;
    QFuture<QSet<PairInt>> newDeadCells;
    QFuture<CellType> newLiveCells;

    CellType::iterator it;
    PairInt erasedXY;


    // Iterate for a number of steps (generations
    //
    for (uint i = 0; i < steps; ++i)
    {
        // Do not continue going through remaining steps if state has changed
        if (InitiateReset == state)
        {
            return;
        }
        resetReady = false;

        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // 1. Check all live cells
        //
        status = QtConcurrent::map(
                    liveCells.keyBegin(), liveCells.keyEnd(),
                    [this] (const PairInt &xy) {CheckLiveCells(xy);});

        // While performing calculations, monitor if reset has been initiated
        //
        while (status.isRunning())
        {
            if (InitiateReset == state)
           {
               status.cancel();
               status.waitForFinished();
               resetReady = true;
               return;
           }
       }
       status.waitForFinished();
       //
       // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


       // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
       // 2. Add surrounding dead cells to a checklist
       //
       newDeadCells = QtConcurrent::mappedReduced(
                   liveCells.keys(),
                   std::bind(&ProcessThread::FindSurroundingDead,this,std::placeholders::_1),
                   &QSet<PairInt>::unite);

       // While performing calculations, monitor if reset has been initiated
       //
       while (newDeadCells.isRunning())
       {
           if (InitiateReset == state)
           {
               newDeadCells.cancel();
               newDeadCells.waitForFinished();
               resetReady = true;
               return;
           }
       }
       newDeadCells.waitForFinished();
       //
       // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


       // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
       // 3. Resurrect dead cells
       //
       newLiveCells = QtConcurrent::mappedReduced(
                   newDeadCells.result(),
                   std::bind(&ProcessThread::CheckDeadCells,this,std::placeholders::_1),
                   insertHash);

       // While performing calculations, monitor if reset has been initiated
       //
       while (newLiveCells.isRunning())
       {
           if (InitiateReset == state)
           {
               newLiveCells.cancel();
               newLiveCells.waitForFinished();
               resetReady = true;
               return;
           }
       }
       newLiveCells.waitForFinished();

       // Merge new cells into the main hashtable
       //
       liveCells.insert(newLiveCells.result());

       UpdateGUI(newLiveCells.result().keys(),Resurrect);
       //
       // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



       // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
       // 4. Update last_state and remove dead cells
       it = liveCells.begin();

       while (it != liveCells.end())
       {
           if (InitiateReset == state)
           {
               resetReady = true;
               return;
           }

           // If contrainToGrid is set to true, delete all cells outside grid bounds
           //
           if (   (!it->current_state)
               || (constrainToGrid && (it.key().first >= grid_X))
               || (constrainToGrid && (it.key().first < 0))
               || (constrainToGrid && (it.key().second >= grid_Y))
               || (constrainToGrid && (it.key().second < 0)))
           {
               erasedXY = it.key();
               RWlock.lockForWrite();
               it = liveCells.erase(it);
               RWlock.unlock();
               EmitConstrained(erasedXY,Kill);
           }
           else
           {
               RWlock.lockForWrite();
               it->last_state = it->current_state;
               RWlock.unlock();
               ++it;
           }

       } // end of liveCells iterator

       resetReady = true;

    } // end of steps iterator

    emit UpdateCellCount(getCellCount());

} // end of progressGeneration



void ProcessThread::initialiseGame (const QList<PairInt> &entries)
{
    QList<PairInt>::const_iterator it;

    clearCells();

    for (it = entries.begin(); it != entries.end(); ++it)
    {
        RWlock.lockForWrite();
        liveCells.insert(*it, {true, true});
        RWlock.unlock();
        EmitConstrained(*it,Resurrect);

    } // end of entries iterator

    emit UpdateCellCount(getCellCount());

} // end of initialiseGame



void ProcessThread::toggleCell(const QModelIndex &index)
{
    PairInt cell = {index.column(), index.row()};

    RWlock.lockForWrite();
    if(!liveCells.contains(cell))
    {
        liveCells.insert(cell,{true,true});
        EmitConstrained(cell,Resurrect);
    }
    else
    {
        liveCells.remove(cell);
        EmitConstrained(cell,Kill);
    }
    RWlock.unlock();
    emit UpdateCellCount(getCellCount());

} // end of toggleCell



int ProcessThread::getCellCount() const
{
    return liveCells.size();

} // end of getCellCount



void ProcessThread::clearCells()
{
    while (!resetReady)
    {
       if (Stopped != state)
       {
           state = Stopped;
       }
    }

    RWlock.lockForWrite();
    liveCells.clear();
    RWlock.unlock();


    EmitConstrained({0,0},KillAll);
    emit UpdateCellCount(getCellCount());

} // end of clearCells



void ProcessThread::initialiseSeed(quint32 rng_seed)
{
    // Local variable definitions
    QRandomGenerator rnd(rng_seed);
    QImage image(grid_X, grid_Y, QImage::Format_MonoLSB);
    QVector<quint32>myVector(grid_X * grid_Y);

    rnd.fillRange(myVector.data(), myVector.size());

    for (int it_X=0; it_X < grid_X; ++it_X)
    {
        for (int it_Y=0; it_Y < grid_Y; ++it_Y)
        {
            image.setPixel(it_X,it_Y,myVector.at(grid_X * it_Y + it_X) % 2);

        } // end of it_Y iterator

    } // end of it_X iterator

    initialisePattern(image);

} // end of initialiseSeed



void ProcessThread::initialisePattern(QImage image)
{
    QList<QPair<int, int>> startingCellPositions;

    for (int it_X=0; it_X < image.width();++it_X)
    {
        for (int it_Y=0; it_Y < image.height(); ++it_Y)
        {
            if (0 == (image.pixel(it_X,it_Y) & 0x01))
            {
                startingCellPositions.append(qMakePair(it_X,it_Y));
            }

        } // end of it_Y iterator

    } // end of it_X iterator

    initialiseGame(startingCellPositions);

} // end of initialisePattern



void ProcessThread::UpdateConstraints(int newstate)
{
    if (2 == newstate)
    {
        constrainToGrid = true;
    }
    else
    {
        constrainToGrid = false;
    }

} // end of UpdateConstraints



void ProcessThread::UpdateTableDim(const int x, const int y)
{
    grid_X = x;
    grid_Y = y;

} // end of UpdateTableDim



void ProcessThread::TransmitLiveCoords() const
{
    emit UpdateGUI(liveCells.keys(),Resurrect);   

} // end of TransmitLiveCoords



void ProcessThread::EmitConstrained(const QPair<int, int> &xy, CellOps action) const
{
    // Only transmit if cell is within visible grid
    //
    if (   (xy.first  >= 0)
        && (xy.second >= 0)
        && (xy.first  < grid_X)
        && (xy.second < grid_Y))
    {
        QList<QPair<int, int>> xy_list = {xy};
        emit UpdateGUI(xy_list,action);
    }

} // end of EmitConstrained



void ProcessThread::ChangeState(GUIStates newState)
{
    state = newState;

} // end of ChangeState



CellType ProcessThread::getliveCells() const
{
    return liveCells;

} // end of getliveCells



PairInt ProcessThread::getGridSize() const
{
    PairInt grid_size(grid_X, grid_Y);
    return grid_size;

} // end of getGridSize



bool ProcessThread::getConstrainToGrid() const
{
    return constrainToGrid;

} // end of getConstrainToGrid
