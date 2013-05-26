#ifndef __parser_hpp
#define __parser_hpp

#include <QFile>
#include <QXmlInputSource>
#include <QXmlDefaultHandler>
#include <QXmlSimpleReader>
#include <QDebug>

class Unit {

  public:
    enum _type { FACTOR, TRANSFORM };
    _type type;
    QString id;
    QString desc;
    double value;
    QString fromSI;
    QString toSI;
    QList<double> lstSubUnits;
};

class UnitGroup {

  public:
    UnitGroup( const QString& _id, const QString& _desc ) :
      id(_id),
      desc(_desc)
    {}
    QString id;
    QString desc;
    QList<Unit> units;
};

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
    bool startElement( const QString&, const QString&, const QString&, const QXmlAttributes& );

};

class UnitXMLParser {

  public:
    UnitXMLParser( const QString& _fileName ) :
      fileName(_fileName)
    { initialize(); }

  private:
    bool initialize();

    QString fileName;
};

#endif
