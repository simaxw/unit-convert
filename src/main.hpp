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
#include <QList>
#include "ccore.hpp"
#include "about.hpp"
#include "parser.hpp"
#include "help.hpp"
#include "settings.hpp"
#include "menufactory.hpp"

#define CONVERT_VERSION "2.2.0"
#define CONVERT_DATE "2018-04-01"
#define COMPANY_NAME "Chronowerks"
#define CONVERT_NAME "EWC Unit Conversion Tool"

class Convert : public QMainWindow {
  Q_OBJECT

  public:
    enum SortDirection { ASC, DESC };
    Convert() :
      mtoggleState(false),
      sdUnitGroups(ASC),
      modelUnitGroups(0),
      unitLayout(0),
      settings(0),
      selectedGroup(0),
      splitterUnitsInfo(0),
      scrUnits(0),
      settingsWindow(0)
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
    void actionToggleDiffTriggered(QAction*);
    void actionSettingsTriggered();
    void actionHelpTriggered();

  private:
    bool mtoggleState;
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

    QMenu *menSort;
    QAction *actionSortAsc;
    QAction *actionSortDesc;

    QLabel *lblTitle;
    QLabel *lblInfo;
    QTreeView *treeUnitGroups;
    QSplitter *splitter;
    QSplitter *splitterUnitsInfo;
    QWidget *widgetUnitList;
    QScrollArea *scrUnits;
    Settings *settingsWindow;
    MenuFactory *mf;

    QList<QWidget*> listConfigurableWidgets;
};

#endif