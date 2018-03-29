#include "menufactory.hpp"

bool MenuFactoryErrorHandler::error( const QXmlParseException& e ) {
  errorMessage = QString( "Error: %1: Line %2, Column %3" ).
    arg(e.message()).arg(e.lineNumber()).arg(e.columnNumber());
  return false;
}

bool MenuFactoryErrorHandler::warning( const QXmlParseException& e ) {
  errorMessage = QString( "Warning: %1: Line %2, Column %3" ).
    arg(e.message()).arg(e.lineNumber()).arg(e.columnNumber());
  return true;
}

bool MenuFactoryErrorHandler::fatalError( const QXmlParseException& e ) {
  errorMessage = QString( "FATAL: %1: Line %2, Column %3" ).
    arg(e.message()).arg(e.lineNumber()).arg(e.columnNumber());
  return true;
}

bool MenuFactoryContentHandler::startElement(
    const QString&,
    const QString& localName,
    const QString&,
    const QXmlAttributes& attr ) {
  docTree << localName;
  if ( localName == "menubar" ) {
    menubar = new QMenuBar;
    menubar->setObjectName( attr.value("id") );
  } else
  if ( localName == "menu" ) {
    QMenu *menu = new QMenu( attr.value("label").replace( "~","&" ) );
    menu->setObjectName( attr.value("name") );
    currentMenu = menu;
  } else
  if ( localName == "action" ) {
    QAction *action = new QAction(0);

    connect( action, SIGNAL(triggered()), this, SLOT(handleActionTriggered()) );
    action->setData( attr.value("slot") );

    if ( !attr.value("label").isEmpty() ) {
      action->setText( attr.value("label").replace( "~","&" ) );
    }

    if ( !attr.value("icon").isEmpty() ) {
      action->setIcon( QIcon( ":/icon/icons/" + attr.value("icon") ) );
    }
        
    if ( !attr.value("accel").isEmpty() ) {
      action->setShortcut( QKeySequence( attr.value("accel") ) );
    }

    if ( !attr.value("help").isEmpty() ) {
      action->setStatusTip( attr.value("help") );
    }

    if ( currentMenu ) currentMenu->addAction(action);

    QString toolbarName = attr.value("toolbar");
    if ( !toolbars.contains(toolbarName) ) {
      QToolBar *toolbar = new QToolBar;
      toolbar->setObjectName(toolbarName);
      toolbars[toolbarName] = toolbar;
    }

    toolbars[toolbarName]->addAction(action);

  }

  return true;
}

bool MenuFactoryContentHandler::endElement(
    const QString&,
    const QString& localName,
    const QString& ) {
  docTree.pop();
  if ( localName == "menu" ) {
    menubar->addMenu( currentMenu );
  }
  return true;
}

void MenuFactoryContentHandler::handleActionTriggered() {
  QAction *A = qobject_cast<QAction*>(sender());
  if ( !A ) QMessageBox::critical( 0, tr("Error"), tr("Error calling Action") );

  QString slotName = A->data().toString();
  int slotIndex = slotContainer->metaObject()->indexOfMethod(
      QMetaObject::normalizedSignature(slotName.toUtf8().constData())
      );
  if ( slotIndex < 0 ) {
    QMessageBox::critical( 0, tr("Error"),
        QString(tr("Error calling Action. Slot %1 does not exist.")).arg(
          slotName) );
    return;
  }

  QMetaMethod slot = slotContainer->metaObject()->method(slotIndex);
  slot.invoke( slotContainer, Qt::DirectConnection );
}

bool MenuFactory::initialize() {
  QFile f( filename );
  QXmlInputSource *in = new QXmlInputSource( &f ); 

  contentHandler = new MenuFactoryContentHandler(slotContainer);
  errorHandler = new MenuFactoryErrorHandler;

  QXmlSimpleReader reader;
  reader.setContentHandler( contentHandler );
  reader.setErrorHandler( errorHandler );
  if ( !reader.parse( in ) ) {
    errorMessage = errorHandler->lastError();
    return false;
  }
  return true;
}
