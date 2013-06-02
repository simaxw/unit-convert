#include "main.hpp"

/*
Convert::Convert() {

  Unit *u = new Unit(Unit::UNDEFINED,"gen", "Generic");
  TransformUnit *tu = new TransformUnit("tunit", "TransformUnit", "A", "B");
  FactorUnit *fu = new FactorUnit ("funit", "FactorUnit", 42.4);
  FormattedUnit *fmu = new FormattedUnit( "fmu", "Formatted Unit", "(\\d+)-(\\d+)");

  QList<Unit*> lst;
  lst << u << fu << tu << fmu;

  foreach ( Unit *u, lst ) {
    switch(u->type) {
      case Unit::TRANSFORM:
        {
        TransformUnit *tu = (TransformUnit*)u;
        qDebug() << "ToSI: " << tu->toString();
        }
        break;
      case Unit::FACTOR:
        {
        FactorUnit *fu = (FactorUnit*)u;
        qDebug() << "Factor: " << fu->toString();
        }
        break;
      case Unit::FORMATTED:
        {
        FormattedUnit *fmu = (FormattedUnit*)u;
        qDebug() << "Format Pattern: " << fmu->toString();
        }
        break;
      case Unit::UNDEFINED:
        qDebug() << "Undefined";
        break;
    }
  }
  //qDebug() << "INFO: " << typeid(u).name();

  se.globalObject().setProperty("x",2);
  QScriptValue val = se.evaluate("1+x*4");
  qDebug() << val.toInteger();
  //initialize();
}
*/

bool Convert::initialize() {
  UnitXMLParser p( qApp->applicationDirPath() + "/units.xml" );

  if ( !p.initialize()) {
    QMessageBox::critical( this, tr("Error"), p.getErrorMessage() );
    return false;
  }

  int i=1;
  foreach( UnitGroup* g, p.getUnitGroups() ) {
    qDebug() << (i++) << g->label;
    foreach ( Unit* u, g->units ) {
      qDebug() << "\tUnit: " << u->label << " // " << u->info;
    }
  }

  return true;

}

void Convert::convertEditChanged( QString ) {
  /*
    QLineEdit *lineEdit = qobject_cast<QLineEdit*>( sender() );
    if ( lineEdit == 0 ) {
        return;
    }

    QString group = lineEdit->objectName().section( '_', 1, 1 );
    if ( group.isEmpty() ) {
            return;
    }

    QMap < QLineEdit*, QMap < QString, QString > > units = groups[group];

    QString SIValue;
    QMap < QString, QString > attribs = units[ lineEdit ];
    QString type = attribs[ "type" ];

    if ( type == "factor" ) {
        SIValue = QString::number( attribs[ "value" ].toDouble() * str.toDouble() );
    } else
    if ( type == "transform" ) {
        SIValue = calc( attribs[ "fromSI" ].arg( str ) );
    }

    foreach( QLineEdit *E, QList<QLineEdit*>( units.keys() ) ) {
        if ( E == lineEdit ) {

            continue;
        } else {
            
            QMap < QString, QString > attribs = units[E];
            QString type = attribs[ "type" ];

            if ( type == "factor" ) {
                E->setText( QString::number( SIValue.toDouble() / attribs[ "value"].toDouble() ) );
            } else
            if ( type == "transform" ) {
                E->setText( calc( attribs[ "toSI" ].arg( SIValue ) ) );
            }
        }
    }

    if ( group == "dist" ) {
        ui.special_txt_dist_feetin->setText(
                getFeetInchesFormat( ui.txt_dist_inches->text().toDouble() )
                );
    }
    */
}

