#Simon Wilper
#2013-05-25
#2010-11-23
#2007-08-23
#2006-08-23
#2015-01-05

TEMPLATE = app

TARGET = bin/convert

INCLUDEPATH += inc

#QMAKE_CXXFLAGS_DEBUG += -O0 -fno-inline
#CONFIG += C++11 debug

OBJECTS_DIR = obj
MOC_DIR = obj
UI_DIR = obj
RCC_DIR = obj

win32:DEFINES += COFFSET=2
unix:DEFINES += COFFSET=0
win32:DATA_OUT = release/bin/data.rcc
unix:DATA_OUT = bin/data.rcc

# 2015-01-06 - Simon Wilper
# Create data.rcc automatically after linking stage
QMAKE_POST_LINK = rcc --verbose --compress 9 --binary -o $$DATA_OUT res/main.qrc

QT += xml widgets script

SOURCES +=\
src/app.cpp\
src/ccore.cpp\
src/main.cpp\
src/about.cpp\
src/parser.cpp\
src/unit.cpp\
src/help.cpp\
src/settings.cpp

HEADERS +=\
inc/ccore.hpp\
inc/main.hpp\
inc/about.hpp\
inc/parser.hpp\
inc/unit.hpp\
inc/help.hpp\
inc/settings.hpp
