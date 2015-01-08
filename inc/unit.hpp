#ifndef __unit_hpp
#define __unit_hpp

#include <QString>
#include <QList>
#include <QIcon>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDoubleValidator>
#include <QRegExpValidator>

class Unit : public QLineEdit {
  Q_OBJECT

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

    unsigned int column;
};

class FactorUnit : public Unit {
  Q_OBJECT

  public:
    FactorUnit( const QString& _id, const QString& _label, const double _value ) :
      Unit(Unit::FACTOR,_id,_label), value(_value)
    {
      setValidator( new QDoubleValidator );
    }

    double value;

    FactorUnit *clone() {
      FactorUnit *fu = new FactorUnit( id, label, value );
      fu->info = this->info;
      fu->lblInfo = this->lblInfo;
      fu->lblUnit = this->lblUnit;
      return fu;
    }
};

class TransformUnit : public Unit {
  Q_OBJECT

  public:
    TransformUnit( const QString& _id, const QString& _label, const QString& _fromSI, const QString& _toSI ) :
      Unit(Unit::TRANSFORM,_id,_label), fromSI(_fromSI), toSI(_toSI)
    {
      setValidator( new QDoubleValidator );
    }

    QString fromSI;
    QString toSI;

    TransformUnit *clone() {
      TransformUnit *tu = new TransformUnit( id, label, fromSI, toSI );
      tu->info = this->info;
      tu->lblInfo = this->lblInfo;
      tu->lblUnit = this->lblUnit;
      return tu;
    }
};

class FormattedUnit : public Unit {
  Q_OBJECT

  public:
    FormattedUnit( const QString& _id, const QString& _label, const double _value, const QString& _inputpattern, const QString& _outputpattern ) :
      Unit(Unit::FORMATTED,_id,_label), value(_value), inputpattern(_inputpattern), outputpattern(_outputpattern)
    {
      setValidator( new QRegExpValidator(QRegExp(inputpattern)) );
    }

    double value;
    QString inputpattern;
    QString outputpattern;
    QList<int> subUnits;

    FormattedUnit *clone() {
      FormattedUnit *fu = new FormattedUnit( id, label, value, inputpattern, outputpattern );
      fu->info = this->info;
      fu->lblInfo = this->lblInfo;
      fu->lblUnit = this->lblUnit;
      fu->subUnits = this->subUnits;
      return fu;
    }
};

class UnitGroup : public QWidget {
  Q_OBJECT

  public:
    UnitGroup( const QString& _id, const QString& _label ) :
      id(_id),
      label(_label),
      columns(1)
    {}

    void initialize( QLabel* );

    QString id;
    QString label;
    QString icon;
    QList<Unit*> units;

    QGridLayout *gridUnitFields;

    QList<Unit*> clone();
    unsigned int columns;
    QList< QList<Unit*> > additionalUnits;
};

#endif
