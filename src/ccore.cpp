#include "ccore.hpp"

bool CCore::convertUnits( QList<Unit*> lstUnits, Unit *u ) {
  if ( lstUnits.size() < 1 || !u ) {
    return false;
  }

  QString txtInput = u->text();
  double siUnitValue = 0;
  double inputValue = qse.evaluate( u->text() ).toNumber();
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

  foreach ( Unit *tu, lstUnits ) {
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
