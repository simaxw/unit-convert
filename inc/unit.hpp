#ifndef __unit_hpp
#define __unit_hpp

#include <QString>
#include <QList>
#include <QIcon>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>

class Unit : public QLineEdit {
  public:
    enum UnitType { FACTOR, TRANSFORM, FORMATTED, UNDEFINED };
    Unit( UnitType, const QString&, const QString& );

    void focusInEvent(QFocusEvent*);

    UnitType type;

    QString id;
    QString label;

    QLabel *lblUnit;

    QString info;
    QLabel *lblInfo;
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

class UnitGroup : public QWidget {
  public:
    UnitGroup( const QString& _id, const QString& _label ) :
      id(_id),
      label(_label)
    {}

    void initialize( QLabel* );

    QString id;
    QString label;
    QIcon icon;
    QList<Unit*> units;
};

#endif
