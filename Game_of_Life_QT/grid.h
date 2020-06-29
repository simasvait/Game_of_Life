#ifndef GRID_H
#define GRID_H

#include <QAbstractTableModel>
#include <QImage>

struct CellStates{
    bool last_state;
    bool current_state;
};

class MyGrid : public QAbstractTableModel
{
    // enables meta-object features, such as dynamic properties, signals, and slots
    Q_OBJECT

public:

    // Constructor
    MyGrid(QObject *parent = nullptr);

    // Methods
    int         rowCount            (const QModelIndex &parent = QModelIndex())             const override;
    int         columnCount         (const QModelIndex &parent = QModelIndex())             const override;
    QVariant    data                (const QModelIndex &index, int role = Qt::DisplayRole)  const override;
    int         getCellCount        () const;

private:
    int         grid_X;
    int         grid_Y;
    bool        constrainToGrid;

    // liveCells Hash Map
    // -------------------
    // Key:   <int x,           int y>
    // Value: <bool last_state, bool current_stage>
    QHash<QPair<int, int>, CellStates> liveCells;

public slots:
    void        initialiseGame      (const QList<QPair<int, int>> &entries);
    void        initialisePattern   (QImage image);
    void        initialiseSeed      (quint32 rng_seed);
    void        progressGeneration  (uint steps);
    void        setGridSize         (int x, int y);
    void        toggleCell          (const QModelIndex &index);
    void        clearCells          ();
    void        UpdateConstraints   (int state);

signals:
    void        GridChanged         (int newX, int newY);
    void        UpdateCellCount     (int number);



};

#endif // GRID_H
