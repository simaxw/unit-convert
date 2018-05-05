#include "licensekey.hpp"

bool LicenseKey::initialize() {
  QVBoxLayout *vboxMain = new QVBoxLayout(this);

  scrTeaser = new QScrollArea(this);
  lblTeaser = new QLabel(this);
  lblTeaser->setText("All Your Base");
  lblTeaser->setAlignment( Qt::AlignTop | Qt::AlignLeft );
  lblTeaser->setWordWrap(true);
  lblTeaser->setStyleSheet("background:white; padding: 4px;");
  scrTeaser->setWidget(lblTeaser);
  scrTeaser->setWidgetResizable(true);

  QFile f(":/data/teaser.html");
  if ( f.open(QIODevice::ReadOnly) ) {
    QTextStream t(&f);
    lblTeaser->setText(t.readAll());
  } else {
    lblTeaser->setText( "<h1>Not Found</h1>" );
  }
  f.close();

  QWidget *widgetFormFields = new QWidget(this);
  formLayout = new QFormLayout(widgetFormFields);
  txtName = new QLineEdit(widgetFormFields);
  txtEMailAddress = new QLineEdit(widgetFormFields);

  formLayout->addRow( tr("Your &Name:"), txtName );
  formLayout->addRow( tr("&E-Mail Address:"), txtEMailAddress );

  widgetFormFields->setLayout(formLayout);

  QWidget *widgetControls = new QWidget(this);
  QHBoxLayout *layoutControls = new QHBoxLayout(widgetControls);

  btnShareware = new QPushButton(tr("Try &Shareware"), widgetControls);
  btnRegister = new QPushButton(tr("&Register"), widgetControls);
  btnCancel = new QPushButton(tr("&Cancel"), widgetControls);
  layoutControls->addWidget(btnShareware);
  layoutControls->addWidget(btnRegister);
  layoutControls->addWidget(btnCancel);

  vboxMain->addWidget(scrTeaser);
  vboxMain->addWidget(widgetFormFields);
  vboxMain->addWidget(widgetControls);

  setLayout(vboxMain);

  btnRegister->setEnabled(false);

  connect( txtName, SIGNAL(textChanged(const QString&)), this,
      SLOT(handleTextChanged(const QString&)) );
  connect( txtEMailAddress, SIGNAL(textChanged(const QString&)), this,
      SLOT(handleTextChanged(const QString&)) );
  connect( btnRegister, SIGNAL(clicked()), this, SLOT(handleRegister()) );

  connect( btnCancel, SIGNAL(clicked()), this, SLOT(handleCancel()));
  connect( btnShareware, SIGNAL(clicked()), this, SLOT(handleShareware()));

  return true;
}

void LicenseKey::handleRegister() {
  QList<QNetworkInterface> nics = QNetworkInterface::allInterfaces();
  QNetworkInterface *bindNic = nullptr;
  for ( QNetworkInterface nic : nics ) {
    if ( nic.hardwareAddress() != "00:00:00:00:00:00" ) {
      bindNic = &nic;
      break;
    }
  }

  if ( bindNic == nullptr ) {
    QMessageBox::critical( this, tr("Error"),
       tr("No suitable NIC found on this System to bind license key to"));
    return;
  }

  QCryptographicHash hash(QCryptographicHash::Sha256);
  hash.addData(txtName->text().toUtf8());
  hash.addData(txtEMailAddress->text().toUtf8());
  hash.addData(bindNic->hardwareAddress().toUtf8());

  qDebug() << hash.result().toHex();

}

void LicenseKey::handleTextChanged(const QString&) {
  if ( txtEMailAddress->text().isEmpty() || txtName->text().isEmpty() ) {
    btnRegister->setEnabled(false);
  } else {
    btnRegister->setEnabled(true);
  }
}

void LicenseKey::handleCancel() {
  done(1);
}

void LicenseKey::handleShareware() {
  done(0);
}
