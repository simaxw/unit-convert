#include <QtTest/QtTest>

#include "unit.hpp"
#include "ccore.hpp"
#include "parser.hpp"

class TestSuiteConvert : public QObject {
  Q_OBJECT

  private:
    UnitXMLParser *p;
    CCore cc;

  private slots:
    void initTestCase() {
      p = new UnitXMLParser(qApp->applicationDirPath() + "/units.xml");
    }

    void initializeLoader() {
      QVERIFY( p->initialize() == true );
      QVERIFY( p->getUnitGroups().size() == 12 );
    }

    void checkVolumes() {
      UnitGroup *g = p->getUnitGroups().at(0);
      g->units.at(0)->setText("1");
      QVERIFY( cc.convertUnits( g, g->units.at(0) ) == true );
      QVERIFY( g->units.at(1)->text() == "1000" );
      QVERIFY( g->units.at(3)->text() == "264.172" );
      QVERIFY( g->units.at(4)->text() == "2113.38" );
    }

    void checkTemperatures() {
      UnitGroup *g = p->getUnitGroups().at(5);
      g->units.at(0)->setText("0");
      QVERIFY( cc.convertUnits( g, g->units.at(0) ) == true );
      QVERIFY( g->units.at(1)->text() == "-273.15" );
      QVERIFY( g->units.at(2)->text() == "-459.67" );
    }

    void cleanupTestCase() {
      delete(p);
    }
};

QTEST_MAIN(TestSuiteConvert);
#include "testsuite.moc"
