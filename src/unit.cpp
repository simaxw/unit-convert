#include <unit.hpp>

Unit::Unit( UnitType _type, const QString& _id, const QString& _label ) :
  type(_type), id(_id), label(_label), lblInfo(0) {

  lblUnit = new QLabel( label );
  lblUnit->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
  lblUnit->setBuddy(this);
}

void Unit::focusInEvent( QFocusEvent* e ) {
  if ( lblInfo != 0 && !label.isEmpty() ) {
    lblInfo->setText("<html>"+info+"</html>");
  } else {
    lblInfo->setText(QString());
  }
  QLineEdit::focusInEvent(e);
}

void UnitGroup::initialize( QLabel *_lblInfo ) {
  QVBoxLayout *layout = new QVBoxLayout;
  setLayout(layout);

  QWidget *widgetUnitFields = new QWidget;
  gridUnitFields = new QGridLayout;
  widgetUnitFields->setLayout(gridUnitFields);

  int r = 0;
  foreach( Unit* u, units ) {
    u->lblInfo = _lblInfo;
    gridUnitFields->addWidget( u->lblUnit, r, 0 );
    gridUnitFields->addWidget( u, r, 1 );
    r++;
  }

  layout->addWidget(widgetUnitFields);
  layout->addStretch(1);
}

QList<Unit*> UnitGroup::clone() {
  QList<Unit*> lstUnits;
  int r = 0;
  foreach( Unit* u, units ) {
    switch( u->type ) {
      case Unit::FACTOR: {
        FactorUnit *fu = ((FactorUnit*)u)->clone();
        lstUnits << fu;
        gridUnitFields->addWidget( fu, r, 2 );
        break;
                         }
      case Unit::TRANSFORM: {
        TransformUnit *tu = ((TransformUnit*)u)->clone();
        lstUnits << tu;
        gridUnitFields->addWidget( tu, r, 2 );
        break;
                            }
      case Unit::FORMATTED: {
        FormattedUnit *fu = ((FormattedUnit*)u)->clone();
        lstUnits << fu;
        gridUnitFields->addWidget( fu, r, 2 );
        break;
                            }
      default:
        break;
    }
    r++;
  }

  return lstUnits;


}
