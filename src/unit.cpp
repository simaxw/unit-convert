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
  QGridLayout *gridUnitFields = new QGridLayout;
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
