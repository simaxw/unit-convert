#include "main.hpp"

bool Convert::initialize() {

  bool rc = QResource::registerResource( qApp->applicationDirPath() + "/data.rcc" );
  if ( !rc ) {
    QMessageBox::critical( this, tr("Error"), tr("Data file data.rcc missing"));
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

    foreach ( Unit *u, g->units ) {
      connect( u, SIGNAL(textEdited(const QString&)),
          this, SLOT(txtUnitsTextEdited(const QString&)));
    }

    QStandardItem *item = new QStandardItem( g->label );
    item->setIcon( QIcon(g->icon) );
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
  connect( ui.actionPrevious, SIGNAL(triggered()), this, SLOT(actionPreviousTriggered()) );
  connect( ui.actionNext, SIGNAL(triggered()), this, SLOT(actionNextTriggered()) );
  connect( ui.actionAbout, SIGNAL(triggered()), this, SLOT(actionAboutTriggered()) );

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

  return true;
}

void Convert::lstUnitGroupsSelectionChanged( const QItemSelection& selected, const QItemSelection& ) {
  int idx = selected.indexes().at(0).row();
  if ( idx > unitLayout->count() ) {
    return;
  }
  setVisibleUnitGroup(idx);
}

void Convert::txtUnitsTextEdited( const QString& txtInput  ) {
  if ( !selectedGroup ) {
    return;
  }

  Unit *u = qobject_cast<Unit*>(sender());
  double siUnitValue = 0;
  double inputValue = u->text().toDouble();
  switch( u->type ) {
    case Unit::FACTOR:
      siUnitValue = inputValue * ((FactorUnit*)u)->value;
      break;
    case Unit::TRANSFORM:
      qse.globalObject().setProperty( "x", inputValue );
      siUnitValue = qse.evaluate( ((TransformUnit*)u)->fromSI ).toNumber();
      break;
    case Unit::FORMATTED:
      {
        FormattedUnit *fu = (FormattedUnit*)u;
        QRegExp r = ((QRegExpValidator*)fu->validator())->regExp();
        r.indexIn( txtInput );

        int i = 1;
        inputValue = 0;
        foreach ( double subUnit, fu->subUnits ) {
          inputValue += subUnit * r.cap(i).toDouble();
          i++;
        }
        inputValue += r.cap(i).toDouble();
        siUnitValue = inputValue * fu->value;
      }
      break;
    default:
      break;
  }

  foreach ( Unit *tu, selectedGroup->units ) {
    if ( tu == u ) {
      continue;
    }
    switch( tu->type ) {
      case Unit::FACTOR:
        tu->setText( QString::number(siUnitValue / ((FactorUnit*)tu)->value) );
        break;
      case Unit::TRANSFORM:
        qse.globalObject().setProperty( "x", siUnitValue );
        tu->setText( qse.evaluate(((TransformUnit*)tu)->toSI).toString() );
        break;
      case Unit::FORMATTED:
        {
          FormattedUnit *fu = (FormattedUnit*)tu;
          int result = round(siUnitValue / fu->value);

          QList<int> lstPatternValues;
          int subResult = 0;
          foreach ( int subUnit, fu->subUnits ) {
            subResult = result / subUnit;
            lstPatternValues << subResult;
            result -= (subResult * subUnit);
          }
          lstPatternValues << result;

          QString strRes = fu->outputpattern;
          foreach ( int val, lstPatternValues ) {
            strRes = strRes.arg(val);
          }
          fu->setText(strRes);
        }
        break;
      default:
        break;
    }
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
    int idx = ui.lstUnitGroups->selectionModel()->selectedIndexes().at(0).row();
    settings->setValue( "last.group", idx );

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

