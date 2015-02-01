#include "main.hpp"

/** initialize the main window
 *
 * @return bool true on success, false otherwise
 */
bool Convert::initialize() {

  // the data.rcc gets compiled as a binary file via rcc. It is expected
  // in the same path as the executable
  bool rc = QResource::registerResource( qApp->applicationDirPath() + "/data.rcc" );
  if ( !rc ) {
    QMessageBox::critical( this, tr("Error"), tr("Data file data.rcc missing."));
    return false;
  }

  // Simon Wilper
  // initialize XML parser with units.xml file now (2015-01-06) contained in the data.rcc
  UnitXMLParser p( ":data/units.xml" );
  if ( !p.initialize()) {
    QMessageBox::critical( this, tr("Error"), p.getErrorMessage() );
    return false;
  }
  // the parser holds the unit groups (widgets)
  unitGroups = p.getUnitGroups();

  // initialize settings object from settings.ini stored in the same
  // path as the executable in INI format
  settings = new QSettings( qApp->applicationDirPath() + "/settings.ini", QSettings::IniFormat, this );

  // UI
  // Status Bar
  statusbar = new QStatusBar(this);
  setStatusBar(statusbar);

  // Main Toolbar
  tbMain = new QToolBar(this);
  tbMain->setObjectName("main");
  tbMain->setMovable(true);
  tbMain->setAllowedAreas( Qt::BottomToolBarArea | Qt::TopToolBarArea );
  tbMain->setIconSize( QSize( 24, 24 ) );
  tbMain->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

  // Actions
  actionQuit     = new QAction( QIcon(":/icon/icons/quit.png"),          tr("&Quit"),      this);

  actionSort     = new QAction( QIcon(":/icon/icons/a_to_z.png"),        tr("&Sort"),      this);
  actionSortAsc  = new QAction( tr("&Ascending"), this );
  actionSortDesc = new QAction( tr("&Descending"), this );
  
  actionSplit    = new QAction( QIcon(":/icon/icons/add-new-tab.png"),   tr("&Split"),     this);
  actionUnsplit  = new QAction( QIcon(":/icon/icons/window-close.png"),  tr("&Unsplit"),   this);
  actionHelp     = new QAction( QIcon(":/icon/icons/about.png"),         tr("&Help"),      this);
  actionAbout    = new QAction( QIcon(":/icon/icons/about.png"),         tr("&About"),     this);

  actionQuit    ->setShortcut( QKeySequence( tr("Ctrl+Q") ) );
  actionSplit   ->setShortcut( QKeySequence( "F2" ) );
  actionUnsplit ->setShortcut( QKeySequence( "F3" ) );
  actionHelp    ->setShortcut( QKeySequence( "F1" ) );

  // Signals connected to Slots
  connect( actionQuit,     SIGNAL(triggered()), this, SLOT(actionQuitTriggered()) );
  connect( actionSort,     SIGNAL(triggered()), this, SLOT(actionSortTriggered()) );
  connect( actionSortAsc,  SIGNAL(triggered()), this, SLOT(actionSortAscTriggered()) );
  connect( actionSortDesc, SIGNAL(triggered()), this, SLOT(actionSortDescTriggered()) );
  connect( actionSplit,    SIGNAL(triggered()), this, SLOT(actionAddSplit()) );
  connect( actionUnsplit,  SIGNAL(triggered()), this, SLOT(actionRemoveSplit()) );
  help = new ConvertHelp;
  help->setWindowTitle( QString(tr("SUConvert %1 - Help")).arg(strVersion) );
  connect( actionHelp,     SIGNAL(triggered()), help, SLOT(show()) );
  connect( actionAbout,    SIGNAL(triggered()), this, SLOT(actionAboutTriggered()) );

  menSort = new QMenu( tr("Sort"), this );
  menSort->addAction( actionSortAsc );
  menSort->addAction( actionSortDesc );

  // add all actions to the main toolbar. Re-order here:
  tbMain->addAction(actionQuit);
  tbMain->addAction(actionSort);
  tbMain->addAction(actionSplit);
  tbMain->addAction(actionUnsplit);
  tbMain->addAction(actionHelp);
  tbMain->addAction(actionAbout);

  addToolBar( Qt::TopToolBarArea, tbMain );

  // ***
  // *** Initialize Main UI Elements
  // ***

  // main splitter
  splitter = new QSplitter( this );

  // initialize the unit group list
  treeUnitGroups = new QTreeView;
  treeUnitGroups->setStyleSheet("font-size: 12pt; font-family:sans; margin:0;");
  treeUnitGroups->setEditTriggers(QAbstractItemView::NoEditTriggers);
  treeUnitGroups->header()->hide();
  treeUnitGroups->setSelectionBehavior( QAbstractItemView::SelectItems );
  treeUnitGroups->setSelectionMode( QAbstractItemView::SingleSelection );
  splitter->addWidget(treeUnitGroups);

  // initialize widget with VBoxLayout
  QWidget *unitStackInfo = new QWidget;
  QVBoxLayout *vboxUnitStackInfo = new QVBoxLayout;
  unitStackInfo->setLayout(vboxUnitStackInfo);

  lblTitle = new QLabel( "Title" );
  lblTitle->setStyleSheet( "font-size:16pt;font-weight:bold;background:rgb(100,100,100);color:white;padding:4px;" );
  vboxUnitStackInfo->addWidget(lblTitle);

  splitter->addWidget(unitStackInfo);

  // assign the StackedLayout to the unit list widget
  widgetUnitList = new QWidget;
  unitLayout = new QStackedLayout;
  widgetUnitList->setLayout(unitLayout);
  widgetUnitList->setStyleSheet( "font-size:16pt;" );

  scrInfo = new QScrollArea;
  lblInfo = new QLabel;
  lblInfo->setWordWrap(true);
  lblInfo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
  lblInfo->setStyleSheet("background:white;color:black;font-size:12pt;line-height:150%;padding:10px;");
  lblInfo->setOpenExternalLinks(true);
  lblInfo->setTextInteractionFlags(
      Qt::LinksAccessibleByKeyboard|
      Qt::LinksAccessibleByMouse|
      Qt::TextBrowserInteraction|
      Qt::TextSelectableByKeyboard|
      Qt::TextSelectableByMouse
      );
  connect(  lblInfo, SIGNAL(linkHovered(const QString& )),
            this, SLOT(lblInfoLinkHovered(const QString&))
            );
  if ( unitGroups.size() == 0 ) {
    lblInfo->setText( "<html>No Units configured</html>" );
  }
  scrInfo->setWidgetResizable(true);
  scrInfo->setWidget(lblInfo);

  // add the widgets to the VBoxLayout
  vboxUnitStackInfo->addWidget(widgetUnitList);
  vboxUnitStackInfo->addWidget(scrInfo);

  // initialize the list model for the unit groups
  modelUnitGroups = new QStandardItemModel;

  // Iterate over the unit groups and add them to the stacked layout.
  // Then create a StandardItem and add this to the StandardItemModel.
  // Finally assign the model to the View
  unsigned int originalIndex = 0;
  foreach( UnitGroup* g, p.getUnitGroups() ) {
    g->initialize(lblInfo);
    unitLayout->addWidget(g);

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
  foreach ( UnitCollection* coll, p.getUnitCollections() ) {
    QStandardItem *itemColl = new QStandardItem(coll->label);
    itemColl->setIcon(QIcon(coll->icon));
    modelUnitGroups->appendRow(itemColl);

    foreach ( UnitGroup *g, coll->lstGroups ) {
      g->initialize(lblInfo);
      unitLayout->addWidget(g);

      foreach ( Unit *u, g->units ) {
        connect( u, SIGNAL(textEdited(const QString&)),
            this, SLOT(txtUnitsTextEdited(const QString&)));
      }

      QStandardItem *item = new QStandardItem( g->label );
      item->setData( QVariant( originalIndex ) );
      item->setIcon( QIcon(g->icon) );

      itemColl->appendRow(item);
      originalIndex++;
    }

  }

  unitLayout->addWidget( new QWidget(this) );

  treeUnitGroups->setModel( modelUnitGroups );

  connect( treeUnitGroups->selectionModel(),
      SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection& )),
      this,
      SLOT(treeUnitGroupsSelectionChanged( const QItemSelection&, const QItemSelection& ))
    );

  setCentralWidget(splitter);

  about = new ConvertAbout;
  about->setWindowIcon( QIcon( ":/icon/icons/about.png" ) );
  about->setWindowTitle( "SUConvert " + strVersion );
  about->strDate = CONVERT_DATE;
  strVersion = QString( CONVERT_VERSION );
  about->strVersion = strVersion;
  about->initialize();
  setWindowTitle( "SUConvert " + strVersion );
  about->setWindowTitle(tr("About") + " " + windowTitle());
  setWindowIcon( QIcon( ":/icon/icons/convert.png" ) );

  if ( settings ) {
    restoreGeometry( settings->value( "mainwindow.geom" ).toByteArray() );
    restoreState( settings->value( "mainwindow.state" ).toByteArray() );
    splitter->restoreState( settings->value( "splitter.size" ).toByteArray() );

    int sd = settings->value( "sort.unitgroups", 0 ).toInt();
    modelUnitGroups->invisibleRootItem()->sortChildren( 0, sd == 0 ? Qt::AscendingOrder : Qt::DescendingOrder );
    sdUnitGroups = (sd == 0 ? ASC : DESC);

    QModelIndex groupIndex;
    QList<QVariant> indexTree = settings->value( "last.unitgroup" ).toList();
    if ( indexTree.length() == 2 ) {
      QModelIndex collectionIndex = modelUnitGroups->index(indexTree.at(1).toInt(),0);
      treeUnitGroups->setExpanded(collectionIndex, true);
      groupIndex = collectionIndex.child(indexTree.at(0).toInt(),0);
    } else
    if ( indexTree.length() == 1 ) {
      groupIndex = modelUnitGroups->index(indexTree.at(0).toInt(),0);
    } else {
      groupIndex = modelUnitGroups->index(0,0);
    }

    treeUnitGroups->selectionModel()->select(
          groupIndex, QItemSelectionModel::ClearAndSelect );
  }

  return true;
}

