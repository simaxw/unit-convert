#ifndef __parser_hpp
#define __parser_hpp

#include <QFile>
#include <QXmlInputSource>
#include <QXmlDefaultHandler>
#include <QXmlSimpleReader>
#include <QStack>

#include "unit.hpp"

class UnitErrorHandler : public QXmlDefaultHandler {

  public:
    bool error(const QXmlParseException&);
    bool warning(const QXmlParseException&);
    bool fatalError(const QXmlParseException&);
    QString errorString() const;

  private:
    QString errorMessage;
};

class UnitContentHandler : public QXmlDefaultHandler {

  public:
    UnitContentHandler() :
      isCDATA(false), currentUnitGroup(0), currentUnit(0)
    {}
    bool startElement( const QString&, const QString&, const QString&, const QXmlAttributes& );
    bool endElement( const QString&, const QString&, const QString& );
    bool startCDATA();
    bool endCDATA();
    bool characters( const QString& );

    QList<UnitGroup*> getUnitGroups() { return unitGroups; }

  private:
    bool isCDATA;
    QString current;
    QStack<QString> docTree;
    QList<UnitGroup*> unitGroups;
    UnitGroup *currentUnitGroup;
    Unit *currentUnit;
};

class UnitXMLParser {

  public:
    UnitXMLParser( const QString& _fileName ) :
      contentHandler(0),
      errorHandler(0),
      fileName(_fileName)
    {}
    bool initialize();

    QList<UnitGroup*> getUnitGroups() { return contentHandler->getUnitGroups(); }
    QString getErrorMessage() { return errorHandler->errorString(); }

  private:
    UnitContentHandler *contentHandler;
    UnitErrorHandler *errorHandler;

    QString fileName;
};

#endif
