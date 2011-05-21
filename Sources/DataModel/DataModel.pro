#-------------------------------------------------
#
# Project created by QtCreator 2011-05-21T21:10:20
#
#-------------------------------------------------

QT       -= gui

TARGET = DataModel
TEMPLATE = lib
VERSION = 1.0.0

INCLUDEPATH = ./Sources/

MOC_DIR = ../../build/moc
OBJECTS_DIR = ../../build/obj
UI_DIR = ../../build/ui
RCC_DIR = ../../build/rcc
DESTDIR = ../../build/DataModel

DEFINES += DATAMODEL_LIBRARY

SOURCES += Sources/scell.cpp \
	Sources/sboard.cpp

HEADERS += DataModel.h\
	Sources/scell.h \
	Sources/sboard.h
