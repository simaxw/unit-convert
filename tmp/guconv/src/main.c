#include "mainwindow.h"

int main( int argc, char *argv[] ) {
	if ( argc < 2 ) {
		fprintf( stderr, "Give file to parse\n" );
		return -1;
	}

	gtk_init( &argc, &argv );

	if ( initialize( argv[1] ) != 0 ) {
		return -1;
	}

	gtk_main();
	return 0;
}