void Convert::treeUnitGroupsSelectionChanged( const QItemSelection& selected, const QItemSelection& ) {
  if ( selected.indexes().size() == 0 ) return;

  QModelIndex index = selected.indexes().at(0);
  if ( !index.isValid() ) return;

  QStandardItem *item = modelUnitGroups->itemFromIndex(index);
  if ( !item ) return;

  QVariant originalIndex = item->data();

  if ( originalIndex.isValid() ) {
    setVisibleUnitGroup(originalIndex.toInt());
  } else {
    unitLayout->setCurrentIndex(unitLayout->count()-1);
    lblInfo->setText(QString());
    lblTitle->setText(QString());
  }

}

void Convert::txtUnitsTextEdited( const QString& txtInput  ) {
  if ( !selectedGroup || txtInput.isEmpty() ) {
    return;
  }

  Unit *u = qobject_cast<Unit*>(sender());
  u->paintResult = true;

  QList<Unit*> lstUnits;

  if ( u->column == 1 ) {
    lstUnits = selectedGroup->units;
  } else
  if ( u->column > 1 ) {
    lstUnits = selectedGroup->additionalUnits.at(u->column-2);
  }

  if ( !cc.convertUnits( lstUnits, u ) ) {
    statusbar->showMessage( tr("Error in Converter Core"), 2000 );
  }

  QString stylePos = "color:green;font-weight:bold;";
  QString styleNeg = "color:red;font-weight:bold;";

  if ( u->column == 2 ) {
    unsigned int i = 0;
    foreach( Unit *B, lstUnits ) {
      if ( B->type == Unit::FORMATTED ) continue;
      Unit *A = selectedGroup->units.at(i);
      double db = B->text().toDouble();
      double da = A->text().toDouble();
      double diff = db-da;
      B->lblDeviation->setText(QString::number(diff, 'f', 2));
      B->lblDeviation->setStyleSheet( diff >= 0 ? stylePos : styleNeg );
      i++;
    }
  } else
  if ( u->column > 2 ) {
    unsigned int i = 0;
    foreach( Unit *B, lstUnits ) {
      if ( B->type == Unit::FORMATTED ) continue;
      Unit *A = selectedGroup->additionalUnits.at(u->column-3).at(i);
      double db = B->text().toDouble();
      double da = A->text().toDouble();
      double diff = db-da;
      B->lblDeviation->setText(QString::number(diff, 'f', 2));
      B->lblDeviation->setStyleSheet( diff >= 0 ? stylePos : styleNeg );
      i++;
    }

  }

}

