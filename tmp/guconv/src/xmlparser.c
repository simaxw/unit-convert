#include "xmlparser.h"

xmlChar *xmlAttrValue( const xmlChar **attr, const xmlChar *key ) {
	if ( attr == NULL ) {
		return NULL;
	}

	guint i = 0;

	while ( attr[i] != NULL ) {
		if ( attr[i+1] != NULL && xmlStrEqual(attr[i], key) ) {
			return xmlStrdup(attr[i+1]);
		}
		i+=2;
	}

	return NULL;
}

void guconvStartElement( void *ctx, const xmlChar *name, const xmlChar **attr ) {
	parserContext *c = (parserContext*)ctx;

	if ( xmlStrEqual( name, (const xmlChar*)"group" ) ) {
		group *g = (group*)malloc( sizeof(group) );
		g->id = _a("id");
		g->label = _a("label");
		g->units = NULL;
		g->table = gtk_table_new( 0, 2, FALSE );
		c->groups = g_slist_prepend( c->groups, g );
	} else

	if ( xmlStrEqual( name, (const xmlChar*)"unit" ) ) {
		group *g = (group*)c->groups->data;
		unit *u = (unit*)malloc( sizeof(unit) );
		u->id = _a("id");
		u->label = _a("label");

		u->type = UNDEF;
		u->fromSI = NULL;
		u->toSI = NULL;
		u->ed_from_si = NULL;
		u->ed_to_si = NULL;
		u->value = 0.0;
		u->info = NULL;
		u->entry = gtk_entry_new();

		xmlChar *type = _a("type");

		if ( xmlStrEqual(type, (const xmlChar*)"factor" ) ) {
			u->type = FACTOR;

			xmlChar *factor = _a("value");
			if ( factor != NULL ) {
				u->value = atof( (char*)factor );
			}

		} else
		if ( xmlStrEqual(type, (const xmlChar*)"transform" ) ) {
			u->type = TRANSFORM;
			u->toSI = _a("toSI");

			// eval data to si
			u->ed_to_si = parse( (char*)u->toSI, c->px );
			u->fromSI = _a("fromSI");

			// eval data from si
			u->ed_from_si = parse( (char*)u->fromSI, c->px );
		}

		g->units = g_slist_prepend( g->units, u );
	}
}

void guconvCDATA( void *ctx, const xmlChar *value, int len ) {
	parserContext *c = (parserContext*)ctx;
	((unit*)((group*)c->groups->data)->units->data)->info = xmlStrdup(value);
}

void guconvErrorHandler( void *ctx, const char *msg, ... ) {
	parserContext *c = (parserContext*)ctx;
	c->e = xmlGetLastError();
}
