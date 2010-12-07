
#ifndef __settings_hpp
#define __settings_hpp

#include <QtGui>

#include "ui_settings_convert.h"

class SxWConvertSettings : public QDialog {
	Q_OBJECT
	
	public:
		SxWConvertSettings();
		QString browserExecutable;

		Ui::dlgSettings ui;

	public slots:
		void browse();

	private:
		void initialize();
		void browseForFile();
};

#endif
