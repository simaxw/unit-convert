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
#include <QDebug>

class Settings : public QWidget {
  Q_OBJECT

  public:
    Settings(
        QWidget *parent = 0,
        QWidget *_widgetUnits = 0,
        QTreeView *_treeView = 0
        ) :
      QWidget(parent),
      widgetUnits(_widgetUnits),
      treeView(_treeView)
      {}
    void initialize();

  private:
    void updateButtonTexts();
    QWidget *widgetUnits;
    QTreeView *treeView;

    QLabel *lblTitle;

    QLabel *lblFontUnitLabels;
    QPushButton *btnSelectFontUnitLabels;

    QLabel *lblFontTreeView;
    QPushButton *btnSelectFontTreeView;

    QPushButton *btnClose;

  private slots:
    void selectFontUnitLabelsTriggered();
    void selectFontTreeViewTriggered();
};

#endif
