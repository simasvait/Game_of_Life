#include "grid.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include <iostream>             // temp


MyGrid::MyGrid(QObject *parent) : QAbstractTableModel(parent)
{
    grid_X = 50;
    grid_Y = 50;
    constrainToGrid = false;

} // end of constructor



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
    bool updated = false; // True when grid is reset

    if ((grid_X != x) && (0 < x))
    {
        updated = true;
        beginResetModel();
        grid_X = x;
    }

    if ((grid_Y != y) && (0 < y))
    {
        if (!updated)
        {
            updated = true;
            beginResetModel();
        }
        grid_Y = y;
    }

    if (updated)
    {
        endResetModel();
    }

    emit GridChanged(grid_X, grid_Y);

} // end of setGrid



QVariant MyGrid::data(const QModelIndex &index, int role) const
{
    // std::cout << "Role: " << role << "  Index: " << index.row() << "  " <<index.column() << std::endl;

    QColor alive(34,177, 76, 255); // [R G B Alpha]
    QColor dead(60,60,60,255);

    if (role == Qt::BackgroundRole)
    {
        if (liveCells.contains({index.row(),index.column()}))
            return QBrush(alive);
        else
            return QBrush(dead);
    }
    else
    {
        return QVariant();
    }

} // end of data

void MyGrid::progressGeneration(uint steps)
{
    QHash<QPair<int, int>, CellStates>::iterator it;
    QSet<QPair<int, int>> deadCells;
    QSet<QPair<int, int>>::iterator it_d;
    int neighbours;
    int x_axis, y_axis;             // Neighbourhood iterators
    QPair<int, int> Neighbour_XY;   // Neighbour coordinates


    for (uint i = 0; i < steps; ++i)
    {
        // Check all live cells
        for (it = liveCells.begin(); it != liveCells.end(); ++it)
        {
            //std::cout << "Iterating through cell: " << it.key().first << "x" << it.key().second << std::endl;

            // Count living neighbours
            neighbours = -1; // -1 to discard own cell

            for (x_axis = -1; x_axis <= 1; ++x_axis)
            {
                for (y_axis = -1; y_axis <=1; ++y_axis)
                {
                    Neighbour_XY = {it.key().first+x_axis, it.key().second+y_axis};

                    // Check to see if cell exists in hash map
                    if (liveCells.contains(Neighbour_XY))
                    {
                        // If cell exists and was alive in last generation, count as neighbour
                        // If cell exists and was added in this generation, ignore
                        if (liveCells[Neighbour_XY].last_state)
                        {
                            ++neighbours;
                        }
                    }
                    // Add to dead cell set for investigation
                    else
                    {
                        deadCells.insert(Neighbour_XY);
                    }

                } // end of y_axis

            } // end of x_axis

            // If cell is underpopulated or overpopulated, it dies
            if ((neighbours < 2) || (neighbours > 3))
            {
                it->current_state = false;
            }

        } // end of live cell iterator


        // Check all surrounding dead cells
        for (it_d = deadCells.begin(); it_d != deadCells.end(); ++it_d)
        {
            // Count living neighbours
            neighbours = 0; // 0 as its a dead cell

            for (x_axis = -1; x_axis <= 1; ++x_axis)
            {
                for (y_axis = -1; y_axis <=1; ++y_axis)
                {
                    Neighbour_XY = {it_d->first+x_axis, it_d->second+y_axis};

                    // Check to see if cell exists and was alive in last generation
                    if (liveCells.contains(Neighbour_XY) && liveCells[Neighbour_XY].last_state)
                    {
                        ++neighbours;
                    }

                } // end of y_axis

            } // end of x_axis

            // If cell has 3 neighbours, resurrect
            if (3 == neighbours)
            {
                liveCells.insert(*it_d,{false, true});
                emit dataChanged(index(it_d->first,it_d->second),
                                 index(it_d->first,it_d->second), {Qt::BackgroundRole});
            }

        } // end of dead cell iterator

        // Update last_state and remove dead cells
        it = liveCells.begin();

        QPair<int, int> erasedXY;

        while (it != liveCells.end())
        {
            //std::cout << "Cell: " << it.key().first << "x" << it.key().second;
            if (   (!it->current_state)
                || (constrainToGrid && (it.key().first >= grid_Y))
                || (constrainToGrid && (it.key().first < 0))
                || (constrainToGrid && (it.key().second >= grid_X))
                || (constrainToGrid && (it.key().second < 0)))
            {
                erasedXY = it.key();
                it = liveCells.erase(it);
                emit dataChanged(index(erasedXY.first,erasedXY.second),
                                 index(erasedXY.first,erasedXY.second), {Qt::BackgroundRole});
            }
            else
            {
                it->last_state = it->current_state;
                ++it;
            }

        } // end of liveCells iterator

        // ----------------------------------------------------------------
        // DEBUG
        /*std::cout << "\nLiveCells: ";
        for (it = liveCells.begin(); it != liveCells.end(); ++it)
        {
            std::cout << it.key().first << "x" << it.key().second << " " <<std::flush;
        }*/
        // END OF DEBUG
        // -------------------------------------------------------------

        deadCells.clear();

        emit UpdateCellCount(getCellCount());

    } // end of steps iterator

} // end of progressGeneration



