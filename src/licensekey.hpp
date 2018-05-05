#include <QDialog>
#include <QLabel>
#include <QTextBrowser>
#include <QUrl>
#include <QScrollArea>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkInterface>
#include <QCryptographicHash>
#include <QDebug>

class LicenseKey : public QDialog {
  Q_OBJECT

  public:
    LicenseKey(QWidget *parent) : QDialog(parent) {}
    bool initialize();

  private:
    QTextBrowser *browser;
    QScrollArea *scrTeaser;
    QLabel *lblTeaser;
    QFormLayout *formLayout;
    QLineEdit *txtName;
    QLineEdit *txtEMailAddress;
    QPushButton *btnShareware;
    QPushButton *btnRegister;
    QPushButton *btnCancel;
    QNetworkAccessManager *nam;

  private slots:
    void handleRegister();
    void handleTextChanged(const QString&);
    void handleCancel();
    void handleShareware();
};
