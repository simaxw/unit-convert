/********************************************************************************
** Form generated from reading UI file 'mainwindow_convert.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_CONVERT_H
#define UI_MAINWINDOW_CONVERT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwindowSxWConvert
{
public:
    QAction *actionAbout;
    QAction *actionQuit;
    QWidget *wContents;
    QVBoxLayout *vboxLayout;
    QTabWidget *tabwidgetConvertUnitSelection;
    QWidget *tabDistances;
    QVBoxLayout *vboxLayout1;
    QGridLayout *gridLayout;
    QLineEdit *txt_dist_millimeter;
    QLabel *lblCentimeter;
    QLineEdit *txt_dist_feet;
    QLineEdit *txt_dist_miles;
    QLabel *lblFeet;
    QLabel *lblInches;
    QLabel *lblMiles;
    QLineEdit *special_txt_dist_feetin;
    QLineEdit *txt_dist_centimeter;
    QLabel *lblFeetOnly;
    QLineEdit *txt_dist_inches;
    QLabel *lblMeter;
    QLabel *lblMillimeter;
    QLineEdit *txt_dist_meter;
    QLineEdit *txt_dist_kilometer;
    QLabel *lblKilometer;
    QSpacerItem *spacerItem;
    QWidget *tabTemperatures;
    QVBoxLayout *vboxLayout2;
    QGridLayout *gridLayout1;
    QLabel *lblKelvin;
    QLabel *lblCelsius;
    QLineEdit *txt_temp_kelvin;
    QLabel *lblFahrenheit;
    QLineEdit *txt_temp_fahrenheit;
    QLineEdit *txt_temp_celsius;
    QLabel *lblRankine;
    QLineEdit *txt_temp_rankine;
    QSpacerItem *spacerItem1;
    QWidget *tabPressures;
    QVBoxLayout *vboxLayout3;
    QGridLayout *gridLayout2;
    QLineEdit *txt_pres_mmw;
    QLabel *lblinwg;
    QLineEdit *txt_pres_atm;
    QLabel *lblKPascal;
    QLabel *lblBar;
    QLineEdit *txt_pres_bar;
    QLineEdit *txt_pres_mbar;
    QLabel *lblmmHG;
    QLabel *lblPascal;
    QLabel *lblAtmos;
    QLabel *lblPsi;
    QLineEdit *txt_pres_pa;
    QLabel *lblMillibar;
    QLineEdit *txt_pres_kpa;
    QLineEdit *txt_pres_psi;
    QLineEdit *txt_pres_inwg;
    QSpacerItem *spacerItem2;
    QWidget *tabAreas;
    QVBoxLayout *vboxLayout4;
    QGridLayout *gridLayout3;
    QLineEdit *txt_area_squaremeter;
    QLineEdit *txt_area_squarefoot;
    QLabel *lblSquareyard;
    QLineEdit *txt_area_acre;
    QLineEdit *txt_area_squareyard;
    QLabel *lblSquareinch;
    QLineEdit *txt_area_squareinch;
    QLabel *lblSquarefoot;
    QLabel *lblSquaremile;
    QLineEdit *txt_area_squaremile;
    QLabel *lblSquaremeter;
    QLineEdit *txt_area_hectare;
    QLabel *lblSquareKm;
    QLineEdit *txt_area_squarekm;
    QLabel *lblHa;
    QLabel *lblAcre;
    QSpacerItem *spacerItem3;
    QWidget *tabMasses;
    QVBoxLayout *vboxLayout5;
    QGridLayout *gridLayout4;
    QLineEdit *txt_mass_tonmetric;
    QLineEdit *txt_mass_gram;
    QLabel *lblKg;
    QLabel *lblOunceTroy;
    QLineEdit *txt_mass_pound;
    QLabel *lblOunceAv;
    QLineEdit *txt_mass_kg;
    QLineEdit *txt_mass_ounceav;
    QLabel *lblTonShort;
    QLineEdit *txt_mass_ouncetroy;
    QLabel *lblPound;
    QLineEdit *txt_mass_tonlong;
    QLineEdit *txt_mass_tonshort;
    QLabel *lblGram;
    QLabel *lblTonMetric;
    QLabel *lblTonLong;
    QSpacerItem *spacerItem4;
    QWidget *tabVolumes;
    QVBoxLayout *vboxLayout6;
    QGridLayout *gridLayout5;
    QLineEdit *txt_vol_gallon;
    QLabel *lblLiter;
    QLabel *lblGallon;
    QLineEdit *txt_vol_pint;
    QLineEdit *txt_vol_liter;
    QLabel *lblPint;
    QSpacerItem *spacerItem5;
    QWidget *tabMomentum;
    QVBoxLayout *vboxLayout7;
    QGridLayout *gridLayout6;
    QLabel *lblKgm;
    QLineEdit *txt_mom_kgmsquared;
    QLabel *lblPoundSquareFoot;
    QLineEdit *txt_mom_poundsquarefoot;
    QSpacerItem *spacerItem6;
    QLabel *lblDesc;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *mainwindowSxWConvert)
    {
        if (mainwindowSxWConvert->objectName().isEmpty())
            mainwindowSxWConvert->setObjectName(QStringLiteral("mainwindowSxWConvert"));
        mainwindowSxWConvert->resize(737, 605);
        QIcon icon;
        icon.addFile(QStringLiteral(":/mainicon/img/document_arrow_left_right.png"), QSize(), QIcon::Normal, QIcon::Off);
        mainwindowSxWConvert->setWindowIcon(icon);
        actionAbout = new QAction(mainwindowSxWConvert);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/mainicon/img/light_bulb.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon1);
        actionQuit = new QAction(mainwindowSxWConvert);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/mainicon/img/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon2);
        wContents = new QWidget(mainwindowSxWConvert);
        wContents->setObjectName(QStringLiteral("wContents"));
        vboxLayout = new QVBoxLayout(wContents);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        tabwidgetConvertUnitSelection = new QTabWidget(wContents);
        tabwidgetConvertUnitSelection->setObjectName(QStringLiteral("tabwidgetConvertUnitSelection"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabwidgetConvertUnitSelection->sizePolicy().hasHeightForWidth());
        tabwidgetConvertUnitSelection->setSizePolicy(sizePolicy);
        tabwidgetConvertUnitSelection->setLayoutDirection(Qt::LeftToRight);
        tabwidgetConvertUnitSelection->setTabPosition(QTabWidget::North);
        tabwidgetConvertUnitSelection->setTabShape(QTabWidget::Rounded);
        tabwidgetConvertUnitSelection->setUsesScrollButtons(true);
        tabDistances = new QWidget();
        tabDistances->setObjectName(QStringLiteral("tabDistances"));
        vboxLayout1 = new QVBoxLayout(tabDistances);
#ifndef Q_OS_MAC
        vboxLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout1->setContentsMargins(9, 9, 9, 9);
#endif
        vboxLayout1->setObjectName(QStringLiteral("vboxLayout1"));
        gridLayout = new QGridLayout();
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(0, 0, 0, 0);
#endif
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        txt_dist_millimeter = new QLineEdit(tabDistances);
        txt_dist_millimeter->setObjectName(QStringLiteral("txt_dist_millimeter"));

        gridLayout->addWidget(txt_dist_millimeter, 2, 1, 1, 1);

        lblCentimeter = new QLabel(tabDistances);
        lblCentimeter->setObjectName(QStringLiteral("lblCentimeter"));
        lblCentimeter->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblCentimeter, 1, 0, 1, 1);

        txt_dist_feet = new QLineEdit(tabDistances);
        txt_dist_feet->setObjectName(QStringLiteral("txt_dist_feet"));

        gridLayout->addWidget(txt_dist_feet, 1, 3, 1, 1);

        txt_dist_miles = new QLineEdit(tabDistances);
        txt_dist_miles->setObjectName(QStringLiteral("txt_dist_miles"));

        gridLayout->addWidget(txt_dist_miles, 3, 3, 1, 1);

        lblFeet = new QLabel(tabDistances);
        lblFeet->setObjectName(QStringLiteral("lblFeet"));
        lblFeet->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblFeet, 0, 2, 1, 1);

        lblInches = new QLabel(tabDistances);
        lblInches->setObjectName(QStringLiteral("lblInches"));
        lblInches->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblInches, 2, 2, 1, 1);

        lblMiles = new QLabel(tabDistances);
        lblMiles->setObjectName(QStringLiteral("lblMiles"));
        lblMiles->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblMiles, 3, 2, 1, 1);

        special_txt_dist_feetin = new QLineEdit(tabDistances);
        special_txt_dist_feetin->setObjectName(QStringLiteral("special_txt_dist_feetin"));

        gridLayout->addWidget(special_txt_dist_feetin, 0, 3, 1, 1);

        txt_dist_centimeter = new QLineEdit(tabDistances);
        txt_dist_centimeter->setObjectName(QStringLiteral("txt_dist_centimeter"));

        gridLayout->addWidget(txt_dist_centimeter, 1, 1, 1, 1);

        lblFeetOnly = new QLabel(tabDistances);
        lblFeetOnly->setObjectName(QStringLiteral("lblFeetOnly"));
        lblFeetOnly->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblFeetOnly, 1, 2, 1, 1);

        txt_dist_inches = new QLineEdit(tabDistances);
        txt_dist_inches->setObjectName(QStringLiteral("txt_dist_inches"));

        gridLayout->addWidget(txt_dist_inches, 2, 3, 1, 1);

        lblMeter = new QLabel(tabDistances);
        lblMeter->setObjectName(QStringLiteral("lblMeter"));
        lblMeter->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblMeter, 0, 0, 1, 1);

        lblMillimeter = new QLabel(tabDistances);
        lblMillimeter->setObjectName(QStringLiteral("lblMillimeter"));
        lblMillimeter->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblMillimeter, 2, 0, 1, 1);

        txt_dist_meter = new QLineEdit(tabDistances);
        txt_dist_meter->setObjectName(QStringLiteral("txt_dist_meter"));
        txt_dist_meter->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(txt_dist_meter, 0, 1, 1, 1);

        txt_dist_kilometer = new QLineEdit(tabDistances);
        txt_dist_kilometer->setObjectName(QStringLiteral("txt_dist_kilometer"));

        gridLayout->addWidget(txt_dist_kilometer, 3, 1, 1, 1);

        lblKilometer = new QLabel(tabDistances);
        lblKilometer->setObjectName(QStringLiteral("lblKilometer"));
        lblKilometer->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblKilometer, 3, 0, 1, 1);


        vboxLayout1->addLayout(gridLayout);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout1->addItem(spacerItem);

        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icon/icons/cursor.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabwidgetConvertUnitSelection->addTab(tabDistances, icon3, QString());
        tabTemperatures = new QWidget();
        tabTemperatures->setObjectName(QStringLiteral("tabTemperatures"));
        vboxLayout2 = new QVBoxLayout(tabTemperatures);
#ifndef Q_OS_MAC
        vboxLayout2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout2->setContentsMargins(9, 9, 9, 9);
#endif
        vboxLayout2->setObjectName(QStringLiteral("vboxLayout2"));
        gridLayout1 = new QGridLayout();
#ifndef Q_OS_MAC
        gridLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout1->setContentsMargins(0, 0, 0, 0);
#endif
        gridLayout1->setObjectName(QStringLiteral("gridLayout1"));
        lblKelvin = new QLabel(tabTemperatures);
        lblKelvin->setObjectName(QStringLiteral("lblKelvin"));
        lblKelvin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout1->addWidget(lblKelvin, 0, 0, 1, 1);

        lblCelsius = new QLabel(tabTemperatures);
        lblCelsius->setObjectName(QStringLiteral("lblCelsius"));
        lblCelsius->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout1->addWidget(lblCelsius, 0, 2, 1, 1);

        txt_temp_kelvin = new QLineEdit(tabTemperatures);
        txt_temp_kelvin->setObjectName(QStringLiteral("txt_temp_kelvin"));
        txt_temp_kelvin->setMinimumSize(QSize(150, 0));

        gridLayout1->addWidget(txt_temp_kelvin, 0, 1, 1, 1);

        lblFahrenheit = new QLabel(tabTemperatures);
        lblFahrenheit->setObjectName(QStringLiteral("lblFahrenheit"));
        lblFahrenheit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout1->addWidget(lblFahrenheit, 1, 0, 1, 1);

        txt_temp_fahrenheit = new QLineEdit(tabTemperatures);
        txt_temp_fahrenheit->setObjectName(QStringLiteral("txt_temp_fahrenheit"));

        gridLayout1->addWidget(txt_temp_fahrenheit, 1, 1, 1, 1);

        txt_temp_celsius = new QLineEdit(tabTemperatures);
        txt_temp_celsius->setObjectName(QStringLiteral("txt_temp_celsius"));

        gridLayout1->addWidget(txt_temp_celsius, 0, 3, 1, 1);

        lblRankine = new QLabel(tabTemperatures);
        lblRankine->setObjectName(QStringLiteral("lblRankine"));

        gridLayout1->addWidget(lblRankine, 1, 2, 1, 1);

        txt_temp_rankine = new QLineEdit(tabTemperatures);
        txt_temp_rankine->setObjectName(QStringLiteral("txt_temp_rankine"));

        gridLayout1->addWidget(txt_temp_rankine, 1, 3, 1, 1);


        vboxLayout2->addLayout(gridLayout1);

        spacerItem1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout2->addItem(spacerItem1);

        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icon/icons/temperature.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabwidgetConvertUnitSelection->addTab(tabTemperatures, icon4, QString());
        tabPressures = new QWidget();
        tabPressures->setObjectName(QStringLiteral("tabPressures"));
        vboxLayout3 = new QVBoxLayout(tabPressures);
#ifndef Q_OS_MAC
        vboxLayout3->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout3->setContentsMargins(9, 9, 9, 9);
#endif
        vboxLayout3->setObjectName(QStringLiteral("vboxLayout3"));
        gridLayout2 = new QGridLayout();
#ifndef Q_OS_MAC
        gridLayout2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout2->setContentsMargins(0, 0, 0, 0);
#endif
        gridLayout2->setObjectName(QStringLiteral("gridLayout2"));
        txt_pres_mmw = new QLineEdit(tabPressures);
        txt_pres_mmw->setObjectName(QStringLiteral("txt_pres_mmw"));

        gridLayout2->addWidget(txt_pres_mmw, 2, 1, 1, 1);

        lblinwg = new QLabel(tabPressures);
        lblinwg->setObjectName(QStringLiteral("lblinwg"));
        lblinwg->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout2->addWidget(lblinwg, 1, 0, 1, 1);

        txt_pres_atm = new QLineEdit(tabPressures);
        txt_pres_atm->setObjectName(QStringLiteral("txt_pres_atm"));

        gridLayout2->addWidget(txt_pres_atm, 3, 1, 1, 1);

        lblKPascal = new QLabel(tabPressures);
        lblKPascal->setObjectName(QStringLiteral("lblKPascal"));
        lblKPascal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout2->addWidget(lblKPascal, 0, 2, 1, 1);

        lblBar = new QLabel(tabPressures);
        lblBar->setObjectName(QStringLiteral("lblBar"));
        lblBar->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout2->addWidget(lblBar, 1, 2, 1, 1);

        txt_pres_bar = new QLineEdit(tabPressures);
        txt_pres_bar->setObjectName(QStringLiteral("txt_pres_bar"));

        gridLayout2->addWidget(txt_pres_bar, 1, 3, 1, 1);

        txt_pres_mbar = new QLineEdit(tabPressures);
        txt_pres_mbar->setObjectName(QStringLiteral("txt_pres_mbar"));

        gridLayout2->addWidget(txt_pres_mbar, 2, 3, 1, 1);

        lblmmHG = new QLabel(tabPressures);
        lblmmHG->setObjectName(QStringLiteral("lblmmHG"));
        lblmmHG->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout2->addWidget(lblmmHG, 2, 0, 1, 1);

        lblPascal = new QLabel(tabPressures);
        lblPascal->setObjectName(QStringLiteral("lblPascal"));
        lblPascal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout2->addWidget(lblPascal, 0, 0, 1, 1);

        lblAtmos = new QLabel(tabPressures);
        lblAtmos->setObjectName(QStringLiteral("lblAtmos"));
        lblAtmos->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout2->addWidget(lblAtmos, 3, 0, 1, 1);

        lblPsi = new QLabel(tabPressures);
        lblPsi->setObjectName(QStringLiteral("lblPsi"));
        lblPsi->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout2->addWidget(lblPsi, 3, 2, 1, 1);

        txt_pres_pa = new QLineEdit(tabPressures);
        txt_pres_pa->setObjectName(QStringLiteral("txt_pres_pa"));

        gridLayout2->addWidget(txt_pres_pa, 0, 1, 1, 1);

        lblMillibar = new QLabel(tabPressures);
        lblMillibar->setObjectName(QStringLiteral("lblMillibar"));
        lblMillibar->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout2->addWidget(lblMillibar, 2, 2, 1, 1);

        txt_pres_kpa = new QLineEdit(tabPressures);
        txt_pres_kpa->setObjectName(QStringLiteral("txt_pres_kpa"));

        gridLayout2->addWidget(txt_pres_kpa, 0, 3, 1, 1);

        txt_pres_psi = new QLineEdit(tabPressures);
        txt_pres_psi->setObjectName(QStringLiteral("txt_pres_psi"));

        gridLayout2->addWidget(txt_pres_psi, 3, 3, 1, 1);

        txt_pres_inwg = new QLineEdit(tabPressures);
        txt_pres_inwg->setObjectName(QStringLiteral("txt_pres_inwg"));

        gridLayout2->addWidget(txt_pres_inwg, 1, 1, 1, 1);


        vboxLayout3->addLayout(gridLayout2);

        spacerItem2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout3->addItem(spacerItem2);

        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icon/icons/arrow_bottom.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabwidgetConvertUnitSelection->addTab(tabPressures, icon5, QString());
        tabAreas = new QWidget();
        tabAreas->setObjectName(QStringLiteral("tabAreas"));
        vboxLayout4 = new QVBoxLayout(tabAreas);
#ifndef Q_OS_MAC
        vboxLayout4->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout4->setContentsMargins(9, 9, 9, 9);
#endif
        vboxLayout4->setObjectName(QStringLiteral("vboxLayout4"));
        gridLayout3 = new QGridLayout();
#ifndef Q_OS_MAC
        gridLayout3->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout3->setContentsMargins(0, 0, 0, 0);
#endif
        gridLayout3->setObjectName(QStringLiteral("gridLayout3"));
        txt_area_squaremeter = new QLineEdit(tabAreas);
        txt_area_squaremeter->setObjectName(QStringLiteral("txt_area_squaremeter"));

        gridLayout3->addWidget(txt_area_squaremeter, 0, 1, 1, 1);

        txt_area_squarefoot = new QLineEdit(tabAreas);
        txt_area_squarefoot->setObjectName(QStringLiteral("txt_area_squarefoot"));

        gridLayout3->addWidget(txt_area_squarefoot, 0, 3, 1, 1);

        lblSquareyard = new QLabel(tabAreas);
        lblSquareyard->setObjectName(QStringLiteral("lblSquareyard"));
        lblSquareyard->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout3->addWidget(lblSquareyard, 2, 2, 1, 1);

        txt_area_acre = new QLineEdit(tabAreas);
        txt_area_acre->setObjectName(QStringLiteral("txt_area_acre"));

        gridLayout3->addWidget(txt_area_acre, 2, 1, 1, 1);

        txt_area_squareyard = new QLineEdit(tabAreas);
        txt_area_squareyard->setObjectName(QStringLiteral("txt_area_squareyard"));

        gridLayout3->addWidget(txt_area_squareyard, 2, 3, 1, 1);

        lblSquareinch = new QLabel(tabAreas);
        lblSquareinch->setObjectName(QStringLiteral("lblSquareinch"));
        lblSquareinch->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout3->addWidget(lblSquareinch, 3, 0, 1, 1);

        txt_area_squareinch = new QLineEdit(tabAreas);
        txt_area_squareinch->setObjectName(QStringLiteral("txt_area_squareinch"));

        gridLayout3->addWidget(txt_area_squareinch, 3, 1, 1, 1);

        lblSquarefoot = new QLabel(tabAreas);
        lblSquarefoot->setObjectName(QStringLiteral("lblSquarefoot"));
        lblSquarefoot->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout3->addWidget(lblSquarefoot, 0, 2, 1, 1);

        lblSquaremile = new QLabel(tabAreas);
        lblSquaremile->setObjectName(QStringLiteral("lblSquaremile"));
        lblSquaremile->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout3->addWidget(lblSquaremile, 3, 2, 1, 1);

        txt_area_squaremile = new QLineEdit(tabAreas);
        txt_area_squaremile->setObjectName(QStringLiteral("txt_area_squaremile"));

        gridLayout3->addWidget(txt_area_squaremile, 3, 3, 1, 1);

        lblSquaremeter = new QLabel(tabAreas);
        lblSquaremeter->setObjectName(QStringLiteral("lblSquaremeter"));
        lblSquaremeter->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout3->addWidget(lblSquaremeter, 0, 0, 1, 1);

        txt_area_hectare = new QLineEdit(tabAreas);
        txt_area_hectare->setObjectName(QStringLiteral("txt_area_hectare"));

        gridLayout3->addWidget(txt_area_hectare, 1, 3, 1, 1);

        lblSquareKm = new QLabel(tabAreas);
        lblSquareKm->setObjectName(QStringLiteral("lblSquareKm"));
        lblSquareKm->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout3->addWidget(lblSquareKm, 1, 0, 1, 1);

        txt_area_squarekm = new QLineEdit(tabAreas);
        txt_area_squarekm->setObjectName(QStringLiteral("txt_area_squarekm"));

        gridLayout3->addWidget(txt_area_squarekm, 1, 1, 1, 1);

        lblHa = new QLabel(tabAreas);
        lblHa->setObjectName(QStringLiteral("lblHa"));
        lblHa->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout3->addWidget(lblHa, 1, 2, 1, 1);

        lblAcre = new QLabel(tabAreas);
        lblAcre->setObjectName(QStringLiteral("lblAcre"));
        lblAcre->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout3->addWidget(lblAcre, 2, 0, 1, 1);


        vboxLayout4->addLayout(gridLayout3);

        spacerItem3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout4->addItem(spacerItem3);

        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icon/icons/rect.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabwidgetConvertUnitSelection->addTab(tabAreas, icon6, QString());
        tabMasses = new QWidget();
        tabMasses->setObjectName(QStringLiteral("tabMasses"));
        vboxLayout5 = new QVBoxLayout(tabMasses);
#ifndef Q_OS_MAC
        vboxLayout5->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout5->setContentsMargins(9, 9, 9, 9);
#endif
        vboxLayout5->setObjectName(QStringLiteral("vboxLayout5"));
        gridLayout4 = new QGridLayout();
#ifndef Q_OS_MAC
        gridLayout4->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout4->setContentsMargins(0, 0, 0, 0);
#endif
        gridLayout4->setObjectName(QStringLiteral("gridLayout4"));
        txt_mass_tonmetric = new QLineEdit(tabMasses);
        txt_mass_tonmetric->setObjectName(QStringLiteral("txt_mass_tonmetric"));

        gridLayout4->addWidget(txt_mass_tonmetric, 2, 1, 1, 1);

        txt_mass_gram = new QLineEdit(tabMasses);
        txt_mass_gram->setObjectName(QStringLiteral("txt_mass_gram"));

        gridLayout4->addWidget(txt_mass_gram, 0, 3, 1, 1);

        lblKg = new QLabel(tabMasses);
        lblKg->setObjectName(QStringLiteral("lblKg"));
        lblKg->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout4->addWidget(lblKg, 0, 0, 1, 1);

        lblOunceTroy = new QLabel(tabMasses);
        lblOunceTroy->setObjectName(QStringLiteral("lblOunceTroy"));
        lblOunceTroy->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout4->addWidget(lblOunceTroy, 1, 2, 1, 1);

        txt_mass_pound = new QLineEdit(tabMasses);
        txt_mass_pound->setObjectName(QStringLiteral("txt_mass_pound"));

        gridLayout4->addWidget(txt_mass_pound, 1, 1, 1, 1);

        lblOunceAv = new QLabel(tabMasses);
        lblOunceAv->setObjectName(QStringLiteral("lblOunceAv"));
        lblOunceAv->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout4->addWidget(lblOunceAv, 2, 2, 1, 1);

        txt_mass_kg = new QLineEdit(tabMasses);
        txt_mass_kg->setObjectName(QStringLiteral("txt_mass_kg"));

        gridLayout4->addWidget(txt_mass_kg, 0, 1, 1, 1);

        txt_mass_ounceav = new QLineEdit(tabMasses);
        txt_mass_ounceav->setObjectName(QStringLiteral("txt_mass_ounceav"));

        gridLayout4->addWidget(txt_mass_ounceav, 2, 3, 1, 1);

        lblTonShort = new QLabel(tabMasses);
        lblTonShort->setObjectName(QStringLiteral("lblTonShort"));
        lblTonShort->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout4->addWidget(lblTonShort, 4, 0, 1, 1);

        txt_mass_ouncetroy = new QLineEdit(tabMasses);
        txt_mass_ouncetroy->setObjectName(QStringLiteral("txt_mass_ouncetroy"));

        gridLayout4->addWidget(txt_mass_ouncetroy, 1, 3, 1, 1);

        lblPound = new QLabel(tabMasses);
        lblPound->setObjectName(QStringLiteral("lblPound"));
        lblPound->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout4->addWidget(lblPound, 1, 0, 1, 1);

        txt_mass_tonlong = new QLineEdit(tabMasses);
        txt_mass_tonlong->setObjectName(QStringLiteral("txt_mass_tonlong"));

        gridLayout4->addWidget(txt_mass_tonlong, 3, 1, 1, 1);

        txt_mass_tonshort = new QLineEdit(tabMasses);
        txt_mass_tonshort->setObjectName(QStringLiteral("txt_mass_tonshort"));

        gridLayout4->addWidget(txt_mass_tonshort, 4, 1, 1, 1);

        lblGram = new QLabel(tabMasses);
        lblGram->setObjectName(QStringLiteral("lblGram"));
        lblGram->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout4->addWidget(lblGram, 0, 2, 1, 1);

        lblTonMetric = new QLabel(tabMasses);
        lblTonMetric->setObjectName(QStringLiteral("lblTonMetric"));
        lblTonMetric->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout4->addWidget(lblTonMetric, 2, 0, 1, 1);

        lblTonLong = new QLabel(tabMasses);
        lblTonLong->setObjectName(QStringLiteral("lblTonLong"));
        lblTonLong->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout4->addWidget(lblTonLong, 3, 0, 1, 1);


        vboxLayout5->addLayout(gridLayout4);

        spacerItem4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout5->addItem(spacerItem4);

        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icon/icons/weight.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabwidgetConvertUnitSelection->addTab(tabMasses, icon7, QString());
        tabVolumes = new QWidget();
        tabVolumes->setObjectName(QStringLiteral("tabVolumes"));
        vboxLayout6 = new QVBoxLayout(tabVolumes);
#ifndef Q_OS_MAC
        vboxLayout6->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout6->setContentsMargins(9, 9, 9, 9);
#endif
        vboxLayout6->setObjectName(QStringLiteral("vboxLayout6"));
        gridLayout5 = new QGridLayout();
#ifndef Q_OS_MAC
        gridLayout5->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout5->setContentsMargins(0, 0, 0, 0);
#endif
        gridLayout5->setObjectName(QStringLiteral("gridLayout5"));
        txt_vol_gallon = new QLineEdit(tabVolumes);
        txt_vol_gallon->setObjectName(QStringLiteral("txt_vol_gallon"));

        gridLayout5->addWidget(txt_vol_gallon, 1, 1, 1, 1);

        lblLiter = new QLabel(tabVolumes);
        lblLiter->setObjectName(QStringLiteral("lblLiter"));

        gridLayout5->addWidget(lblLiter, 0, 0, 1, 1);

        lblGallon = new QLabel(tabVolumes);
        lblGallon->setObjectName(QStringLiteral("lblGallon"));

        gridLayout5->addWidget(lblGallon, 1, 0, 1, 1);

        txt_vol_pint = new QLineEdit(tabVolumes);
        txt_vol_pint->setObjectName(QStringLiteral("txt_vol_pint"));

        gridLayout5->addWidget(txt_vol_pint, 2, 1, 1, 1);

        txt_vol_liter = new QLineEdit(tabVolumes);
        txt_vol_liter->setObjectName(QStringLiteral("txt_vol_liter"));

        gridLayout5->addWidget(txt_vol_liter, 0, 1, 1, 1);

        lblPint = new QLabel(tabVolumes);
        lblPint->setObjectName(QStringLiteral("lblPint"));

        gridLayout5->addWidget(lblPint, 2, 0, 1, 1);


        vboxLayout6->addLayout(gridLayout5);

        spacerItem5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout6->addItem(spacerItem5);

        QIcon icon8;
        icon8.addFile(QStringLiteral(":/icon/icons/volume.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabwidgetConvertUnitSelection->addTab(tabVolumes, icon8, QString());
        tabMomentum = new QWidget();
        tabMomentum->setObjectName(QStringLiteral("tabMomentum"));
        vboxLayout7 = new QVBoxLayout(tabMomentum);
        vboxLayout7->setObjectName(QStringLiteral("vboxLayout7"));
        gridLayout6 = new QGridLayout();
        gridLayout6->setObjectName(QStringLiteral("gridLayout6"));
        lblKgm = new QLabel(tabMomentum);
        lblKgm->setObjectName(QStringLiteral("lblKgm"));

        gridLayout6->addWidget(lblKgm, 0, 0, 1, 1);

        txt_mom_kgmsquared = new QLineEdit(tabMomentum);
        txt_mom_kgmsquared->setObjectName(QStringLiteral("txt_mom_kgmsquared"));

        gridLayout6->addWidget(txt_mom_kgmsquared, 0, 1, 1, 1);

        lblPoundSquareFoot = new QLabel(tabMomentum);
        lblPoundSquareFoot->setObjectName(QStringLiteral("lblPoundSquareFoot"));

        gridLayout6->addWidget(lblPoundSquareFoot, 1, 0, 1, 1);

        txt_mom_poundsquarefoot = new QLineEdit(tabMomentum);
        txt_mom_poundsquarefoot->setObjectName(QStringLiteral("txt_mom_poundsquarefoot"));

        gridLayout6->addWidget(txt_mom_poundsquarefoot, 1, 1, 1, 1);


        vboxLayout7->addLayout(gridLayout6);

        spacerItem6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout7->addItem(spacerItem6);

        QIcon icon9;
        icon9.addFile(QStringLiteral(":/icon/icons/windows_options.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabwidgetConvertUnitSelection->addTab(tabMomentum, icon9, QString());

        vboxLayout->addWidget(tabwidgetConvertUnitSelection);

        lblDesc = new QLabel(wContents);
        lblDesc->setObjectName(QStringLiteral("lblDesc"));
        lblDesc->setFrameShape(QFrame::StyledPanel);
        lblDesc->setFrameShadow(QFrame::Raised);
        lblDesc->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lblDesc->setWordWrap(true);
        lblDesc->setOpenExternalLinks(true);

        vboxLayout->addWidget(lblDesc);

        mainwindowSxWConvert->setCentralWidget(wContents);
        statusbar = new QStatusBar(mainwindowSxWConvert);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        statusbar->setEnabled(true);
        statusbar->setSizeGripEnabled(true);
        mainwindowSxWConvert->setStatusBar(statusbar);
        toolBar = new QToolBar(mainwindowSxWConvert);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMovable(true);
        toolBar->setAllowedAreas(Qt::BottomToolBarArea|Qt::TopToolBarArea);
        toolBar->setIconSize(QSize(16, 16));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        mainwindowSxWConvert->addToolBar(Qt::TopToolBarArea, toolBar);
        QWidget::setTabOrder(txt_dist_meter, special_txt_dist_feetin);
        QWidget::setTabOrder(special_txt_dist_feetin, txt_dist_centimeter);
        QWidget::setTabOrder(txt_dist_centimeter, txt_dist_inches);
        QWidget::setTabOrder(txt_dist_inches, txt_dist_miles);
        QWidget::setTabOrder(txt_dist_miles, txt_temp_kelvin);
        QWidget::setTabOrder(txt_temp_kelvin, txt_temp_fahrenheit);
        QWidget::setTabOrder(txt_temp_fahrenheit, txt_temp_celsius);
        QWidget::setTabOrder(txt_temp_celsius, txt_pres_pa);
        QWidget::setTabOrder(txt_pres_pa, txt_pres_inwg);
        QWidget::setTabOrder(txt_pres_inwg, txt_pres_mmw);
        QWidget::setTabOrder(txt_pres_mmw, txt_pres_atm);
        QWidget::setTabOrder(txt_pres_atm, txt_pres_bar);
        QWidget::setTabOrder(txt_pres_bar, txt_pres_mbar);
        QWidget::setTabOrder(txt_pres_mbar, txt_pres_psi);
        QWidget::setTabOrder(txt_pres_psi, txt_area_squaremeter);
        QWidget::setTabOrder(txt_area_squaremeter, txt_area_squarekm);
        QWidget::setTabOrder(txt_area_squarekm, txt_area_acre);
        QWidget::setTabOrder(txt_area_acre, txt_area_squareinch);
        QWidget::setTabOrder(txt_area_squareinch, txt_area_squarefoot);
        QWidget::setTabOrder(txt_area_squarefoot, txt_area_hectare);
        QWidget::setTabOrder(txt_area_hectare, txt_area_squareyard);
        QWidget::setTabOrder(txt_area_squareyard, txt_area_squaremile);
        QWidget::setTabOrder(txt_area_squaremile, txt_mass_kg);
        QWidget::setTabOrder(txt_mass_kg, txt_mass_tonmetric);
        QWidget::setTabOrder(txt_mass_tonmetric, txt_mass_tonlong);
        QWidget::setTabOrder(txt_mass_tonlong, txt_mass_tonshort);
        QWidget::setTabOrder(txt_mass_tonshort, txt_mass_pound);
        QWidget::setTabOrder(txt_mass_pound, txt_mass_ouncetroy);
        QWidget::setTabOrder(txt_mass_ouncetroy, txt_mass_ounceav);
        QWidget::setTabOrder(txt_mass_ounceav, tabwidgetConvertUnitSelection);

        toolBar->addAction(actionQuit);
        toolBar->addAction(actionAbout);

        retranslateUi(mainwindowSxWConvert);

        tabwidgetConvertUnitSelection->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(mainwindowSxWConvert);
    } // setupUi

    void retranslateUi(QMainWindow *mainwindowSxWConvert)
    {
        mainwindowSxWConvert->setWindowTitle(QApplication::translate("mainwindowSxWConvert", "SxW Convert", 0));
        actionAbout->setText(QApplication::translate("mainwindowSxWConvert", "&About", 0));
#ifndef QT_NO_STATUSTIP
        actionAbout->setStatusTip(QApplication::translate("mainwindowSxWConvert", "Show Program Information", 0));
#endif // QT_NO_STATUSTIP
        actionAbout->setShortcut(QApplication::translate("mainwindowSxWConvert", "F1", 0));
        actionQuit->setText(QApplication::translate("mainwindowSxWConvert", "&Quit", 0));
#ifndef QT_NO_STATUSTIP
        actionQuit->setStatusTip(QApplication::translate("mainwindowSxWConvert", "Quit the Program", 0));
#endif // QT_NO_STATUSTIP
        actionQuit->setShortcut(QApplication::translate("mainwindowSxWConvert", "Ctrl+Q", 0));
        lblCentimeter->setText(QApplication::translate("mainwindowSxWConvert", "Centimeter [cm]", 0));
        lblFeet->setText(QApplication::translate("mainwindowSxWConvert", "Feet [ft - inch]", 0));
        lblInches->setText(QApplication::translate("mainwindowSxWConvert", "Inches [in]", 0));
        lblMiles->setText(QApplication::translate("mainwindowSxWConvert", "Miles [mi]", 0));
        lblFeetOnly->setText(QApplication::translate("mainwindowSxWConvert", "Feet [ft]", 0));
        lblMeter->setText(QApplication::translate("mainwindowSxWConvert", "Meter [m]", 0));
        lblMillimeter->setText(QApplication::translate("mainwindowSxWConvert", "Millimeter [mm]", 0));
        lblKilometer->setText(QApplication::translate("mainwindowSxWConvert", "Kilometer [km]", 0));
        tabwidgetConvertUnitSelection->setTabText(tabwidgetConvertUnitSelection->indexOf(tabDistances), QApplication::translate("mainwindowSxWConvert", "Distances", 0));
        lblKelvin->setText(QApplication::translate("mainwindowSxWConvert", "Kelvin [K]", 0));
        lblCelsius->setText(QApplication::translate("mainwindowSxWConvert", "Celsius [\302\260C]", 0));
        lblFahrenheit->setText(QApplication::translate("mainwindowSxWConvert", "Fahrenheit [\302\260F]", 0));
        lblRankine->setText(QApplication::translate("mainwindowSxWConvert", "Rankine [Rk]", 0));
        tabwidgetConvertUnitSelection->setTabText(tabwidgetConvertUnitSelection->indexOf(tabTemperatures), QApplication::translate("mainwindowSxWConvert", "Temperatures", 0));
#ifndef QT_NO_TOOLTIP
        lblinwg->setToolTip(QApplication::translate("mainwindowSxWConvert", "inches Water Gauge", 0));
#endif // QT_NO_TOOLTIP
        lblinwg->setText(QApplication::translate("mainwindowSxWConvert", "Inches of Water Gage [\" WG]", 0));
        lblKPascal->setText(QApplication::translate("mainwindowSxWConvert", "Kilopascal [KPa]", 0));
        lblBar->setText(QApplication::translate("mainwindowSxWConvert", "Bar [bar]", 0));
        lblmmHG->setText(QApplication::translate("mainwindowSxWConvert", "mm of Water [mm WG]", 0));
        lblPascal->setText(QApplication::translate("mainwindowSxWConvert", "Pascal [Pa]", 0));
        lblAtmos->setText(QApplication::translate("mainwindowSxWConvert", "Atmosphere [atm]", 0));
        lblPsi->setText(QApplication::translate("mainwindowSxWConvert", "Pound per Square Inch [psi]", 0));
        lblMillibar->setText(QApplication::translate("mainwindowSxWConvert", "Millibar [mbar]", 0));
        tabwidgetConvertUnitSelection->setTabText(tabwidgetConvertUnitSelection->indexOf(tabPressures), QApplication::translate("mainwindowSxWConvert", "Pressures", 0));
        lblSquareyard->setText(QApplication::translate("mainwindowSxWConvert", "Square Yard [yd <sup>2</sup>]", 0));
        lblSquareinch->setText(QApplication::translate("mainwindowSxWConvert", "Square Inch [inch <sup>2</sup>]", 0));
        lblSquarefoot->setText(QApplication::translate("mainwindowSxWConvert", "Square Foot [ft <sup>2</sup>]", 0));
        lblSquaremile->setText(QApplication::translate("mainwindowSxWConvert", "Square Mile [sq <sup>2</sup>]", 0));
        lblSquaremeter->setText(QApplication::translate("mainwindowSxWConvert", "Square Meter [m <sup>2</sup>]", 0));
        lblSquareKm->setText(QApplication::translate("mainwindowSxWConvert", "Square Kilometer [km <sup>2</sup>]", 0));
        lblHa->setText(QApplication::translate("mainwindowSxWConvert", "Hectare [ha] ", 0));
        lblAcre->setText(QApplication::translate("mainwindowSxWConvert", "Acre [ac] ", 0));
        tabwidgetConvertUnitSelection->setTabText(tabwidgetConvertUnitSelection->indexOf(tabAreas), QApplication::translate("mainwindowSxWConvert", "Areas", 0));
        lblKg->setText(QApplication::translate("mainwindowSxWConvert", "Kilogram [kg]", 0));
        lblOunceTroy->setText(QApplication::translate("mainwindowSxWConvert", "Ounce, Troy [oz]", 0));
        lblOunceAv->setText(QApplication::translate("mainwindowSxWConvert", "Ounce, Avoirdupois [oz]", 0));
        lblTonShort->setText(QApplication::translate("mainwindowSxWConvert", "Ton (short) [t]", 0));
        lblPound->setText(QApplication::translate("mainwindowSxWConvert", "Pound [lb]", 0));
        lblGram->setText(QApplication::translate("mainwindowSxWConvert", "Gram [g]", 0));
        lblTonMetric->setText(QApplication::translate("mainwindowSxWConvert", "Ton [t]", 0));
        lblTonLong->setText(QApplication::translate("mainwindowSxWConvert", "Ton (long) [t]", 0));
        tabwidgetConvertUnitSelection->setTabText(tabwidgetConvertUnitSelection->indexOf(tabMasses), QApplication::translate("mainwindowSxWConvert", "Masses", 0));
        lblLiter->setText(QApplication::translate("mainwindowSxWConvert", "Liter", 0));
        lblGallon->setText(QApplication::translate("mainwindowSxWConvert", "Gallon", 0));
        lblPint->setText(QApplication::translate("mainwindowSxWConvert", "Pint", 0));
        tabwidgetConvertUnitSelection->setTabText(tabwidgetConvertUnitSelection->indexOf(tabVolumes), QApplication::translate("mainwindowSxWConvert", "Volumes", 0));
        lblKgm->setText(QApplication::translate("mainwindowSxWConvert", "Kilogram meter Squared [kgm <sup>2</sup>]", 0));
        lblPoundSquareFoot->setText(QApplication::translate("mainwindowSxWConvert", "Pound Square Foot", 0));
        tabwidgetConvertUnitSelection->setTabText(tabwidgetConvertUnitSelection->indexOf(tabMomentum), QApplication::translate("mainwindowSxWConvert", "Momentum of Inertia", 0));
        lblDesc->setText(QString());
        toolBar->setWindowTitle(QApplication::translate("mainwindowSxWConvert", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class mainwindowSxWConvert: public Ui_mainwindowSxWConvert {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_CONVERT_H
