#Simon Wilper
#2015-01-05

TARGET = ../bin/t
DEFINES += IS_TESTCASE
INCLUDEPATH += ../inc ../.obj

QT += testlib xml widgets script
CONFIG += testcase

SOURCES +=\
../src/main.cpp\
../src/about.cpp\
../src/parser.cpp\
../src/unit.cpp\
testsuite.cpp

HEADERS +=\
../inc/about.hpp\
../inc/main.hpp\
../inc/parser.hpp\
../inc/unit.hpp
