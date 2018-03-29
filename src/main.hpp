#ifndef __main_hpp
#define __main_hpp

#include <QDebug>
#include <QApplication>
#include <QMainWindow>
#include <QDialog>
#include <QStatusBar>
#include <QSettings>
#include <QResource>
#include <QStandardItemModel>
#include <QStackedLayout>
#include <QMessageBox>
#include <QPaintEngine>
#include <QPainter>
#include <QItemSelection>
#include <QAction>
#include <QToolBar>
#include <QMenu>
#include <QSplitter>
#include <QTreeView>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QtMath>
#include <QCloseEvent>
#include <QLayoutItem>
#include "ccore.hpp"
#include "about.hpp"
#include "parser.hpp"
#include "help.hpp"
#include "settings.hpp"
#include "menufactory.hpp"

#define CONVERT_VERSION "2.1.0-dev"
#define CONVERT_DATE "2018-03-25"
#define COMPANY_NAME "Chronowerks"
#define CONVERT_NAME "EWC Unit Conversion Tool"

class Convert : public QMainWindow {
  Q_OBJECT

  public:
    enum SortDirection { ASC, DESC };
    Convert() :
      sdUnitGroups(ASC),
      modelUnitGroups(0),
      unitLayout(0),
      settings(0),
      selectedGroup(0),
      splitterUnits_Info(0),
      scrUnits(0)
    {}
    bool initialize();
    void closeEvent( QCloseEvent* );

  private slots:
    void treeUnitGroupsSelectionChanged( const QItemSelection&,
        const QItemSelection& );
    void txtUnitsTextEdited( const QString& );
    void lblInfoLinkHovered( const QString& );
    void actionQuitTriggered();
    void actionAboutTriggered();
    void actionSortTriggered();
    void actionSortAscTriggered();
    void actionSortDescTriggered();
    void actionAddSplit();
    void actionRemoveSplit();
    void actionToggleDiffTriggered();
    void actionSettingsTriggered();
    void actionHelpTriggered();

  private:
    SortDirection sdUnitGroups;
    void setVisibleUnitGroup( int );

    QStandardItemModel *modelUnitGroups;
    QStackedLayout *unitLayout;
    QList<UnitGroup*> unitGroups;
    QSettings *settings;
    UnitGroup *selectedGroup;
    ConvertAbout *about;
    ConvertHelp *help;
    QString strVersion;
    CCore cc;
    QStatusBar *statusbar;

    QAction *actionSort;
    QMenu *menSort;
    QAction *actionSortAsc;
    QAction *actionSortDesc;

    QAction *actionToggleDiff;

    QLabel *lblTitle;
    QLabel *lblInfo;
    QToolBar *tbMain;
    QTreeView *treeUnitGroups;
    QSplitter *splitter;
    QSplitter *splitterUnits_Info;
    QWidget *widgetUnitList;
    QScrollArea *scrInfo;
    QScrollArea *scrUnits;
    Settings *settingsWindow;
    MenuFactory *mf;
};

#endif
