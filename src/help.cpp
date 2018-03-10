#include "help.hpp"

void ConvertHelp::initialize() {
  resize(800,600);
  QVBoxLayout *layout = new QVBoxLayout;
  setLayout(layout);

  QScrollArea *scrHelp = new QScrollArea;
  lblHelp = new QLabel( this );
  lblHelp->setAlignment( Qt::AlignTop | Qt::AlignLeft );
  lblHelp->setWordWrap(true);
  lblHelp->setStyleSheet("background:white;");
  scrHelp->setWidget(lblHelp);
  scrHelp->setWidgetResizable(true);

  QFile f(":/data/help.html");
  if ( f.open(QIODevice::ReadOnly) ) {
    QTextStream t(&f);
    lblHelp->setText(t.readAll());
  } else {
    lblHelp->setText( "<h1>Help Not Found</h1>" );
  }
  f.close();

  QWidget *widgetControls = new QWidget;
  QHBoxLayout *hboxControls = new QHBoxLayout;
  widgetControls->setLayout(hboxControls);

  btnClose = new QPushButton( tr("&Close") );
  connect( btnClose, SIGNAL(clicked()), this, SLOT(close()) );

  hboxControls->addStretch(1);
  hboxControls->addWidget(btnClose);

  layout->addWidget(scrHelp);
  layout->addWidget(widgetControls);
}
