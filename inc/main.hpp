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

#define CONVERT_VERSION "2.0.2"
#define CONVERT_DATE "Jun 11 2013"

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

#ifdef IS_TESTCASE
  public:
#else
  private:
#endif
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
