// ---------------------------------------------------------------------------------------------------------
//
// Filename: grid.cpp
//
// Description:
// This source file contains MyGrid class used to display cells on a Tableview grid.
//
// Change Hisory:
//
//  VER          DATE            AUTHOR          DESCRIPTION
//  1.0          18-Jun-2020     Simas V.        Initial single-threaded version.
//  1.0.1-DEV    08-Jul-2020     Simas V.        Updated to add multi-threading capabilities:
//                                                  - Moved calculations from MyGrid to ProcessThread
//                                                  - Added TableData to store visible cell coordinates
//                                                  - Added methods and signals to hangle syncronisation
//                                                    between TableData and liveCells within ProcessThread
//
// ---------------------------------------------------------------------------------------------------------
#include "ui_mainwindow.h"
#include "grid.h"

// Initial grid size
#define DEFAULT_GRID 10

MyGrid::MyGrid(QObject *parent) : QAbstractTableModel(parent)
{
    grid_X          = DEFAULT_GRID;
    grid_Y          = DEFAULT_GRID;
    constrainToGrid = false;
    TableData       = new bool[grid_X*grid_Y];

    // Initialise TableData to zero
    //
    ClearTable();

} // end of constructor



MyGrid::MyGrid(int x, int y, QObject *parent) : QAbstractTableModel(parent)
{
    // Initialise to parameterised values if they are non-zero
    if ((0 < x) && (0 < y))
    {
        grid_X = x;
        grid_Y = y;
    }
    else
    {
        grid_X = DEFAULT_GRID;
        grid_Y = DEFAULT_GRID;
    }

    constrainToGrid = false;
    TableData       = new bool[grid_X*grid_Y];

    // Initialise TableData to zero
    //
    ClearTable();

} // end of constructor



MyGrid::~MyGrid()
{
    delete TableData;

} // end of ~MyGrid



void MyGrid::ClearTable()
{
    for (int i = 0; i < grid_X * grid_Y; ++i)
    {
        TableData[i] = false;
    }

} // end of ClearTable



int MyGrid::rowCount(const QModelIndex & /*parent*/) const
{
   return grid_Y;

} // end of rowCount



int MyGrid::columnCount(const QModelIndex & /*parent*/) const
{
    return grid_X;

} // end of columnCount



void MyGrid::setGridSize(int x, int y)
{
    bool resetModel  = false;

    // Only update if value is non-zero and has changed
    //
    if ((grid_X != x) && (0 < x))
    {
        resetModel = true;
        beginResetModel();
        grid_X = x;
    }
    if ((grid_Y != y) && (0 < y))
    {
        if (!resetModel)
        {
            resetModel = true;
            beginResetModel();
        }
        grid_Y = y;
    }

    if (resetModel)
    {
        endResetModel();
        emit GridChanged(grid_X, grid_Y);
    }

    // If TableData exists, delete it and create a new one with updated size
    //
    if (nullptr != TableData)
    {
        delete TableData;
    }

    // Assume that overflow is handled in the function setting grid_X and grid_Y (for now)
    TableData = new bool[grid_X*grid_Y];
    ClearTable();

    emit ReinitialiseData();

} // end of setGrid



QVariant MyGrid::data(const QModelIndex &index, int role) const
{
    // Set living and dead cell colours
    //
    QColor alive(34,177, 76, 255); // Format: [R G B Alpha]
    QColor dead(60,60,60,255);

    if (role == Qt::BackgroundRole)
    {
        if(true == TableData[index.row() * grid_X + index.column()])
        {
            return QBrush(alive);
        }
        else
        {
            return QBrush(dead);
        }
    }
    else
    {
        return QVariant();
    }

} // end of data



void MyGrid::UpdateTableData (const QList<QPair<int, int>> xy_list, ProcessThread::CellOps action)
{

    QList<QPair<int, int>>::const_iterator it;

    // Iterate through input list and add/remove valid (within bounds) living cells
    //
    for (it = xy_list.begin(); it != xy_list.end(); ++it)
    {
       int cell_idx = it->second * grid_X + it->first;

       // update only if index is in range
       //
       if (    (it->first >= 0)
            && (it->second >= 0)
            && (it->first < grid_X)
            && (it->second < grid_Y))
       {
           if (ProcessThread::Resurrect == action)
           {
               TableData[cell_idx] = true;
               emit dataChanged(index(it->second,it->first), index(it->second,it->first), {Qt::BackgroundRole});
           }
           else if (ProcessThread::Kill == action)
           {
               TableData[cell_idx] = false;
               emit dataChanged(index(it->second,it->first), index(it->second,it->first), {Qt::BackgroundRole});
           }
           else if (ProcessThread::KillAll == action)
           {
               // If KillAll action is triggered, clear data, update the view and exit function
               //
               ClearTable();
               emit dataChanged(index(0,0), index(grid_X-1,grid_Y-1), {Qt::BackgroundRole});
               return;
           }
       }

    } // end of iterator loop

} // end of UpdateTableData



bool MyGrid::GetTableData(int item) const
{
    if ((item >= 0) && (item < grid_X * grid_Y))
    {
        return TableData[item];
    }
    return 0;

} // end of GetTableData



bool MyGrid::GetConstrainBool() const
{
    return constrainToGrid;

} // end of GetConstrainBool
