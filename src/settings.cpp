#include "settings.hpp"

void Settings::initialize() {
  QRect availGeom = QApplication::desktop()->availableGeometry();
  int w = availGeom.width()*.4;
  int h = availGeom.height()*.3;
  int x = availGeom.width()/2-w/2;
  int y = availGeom.height()/2-h/2;
  setGeometry(x,y,w,h);
  setWindowIcon( QIcon( ":/icon/icons/settings.png" ) );
  lblTitle = new QLabel( tr("Font Settings") );
  lblTitle->setStyleSheet( "font-size:16pt;font-weight:bold;background:rgb(100,100,100);color:white;padding:4px;" );

  QWidget *widgetGrid = new QWidget;
  QGridLayout *grid = new QGridLayout;
  widgetGrid->setLayout(grid);
  lblFontUnitLabels = new QLabel( tr("Unit Labels") );
  lblFontUnitLabels->setAlignment( Qt::AlignRight|Qt::AlignVCenter );
  grid->addWidget(lblFontUnitLabels,0,0);

  btnSelectFontUnitLabels = new QPushButton( "..." );
  grid->addWidget(btnSelectFontUnitLabels,0,1);

  lblFontTreeView = new QLabel( tr("Tree View") );
  lblFontTreeView->setAlignment( Qt::AlignRight|Qt::AlignVCenter );
  grid->addWidget(lblFontTreeView,1,0);
  btnSelectFontTreeView = new QPushButton( "..." );
  grid->addWidget(btnSelectFontTreeView,1,1);

  QVBoxLayout *vboxCentral = new QVBoxLayout;
  setLayout(vboxCentral);

  QWidget *widgetControls = new QWidget;
  QHBoxLayout *hboxControls = new QHBoxLayout;
  widgetControls->setLayout(hboxControls);
  btnClose = new QPushButton( tr("Close") );
  hboxControls->addStretch();
  hboxControls->addWidget(btnClose);

  vboxCentral->addWidget( lblTitle );
  vboxCentral->addWidget( widgetGrid );
  vboxCentral->addStretch();
  vboxCentral->addWidget( widgetControls );

  connect( btnSelectFontUnitLabels, SIGNAL(clicked()), this, SLOT(selectFontUnitLabelsTriggered()) );
  connect( btnSelectFontTreeView, SIGNAL(clicked()), this, SLOT(selectFontTreeViewTriggered()) );
  connect( btnClose, SIGNAL(clicked()), this, SLOT(close()) );

  updateButtonTexts();
}

void Settings::selectFontUnitLabelsTriggered() {
  if ( !widgetUnits ) return;
  widgetUnits->setFont( QFontDialog::getFont( 0, widgetUnits->font() ) );
  updateButtonTexts();
}

void Settings::selectFontTreeViewTriggered() {
  if ( !treeView ) return;
  treeView->setFont( QFontDialog::getFont( 0, treeView->font() ) );
  updateButtonTexts();
}

void Settings::updateButtonTexts() {
  if ( widgetUnits ) {
    QFont f = widgetUnits->font();
    btnSelectFontUnitLabels->setText(QString("%1, %2pt").arg(f.family()).arg(f.pointSize()));
    btnSelectFontUnitLabels->setFont(f);
  }
  if ( treeView ) {
    QFont f = treeView->font();
    btnSelectFontTreeView->setText(QString("%1, %2pt").arg(f.family()).arg(f.pointSize()));
    btnSelectFontTreeView->setFont(f);
  }
}
