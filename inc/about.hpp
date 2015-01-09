#ifndef __about_hpp
#define __about_hpp

#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDialog>
#include <QKeyEvent>
#include <QDebug>

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
    QLabel *lblAbout;
    QPushButton *btnClose;
};

#endif
