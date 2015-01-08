#include "main.hpp"

bool Convert::initialize() {

  bool rc = QResource::registerResource( qApp->applicationDirPath() + "/data.rcc" );
  if ( !rc ) {
    QMessageBox::critical( this, tr("Error"), tr("Data file data.rcc missing"));
    return false;
  }

  // Simon Wilper
  // initialize XML parser with units.xml file now (2015-01-06) contained in the data.rcc
  UnitXMLParser p( ":data/units.xml" );
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
  unsigned int originalIndex = 0;
  foreach( UnitGroup* g, p.getUnitGroups() ) {
    g->initialize(ui.lblInfo);
    unitLayout->addWidget( g );

    foreach ( Unit *u, g->units ) {
      connect( u, SIGNAL(textEdited(const QString&)),
          this, SLOT(txtUnitsTextEdited(const QString&)));
    }

    QStandardItem *item = new QStandardItem( g->label );
    item->setData( QVariant( originalIndex ) );
    item->setIcon( QIcon(g->icon) );
    modelUnitGroups->appendRow( item );

    originalIndex++;
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
  connect( ui.actionPrevious, SIGNAL(triggered()), this, SLOT(actionPreviousTriggered()) );
  connect( ui.actionNext, SIGNAL(triggered()), this, SLOT(actionNextTriggered()) );
  connect( ui.actionAbout, SIGNAL(triggered()), this, SLOT(actionAboutTriggered()) );
  connect( ui.actionSortAsc, SIGNAL(triggered()), this, SLOT(actionSortAscTriggered()) );
  connect( ui.actionSortDesc, SIGNAL(triggered()), this, SLOT(actionSortDescTriggered()) );
  connect( ui.actionSplit, SIGNAL(triggered()), this, SLOT(actionAddSplit()) );
  connect( ui.actionUnsplit, SIGNAL(triggered()), this, SLOT(actionRemoveSplit()) );

  if ( unitLayout->count() > 0 ) {
    int lastIdx = settings->value( "last.group", 0 ).toInt();
    QModelIndex index = modelUnitGroups->index( lastIdx, 0 );
    ui.lstUnitGroups->selectionModel()->select( index, QItemSelectionModel::Select );

    if ( selectedGroup ) {
      int lastFocusedIdx = settings->value( "last.focused", 0 ).toInt();
      if ( lastFocusedIdx >= 0 && lastFocusedIdx < selectedGroup->units.size() ) {
        selectedGroup->units.at(lastFocusedIdx)->setFocus();
      }
    }
  }

  if ( settings ) {
    restoreGeometry( settings->value( "mainwindow.geom" ).toByteArray() );
    restoreState( settings->value( "mainwindow.state" ).toByteArray() );
    ui.splitter->restoreState( settings->value( "splitter.size" ).toByteArray() );
  }

  strVersion = QString( CONVERT_VERSION );
  setWindowTitle( "Convert " + strVersion );
  about.strDate = CONVERT_DATE;
  about.strVersion = strVersion;
  about.initialize();

  modelUnitGroups->invisibleRootItem()->sortChildren( 0, Qt::AscendingOrder );

  return true;
}

void Convert::lstUnitGroupsSelectionChanged( const QItemSelection& selected, const QItemSelection& ) {
  int idx = selected.indexes().at(0).row();
  if ( idx > unitLayout->count() ) {
    return;
  }
  QVariant voriginalIndex = modelUnitGroups->itemFromIndex(selected.indexes().at(0))->data();
  setVisibleUnitGroup(voriginalIndex.toInt());
}

void Convert::txtUnitsTextEdited( const QString& txtInput  ) {
  if ( !selectedGroup || txtInput.isEmpty() ) {
    return;
  }

  Unit *u = qobject_cast<Unit*>(sender());
  QList<Unit*> lstUnits;

  if ( u->column == 1 ) {
    lstUnits = selectedGroup->units;
  } else
  if ( u->column > 1 ) {
    lstUnits = selectedGroup->additionalUnits.at(u->column-2);
  }

  if ( !cc.convertUnits( lstUnits, u ) ) {
    ui.statusBar->showMessage( tr("Error in Converter Core"), 2000 );
  }

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
    QVariant voriginalIndex = modelUnitGroups->itemFromIndex(ui.lstUnitGroups->selectionModel()->selectedIndexes().at(0))->data();
    settings->setValue( "last.group", voriginalIndex.toInt() );

    if ( selectedGroup ) {
      Unit *u = (Unit*)qApp->focusWidget();
      int idx = selectedGroup->units.indexOf(u);
      settings->setValue( "last.focused", idx );
    }

    settings->setValue( "mainwindow.geom", saveGeometry() );
    settings->setValue( "mainwindow.state", saveState() );
    settings->setValue( "splitter.size", ui.splitter->saveState() );

  }
  qApp->quit();
}

void Convert::actionPreviousTriggered() {
  int idx = ui.lstUnitGroups->selectionModel()->selectedIndexes().at(0).row();
  if ( idx != 0 ) {
    QModelIndex index = modelUnitGroups->index( idx-1, 0 );
    ui.lstUnitGroups->selectionModel()->select( index, QItemSelectionModel::ClearAndSelect );
  }
}

void Convert::actionNextTriggered() {
  int idx = ui.lstUnitGroups->selectionModel()->selectedIndexes().at(0).row();
  if ( idx < unitGroups.size()-1 ) {
    QModelIndex index = modelUnitGroups->index( idx+1, 0 );
    ui.lstUnitGroups->selectionModel()->select( index, QItemSelectionModel::ClearAndSelect );
  }
}

void Convert::actionAboutTriggered() {
  about.reset();
  about.show();
}

void Convert::setVisibleUnitGroup( int idx ) {
  // switch QStackedLayout to the selected deck
  unitLayout->setCurrentIndex(idx);

  // transfer focus to first input field
  unitGroups.at(idx)->units.at(0)->setFocus();

  // set selected group private member
  selectedGroup = unitGroups.at(idx);
}

void Convert::actionSortAscTriggered() {
  modelUnitGroups->invisibleRootItem()->sortChildren( 0, Qt::AscendingOrder );
}

void Convert::actionSortDescTriggered() {
  modelUnitGroups->invisibleRootItem()->sortChildren( 0, Qt::DescendingOrder );
}

void Convert::actionAddSplit() {
  if ( selectedGroup->columns == 5 ) {
    ui.statusBar->showMessage( tr("Maximum of 5 additional unit sets allowed"), 3000 );
    return;
  }
  QList<Unit*> lstUnits = selectedGroup->clone();
  foreach( Unit* u, lstUnits ) {
    connect( u, SIGNAL(textEdited(const QString&)), this, SLOT(txtUnitsTextEdited(const QString&)) );
  }
}

void Convert::actionRemoveSplit() {
  if ( selectedGroup->additionalUnits.size() > 0 ) {
    qDeleteAll(
        selectedGroup->additionalUnits.last().begin(),
        selectedGroup->additionalUnits.last().end()
        );
    selectedGroup->additionalUnits.removeLast();
    selectedGroup->columns--;
  }
}
