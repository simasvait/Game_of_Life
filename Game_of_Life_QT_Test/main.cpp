// ---------------------------------------------------------------------------------------------------------
//
// Filename: main.cpp
//
// Description:
// Main function for initialising and running the unit tests.
//
// Change Hisory:
//
//  VER          DATE            AUTHOR          DESCRIPTION
//  1.0          08-Jul-2020     Simas V.        Initial draft.
//  1.1          14-Jul-2020     Simas V.        Renamed tst_case1 to tst_grid1 and added tst_processThread1
//
// ---------------------------------------------------------------------------------------------------------
//#include "../Game_of_Life_QT/mainwindow.h"
//#include "../Game_of_Life_QT/grid.h"
//#include "../Game_of_Life_QT/processThread.h"

#include "tst_grid1.h"              // Tests for MyGrid class
#include "tst_processThread1.h"     // Tests for ProcessThread class

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
