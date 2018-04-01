#ifndef __settings_hpp
#define __settings_hpp

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFontDialog>
#include <QFont>
#include <QTreeView>
#include <QIcon>
#include <QDesktopWidget>
#include <QApplication>
#include <QList>
#include <QDebug>

class Settings : public QWidget {
  Q_OBJECT

  public:
    Settings(
        QList<QWidget*> listConfigurableWidgets
        ) :
      mlistConfigurableWidgets(listConfigurableWidgets)
      {}
    void initialize();

  private:
    QLabel *lblTitle;
    QPushButton *btnClose;
    QList<QWidget*> mlistConfigurableWidgets;

  private slots:
    void selectFont();
};

#endif
