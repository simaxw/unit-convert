#include "unit.hpp"

Unit::Unit( UnitType _type, const QString& _id, const QString& _label ) :
  type(_type),
  id(_id),
  label(_label),
  lblDeviation(0),
  lblInfo(0),
  column(1),
  paintResult(false),
  isExtendedInput(false)
{
  lblUnit = new QLabel( label );
  lblUnit->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
  lblUnit->setBuddy(this);
}

void Unit::paintEvent(QPaintEvent *e) {
  QLineEdit::paintEvent(e);

  if ( text().isEmpty() ) return;
  if ( type == FORMATTED ) return;

  bool ok = false;
  text().toDouble(&ok);
  if ( ok ) return;

  if ( !paintResult ) return;

  QPainter painter(this);
  QRect r = e->rect();
  painter.setPen( QColor(150,150,150) );
  QFontMetrics fm(font());
  int endPos = fm.horizontalAdvance(text());
  result = qse.evaluate(text()).toString();
  painter.drawText( endPos+10, r.height()-(fm.height()/2) + COFFSET, "= " + result );
}

void Unit::focusInEvent( QFocusEvent* e ) {
  if ( !lblInfo ) return;
  if ( !label.isEmpty() ) {
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

QList<Unit*> UnitGroup::clone( bool showDiffLabel ) {
  columns++;
  gridcolumns+=2;
  QList<Unit*> lstUnits;
  int r = 0;
  foreach( Unit* u, units ) {
    switch( u->type ) {
      case Unit::FACTOR: {
        FactorUnit *fu = ((FactorUnit*)u)->clone();
        fu->column = columns;
        lstUnits << fu;
        gridUnitFields->addWidget( fu->lblDeviation, r, gridcolumns );
        fu->lblDeviation->setVisible(showDiffLabel);
        fu->lblDeviation->setFont(QFont("sans serif",9));
        gridUnitFields->addWidget( fu, r, gridcolumns+1 );
        break;
        }
      case Unit::TRANSFORM: {
        TransformUnit *tu = ((TransformUnit*)u)->clone();
        tu->column = columns;
        lstUnits << tu;
        gridUnitFields->addWidget( tu->lblDeviation, r, gridcolumns );
        tu->lblDeviation->setVisible(showDiffLabel);
        tu->lblDeviation->setFont(QFont("sans serif",9));
        gridUnitFields->addWidget( tu, r, gridcolumns+1 );
        break;
        }
      case Unit::FORMATTED: {
        FormattedUnit *fu = ((FormattedUnit*)u)->clone();
        fu->column = columns;
        lstUnits << fu;
        gridUnitFields->addWidget( fu->lblDeviation, r, gridcolumns );
        fu->lblDeviation->setVisible(showDiffLabel);
        fu->lblDeviation->setFont(QFont("sans serif",9));
        gridUnitFields->addWidget( fu, r, gridcolumns+1 );
        break;
        }
      default:
        break;
    }
    r++;
  }
  additionalUnits << lstUnits;
  return lstUnits;
}

void FormattedUnit::paintEvent(QPaintEvent *e) {
  QLineEdit::paintEvent(e);

  if ( text().isEmpty() ) return;
  if ( !isExtendedInput ) return;

  QRegularExpression r(inputpattern);
  QRegularExpressionMatch m = r.match(text());

  QString eval = m.captured(1) + " * " + QString::number(subUnits[0]) + " + " + m.captured(2);
  if ( !m.captured(3).isEmpty() ) {
    eval += " + (" + m.captured(3) + ")";
  }

  if ( !paintResult ) return;

  QPainter painter(this);
  QRect rect = e->rect();
  painter.setPen( QColor(150,150,150) );
  QFontMetrics fm(font());
  int endPos = fm.horizontalAdvance(text());
  result = qse.evaluate(eval).toString();
  painter.drawText( endPos+10, rect.height()-(fm.height()/2) + COFFSET, "= " + result );
}
