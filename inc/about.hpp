
#ifndef __about_hpp
#define __about_hpp

#include <QtGui>

#include "ui_aboutbox_convert.h"

class SxWConvertAboutbox : public QDialog {
	Q_OBJECT

	public:
		SxWConvertAboutbox();
		void reset();

	protected:
		void keyPressEvent( QKeyEvent* );

	private:
		void initialize();

		Ui::aboutbox ui;
};

#endif
