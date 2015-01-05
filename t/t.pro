#Simon Wilper
#2015-01-05

TARGET = ../bin/t
INCLUDEPATH += ../inc

QT = core gui widgets testlib xml script
CONFIG += testcase

SOURCES +=\
../src/ccore.cpp\
../src/parser.cpp\
../src/unit.cpp\
testsuite.cpp

HEADERS +=\
../inc/ccore.hpp\
../inc/parser.hpp\
../inc/unit.hpp
