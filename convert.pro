# /* vim: set filetype=make : */

#Simon Wilper
#2013-05-25
#2010-11-23
#2007-08-23
#2006-08-23

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
	about.cpp\
	parser.cpp

HEADERS +=\
	main.hpp\
	about.hpp\
	parser.hpp
