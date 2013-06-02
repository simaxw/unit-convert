#include "parser.hpp"

bool UnitErrorHandler::error( const QXmlParseException& e ) {
  errorMessage = QString( "Error: %1: Line %2, Column %3" ).
    arg(e.message()).arg(e.lineNumber()).arg(e.columnNumber());
  return false;
}

bool UnitErrorHandler::warning( const QXmlParseException& e ) {
  errorMessage = QString( "Warning: %1: Line %2, Column %3" ).
    arg(e.message()).arg(e.lineNumber()).arg(e.columnNumber());
  return true;
}

bool UnitErrorHandler::fatalError( const QXmlParseException& e ) {
  errorMessage = QString( "FATAL: %1: Line %2, Column %3" ).
    arg(e.message()).arg(e.lineNumber()).arg(e.columnNumber());
  return true;
}

QString UnitErrorHandler::errorString() const {
  return errorMessage;
}

bool UnitContentHandler::startElement(
    const QString&,
    const QString& localName,
    const QString&,
    const QXmlAttributes& attr ) {
  docTree << localName;

  if ( localName == "group" ) {
    UnitGroup *g = new UnitGroup( attr.value("id"), attr.value("label") );
    QString iconPath = attr.value("icon");
    if ( !iconPath.isEmpty() ) {
      g->icon = new QIcon( iconPath );
    }
    currentUnitGroup = g;
  } else
  if ( localName == "unit" ) {
    QString type = attr.value("type");
    QString id = attr.value("id");
    QString label = attr.value("label");
    if ( type == "factor" ) {
      FactorUnit *fu = new FactorUnit( id,label, attr.value("value").toDouble() );
      currentUnit = fu;
    } else
    if ( type == "transform" ) {
      TransformUnit *tu = new TransformUnit( id,label, attr.value("fromSI"), attr.value("toSI") );
      currentUnit = tu;
    } else
    if ( type == "formatted" ) {
      FormattedUnit *fu = new FormattedUnit( id,label, attr.value("value").toDouble(), attr.value("pattern") );
      currentUnit = fu;
    }
  } else
  if ( localName == "info" ) {
  } else
  if ( localName == "subunits" ) {
  } else
  if ( localName == "subunit" ) {
    QString val = attr.value("value");
    ((FormattedUnit*)currentUnit)->subUnits.append(val.toDouble());
  }

  return true;
}

bool UnitContentHandler::endElement(
    const QString&,
    const QString& localName,
    const QString& ) {

  if ( !docTree.isEmpty() ) {
    docTree.pop();
  }

  if ( localName == "group" ) {
    unitGroups.append(currentUnitGroup);
  } else
  if ( localName == "unit" ) {
    currentUnitGroup->units.append(currentUnit);
  }
  return true;
}

bool UnitContentHandler::startCDATA() {
  isCDATA = true;
  return true;
}

bool UnitContentHandler::endCDATA() {
  isCDATA = false;
  return true;
}

bool UnitContentHandler::characters( const QString& chars ) {
  if ( docTree.top() == "info" && isCDATA && currentUnit != 0 ) {
    currentUnit->info = chars;
  }
  return true;
}

bool UnitXMLParser::initialize() {
  QFile f( fileName );
  QXmlInputSource *in = new QXmlInputSource( &f ); 

  contentHandler = new UnitContentHandler;
  errorHandler = new UnitErrorHandler;

  QXmlSimpleReader reader;
  reader.setContentHandler( contentHandler );
  reader.setErrorHandler( errorHandler );
  reader.setLexicalHandler( contentHandler );
  if ( !reader.parse( in ) ) {
    return false;
  }
  return true;
}
