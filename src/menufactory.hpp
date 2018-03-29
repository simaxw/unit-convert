#ifndef __menufactory_hpp
#define __menufactory_hpp

#include <QDebug>
#include <QFile>
#include <QXmlInputSource>
#include <QXmlDefaultHandler>
#include <QXmlSimpleReader>
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

class MenuFactoryErrorHandler : public QXmlDefaultHandler {
  public:
    bool error(const QXmlParseException&);
    bool warning(const QXmlParseException&);
    bool fatalError(const QXmlParseException&);
    QString lastError() { return errorMessage; }

  private:
    QString errorMessage;
};

class MenuFactoryContentHandler : public QObject, public QXmlDefaultHandler {
  Q_OBJECT

  public:
    MenuFactoryContentHandler( QObject* _slotContainer ) :
      menubar(0),
      currentMenu(0),
      slotContainer(_slotContainer)
    {}
    bool startElement( const QString&, const QString&, const QString&,
        const QXmlAttributes& );
    bool endElement( const QString&, const QString&, const QString& );
    QMenuBar* getMenuBar() { return menubar; }
    QList<QToolBar*> getToolbars() { return toolbars.values(); }

  private:
    QStack<QString> docTree;
    QHash<QString,QToolBar*> toolbars;

    QMenuBar *menubar;
    QMenu *currentMenu;

    QObject *slotContainer;

  private slots:
    void handleActionTriggered();

};

class MenuFactory {
  public:
    MenuFactory( const QString& _filename, QObject *_slotContainer ) :
      filename(_filename),
      slotContainer(_slotContainer),
      errorHandler(0),
      contentHandler(0)
    {}
    bool initialize();
    QString lastError() { return errorMessage; }
    MenuFactoryContentHandler* getContentHandler() { return contentHandler; }

  private:
    QString filename;
    QObject *slotContainer;
    QString errorMessage;

    MenuFactoryErrorHandler *errorHandler;
    MenuFactoryContentHandler *contentHandler;

};

#endif
