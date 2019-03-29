# Simon Wilper
# 2013-05-25
# 2010-11-23
# 2007-08-23
# 2006-08-23
# 2015-01-05
# 2019-03-29

TEMPLATE = app

TARGET = bin/convert

QT += xml widgets script network
CONFIG += C++14 release silent

OBJECTS_DIR = obj
MOC_DIR = obj
UI_DIR = obj
RCC_DIR = obj

INCLUDEPATH += obj

win32:RC_FILE = res/convert.rc

win32:DEFINES += COFFSET=2
unix:DEFINES += COFFSET=0

win32:DATA_OUT = release/bin/data.rcc
unix:DATA_OUT = bin/data.rcc

# Create data.rcc automatically after linking stage
# QMAKE_POST_LINK = rcc --verbose --compress 9 --binary\
#   -o $$DATA_OUT res/main.qrc

#QMAKE_CXXFLAGS += -s -g0
#QMAKE_LFLAGS += -Wl,-s -g0

QMAKE_CXXFLAGS += -g
QMAKE_LFLAGS += -g

SOURCES +=\
src/app.cpp\
src/ccore.cpp\
src/main.cpp\
src/about.cpp\
src/parser.cpp\
src/unit.cpp\
src/help.cpp\
src/settings.cpp\
src/menufactory.cpp
# src/licensekey.cpp

HEADERS +=\
src/ccore.hpp\
src/main.hpp\
src/about.hpp\
src/parser.hpp\
src/unit.hpp\
src/help.hpp\
src/settings.hpp\
src/menufactory.hpp
# src/licensekey.hpp
