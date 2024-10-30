#ifndef __menufactory_hpp
#define __menufactory_hpp

#include <QDebug>
#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamAttributes>
#include <QStack>
#include <QMenuBar>
#include <QToolBar>
#include <QMenu>
#include <QAction>
#include <QIcon>
#include <QKeySequence>
#include <QHash>
#include <QMessageBox>
#include <QMetaObject>
#include <QMetaMethod>

class MenuFactory : public QObject {
  Q_OBJECT

  public:
    MenuFactory( const QString& _filename, QObject *_slotContainer ) :
      actionIndex(0),
      filename(_filename),
      slotContainer(_slotContainer)
    {}
    QString translateMenuItem(int);
    bool initialize();
    QString lastError() { return errorMessage; }
    QMenuBar* getMenuBar() { return menubar; }
    QList<QToolBar*> getToolbars() { return toolbars.values(); }

  private:
    int actionIndex;
    bool startElement(const QString&, const QXmlStreamAttributes&);
    bool endElement(const QString&);
    QString filename;
    QObject *slotContainer;
    QString errorMessage;
    QStack<QString> docTree;
    QHash<QString,QToolBar*> toolbars;
    QMenuBar *menubar;
    QMenu *currentMenu;
    QStringList menuItems;

  private slots:
    void handleActionTriggered();
};

#endif
