#ifndef __parser_hpp
#define __parser_hpp

#include <QDebug>
#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamAttributes>
#include <QStack>

#include "unit.hpp"

class UnitXMLParser {
  public:
    UnitXMLParser( const QString& _filename ) :
      filename(_filename),
      isCollection(false),
      currentUnitGroup(nullptr),
      currentUnit(nullptr),
      currentCollection(nullptr)
    {}
    bool initialize();

    QList<UnitCollection*> getUnitCollections() { return collections; }
    QList<UnitGroup*> getUnitGroups() { return unitGroups; }
    QString getErrorMessage() { return errorMessage; }

    bool startElement( const QString&, const QXmlStreamAttributes& );
    bool endElement( const QString&);
    bool characters( const QString& );

  private:
    QString filename;
    QString errorMessage;
    bool isCollection;
    QString current;
    QStack<QString> docTree;
    QList<UnitGroup*> unitGroups;
    QList<UnitCollection*> collections;
    UnitGroup *currentUnitGroup;
    Unit *currentUnit;
    UnitCollection *currentCollection;
};

#endif
