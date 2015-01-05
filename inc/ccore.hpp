#ifndef __ccore_hpp
#define __ccore_hpp

#include <QRegExp>
#include <QRegExpValidator>
#include <QScriptEngine>
#include <cmath>
#include "unit.hpp"

class CCore {
  public:
    CCore() {}
    bool convertUnits( UnitGroup*, Unit* );

  private:
    QScriptEngine qse;
};

#endif
