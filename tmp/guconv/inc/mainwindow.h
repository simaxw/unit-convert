#ifndef __mainwindow_h
#define __mainwindow_h

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include <gtk/gtk.h>

#include "arithmetic.h"
#include "xmlparser.h"

double x = 0.0;

typedef struct _sdata {
	group *g;
	unit *u;
	gpointer data;
} sdata;

enum {
	LS_GROUP_NAME,
	LS_GROUP_OBJ,
	LS_GROUP_NUMFIELDS
};

int initialize( char* );

#endif
