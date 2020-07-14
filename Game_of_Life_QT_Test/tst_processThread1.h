// ---------------------------------------------------------------------------------------------------------
//
// Filename: tst_processThread1.h
//
// Description:
// Tests for ProcessThread class covering processThread.cpp and processThread.h files.
//
// Change Hisory:
//
//  VER          DATE            AUTHOR          DESCRIPTION
//  1.0          14-Jul-2020     Simas V.        Initial draft.
//
// ---------------------------------------------------------------------------------------------------------
#ifndef TST_PROCESSTHREAD1_H
#define TST_PROCESSTHREAD1_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../Game_of_Life_QT/processThread.h"

#include <QDebug>

using namespace testing;

struct MyProcessThread : testing::Test
{
    ProcessThread *test_class;

    MyProcessThread()
    {
        test_class = new ProcessThread;
    }
    ~MyProcessThread()
    {
        delete test_class;
    }
};


TEST_F(MyProcessThread, Initialise_01)
{
    int defaultVal = 50;
    // Test Default Constructor
    CellType local_liveCells = test_class->getliveCells();

    EXPECT_EQ(test_class->getGridSize().first, defaultVal);
    EXPECT_EQ(test_class->getGridSize().second, defaultVal);
    EXPECT_EQ(test_class->getConstrainToGrid(), false);
    EXPECT_EQ(local_liveCells.size(),0);

} // end of MyProcessThread/Initialise_01



/*
   Class Structure
  --------------------

    Methods:

    public:
    --------------------
    getCellCount
    getliveCells
    getGridSize
    getConstrainToGrid

    private:
    --------------------
    CheckLiveCells
    CheckDeadCells
    FindSurroundingDead
    EmitConstrained
    CountNeighbours

    public slots:
    --------------------
    initialiseGame
    initialisePattern
    initialiseSeed
    progressGeneration
    toggleCell
    clearCells
    UpdateConstraints
    UpdateTableDim
    TransmitLiveCoords
    ChangeState
    TerminateObject


    Private variables:
    ---------------------
    grid_X
    grid_Y
    constrainToGrid
    resetReady
    state
    RWlock
    liveCells

 */




#endif // TST_PROCESSTHREAD1_H
