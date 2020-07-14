// ---------------------------------------------------------------------------------------------------------
//
// Filename: tst_grid1.h
//
// Description:
// Tests for MyGrid class covering grid.cpp and grid.h files.
//
// Change Hisory:
//
//  VER          DATE            AUTHOR          DESCRIPTION
//  1.0          08-Jul-2020     Simas V.        Initial draft.
//  1.1          14-Jul-2020     Simas V.        Added check for data() function
//
// ---------------------------------------------------------------------------------------------------------
#ifndef TST_GRID1_H
#define TST_GRID1_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../Game_of_Life_QT/grid.h"


using namespace testing;

struct MyGridTest : testing::Test
{
    MyGrid *test_grid;

    MyGridTest()
    {
        test_grid = new MyGrid;
    }
    ~MyGridTest()
    {
        delete test_grid;
    }
};


TEST_F(MyGridTest, Initialise_01)
{
    int defaultVal = 50;

    // Test Default Constructor
    EXPECT_EQ(test_grid->columnCount(), defaultVal);
    EXPECT_EQ(test_grid->rowCount(), defaultVal);

    for (int i = 0; i < defaultVal * defaultVal; ++i)
    {
        EXPECT_EQ(test_grid->GetTableData(i),0);
    }

} // end of MyGridTest/Initialise_01

TEST(MyGridTest2, Initialise_02)
{
    int x = 75;
    int y = 43;

    MyGrid *test_grid = new MyGrid(x,y);

    // Test parameterised Constructor
    EXPECT_EQ(test_grid->columnCount(), 75);
    EXPECT_EQ(test_grid->rowCount(), 43);

    for (int i = 0; i < x * y; ++i)
    {
        EXPECT_EQ(test_grid->GetTableData(i),0);
    }

    delete test_grid;

}  // end of MyGridTest/Initialise_02

TEST_F(MyGridTest, ResizeGrid)
{
    test_grid->setGridSize(23,77);
    // Check Valid coordinates
    EXPECT_EQ(test_grid->columnCount(), 23);
    EXPECT_EQ(test_grid->rowCount(), 77);

    // Check Invalid X
    test_grid->setGridSize(-5,40);
    EXPECT_EQ(test_grid->columnCount(), 23);
    EXPECT_EQ(test_grid->rowCount(), 40);

    // Check Invalid Y
    test_grid->setGridSize(2,0);
    EXPECT_EQ(test_grid->columnCount(), 2);
    EXPECT_EQ(test_grid->rowCount(), 40);

    // Check Invalid X and Y
    test_grid->setGridSize(-1,-3);
    EXPECT_EQ(test_grid->columnCount(), 2);
    EXPECT_EQ(test_grid->rowCount(), 40);

}  // end of MyGridTest/ResizeGrid

#include <QAbstractItemModel>

// Helper Functions
void TestTableRange(MyGrid * grid_ptr, int grid_x, int grid_y, QList<PairInt> *list, bool match)
{
    QColor  alive(34,177, 76, 255);
    QColor  dead(60,60,60,255);
    int     table_idx;
    bool    cellAlive;

    for (int x = 0; x < grid_x; ++x)
    {
        for (int y = 0; y < grid_y;++y)
        {
            table_idx = y * grid_x + x;
            cellAlive = match == list->contains({x,y});
            EXPECT_EQ(grid_ptr->GetTableData(table_idx),cellAlive);
            // Check that correct colour is set
            EXPECT_EQ(grid_ptr->data(grid_ptr->index(y,x),Qt::BackgroundRole), cellAlive ? alive : dead);
        }
    }

} // end of TestTableRange
void TestTableRange(MyGrid * grid_ptr, int grid_x, int grid_y, bool cell)
{
    int table_idx;
    for (int x = 0; x < grid_x; ++x)
    {
        for (int y = 0; y < grid_y;++y)
        {
            table_idx = y * grid_x + x;
            EXPECT_EQ(grid_ptr->GetTableData(table_idx),cell);
        }
    }

} // end of TestTableRange (overloaded)

TEST_F(MyGridTest, UpdateTable_01)
{
    int grid_x = 13;
    int grid_y = 15;
    test_grid->setGridSize(grid_x,grid_y);

    // Check valid cells
    QList<PairInt> cell_list = {
        {1,3},{5,4},{7,7},{9,8},
        {10,10},{0,1},{12,12}
    };

    test_grid->UpdateTableData(cell_list,ProcessThread::Resurrect);
    TestTableRange(test_grid,grid_x,grid_y,&cell_list, true);

}  // end of MyGridTest/UpdateTable_01

TEST_F(MyGridTest, UpdateTable_02)
{
    int grid_x = 5;
    int grid_y = 5;
    test_grid->setGridSize(grid_x,grid_y);

    // Check if grid cleared when size was changed
    TestTableRange(test_grid,grid_x,grid_y,false);

    // Check out of bound cells
    QList<PairInt> cell_list = {
        {5,5},{6,4},{1,7},
        {9,8},{-1,4},{3,-4},
        {-2,-6},{5000,5000},
        {INT_MIN,0},{0,INT_MIN},
        {INT_MAX,0},{0,INT_MAX},
        {INT_MIN,INT_MIN},
        {INT_MAX,INT_MAX},
        {INT_MIN,INT_MAX},
        {INT_MAX,INT_MIN}
    };

    test_grid->UpdateTableData(cell_list,ProcessThread::Resurrect);
    TestTableRange(test_grid,10,10,false);

}  // end of MyGridTest/UpdateTable_02

TEST_F(MyGridTest, UpdateTable_03)
{
    int grid_x = 70;
    int grid_y = 98;
    test_grid->setGridSize(grid_x,grid_y);

    // Check if grid cleared when size was changed
    TestTableRange(test_grid,grid_x,grid_y,false);

    QList<PairInt> cell_list;
    for (int x = 0; x < grid_x; ++x)
    {
        for (int y = 0; y < grid_y;++y)
        {
            cell_list.append({x,y});
        }
    }

    // Set all cells
    test_grid->UpdateTableData(cell_list,ProcessThread::Resurrect);

    // Check if all cells are set
    TestTableRange(test_grid,grid_x,grid_y,true);


    // Check killing of cells
    cell_list = {
        {0,0},{32,1},{8,6},{55,97},{14,44},{34,20},
        {0,84},{74,87},{90,90},{15,91},{1,48},{66,32}
    };

    test_grid->UpdateTableData(cell_list,ProcessThread::Kill);
    TestTableRange(test_grid,grid_x,grid_y,&cell_list,false);


    // Check kill-all
    test_grid->UpdateTableData({{0,0}},ProcessThread::KillAll);
    TestTableRange(test_grid,grid_x,grid_y,false);

}  // end of MyGridTest/UpdateTable_03


// Check resize with INT_MAX


#endif // TST_GRID1_H
