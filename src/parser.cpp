#include "parser.hpp"

bool UnitXMLParser::startElement(
    const QString& localName,
    const QXmlStreamAttributes& attr ) {

  docTree << localName;

  if ( localName == "collection" ) {
    UnitCollection *coll = new UnitCollection(
        attr.value("id").toString(),
        attr.value("label").toString(),
        attr.value("icon").toString());
    isCollection = true;
    currentCollection = coll;
  } else
  if ( localName == "group" ) {
    UnitGroup *g = new UnitGroup(
        attr.value("id").toString(),
        attr.value("label").toString());
    g->icon = attr.value("icon").toString();
    currentUnitGroup = g;
  } else
  if ( localName == "unit" ) {
    QString type = attr.value("type").toString();
    QString id = attr.value("id").toString();
    QString label = attr.value("label")
      .toString()
      .replace("_","&")
      .replace(QRegularExpression("(\\^(\\-?\\d+))"),"<sup>\\2</sup>");

    if ( type == "factor" ) {
      FactorUnit *fu = new FactorUnit(id, label, attr.value("value").toString().toDouble());
      currentUnit = fu;
    } else
    if ( type == "transform" ) {
      TransformUnit *tu = new TransformUnit(id, label,
          attr.value("fromSI").toString(),
          attr.value("toSI").toString());
      currentUnit = tu;
    } else
    if ( type == "formatted" ) {
      FormattedUnit *fu = new FormattedUnit(
          id, label, attr.value("value").toDouble(),
          attr.value("inputpattern").toString(),
          attr.value("outputpattern").toString());
      if ( attr.value("extendedinput").toString() == "true" ) {
        fu->isExtendedInput = true;
      }
      currentUnit = fu;
    }
  } else
  if ( localName == "subunit" ) {
    QString val = attr.value("value").toString();
    if ( !val.isEmpty() ) {
      ((FormattedUnit*)currentUnit)->subUnits.append(val.toInt());
    }
  }

  return true;
}

bool UnitXMLParser::endElement(
    const QString& localName
    ) {

  if ( !docTree.isEmpty() ) {
    docTree.pop();
  }

  if ( localName == "collection" ) {
    isCollection = false;
    collections.append(currentCollection);
  } else
  if ( localName == "group" ) {
    if ( currentUnitGroup ) {
      if ( isCollection && currentCollection )
        currentCollection->lstGroups.append(currentUnitGroup);
      else
        unitGroups.append(currentUnitGroup);
    }
  } else
  if ( localName == "unit" ) {
    if ( currentUnitGroup && currentUnit ) {
      currentUnitGroup->units.append(currentUnit);
    }
  }
  return true;
}

bool UnitXMLParser::characters( const QString& chars ) {
  if ( docTree.top() == "info" && currentUnit != 0 ) {
    currentUnit->info = chars;
  }
  return true;
}

bool UnitXMLParser::initialize() {
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
    else if (t == QXmlStreamReader::Characters && reader.isCDATA()) {
      characters(reader.text().toString());
    }
  }

  if (reader.hasError()) {
    errorMessage = reader.errorString();
    return false;
  }

  return true;
}
