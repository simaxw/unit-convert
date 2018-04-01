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

  int row = 0;
  for ( auto widget : mlistConfigurableWidgets ) {
    QLabel *lblWidgetName = new QLabel(widget->objectName());
    lblWidgetName->setAlignment( Qt::AlignRight|Qt::AlignVCenter );
    grid->addWidget(lblWidgetName, row, 0);

    QPushButton *btnSelectFont = new QPushButton( "..." );
    btnSelectFont->setProperty("widgetindex", row);
    grid->addWidget(btnSelectFont, row, 1);

    QFont f = widget->font();
    btnSelectFont->setText(QString("%1, %2pt").arg(f.family()).arg(f.pointSize()));
    btnSelectFont->setFont(f);

    connect(btnSelectFont, SIGNAL(clicked()),
        this, SLOT(selectFont()));

    row++;
  }

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

  connect( btnClose, SIGNAL(clicked()), this, SLOT(close()) );
}

void Settings::selectFont() {
  QPushButton *btn = qobject_cast<QPushButton*>(sender());
  if ( !btn ) return;

  QWidget *w = mlistConfigurableWidgets[btn->property("widgetindex").toInt()];

  w->setFont(QFontDialog::getFont(0, w->font()));

  QFont f = w->font();
  btn->setText(QString("%1, %2pt").arg(f.family()).arg(f.pointSize()));
  btn->setFont(f);
}
