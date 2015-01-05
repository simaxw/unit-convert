#include <QtTest/QtTest>

#include <parser.hpp>
#include <main.hpp>

class TestSuiteConvert : public QObject {
  Q_OBJECT

  private:
    UnitXMLParser *p;

  private slots:
    void initTestCase() {
      p = new UnitXMLParser(qApp->applicationDirPath() + "/units.xml");
    }

    void initializeLoader() {
      QVERIFY( p->initialize() == true );
      QVERIFY( p->getUnitGroups().size() == 12 );
    }

    void guiTests() {
      Convert C;
      QVERIFY( C.initialize() == true );
      for ( int i=0; i<p->getUnitGroups().size(); i++ )
        QTest::keyClick( &C, Qt::Key_Up, Qt::ControlModifier );

      QTest::keyClicks( C.selectedGroup->units.at(0), "1" );
      QVERIFY( C.selectedGroup->units.at(1)->text() == "1000" );
      QVERIFY( C.selectedGroup->units.at(3)->text() == "264.172" );

    }

    void cleanupTestCase() {
      delete(p);
    }
};

QTEST_MAIN(TestSuiteConvert);
#include "testsuite.moc"
