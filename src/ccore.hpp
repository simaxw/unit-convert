#ifndef __ccore_hpp
#define __ccore_hpp

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionValidator>
#include <QJSEngine>
#include <QList>
#include <cmath>
#include "unit.hpp"

class CCore {
  public:
    CCore() {}
    bool convertUnits( QList<Unit*>, Unit* );

  private:
    QJSEngine qse;
};

#endif
