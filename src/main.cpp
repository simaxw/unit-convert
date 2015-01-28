#include "main.hpp"

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
  actionPrevious = new QAction( QIcon(":/icon/icons/up.png"),            tr("&Previous"),  this);
  actionNext     = new QAction( QIcon(":/icon/icons/down.png"),          tr("&Next"),      this);
  actionSortAsc  = new QAction( QIcon(":/icon/icons/a_to_z.png"),        tr("Sort &Asc"),  this);
  actionSortDesc = new QAction( QIcon(":/icon/icons/a_to_z.png"),        tr("Sort Des&c"), this);
  actionSplit    = new QAction( QIcon(":/icon/icons/add-new-tab.png"),   tr("&Split"),     this);
  actionUnsplit  = new QAction( QIcon(":/icon/icons/window-close.png"),  tr("&Unsplit"),   this);
  actionHelp     = new QAction( QIcon(":/icon/icons/about.png"),         tr("&Help"),      this);
  actionAbout    = new QAction( QIcon(":/icon/icons/about.png"),         tr("&About"),     this);

  actionQuit    ->setShortcut( QKeySequence( tr("Ctrl+Q") ) );
  actionPrevious->setShortcut( QKeySequence( "Ctrl+Up" ) );
  actionNext    ->setShortcut( QKeySequence( "Ctrl+Down" ) );
  actionSplit   ->setShortcut( QKeySequence( "F2" ) );
  actionUnsplit ->setShortcut( QKeySequence( "F3" ) );
  actionHelp    ->setShortcut( QKeySequence( "F1" ) );

  // Signals connected to Slots
  connect( actionQuit,     SIGNAL(triggered()), this, SLOT(actionQuitTriggered()) );
  connect( actionPrevious, SIGNAL(triggered()), this, SLOT(actionPreviousTriggered()) );
  connect( actionNext,     SIGNAL(triggered()), this, SLOT(actionNextTriggered()) );
  connect( actionSortAsc,  SIGNAL(triggered()), this, SLOT(actionSortAscTriggered()) );
  connect( actionSortDesc, SIGNAL(triggered()), this, SLOT(actionSortDescTriggered()) );
  connect( actionSplit,    SIGNAL(triggered()), this, SLOT(actionAddSplit()) );
  connect( actionUnsplit,  SIGNAL(triggered()), this, SLOT(actionRemoveSplit()) );
  help = new ConvertHelp;
  connect( actionHelp,     SIGNAL(triggered()), help, SLOT(show()) );
  connect( actionAbout,    SIGNAL(triggered()), this, SLOT(actionAboutTriggered()) );

  // add all actions to the main toolbar. Re-order here:
  tbMain->addAction(actionQuit);
  tbMain->addAction(actionSortAsc);
  tbMain->addAction(actionSortDesc);
  tbMain->addAction(actionPrevious);
  tbMain->addAction(actionNext);
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
  lstUnitGroups = new QListView;
  lstUnitGroups->setStyleSheet("font-size: 12pt; font-family:sans; margin:10px;");
  lstUnitGroups->setEditTriggers(QAbstractItemView::NoEditTriggers);
  splitter->addWidget(lstUnitGroups);

  // initialize widget with VBoxLayout
  QWidget *unitStackInfo = new QWidget;
  QVBoxLayout *vboxUnitStackInfo = new QVBoxLayout;
  unitStackInfo->setLayout(vboxUnitStackInfo);
  splitter->addWidget(unitStackInfo);

  // assign the StackedLayout to the unit list widget
  widgetUnitList = new QWidget;
  unitLayout = new QStackedLayout;
  widgetUnitList->setLayout(unitLayout);

  scrInfo = new QScrollArea;
  lblInfo = new QLabel;
  lblInfo->setWordWrap(true);
  lblInfo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
  lblInfo->setStyleSheet("background:white;color:black;font-size:12pt;line-height:150%;padding:10px;");
  lblInfo->setOpenExternalLinks(true);
  lblInfo->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
  connect( lblInfo, SIGNAL(linkHovered(const QString& )), this, SLOT(lblInfoLinkHovered(const QString&)) );
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
  // Finally assign the model to the ListView
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

  lstUnitGroups->setModel( modelUnitGroups );

  connect( lstUnitGroups->selectionModel(),
      SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection& )),
      this,
      SLOT(lstUnitGroupsSelectionChanged( const QItemSelection&, const QItemSelection& ))
    );

  setCentralWidget(splitter);

  if ( unitLayout->count() > 0 ) {
    int lastIdx = settings->value( "last.group", 0 ).toInt();
    QModelIndex index = modelUnitGroups->index( lastIdx, 0 );
    lstUnitGroups->selectionModel()->select( index, QItemSelectionModel::Select );

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
    splitter->restoreState( settings->value( "splitter.size" ).toByteArray() );
  }

  about = new ConvertAbout;
  about->setWindowIcon( QIcon( ":/icon/icons/about.png" ) );
  about->strDate = CONVERT_DATE;
  strVersion = QString( CONVERT_VERSION );
  about->strVersion = strVersion;
  about->initialize();
  setWindowTitle( "SUConvert " + strVersion );
  about->setWindowTitle(tr("About") + " " + windowTitle());
  setWindowIcon( QIcon( ":/icon/icons/convert.png" ) );

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
    QVariant voriginalIndex = modelUnitGroups->itemFromIndex(lstUnitGroups->selectionModel()->selectedIndexes().at(0))->data();
    settings->setValue( "last.group", voriginalIndex.toInt() );

    if ( selectedGroup ) {
      Unit *u = (Unit*)qApp->focusWidget();
      int idx = selectedGroup->units.indexOf(u);
      settings->setValue( "last.focused", idx );
    }

    settings->setValue( "mainwindow.geom", saveGeometry() );
    settings->setValue( "mainwindow.state", saveState() );
    settings->setValue( "splitter.size", splitter->saveState() );

  }
  qApp->quit();
}

void Convert::actionPreviousTriggered() {
  int idx = lstUnitGroups->selectionModel()->selectedIndexes().at(0).row();
  if ( idx != 0 ) {
    QModelIndex index = modelUnitGroups->index( idx-1, 0 );
    lstUnitGroups->selectionModel()->select( index, QItemSelectionModel::ClearAndSelect );
  }
}

void Convert::actionNextTriggered() {
  int idx = lstUnitGroups->selectionModel()->selectedIndexes().at(0).row();
  if ( idx < unitGroups.size()-1 ) {
    QModelIndex index = modelUnitGroups->index( idx+1, 0 );
    lstUnitGroups->selectionModel()->select( index, QItemSelectionModel::ClearAndSelect );
  }
}

void Convert::actionAboutTriggered() {
  about->reset();
  about->show();
}

void Convert::setVisibleUnitGroup( int idx ) {
  // switch DynamicStackedLayout to the selected deck
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
