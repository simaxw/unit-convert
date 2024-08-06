#include "convert.hpp"

/** Main Entry Point of the Application
 *
 * @param argc argument count
 * @param argv argument values
 * @return int returnvalue of app.exec();
 */
int main( int argc, char *argv[] ) {
  QApplication app( argc, argv );

  Convert c;
  if ( !c.initialize() ) {
    return 1;
  }

  c.show();
  return app.exec();
}
