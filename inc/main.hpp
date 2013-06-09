#ifndef __main_hpp
#define __main_hpp

#include <QDebug>
#include <QSettings>
#include <QResource>
#include <QStandardItemModel>
#include <QStackedLayout>
#include <QMessageBox>
#include <QScriptEngine>
#include "about.hpp"
#include "parser.hpp"
#include "ui_mainwindow.h"

#include <cmath>

class Convert : public QMainWindow {
  Q_OBJECT

  public:
    Convert() :
      modelUnitGroups(0),
      unitLayout(0),
      settings(0),
      selectedGroup(0)
    {}
    bool initialize();

  private slots:
    void lstUnitGroupsSelectionChanged( const QItemSelection&, const QItemSelection& );
    void txtUnitsTextEdited( const QString& );
    void lblInfoLinkHovered( const QString& );
    void actionQuitTriggered();
    void actionPreviousTriggered();
    void actionNextTriggered();
    void actionAboutTriggered();

  private:
    void setVisibleUnitGroup( int );
    QStandardItemModel *modelUnitGroups;
    Ui::mainwindowConvert ui;
    QStackedLayout *unitLayout;
    QList<UnitGroup*> unitGroups;
    QSettings *settings;
    UnitGroup *selectedGroup;
    QScriptEngine qse;
    ConvertAbout about;
    QString strVersion;
};

#endif