void Convert::lblInfoLinkHovered( const QString& url ) {
  if ( !url.isEmpty() ) {
    statusbar->showMessage( QString(tr("Navigate to URL: %1")).arg(url) );
  } else {
    statusbar->clearMessage();
  }
}

void Convert::actionQuitTriggered() {
  if ( settings ) {
    settings->setValue( "mainwindow.geom", saveGeometry() );
    settings->setValue( "mainwindow.state", saveState() );
    settings->setValue( "splitter.size", splitter->saveState() );
    settings->setValue( "sort.unitgroups", QVariant(sdUnitGroups) );

    QModelIndexList indexes = treeUnitGroups->selectionModel()->selectedIndexes();
    if ( indexes.length() > 0 ) {
      QModelIndex index = indexes.at(0);
      if ( index.isValid() ) {
        QList<QVariant> indexTree;
        indexTree << QVariant(index.row());
        QModelIndex parent = index.parent();
        if ( parent.isValid() ) {
          indexTree << QVariant(parent.row());
        }
        settings->setValue( "last.unitgroup", QVariant(indexTree) );
      }
    }
  }
  qApp->quit();
}

void Convert::actionAboutTriggered() {
  about->reset();
  about->show();
}

/** Switch to the selected widget in the QStackedLayout and transfer the input
 * focus to the first unit field
 *
 * @param int idx index of widget in the stack
 */
