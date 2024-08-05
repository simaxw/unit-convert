#include "menufactory.hpp"

bool MenuFactory::initialize() {
  QFile f(filename);
  if (!f.open(QIODevice::ReadOnly | QIODevice::Text)) {
    errorMessage = QString("Unable to open File: %1")
      .arg(f.errorString());
    return false;
  }
  QXmlStreamReader reader(&f);
  while (!reader.atEnd()) {
    QXmlStreamReader::TokenType t = reader.readNext();
    if (t == QXmlStreamReader::StartElement) {
      startElement(reader.name().toString(), reader.attributes());
    }
    else if (t == QXmlStreamReader::EndElement) {
      endElement(reader.name().toString());
    }
  }

  if (reader.hasError()) {
    return false;
  }

  return true;
}

bool MenuFactory::startElement(
    const QString& localName,
    const QXmlStreamAttributes& attr ) {
  docTree << localName;
  if ( localName == "menubar" ) {
    menubar = new QMenuBar;
    menubar->setObjectName(attr.value("id").toString());
  } else
  if ( localName == "menu" ) {
    QMenu *menu = new QMenu(
        attr.value("label").toString().replace( "~","&" ) );
    menu->setObjectName(attr.value("name").toString());
    currentMenu = menu;
  } else
  if ( localName == "action" ) {
    QAction *action = new QAction(nullptr);

    if ( !attr.value("slot").isEmpty() ) {
      connect( action, SIGNAL(triggered()),
          this, SLOT(handleActionTriggered()) );
      action->setData(attr.value("slot").toString());
    }

    if ( !attr.value("label").isEmpty() ) {
      action->setText(
          attr.value("label").toString().replace("~", "&") );
    }

    if ( !attr.value("icon").isEmpty() ) {
      action->setIcon(
          QIcon(":/icon/icons/" + attr.value("icon").toString()));
    }
        
    if (!attr.value("accel").isEmpty()) {
      action->setShortcut(QKeySequence(attr.value("accel").toString()));
    }

    if (!attr.value("help").isEmpty()) {
      action->setStatusTip(attr.value("help").toString());
    }

    if (attr.value("isToggle").toString() == "true") {
      action->setCheckable(true);
    }

    if (currentMenu) currentMenu->addAction(action);

    QString toolbarName = attr.value("toolbar").toString();
    if ( !toolbars.contains(toolbarName) ) {
      QToolBar *toolbar = new QToolBar;
      toolbar->setObjectName(toolbarName);
      toolbars[toolbarName] = toolbar;
    }

    toolbars[toolbarName]->addAction(action);
  }

  return true;
}

bool MenuFactory::endElement(const QString& localName) {
  docTree.pop();
  if ( localName == "menu" ) {
    menubar->addMenu(currentMenu);
  }
  return true;
}

void MenuFactory::handleActionTriggered() {
  QAction *A = qobject_cast<QAction*>(sender());
  if ( !A ) QMessageBox::critical(
      nullptr, tr("Error"), tr("Error calling Action"));

  QString slotName = A->data().toString();

  if ( A->isCheckable() ) {
    bool rc = slotContainer->metaObject()->invokeMethod(
        slotContainer,
        slotName.toUtf8().constData(),
        Qt::DirectConnection,
        Q_ARG(QAction*, A));

    if ( !rc ) {
      QMessageBox::critical( 0, tr("Error"),
          QString(
            tr("Could not toggle. \"%1\" not called.")).arg(slotName));
      return;
    }
  } else {
    int slotIndex = slotContainer->metaObject()->indexOfMethod(
        QMetaObject::normalizedSignature(slotName.toUtf8().constData())
        );
    if ( slotIndex < 0 ) {
      QMessageBox::critical( 0, tr("Error"),
          QString(
            tr("Error calling Action. Slot \"%1\" does not exist."))
          .arg(slotName));
      return;
    }
    QMetaMethod slot = slotContainer->metaObject()->method(slotIndex);
    slot.invoke( slotContainer, Qt::DirectConnection );
  }
}
