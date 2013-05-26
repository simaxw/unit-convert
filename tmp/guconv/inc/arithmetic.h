#ifndef __arithmetic_h
#define __arithmetic_h

#include <stdlib.h>
#include <string.h>
#include <glib.h>

typedef struct _tdata {
	GTokenValue tvalue;
	GTokenType ttoken;
} tdata;

typedef struct _evaldata {
	GSList *ops;
	GSList *output;
} evaldata;

evaldata *parse( char*, gpointer );
double eval( evaldata* );

#endif
