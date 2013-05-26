#include "mainwindow.h"

void destroy( GtkWidget *w, gpointer data ) {
	gtk_main_quit();
}

gboolean text_changed( GtkWidget *widget, GdkEvent *e, gpointer data ) {

	if (
		(e->key.keyval > 65360 && e->key.keyval < 65365) ||
		e->key.keyval == 65289 || // tab
		e->key.keyval == 65056 // shift-tab
	) {
		return FALSE;
	}

	GtkEntry *entry = GTK_ENTRY(widget);
	sdata *sd = (sdata*)data;
	GSList *l = sd->g->units;
	unit *u = sd->u;

	if ( l == NULL ) {
		return TRUE;
	}

	if ( u == NULL ) {
		return TRUE;
	}


	double value = atof( gtk_entry_get_text(entry) );

	double sivalue = 0.0;
	if ( u->type == FACTOR ) {
		sivalue = value * u->value;
	} else
	if ( u->type == TRANSFORM ) {
		if ( u->ed_to_si == NULL || u->ed_from_si == NULL ) {
			return TRUE;
		}
		x = value;
		sivalue = eval(u->ed_from_si);
	} else {
		return TRUE;
	}

	do {
		unit *uc = (unit*)l->data;
		if ( uc != u ) {
				char buffer[256];
				memset( buffer, 0, 256 );
				if ( u->type == FACTOR ) {
					snprintf( buffer, 256, "%.6lf", (sivalue / uc->value) );
				} else if ( u->type == TRANSFORM ) {
					if ( u->ed_to_si == NULL || u->ed_from_si == NULL ) {
						return TRUE;
					}
					x = sivalue;
					snprintf( buffer, 256, "%.6lf", eval(uc->ed_to_si) );
				} else {
					return TRUE;
				}
				gtk_entry_set_text( GTK_ENTRY(uc->entry), buffer );
		}
	} while ( (l = g_slist_next(l)) != NULL );

	return FALSE;
}

void add_unit_to_table( group *g, unit *u, int row ) {
	GtkWidget *label = gtk_label_new_with_mnemonic( (char*)u->label );
	gtk_table_attach( GTK_TABLE(g->table), label, 0,1,row,row+1, GTK_SHRINK,GTK_SHRINK, 2,2 );
	gtk_widget_show(label);

	gtk_label_set_mnemonic_widget( GTK_LABEL(label), u->entry );
	sdata *sd = (sdata*)malloc( sizeof(sdata) );
	sd->g = g;
	sd->u = u;
	g_signal_connect( u->entry, "key-release-event", G_CALLBACK(text_changed), sd );
	gtk_table_attach( GTK_TABLE(g->table), u->entry, 1,2,row,row+1, GTK_EXPAND,GTK_SHRINK, 2,2 );
	gtk_widget_show(u->entry);
}

void create_unit_pane_for_group( group *g, GtkPaned *pane ) {
	int row = 0;
	GSList *l = g->units;
	if ( l != NULL ) {
		do {
			unit *u = (unit*)l->data;
			add_unit_to_table( g, u, row );
			row++;
		} while ( (l = g_slist_next(l)) != NULL );
	}
}

void unit_group_selection_changed( GtkTreeSelection *selection, gpointer data ) {
	GtkTreeIter iter;
	GtkTreeModel *model;

	if ( gtk_tree_selection_get_selected( selection, &model, &iter ) ) {
		GObject *table;
		gtk_tree_model_get( model, &iter, LS_GROUP_OBJ, &table, -1 );

		GList *children = gtk_container_get_children( GTK_CONTAINER(data) );
		if ( children != NULL ) {
			do {
				gtk_container_remove( GTK_CONTAINER(data), GTK_WIDGET(children->data) );
			} while ( (children = g_list_next(children)) != NULL );
		}

		GtkWidget *w = GTK_WIDGET(table);
		gtk_widget_show( w );
		gtk_box_pack_start( GTK_BOX(data), w, TRUE,TRUE,0 );
	}
}

