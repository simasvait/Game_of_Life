QT       += core gui concurrent widgets



include(gtest_dependency.pri)
include(../Game_of_Life_QT/Game_of_Life_QT.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread


HEADERS += \
    tst_grid1.h \
    tst_processThread1.h

SOURCES += \
        main.cpp




