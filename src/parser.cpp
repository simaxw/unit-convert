#include "parser.hpp"

bool UnitErrorHandler::error( const QXmlParseException& e ) {
  errorMessage = "ERROR: " + e.message() + ": Line: " + e.lineNumber();
  return false;
}

bool UnitErrorHandler::warning( const QXmlParseException& e ) {
  errorMessage = "WARNING: " + e.message() + ": Line: " + e.lineNumber();
  return true;
}

bool UnitErrorHandler::fatalError( const QXmlParseException& e ) {
  errorMessage = "FATAL: " + e.message() + ": Line: " + e.lineNumber();
  return true;
}

QString UnitErrorHandler::errorString() const {
  return errorMessage;
}

bool UnitContentHandler::startElement(
    const QString&,
    const QString& localName,
    const QString& qualifiedName,
    const QXmlAttributes& ) {

  qDebug() << "Start Element triggered: " << qualifiedName << ", " << localName;
  return true;
}

bool UnitXMLParser::initialize() {
  QFile f( fileName );
  QXmlInputSource *in = new QXmlInputSource( &f ); 

  UnitContentHandler *contentHandler = new UnitContentHandler;
  UnitErrorHandler *errorHandler = new UnitErrorHandler;

  QXmlSimpleReader reader;
  reader.setContentHandler( contentHandler );
  reader.setErrorHandler( errorHandler );
  if ( !reader.parse( in ) ) {
    qDebug() << "Error parsing file: " << errorHandler->errorString();
    return false;
  }
  return true;
}
