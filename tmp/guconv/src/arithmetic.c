#include "arithmetic.h"

evaldata *parse( char *expression, gpointer px ) {

	evaldata *e = (evaldata*)malloc(sizeof(evaldata));

	GSList *ops = NULL;
	GSList *output = NULL;

	GScanner *scanner = g_scanner_new( NULL );
	g_scanner_input_text( scanner, expression, strlen(expression) );

	while ( !g_scanner_eof(scanner) ) {
		g_scanner_get_next_token(scanner);

		if ( scanner->token == G_TOKEN_INT || scanner->token == G_TOKEN_FLOAT ) {
			tdata *t = (tdata*)malloc(sizeof(tdata));
			t->tvalue = scanner->value;
			t->ttoken = scanner->token;
			output = g_slist_append(output, t );
		}
		else if (
			scanner->token == '+' ||
			scanner->token == '-' ||
			scanner->token == '*' ||
			scanner->token == '/'
			) {
			tdata *t = (tdata*)malloc(sizeof(tdata));
			t->tvalue = scanner->value;
			t->ttoken = scanner->token;
			ops = g_slist_append(ops, t );
		}
		else if ( scanner->token == 'x' || scanner->token == G_TOKEN_IDENTIFIER ) {
			tdata *t = (tdata*)malloc(sizeof(tdata));
			GTokenValue val;
			val.v_symbol = px;
			t->tvalue = val;
			t->ttoken = G_TOKEN_SYMBOL;
			output = g_slist_append(output, t );
		}
	}

	e->ops = ops;
	e->output = output;

	return e;
}

double eval( evaldata *e ) {
	GSList *lops = e->ops;
	GSList *lout = e->output;

	if ( lops == NULL || lout == NULL ) {
		return 0.0;
	}
	double A = 0.0;
	GTokenType Atype = ((tdata*)lout->data)->ttoken;
	if ( Atype == G_TOKEN_INT ) A=((tdata*)lout->data)->tvalue.v_int;
	else if ( Atype == G_TOKEN_FLOAT ) A=((tdata*)lout->data)->tvalue.v_float;
	else if ( Atype == G_TOKEN_SYMBOL ) A=*((double*)((tdata*)lout->data)->tvalue.v_symbol);

	do {
		lout = g_slist_next(lout);
		if ( lout == NULL ) {
			break;
		}

		double B = 0.0;
		GTokenType Btype = ((tdata*)lout->data)->ttoken;
		if ( Btype == G_TOKEN_INT ) B=((tdata*)lout->data)->tvalue.v_int;
		else if ( Btype == G_TOKEN_FLOAT ) B=((tdata*)lout->data)->tvalue.v_float;
		else if ( Btype == G_TOKEN_SYMBOL ) B=*((double*)(((tdata*)lout->data)->tvalue.v_symbol));

		char oper = ((tdata*)lops->data)->ttoken;

		if ( oper == '+' ) A = A+B;
		if ( oper == '-' ) A = A-B;
		if ( oper == '*' ) A = A*B;
		if ( oper == '/' ) A = A/B;

	} while ( (lops = g_slist_next(lops)) != NULL );

	return A;
}
