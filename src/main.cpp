#include "convert.hpp"

/** Main Entry Point of the Application
 *
 * @param argc argument count
 * @param argv argument values
 * @return int returnvalue of app.exec();
 */
int main( int argc, char *argv[] ) {
  QApplication app( argc, argv );

  // the data.rcc gets compiled as a binary file via rcc. It is expected
  // in the same path as the executable or in /usr/share/convert on Linux
  bool rc = false;
  for (const QString& p: QStringList{
      app.applicationDirPath(),
      "/usr/share/convert"}
      ) {
    rc = QResource::registerResource( p + "/data.rcc" );
    if ( rc ) break;
  }

  if ( !rc ) {
    QMessageBox::critical(nullptr, "Error",
        "Data file data.rcc missing. It is either expected in "
        "/usr/share/convert or in the same directory the binary "
        "resides in");
    return 1;
  }

  QTranslator translator;

  if (translator.load(QLocale(), "convert", ".", ":/i18n", ".qm")) {
    QApplication::installTranslator(&translator);
  } else {
    QMessageBox::critical(nullptr,
        "Translation Warning", "Translator load failed");
  }

  Convert c;
  if ( !c.initialize() ) {
    return 1;
  }

  c.show();
  return app.exec();
}
