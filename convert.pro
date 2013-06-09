#Simon Wilper
#2013-05-25
#2010-11-23
#2007-08-23
#2006-08-23

DEFINES += CONVERT_VERSION_MAJOR=2
DEFINES += CONVERT_VERSION_MINOR=0
DEFINES += CONVERT_VERSION_REVISION=1

TEMPLATE = app

TARGET = bin/convert

VPATH += .obj src inc ui res
INCLUDEPATH += inc

OBJECTS_DIR = .obj
MOC_DIR = .obj
UI_DIR = .obj
RCC_DIR = .obj

QT += xml widgets script

FORMS +=\
about.ui\
mainwindow.ui

SOURCES +=\
main.cpp\
about.cpp\
parser.cpp\
unit.cpp

HEADERS +=\
main.hpp\
about.hpp\
parser.hpp\
unit.hpp
