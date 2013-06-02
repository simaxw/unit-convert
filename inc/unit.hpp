#ifndef __unit_hpp
#define __unit_hpp

#include <QString>
#include <QList>
#include <QIcon>
#include <QLineEdit>
#include <QLabel>

class Unit {

  public:
    enum UnitType { FACTOR, TRANSFORM, FORMATTED, UNDEFINED };

    Unit( UnitType _type, const QString& _id, const QString& _label ) :
      type(_type), id(_id), label(_label)
    {
      lblUnit = new QLabel( _label );
      txtUnit = new QLineEdit;
      lblUnit->setBuddy(txtUnit);
    }

    UnitType type;
    QString id;
    QString label;

    QLineEdit *txtUnit;
    QLabel *lblUnit;

    QString info;

    QString toString() {
      return "Unit id=" + id + ", label=" + label;
    }
};

class FactorUnit : public Unit {

  public:
    FactorUnit( const QString& _id, const QString& _label, const double _value ) :
      Unit(Unit::FACTOR,_id,_label), value(_value)
    {}

    double value;
};

class TransformUnit : public Unit {

  public:
    TransformUnit( const QString& _id, const QString& _label, const QString& _fromSI, const QString& _toSI ) :
      Unit(Unit::TRANSFORM,_id,_label), fromSI(_fromSI), toSI(_toSI)
    {}

    QString fromSI;
    QString toSI;

};

class FormattedUnit : public Unit {

  public:
    FormattedUnit( const QString& _id, const QString& _label, const double _value, const QString& _pattern ) :
      Unit(Unit::FORMATTED,_id,_label), value(_value), pattern(_pattern)
    {}

    double value;
    QString pattern;
    QList<double> subUnits;

};

class UnitGroup {

  public:
    UnitGroup( const QString& _id, const QString& _label ) :
      id(_id),
      label(_label)
    {}
    QString id;
    QString label;
    QIcon *icon;
    QList<Unit*> units;

    QString toString() { return "Unit Group: " + id + " (" + label + ")"; }
};

#endif
