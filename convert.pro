#Simon Wilper
#2013-05-25
#2010-11-23
#2007-08-23
#2006-08-23
#2015-01-05

TEMPLATE = app

TARGET = bin/convert

INCLUDEPATH += inc

OBJECTS_DIR = obj
MOC_DIR = obj
UI_DIR = obj
RCC_DIR = obj

win32:DATA_OUT = release/bin/data.rcc
unix:DATA_OUT = bin/data.rcc

# 2015-01-06 - Simon Wilper
# Create data.rcc automatically after linking stage
QMAKE_POST_LINK = rcc --verbose --compress 9 --binary -o $$DATA_OUT res/main.qrc

QT += xml widgets script

FORMS +=\
ui/about.ui\
ui/mainwindow.ui

SOURCES +=\
src/app.cpp\
src/ccore.cpp\
src/main.cpp\
src/about.cpp\
src/parser.cpp\
src/unit.cpp

HEADERS +=\
inc/ccore.hpp\
inc/main.hpp\
inc/about.hpp\
inc/parser.hpp\
inc/unit.hpp
