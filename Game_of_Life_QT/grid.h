// ---------------------------------------------------------------------------------------------------------
//
// Filename: grid.h
//
// Description:
// This header file defines MyGrid class used to display cells on a Tableview grid.
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
#ifndef GRID_H
#define GRID_H

#include <QAbstractTableModel>

#include "../Game_of_Life_QT/processThread.h"      // added for CellOps enum definition

class MyGrid : public QAbstractTableModel
{
    Q_OBJECT

public:
    // Constructor and destructor
    MyGrid(QObject *parent = nullptr);
    MyGrid(int x, int y, QObject *parent = nullptr);
    ~MyGrid();

    // Public methods
    int         rowCount        (const QModelIndex &parent = QModelIndex()) const override;
    int         columnCount     (const QModelIndex &parent = QModelIndex()) const override;
    QVariant    data            (const QModelIndex &index, int role = Qt::DisplayRole) const override;
    // Added for testing
    bool        GetTableData    (int item) const;
    bool        GetConstrainBool() const;

private:
    // Private variables
    int         grid_X;
    int         grid_Y;
    bool        constrainToGrid;
    bool       *TableData;
    // Private methods
    void        ClearTable      ();

public slots:
    void        setGridSize     (int x, int y);
    void        UpdateTableData (const QList<QPair<int, int>> xy_list, ProcessThread::CellOps action);

signals:
    void        GridChanged     (int newX, int newY);
    void        ReinitialiseData();

};

#endif // GRID_H
