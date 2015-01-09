#ifndef __help_hpp
#define __help_hpp

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QFile>
#include <QTextStream>

class ConvertHelp : public QWidget {
  Q_OBJECT

  public:
    ConvertHelp() { initialize(); }
    void initialize();

  private:
    QLabel *lblHelp;
    QPushButton *btnClose;

};

#endif
