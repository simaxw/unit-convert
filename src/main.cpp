#include "main.hpp"

bool Convert::initialize() {

  bool rc = QResource::registerResource( qApp->applicationDirPath() + "/data.rcc" );
  if ( !rc ) {
    return false;
  }

  // initialize XML parser with units.xml file contained in the same
  // directory the binary resides in
  UnitXMLParser p( qApp->applicationDirPath() + "/units.xml" );
  if ( !p.initialize()) {
    QMessageBox::critical( this, tr("Error"), p.getErrorMessage() );
    return false;
  }

  settings = new QSettings( qApp->applicationDirPath() + "/settings.ini", QSettings::IniFormat, this );

  // the parser holds the unit groups (widgets)
  unitGroups = p.getUnitGroups();

  // initialize this main window UI
  ui.setupUi( this );

  // assign the widget on the right the StackedLayout
  unitLayout = new QStackedLayout(ui.widgetUnitList);
  ui.widgetUnitList->setLayout(unitLayout);

  // initialize the list model for the unit groups
  modelUnitGroups = new QStandardItemModel;

  // iterate over the unit groups and add them to the stacked layout.
  foreach( UnitGroup* g, p.getUnitGroups() ) {
    g->initialize(ui.lblInfo);
    unitLayout->addWidget( g );

    QStandardItem *item = new QStandardItem( g->label );
    item->setIcon( g->icon );
    modelUnitGroups->appendRow( item );
  }

  ui.lstUnitGroups->setModel( modelUnitGroups );
  connect( ui.lstUnitGroups->selectionModel(),
      SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection& )),
      this,
      SLOT(lstUnitGroupsSelectionChanged( const QItemSelection&, const QItemSelection& ))
    );

  if ( unitGroups.size() == 0 ) {
    ui.lblInfo->setText( "<html>No Units configured</html>" );
  }

  connect( ui.actionQuit, SIGNAL(triggered()), this, SLOT(actionQuitTriggered()) );
  connect( ui.lblInfo, SIGNAL(linkHovered(const QString& )), this, SLOT(lblInfoLinkHovered(const QString&)));

  if ( unitLayout->count() > 0 ) {
    int lastIdx = settings->value( "last.group", 0 ).toInt();
    QModelIndex index = modelUnitGroups->index( lastIdx, 0 );
    ui.lstUnitGroups->selectionModel()->select( index, QItemSelectionModel::Select );
  }
  return true;
}

void Convert::lstUnitGroupsSelectionChanged( const QItemSelection& selected, const QItemSelection& ) {
  int idx = selected.indexes().at(0).row();
  if ( idx > unitLayout->count() ) {
    return;
  }
  setVisibleUnitGroup(idx);
}

void Convert::lblInfoLinkHovered( const QString& url ) {
  if ( !url.isEmpty() ) {
    ui.statusBar->showMessage( QString(tr("Navigate to URL: %1")).arg(url) );
  } else {
    ui.statusBar->clearMessage();
  }
}

void Convert::actionQuitTriggered() {
  if ( settings ) {
    settings->setValue( "last.group", ui.lstUnitGroups->selectionModel()->currentIndex().row() );
  }
  qApp->quit();
}

void Convert::setVisibleUnitGroup( int idx ) {
  unitLayout->setCurrentIndex(idx);
  ui.lblUnitGroups->setText( "&Unit Group: " + unitGroups.at(idx)->label );
  unitGroups.at(idx)->units.at(0)->setFocus();
}

/** Main
 * @param argc argument count
 * @param argv argument values
 * @return int returnvalue of app.exec();
 */
int main( int argc, char *argv[] ) {
  QApplication app( argc, argv );

  Convert c;
  if ( !c.initialize() ) {
    return -1;
  }

  c.show();

  return app.exec();
}
