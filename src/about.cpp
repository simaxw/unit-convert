#include "about.hpp"

/** Default Constructor
 */
ConvertAbout::ConvertAbout() {
  initialize();
}

/** Reset About Box
 */
void ConvertAbout::reset() {
  resize( 350,200 );
  ui.lblAbout->setPixmap( QPixmap() );
  QByteArray aboutText64("PGgxPkNvbnZlcnQ8L2gxPjxwPlVuaXQgQ29udmVyc2lvbiBUb29sPC9wPjxwPlZlcnNpb24gJTEgLSAlMjwvcD48Y2VudGVyPjxwPjxiPlNpbW9uIFdpbHBlcjwvYj48L3A+IDxwPjxiPlV3ZSBFc2NoZW5ob3JzdDwvYj48L3A+PC9jZW50ZXI+Cg==");
  QString aboutText = QString(QByteArray::fromBase64(aboutText64)).arg("2.0.0").arg("Jun 9 2013");
  ui.lblAbout->setText(aboutText);
}

/** Key Press Event Handler
 * @param QKeyEvent* Key Event
 */
void ConvertAbout::keyPressEvent( QKeyEvent *e ) {
  if ( e->key() == Qt::Key_F5 && e->modifiers() == Qt::ControlModifier ) {
    ui.lblAbout->setPixmap( QPixmap( ":/icon/icons/wdysr.png" ) );
  }
}

/** Init
 */
void ConvertAbout::initialize() {
  ui.setupUi( this );
  reset();
}
