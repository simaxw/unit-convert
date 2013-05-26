#ifndef __xmlparser_h
#define __xmlparser_h

#include <libxml/parser.h>
#include <glib.h>
#include <gtk/gtk.h>

#include "arithmetic.h"

#define _a(name) xmlAttrValue( attr, (const xmlChar*)name )

typedef struct _parserContext {
	GSList *groups;
	xmlError *e;
	gpointer px;
} parserContext;

typedef enum _unitType {
	FACTOR, TRANSFORM, UNDEF
} unitType;

typedef struct _unit {
	xmlChar *id;
	xmlChar *label;
	unitType type;
	double value;
	xmlChar *fromSI;
	xmlChar *toSI;
	evaldata *ed_from_si;
	evaldata *ed_to_si;
	xmlChar *info;
	GtkWidget *entry;
} unit;

typedef struct _group {
	xmlChar *id;
	xmlChar *label;
	GSList *units;
	GtkWidget *table;
} group;

/** Get an attribute from the list of XML attributes in xmlChar**
 *
 * @param xmlChar** list of XML attributes
 * @param xmlChar* name of the attribute to get the value for
 * @return xmlChar* the value of the attribute
 */
xmlChar *xmlAttrValue( const xmlChar**, const xmlChar* );

/** Handle start elements in units.xml
 *
 * @param void* parser context
 * @param xmlChar* tag name
 * @param xmlChar** attributes
 */
void guconvStartElement( void*, const xmlChar*, const xmlChar** );

/** Handle CDATA sections
 *
 * @param void* parser context
 * @param xmlChar* data
 * @param int length of data
 */
void guconvCDATA( void*, const xmlChar*, int );

/** Handle parsing errors
 *
 * @param void* parser context
 * @param char* error message
 * @param ... variable arguments
 */
void guconvErrorHandler( void*, const char*, ... );

#endif
