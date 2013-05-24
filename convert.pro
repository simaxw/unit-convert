# /* vim: set filetype=make : */

# Simon Wilper / Aug 23 2006
# Changes:
# Aug 23 2007
# Nov 23 2010

TEMPLATE = app

TARGET = bin/convert

VPATH += obj src inc ui res
INCLUDEPATH += inc

OBJECTS_DIR = obj
MOC_DIR = obj
UI_DIR = obj
RCC_DIR = obj

QT += xml widgets script

RESOURCES +=\
  mainwindow.qrc

FORMS +=\
  aboutbox_convert.ui\
  mainwindow_convert.ui

SOURCES +=\
  main.cpp\
  about.cpp

HEADERS +=\
  main.hpp\
  about.hpp