int initialize( char *xml_units ) {
	xmlSAXHandler h;
	memset( &h, 0, sizeof h );

	h.startElement = guconvStartElement;
	h.cdataBlock = guconvCDATA;

	h.warning = guconvErrorHandler;
	h.error = guconvErrorHandler;
	h.fatalError = guconvErrorHandler;

	parserContext ctx;
	memset( &ctx, 0, sizeof(ctx) );

	ctx.px = &x;

	int rc = xmlSAXUserParseFile( &h, &ctx, xml_units );

	if ( rc != 0 ) {

		GtkWidget *w;

		if ( ctx.e != NULL && ctx.e->message != NULL ) {
			w = gtk_message_dialog_new( NULL,
					GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE,
					"XML Parse Error: %s in line: %d column %d",
					ctx.e->message, ctx.e->line, ctx.e->int2
				);
		} else {
			w = gtk_message_dialog_new( NULL,
					GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE,
					"Unable to process file '%s'", xml_units
				);
		}

		gtk_window_set_title( GTK_WINDOW(w), "GUnitConvert" );
		gtk_dialog_run( GTK_DIALOG(w) );
		return rc;
	}

	// ---

	GtkWidget *mainwindow = gtk_window_new( GTK_WINDOW_TOPLEVEL );
	gtk_window_set_title( GTK_WINDOW(mainwindow), "GUnitConvert" );
	g_signal_connect( mainwindow, "destroy", G_CALLBACK(destroy), NULL );

	GtkWidget *pane_main = gtk_hpaned_new();

	GtkWidget *pane_units = gtk_hbox_new( TRUE, 0 );
	gtk_paned_pack2( GTK_PANED(pane_main), pane_units, TRUE, FALSE );

	GtkListStore *ls_groups = gtk_list_store_new( LS_GROUP_NUMFIELDS, G_TYPE_STRING, G_TYPE_OBJECT );
	GtkTreeIter iter;
	GSList *l = ctx.groups;
	do {
		group *g = (group*)l->data;
		if ( g->units != NULL ) {
			create_unit_pane_for_group(g, GTK_PANED(pane_main));
			gtk_list_store_append( ls_groups, &iter );
			gtk_list_store_set( ls_groups, &iter,
				LS_GROUP_NAME, g->label,
				LS_GROUP_OBJ, g->table,
				-1
			);
		}
	} while ( (l = g_slist_next(l)) != NULL );

	GtkWidget *w_list_groups = gtk_tree_view_new_with_model( GTK_TREE_MODEL(ls_groups) );
	GtkCellRenderer *renderer_name = gtk_cell_renderer_text_new();
	GtkTreeViewColumn *column_name = gtk_tree_view_column_new_with_attributes(
		"Unit Groups", renderer_name, "text", LS_GROUP_NAME, NULL
	);
	gtk_tree_view_append_column( GTK_TREE_VIEW(w_list_groups), column_name );
	GtkTreeSelection *sel = gtk_tree_view_get_selection( GTK_TREE_VIEW(w_list_groups) );
	gtk_tree_selection_set_mode( sel, GTK_SELECTION_SINGLE );
	g_signal_connect( G_OBJECT(sel), "changed", G_CALLBACK(unit_group_selection_changed), pane_units );

	GtkWidget *w_infolabel = gtk_label_new( "This is Sparta" );

	gtk_paned_pack1( GTK_PANED(pane_main), w_list_groups, TRUE, FALSE );

	gtk_container_add( GTK_CONTAINER(mainwindow), pane_main );
	gtk_container_add( GTK_CONTAINER(pane_main), w_infolabel );

	gtk_widget_show(pane_units);
	gtk_widget_show(w_list_groups);
	gtk_widget_show( pane_main );
	gtk_widget_show( w_infolabel );
	gtk_widget_show(mainwindow);
	return 0;
}
