#ifndef __ccore_hpp
#define __ccore_hpp

#include <QDebug>
#include <QRegExp>
#include <QRegExpValidator>
#include <QScriptEngine>
#include <QList>
#include <cmath>
#include "unit.hpp"

class CCore {
  public:
    CCore() {}
    bool convertUnits( QList<Unit*>, Unit* );

  private:
    QScriptEngine qse;
};

#endif
