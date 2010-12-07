
#ifndef __main_hpp
#define __main_hpp

#include <QtGui>
#include <QtXml>

#include "about.hpp"

#include "ui_mainwindow_convert.h"

class SxWConvert : public QMainWindow {
	Q_OBJECT

	public:
		SxWConvert();

	public slots:
        void convertEditChanged( QString );
        void specialtxtFeetEdited( QString );

		// Actions 
		void about();
		void quit();

		void focusChangeHandler( QWidget*, QWidget* );

	protected:
		void closeEvent( QCloseEvent* );

	private:
        QString calc( QString );
		void initialize();
		void installSlots();
        void loadDesc();
        void loadValidators();
        void setup();
		void saveSettings();
		
		QString getFeetInchesFormat( double );

		Ui::mainwindowSxWConvert ui;

		SxWConvertAboutbox aboutBox;

		/* Settings
		 */
		QSettings *settings;

		/* Description Stringlist
		 */
		QMap < QString, QString > descList;
        QMap < QString, QMap < QLineEdit*, QMap < QString, QString > > > groups;

		/* Workaround for QTextBrowser::anchorClicked( const QUrl& );
		 * whenever an anchor (hyperref) is clicked the browser clears the
		 * display area.
		 * This variable holds the current description key and gets set by
		 * the focus handler so that the
		 * description can be restored on anchor click
		 */
		QString currentFocusDesc;
};

#endif
