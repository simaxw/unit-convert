/********************************************************************************
** Form generated from reading UI file 'aboutbox_convert.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTBOX_CONVERT_H
#define UI_ABOUTBOX_CONVERT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_aboutbox
{
public:
    QVBoxLayout *vboxLayout;
    QLabel *lblAbout;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;

    void setupUi(QDialog *aboutbox)
    {
        if (aboutbox->objectName().isEmpty())
            aboutbox->setObjectName(QStringLiteral("aboutbox"));
        aboutbox->resize(481, 351);
        QIcon icon;
        icon.addFile(QStringLiteral(":/mainicon/img/light_bulb.png"), QSize(), QIcon::Normal, QIcon::Off);
        aboutbox->setWindowIcon(icon);
        vboxLayout = new QVBoxLayout(aboutbox);
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout->setContentsMargins(9, 9, 9, 9);
#endif
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        lblAbout = new QLabel(aboutbox);
        lblAbout->setObjectName(QStringLiteral("lblAbout"));
        lblAbout->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        vboxLayout->addWidget(lblAbout);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okButton = new QPushButton(aboutbox);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setDefault(true);
        okButton->setFlat(false);

        hboxLayout->addWidget(okButton);


        vboxLayout->addLayout(hboxLayout);


        retranslateUi(aboutbox);
        QObject::connect(okButton, SIGNAL(clicked()), aboutbox, SLOT(accept()));

        QMetaObject::connectSlotsByName(aboutbox);
    } // setupUi

    void retranslateUi(QDialog *aboutbox)
    {
        aboutbox->setWindowTitle(QApplication::translate("aboutbox", "About", 0));
        lblAbout->setText(QString());
        okButton->setText(QApplication::translate("aboutbox", "&OK", 0));
    } // retranslateUi

};

namespace Ui {
    class aboutbox: public Ui_aboutbox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTBOX_CONVERT_H