void Convert::specialtxtFeetEdited( QString ) {
  /*
    const QRegExpValidator *validator;

    if ( (validator = qobject_cast<const QRegExpValidator*>(
                    ui.special_txt_dist_feetin->validator()
                    ) ) == 0 ) {
        return;
    }

    QRegExp rgxFeet = validator->regExp();

  // execute regular expression
  rgxFeet.indexIn( str );

  // save second capture (the inches)
  double cap2;

  // determine slash-position if user enters eg 22-1/5
  int slashPos =  rgxFeet.cap(2).indexOf( "/" );

  // proceed only if slash is neither first nor at last position
  if ( slashPos > 0 && slashPos < rgxFeet.cap(2).length()-1 ) {

    // split and do the math
    QStringList list = rgxFeet.cap(2).split("/");
    cap2 = list[0].toDouble() / list[1].toDouble();

  } else {

    // otherwise copy the second capture to cap2
    cap2 = rgxFeet.cap(2).toDouble();
  }

  double inches = (rgxFeet.cap(1).toDouble() * 12) + cap2;
  double cm = inches * 2.54;
  double m = cm * 1e-2;
  double km = m * 1e-3;
  double mm = m * 1e3;

  ui.txt_dist_meter->setText( QString::number( inches / 12 * 0.3048 ) );
  ui.txt_dist_centimeter->setText( QString::number( inches / 12 * 0.3048 * 100 ) );
    ui.txt_dist_millimeter->setText( QString::number( mm ) );
    ui.txt_dist_kilometer->setText( QString::number( km ) );

    ui.txt_dist_feet->setText( QString::number( inches / 12 ) );

  ui.txt_dist_millimeter->setText( QString::number( mm ) );
  ui.txt_dist_kilometer->setText( QString::number( km ) );

  ui.txt_dist_inches->setText( QString::number( inches ) );
  ui.txt_dist_miles->setText( QString::number( inches / 5280 / 12 ) );

  */
}

// Actions
void Convert::about() {
  aboutBox.reset();
  aboutBox.exec();
}

void Convert::quit() {
  saveSettings();
  qApp->quit();
}


// Focushandler
void Convert::focusChangeHandler( QWidget*, QWidget* ) {
  /*
    if ( qobject_cast<QLineEdit*>( now ) == 0 ) {
        return;
    }

    currentFocusDesc = now->objectName();
  ui.lblDesc->setText( descList[currentFocusDesc] );
  */
}

void Convert::closeEvent( QCloseEvent* ) {
  //saveSettings();
}

QString Convert::calc( QString ) {
  /*
    QStringList list = str.split( " " );
    if ( list.size() % 2 == 0 ) {
        return 0;
    }

    double A = list[0].toDouble(), B;
    char op;

    for ( int i=1; i<list.size(); i+=2 ) {
        op = list[i].at(0).toLatin1();
        B = list[i+1].toDouble();

        switch ( op ) {
            case '+':
                A = A + B;
                break;
            case '-':
                A = A - B;
                break;
            case '*':
                A = A * B;
                break;
            case '/':
                A = A / B;
                break;
        }
    }

    return QString::number( A );
    */
  return QString();
}

/** Main Initialization Point to be called by all Constructors
 * @return void
 */
  /*
void Convert::initialize() {

  // construct QSettings object
  settings = new QSettings( "settings.ini", QSettings::IniFormat, this );
  settings->beginGroup( "general" );

  ui.setupUi(this);

    // restore geometry and selected page from QSettings object
  setGeometry( settings->value( "geometry", QRect( 100, 100, 400, 450 ) ).toRect() );
  //ui.tabwidgetConvertUnitSelection->setCurrentIndex( settings->value( "page", 0 ).toInt() );

  settings->endGroup();

  // description map
    loadDesc();

    // validators
    loadValidators();

  installSlots();
    setup();
}
    */

/** installs the slots
 */
  void Convert::installSlots() {
    /*
    foreach( QLineEdit *lineEdit, findChildren<QLineEdit*>( QRegExp( "^txt_" ) ) ) {
      connect( lineEdit, SIGNAL( textEdited( QString ) ), this, SLOT( convertEditChanged( QString ) ) );
    }

    //connect( ui.special_txt_dist_feetin, SIGNAL( textEdited( QString ) ),
      //  this, SLOT( specialtxtFeetEdited( QString ) ) );

    // actions (menubar)
    connect( ui.actionAbout, SIGNAL( triggered() ), this, SLOT( about() ) );
    connect( ui.actionQuit, SIGNAL( triggered() ), this, SLOT( quit() ) );

    // focusmanager
    connect(
        qApp, SIGNAL( focusChanged( QWidget*, QWidget* ) ),
        this, SLOT( focusChangeHandler( QWidget*, QWidget* ) )
        );
        */
  }

