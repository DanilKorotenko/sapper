######################################################################
# Automatically generated by qmake (1.06c) ?? 11. ??? 08:09:18 2005
######################################################################

TEMPLATE = app

QT += core
QT -= gui

INCLUDEPATH += ./src
CONFIG += console
CONFIG -= app_bundle

# Input
SOURCES += ./src/ConsoleApplication/main.cpp \
    src/ConsoleApplication/SConsoleGame.cpp \
    src/ConsoleApplication/SConsoleBoard.cpp \
    src/dataModel/scell.cpp \
    src/dataModel/sboard.cpp

HEADERS += \
    src/ConsoleApplication/SConsoleGame.h \
    src/ConsoleApplication/SConsoleBoard.h \
    src/dataModel/sboard.h \
    src/dataModel/scell.h