void MyGrid::initialiseGame (const QList<QPair<int, int>> &entries)
{
    QList<QPair<int, int>>::const_iterator it;

    liveCells.clear();

    for (it = entries.begin(); it != entries.end(); ++it)
    {
        liveCells.insert(*it, {true, true});

    } // end of entries iterator

    emit dataChanged(index(0, 0), index(grid_X - 1, grid_Y - 1), {Qt::BackgroundRole});
    emit UpdateCellCount(getCellCount());

} // end of initialiseGame



void MyGrid::toggleCell(const QModelIndex &index)
{
    QPair <int, int> cell = {index.row(), index.column()};

    if(!liveCells.contains(cell))
    {
        liveCells.insert(cell,{true,true});
    }
    else
    {
        liveCells.remove(cell);
    }

    emit UpdateCellCount(getCellCount());
    emit dataChanged(QAbstractTableModel::index(index.row(), index.column()),
                     QAbstractTableModel::index(index.row(), index.column()),
                     {Qt::BackgroundRole});

} // end of toggleCell



int MyGrid::getCellCount() const
{
    return liveCells.size();

} // end of getCellCount



void MyGrid::clearCells()
{
    liveCells.clear();

    emit dataChanged(index(0,0),index(grid_X - 1, grid_Y - 1),{Qt::BackgroundRole});
    emit UpdateCellCount(getCellCount());

} // end of clearCells



void MyGrid::initialiseSeed(quint32 rng_seed)
{
    QRandomGenerator rnd(rng_seed);
    QImage image(grid_X, grid_Y, QImage::Format_MonoLSB);
    QVector<quint32>myVector(grid_X * grid_Y);
    int it_X, it_Y;

    rnd.fillRange(myVector.data(), myVector.size());

    for (it_X=0; it_X < grid_X; ++it_X)
    {
        for (it_Y=0; it_Y < grid_Y; ++it_Y)
        {
            image.setPixel(it_X,it_Y,myVector.at(grid_X * it_X + it_Y) % 2);

        } // end of it_Y iterator

    } // end of it+X iterator

    initialisePattern(image);

} // end of initialiseSeed



void MyGrid::initialisePattern(QImage image)
{
    QList<QPair<int, int>> startingCellPositions;
    int it_X, it_Y;

    for (it_X=0; it_X < image.width();++it_X)
    {
        for (it_Y=0; it_Y < image.height(); ++it_Y)
        {
            if (0 == (image.pixel(it_X,it_Y) & 0x01))
            {
                startingCellPositions.append(qMakePair(it_Y,it_X));
            }

        } // end of it_Y iterator

    } // end of it_X iterator

    initialiseGame(startingCellPositions);

} // end of initialisePattern



void MyGrid::UpdateConstraints(int state)
{
    if (2 == state)
    {
        constrainToGrid = true;
    }
    else
    {
        constrainToGrid = false;
    }

} // end of UpdateConstraints
