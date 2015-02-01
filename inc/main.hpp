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
#include "ccore.hpp"
#include "about.hpp"
#include "parser.hpp"
#include "help.hpp"

#define CONVERT_VERSION "2.1.2"
#define CONVERT_DATE "2015-01-31"

class Convert : public QMainWindow {
  Q_OBJECT

  public:
    enum SortDirection { ASC, DESC };
    Convert() :
      sdUnitGroups(ASC),
      modelUnitGroups(0),
      unitLayout(0),
      settings(0),
      selectedGroup(0)
    {}
    bool initialize();

  private slots:
    void treeUnitGroupsSelectionChanged( const QItemSelection&, const QItemSelection& );
    void txtUnitsTextEdited( const QString& );
    void lblInfoLinkHovered( const QString& );
    void actionQuitTriggered();
    void actionAboutTriggered();
    void actionSortTriggered();
    void actionSortAscTriggered();
    void actionSortDescTriggered();
    void actionAddSplit();
    void actionRemoveSplit();

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

    QAction *actionQuit;
    QAction *actionSplit;
    QAction *actionUnsplit;
    QAction *actionHelp;
    QAction *actionAbout;

    QLabel *lblTitle;
    QLabel *lblInfo;
    QToolBar *tbMain;
    QTreeView *treeUnitGroups;
    QSplitter *splitter;
    QWidget *widgetUnitList;
    QScrollArea *scrInfo;
};

#endif