void Convert::setVisibleUnitGroup( int idx ) {

  // return if index is out of range
  if ( idx >= unitLayout->count() ) return;

  // switch to the selected deck
  unitLayout->setCurrentIndex(idx);
  selectedGroup = qobject_cast<UnitGroup*>(unitLayout->currentWidget());

  // transfer focus to first input field
  if ( selectedGroup->units.size() > 0 )
    selectedGroup->units.at(0)->setFocus();

  lblTitle->setText(selectedGroup->label);
}

void Convert::actionSortAscTriggered() {
  modelUnitGroups->invisibleRootItem()->sortChildren( 0, Qt::AscendingOrder );
  sdUnitGroups = ASC;
}

void Convert::actionSortDescTriggered() {
  modelUnitGroups->invisibleRootItem()->sortChildren( 0, Qt::DescendingOrder );
  sdUnitGroups = DESC;
}

void Convert::actionAddSplit() {
  if ( selectedGroup->columns == 5 ) {
    statusbar->showMessage( tr("Maximum of 5 unit sets reached"), 3000 );
    return;
  }
  QList<Unit*> lstUnits = selectedGroup->clone();
  foreach( Unit* u, lstUnits ) {
    connect( u, SIGNAL(textEdited(const QString&)), this, SLOT(txtUnitsTextEdited(const QString&)) );
  }
}

void Convert::actionRemoveSplit() {
  if ( selectedGroup->additionalUnits.size() > 0 ) {
    foreach ( Unit* u, selectedGroup->additionalUnits.last() ) {
      delete u->lblDeviation;
    }
    qDeleteAll(
        selectedGroup->additionalUnits.last().begin(),
        selectedGroup->additionalUnits.last().end()
        );

    selectedGroup->additionalUnits.removeLast();
    selectedGroup->columns--;
    selectedGroup->gridcolumns-=2;
  }
}

void Convert::actionSortTriggered() {
  menSort->exec(QCursor::pos());
}
