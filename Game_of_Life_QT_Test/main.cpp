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
//  1.0          08-Jun-2020     Simas V.        Initial draft.
//
// ---------------------------------------------------------------------------------------------------------
//#include "../Game_of_Life_QT/mainwindow.h"
//#include "../Game_of_Life_QT/grid.h"
//#include "../Game_of_Life_QT/processThread.h"

#include "tst_case1.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
