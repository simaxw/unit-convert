
#ifndef __about_hpp
#define __about_hpp

#include <QtGui>
#include <QtWidgets>

#include "ui_about.h"

class UnitConvertAboutbox : public QDialog {
  Q_OBJECT

  public:
    UnitConvertAboutbox();
    void reset();

  protected:
    void keyPressEvent( QKeyEvent* );

  private:
    void initialize();

    Ui::aboutbox ui;
};

#endif