void Convert::loadDesc() {
  /*
    QFile f( ":/info/info.xml" );

    if ( !f.open( QIODevice::ReadOnly ) ) {
        return;
    }

    QDomDocument doc;

    if ( !doc.setContent( &f ) ) {
        return;
    }
    f.close();

    QDomNodeList items = doc.documentElement().childNodes();

    QDomNode N;
    QDomElement E;
    QString id;

    QDomCDATASection cdataDesc;
    QString desc;

    for ( unsigned int i=0; i<items.length(); i++ ) {
        N = items.item( i );
        if ( N.isElement() ) {
            E = N.toElement();
            id = E.attribute( "id" );

            N = E.firstChild();
            if ( N.isCDATASection() ) {
                cdataDesc = N.toCDATASection();
                desc = cdataDesc.nodeValue();
                descList[id] = desc;
            } // N.isCDATASection
        } // N.isElement
    } // for
    */
}

void Convert::loadValidators() {
  /*
    QFile f( ":/info/validator-setup.xml" );

    if ( !f.open( QIODevice::ReadOnly ) ) {
        return;
    }

    QDomDocument doc;

    if ( !doc.setContent( &f ) ) {
        return;
    }

    f.close();

    QDomNodeList items = doc.documentElement().childNodes();
    QDomElement E;
    QDomNode N;

    QString tagName, binding, pattern;

    for ( unsigned int i=0; i<items.length(); i++ ) {
        N = items.item( i );
        if ( N.isElement() ) {
            E = N.toElement();
            binding = E.attribute( "binding" );

            // find the QLineEdit identified by binding in the object tree
            QLineEdit *L = findChild<QLineEdit*>( binding );
            if ( L == 0 ) {
                continue;
            }

            tagName = E.tagName();
            if ( tagName == "regex" ) {
                pattern = E.attribute( "pattern" );
                QRegExpValidator *rgxValidator = new QRegExpValidator( QRegExp( pattern ), L );
                L->setValidator( rgxValidator );
            } else
            if ( tagName == "double" ) {
                QDoubleValidator *dblValidator = new QDoubleValidator( L );
                L->setValidator( dblValidator );
            } // if tagName
        } // if N.isElement()
    } // for
    */
}

void Convert::setup() {
  /*
    QFile f( ":/info/setup.xml" );

    if ( !f.open( QIODevice::ReadOnly ) ) {
        return;
    }

    QDomDocument doc;

    if ( !doc.setContent( &f ) ) {
        return;
    }

    f.close();

    QDomNodeList nodes = doc.elementsByTagName( "group" );

    for ( unsigned int i=0; i<nodes.length(); i++ ) {
        QDomElement groupElement = nodes.item( i ).toElement();

        QDomNodeList unitNodeList = groupElement.elementsByTagName( "unit" );
        QMap < QLineEdit*, QMap < QString, QString > > mapUnits;

        for ( unsigned int k=0; k<unitNodeList.length(); k++ ) {
            QDomElement unitElement = unitNodeList.item( k ).toElement();
            QLineEdit *lineEdit = findChild<QLineEdit*>( unitElement.attribute( "id" ) );

            QDomNamedNodeMap nodemap = unitElement.attributes();
            QMap < QString, QString > mtrans;

            for ( uint n=0; n<nodemap.length(); n++ ) {
                QDomNode N = nodemap.item( n );
                mtrans[ N.nodeName() ] = N.nodeValue();
            }

            if ( lineEdit != 0 ) {
                mapUnits[lineEdit] = mtrans;
            }
        }

        groups[ groupElement.attribute( "id" ) ] = mapUnits;
    }
    */
}

// Save Settings on Exit
void Convert::saveSettings() {
  /*
  settings->beginGroup( "general" );
  settings->setValue( "geometry", geometry() );
  //settings->setValue( "page", ui.tabwidgetConvertUnitSelection->currentIndex() );
  settings->endGroup();
  settings->sync();
  */
}

QString Convert::getFeetInchesFormat( double ) {
  /*
  int feet = (int)(in) / 12;
  double inches = ( (int)(in) % 12 ) + ( in - (int)in );
  return QString::number( feet ) + "' - " + QString::number( inches ) + "\"";
  */
  return QString();
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

  return 0; //app.exec();

  /*

    app.setOrganizationName("Wizardworx");
    app.setOrganizationDomain("wizardworx.com");
    app.setApplicationName("unitconvert");

    //const QString version = "V0.8 [dev]";

  UnitConvert uc;
  //uc.setWindowTitle( "UnitConvert " + version );
  //uc.show();

  return 0;
  //return app.exec();
  */
}
