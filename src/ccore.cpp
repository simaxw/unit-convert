#include "ccore.hpp"

bool CCore::convertUnits( UnitGroup *selectedGroup, Unit *u ) {
  if ( !selectedGroup || !u ) {
    return false;
  }

  QString txtInput = u->text();
  //Unit *u = qobject_cast<Unit*>(sender());
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
  return true;
}
