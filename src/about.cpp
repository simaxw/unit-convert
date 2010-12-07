
#include "about.hpp"

/** Default C'tor
 */
SxWConvertAboutbox::SxWConvertAboutbox() {
	initialize();
}

/** Reset About Box
 */
void SxWConvertAboutbox::reset() {
	resize( 330,200 );
	ui.lblAbout->setPixmap( QPixmap( "" ) );
	QByteArray aboutText( "PGgxPlN4V0NvbnZlcnQ8L2gxPjxwPjxiPlBvbHlzaXVzIENvcnAuPC9iPiBNYXkgMTEgMjAwNjwvcD48Y2VudGVyPjxwPjxiPlNpbW9uIFdpbHBlcjwvYj48L3A+IDxwPjxiPlV3ZSBFc2NoZW5ob3JzdDwvYj48L3A+PC9jZW50ZXI+" );

	ui.lblAbout->setText( QByteArray::fromBase64( aboutText ) );
}

/** Key Press Event Handler
 * @param QKeyEvent* Key Event
 */
void SxWConvertAboutbox::keyPressEvent( QKeyEvent *e ) {
    if ( e->key() == Qt::Key_F5 && e->modifiers() == Qt::ControlModifier )
        ui.lblAbout->setPixmap( QPixmap( ":/icon/icons/wdysr.png" ) );
}

/** Init
 */
void SxWConvertAboutbox::initialize() {
	ui.setupUi( this );
}
