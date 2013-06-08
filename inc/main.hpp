#ifndef __main_hpp
#define __main_hpp

#include <QDebug>

#include <QSettings>
#include <QResource>
#include <QStandardItemModel>
#include <QStackedLayout>
#include <QMessageBox>
#include "parser.hpp"
#include "ui_mainwindow.h"

class Convert : public QMainWindow {
  Q_OBJECT

  public:
    Convert() :
      modelUnitGroups(0),
      unitLayout(0),
      settings(0)
    {}
    bool initialize();

  private slots:
    void lstUnitGroupsSelectionChanged( const QItemSelection&, const QItemSelection& );
    void lblInfoLinkHovered( const QString& );
    void actionQuitTriggered();

  private:
    void setVisibleUnitGroup( int );
    QStandardItemModel *modelUnitGroups;
    Ui::mainwindowConvert ui;
    QStackedLayout *unitLayout;
    QList<UnitGroup*> unitGroups;
    QSettings *settings;
};

#endif
