
#include "settings.hpp"

/** Default C'tor
 */
SxWConvertSettings::SxWConvertSettings() {
	initialize();
}

/** Browse for an executable
 */
void SxWConvertSettings::browse() {
    browserExecutable = QFileDialog::getOpenFileName(
            this,
            "Select Browser Executable",
            ".",
            "Executables (*.exe)"
            );
    if ( !browserExecutable.isEmpty() ) {
        ui.txtBrowserExecutable->setText( browserExecutable );
    }
}

/** Initialization
 */
void SxWConvertSettings::initialize() {
    ui.setupUi( this );
    connect( ui.btnBrowse, SIGNAL( clicked() ), this, SLOT( browse() ) );
}
