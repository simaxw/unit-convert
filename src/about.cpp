#include "about.hpp"

/** Default Constructor
 */
ConvertAbout::ConvertAbout() {
}

/** Reset About Box
 */
void ConvertAbout::reset() {
  resize( 350,200 );
  lblAbout->setPixmap( QPixmap() );
  QByteArray aboutText64("PGgxPkNvbnZlcnQ8L2gxPjxwPlVuaXQgQ29udmVyc2lvbiBUb29sPC9wPjxwPlZlcnNpb24gJTEgLSAlMjwvcD48Y2VudGVyPjxwPjxiPlNpbW9uIFdpbHBlcjwvYj48L3A+IDxwPjxiPlV3ZSBFc2NoZW5ob3JzdDwvYj48L3A+PC9jZW50ZXI+Cg==");
  QString aboutText = QString(QByteArray::fromBase64(aboutText64)).arg(strVersion).arg(strDate);
  lblAbout->setText(aboutText);
}

/** Key Press Event Handler
 * @param QKeyEvent* Key Event
 */
void ConvertAbout::keyPressEvent( QKeyEvent *e ) {
  if ( e->key() == Qt::Key_F5 && e->modifiers() == Qt::ControlModifier ) {
    lblAbout->setPixmap( QPixmap( ":/icon/icons/wdysr.png" ) );
  }
}

/** Init
 */
void ConvertAbout::initialize() {
  setStyleSheet("background:white;");
  lblAbout = new QLabel;
  btnClose = new QPushButton( tr("&Close") );

  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(lblAbout);

  QWidget *widgetControls = new QWidget;
  QHBoxLayout *layoutControls = new QHBoxLayout;
  widgetControls->setLayout(layoutControls);
  layoutControls->addStretch(1);
  layoutControls->addWidget(btnClose);
  layout->addWidget(widgetControls);

  setLayout(layout);

  connect( btnClose, SIGNAL(clicked()), this, SLOT(accept()) );

  reset();
}
