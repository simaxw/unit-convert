#ifndef __about_hpp
#define __about_hpp

#include <QKeyEvent>
#include <QDebug>
#include "ui_about.h"

class ConvertAbout : public QDialog {
  Q_OBJECT

  public:
    ConvertAbout();
    void reset();
    void initialize();

    QString strVersion;
    QString strDate;

  protected:
    void keyPressEvent( QKeyEvent* );

  private:
    Ui::aboutbox ui;
};

#endif
