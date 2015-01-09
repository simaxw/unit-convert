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
#include <QSplitter>
#include <QListView>
#include <QVBoxLayout>
#include <QScrollArea>
#include "ccore.hpp"
#include "about.hpp"
#include "parser.hpp"

#define CONVERT_VERSION "2.0.5"
#define CONVERT_DATE "2015-01-08"

class DynamicStackedLayout : public QStackedLayout {
  public:
    DynamicStackedLayout() : QStackedLayout() {}

    QSize sizeHint() const {
      return QSize( 0,100 );
    }
};

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
    void actionSortAscTriggered();
    void actionSortDescTriggered();
    void actionAddSplit();
    void actionRemoveSplit();
    void actionShowDiffTriggered();

  private:
    void setVisibleUnitGroup( int );
    QStandardItemModel *modelUnitGroups;
    QStackedLayout *unitLayout;
    QList<UnitGroup*> unitGroups;
    QSettings *settings;
    UnitGroup *selectedGroup;
    ConvertAbout *about;
    QString strVersion;
    CCore cc;
    QStatusBar *statusbar;

    QAction *actionQuit;
    QAction *actionPrevious;
    QAction *actionNext;
    QAction *actionSortAsc;
    QAction *actionSortDesc;
    QAction *actionSplit;
    QAction *actionUnsplit;
    QAction *actionShowDiff;
    QAction *actionAbout;

    QLabel *lblInfo;
    QToolBar *tbMain;
    QListView *lstUnitGroups;
    QSplitter *splitter;
    QWidget *widgetUnitList;
    QScrollArea *scrInfo;
};

#endif
