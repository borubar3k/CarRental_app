/********************************************************************************
** Form generated from reading UI file 'klientwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KLIENTWINDOW_H
#define UI_KLIENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_klientWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_rej;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_rej_imie;
    QLabel *label_rej_imie;
    QLineEdit *lineEdit_rej_imie;
    QHBoxLayout *horizontalLayout_rej_nazwisko;
    QLabel *label_rej_nazwisko;
    QLineEdit *lineEdit_rej_nazwisko;
    QHBoxLayout *horizontalLayout_rej_pesel;
    QLabel *label_rej_pesel;
    QLineEdit *lineEdit_rej_pesel;
    QHBoxLayout *horizontalLayout_rej_tel;
    QLabel *label_rej_tel;
    QLineEdit *lineEdit_rej_tel;
    QHBoxLayout *horizontalLayout_rej_email;
    QLabel *label_rej_email;
    QLineEdit *lineEdit_rej_email;
    QHBoxLayout *horizontalLayout_rej_haslo;
    QLabel *label_rej_haslo;
    QLineEdit *lineEdit_rej_haslo;
    QHBoxLayout *horizontalLayout_rej;
    QPushButton *pushButton_rej;
    QPushButton *pushButton_rej_powrot;
    QGroupBox *groupBox_logowanie;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_l_email;
    QLabel *label_l_email;
    QLineEdit *lineEdit_l_email;
    QHBoxLayout *horizontalLayout_l_haslo;
    QLabel *label_l_haslo;
    QLineEdit *lineEdit_l_haslo;
    QPushButton *pushButton_logowanie;
    QHBoxLayout *horizontalLayout_l_rej;
    QLabel *label_l_rej;
    QPushButton *pushButton_l_rej;
    QTabWidget *tabWidget;
    QWidget *tab_wyborsamochodu;
    QLabel *label_samochody;
    QGroupBox *groupBox_wybdate;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_dataOd;
    QLabel *label_dataOd;
    QDateEdit *dateEdit_dataOd;
    QHBoxLayout *horizontalLayout_dataDo;
    QLabel *label_dataDo;
    QDateEdit *dateEdit_dataDo;
    QHBoxLayout *horizontalLayout_rodzaj;
    QLabel *label;
    QComboBox *comboBox_rodzaj;
    QHBoxLayout *horizontalLayout_marka;
    QLabel *label_2;
    QComboBox *comboBox_marka;
    QPushButton *pushButton__wybdate_szukaj;
    QListWidget *listWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_wyloguj;
    QPushButton *pushButton_wyloguj;
    QPushButton *pushButton_wypozycz;
    QLabel *label_samochody_2;
    QWidget *tab_historia;
    QListWidget *listWidget_twojahistoria;
    QLabel *label_twojahistoria;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_wyloguj2;
    QPushButton *pushButton_wyloguj_2;
    QPushButton *pushButton_odswiez;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *klientWindow)
    {
        if (klientWindow->objectName().isEmpty())
            klientWindow->setObjectName("klientWindow");
        klientWindow->resize(800, 450);
        centralwidget = new QWidget(klientWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox_rej = new QGroupBox(centralwidget);
        groupBox_rej->setObjectName("groupBox_rej");
        groupBox_rej->setGeometry(QRect(10, 130, 311, 271));
        verticalLayout_2 = new QVBoxLayout(groupBox_rej);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_rej_imie = new QHBoxLayout();
        horizontalLayout_rej_imie->setObjectName("horizontalLayout_rej_imie");
        label_rej_imie = new QLabel(groupBox_rej);
        label_rej_imie->setObjectName("label_rej_imie");

        horizontalLayout_rej_imie->addWidget(label_rej_imie);

        lineEdit_rej_imie = new QLineEdit(groupBox_rej);
        lineEdit_rej_imie->setObjectName("lineEdit_rej_imie");

        horizontalLayout_rej_imie->addWidget(lineEdit_rej_imie);


        verticalLayout_2->addLayout(horizontalLayout_rej_imie);

        horizontalLayout_rej_nazwisko = new QHBoxLayout();
        horizontalLayout_rej_nazwisko->setObjectName("horizontalLayout_rej_nazwisko");
        label_rej_nazwisko = new QLabel(groupBox_rej);
        label_rej_nazwisko->setObjectName("label_rej_nazwisko");

        horizontalLayout_rej_nazwisko->addWidget(label_rej_nazwisko);

        lineEdit_rej_nazwisko = new QLineEdit(groupBox_rej);
        lineEdit_rej_nazwisko->setObjectName("lineEdit_rej_nazwisko");

        horizontalLayout_rej_nazwisko->addWidget(lineEdit_rej_nazwisko);


        verticalLayout_2->addLayout(horizontalLayout_rej_nazwisko);

        horizontalLayout_rej_pesel = new QHBoxLayout();
        horizontalLayout_rej_pesel->setObjectName("horizontalLayout_rej_pesel");
        label_rej_pesel = new QLabel(groupBox_rej);
        label_rej_pesel->setObjectName("label_rej_pesel");

        horizontalLayout_rej_pesel->addWidget(label_rej_pesel);

        lineEdit_rej_pesel = new QLineEdit(groupBox_rej);
        lineEdit_rej_pesel->setObjectName("lineEdit_rej_pesel");

        horizontalLayout_rej_pesel->addWidget(lineEdit_rej_pesel);


        verticalLayout_2->addLayout(horizontalLayout_rej_pesel);

        horizontalLayout_rej_tel = new QHBoxLayout();
        horizontalLayout_rej_tel->setObjectName("horizontalLayout_rej_tel");
        label_rej_tel = new QLabel(groupBox_rej);
        label_rej_tel->setObjectName("label_rej_tel");

        horizontalLayout_rej_tel->addWidget(label_rej_tel);

        lineEdit_rej_tel = new QLineEdit(groupBox_rej);
        lineEdit_rej_tel->setObjectName("lineEdit_rej_tel");

        horizontalLayout_rej_tel->addWidget(lineEdit_rej_tel);


        verticalLayout_2->addLayout(horizontalLayout_rej_tel);

        horizontalLayout_rej_email = new QHBoxLayout();
        horizontalLayout_rej_email->setObjectName("horizontalLayout_rej_email");
        label_rej_email = new QLabel(groupBox_rej);
        label_rej_email->setObjectName("label_rej_email");

        horizontalLayout_rej_email->addWidget(label_rej_email);

        lineEdit_rej_email = new QLineEdit(groupBox_rej);
        lineEdit_rej_email->setObjectName("lineEdit_rej_email");

        horizontalLayout_rej_email->addWidget(lineEdit_rej_email);


        verticalLayout_2->addLayout(horizontalLayout_rej_email);

        horizontalLayout_rej_haslo = new QHBoxLayout();
        horizontalLayout_rej_haslo->setObjectName("horizontalLayout_rej_haslo");
        label_rej_haslo = new QLabel(groupBox_rej);
        label_rej_haslo->setObjectName("label_rej_haslo");

        horizontalLayout_rej_haslo->addWidget(label_rej_haslo);

        lineEdit_rej_haslo = new QLineEdit(groupBox_rej);
        lineEdit_rej_haslo->setObjectName("lineEdit_rej_haslo");
        lineEdit_rej_haslo->setEchoMode(QLineEdit::Password);

        horizontalLayout_rej_haslo->addWidget(lineEdit_rej_haslo);


        verticalLayout_2->addLayout(horizontalLayout_rej_haslo);

        horizontalLayout_rej = new QHBoxLayout();
        horizontalLayout_rej->setObjectName("horizontalLayout_rej");
        pushButton_rej = new QPushButton(groupBox_rej);
        pushButton_rej->setObjectName("pushButton_rej");

        horizontalLayout_rej->addWidget(pushButton_rej);

        pushButton_rej_powrot = new QPushButton(groupBox_rej);
        pushButton_rej_powrot->setObjectName("pushButton_rej_powrot");

        horizontalLayout_rej->addWidget(pushButton_rej_powrot);


        verticalLayout_2->addLayout(horizontalLayout_rej);

        groupBox_logowanie = new QGroupBox(centralwidget);
        groupBox_logowanie->setObjectName("groupBox_logowanie");
        groupBox_logowanie->setGeometry(QRect(10, 160, 311, 241));
        verticalLayout = new QVBoxLayout(groupBox_logowanie);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_l_email = new QHBoxLayout();
        horizontalLayout_l_email->setObjectName("horizontalLayout_l_email");
        label_l_email = new QLabel(groupBox_logowanie);
        label_l_email->setObjectName("label_l_email");

        horizontalLayout_l_email->addWidget(label_l_email);

        lineEdit_l_email = new QLineEdit(groupBox_logowanie);
        lineEdit_l_email->setObjectName("lineEdit_l_email");

        horizontalLayout_l_email->addWidget(lineEdit_l_email);


        verticalLayout->addLayout(horizontalLayout_l_email);

        horizontalLayout_l_haslo = new QHBoxLayout();
        horizontalLayout_l_haslo->setObjectName("horizontalLayout_l_haslo");
        label_l_haslo = new QLabel(groupBox_logowanie);
        label_l_haslo->setObjectName("label_l_haslo");

        horizontalLayout_l_haslo->addWidget(label_l_haslo);

        lineEdit_l_haslo = new QLineEdit(groupBox_logowanie);
        lineEdit_l_haslo->setObjectName("lineEdit_l_haslo");
        lineEdit_l_haslo->setEchoMode(QLineEdit::Password);

        horizontalLayout_l_haslo->addWidget(lineEdit_l_haslo);


        verticalLayout->addLayout(horizontalLayout_l_haslo);

        pushButton_logowanie = new QPushButton(groupBox_logowanie);
        pushButton_logowanie->setObjectName("pushButton_logowanie");

        verticalLayout->addWidget(pushButton_logowanie);

        horizontalLayout_l_rej = new QHBoxLayout();
        horizontalLayout_l_rej->setObjectName("horizontalLayout_l_rej");
        label_l_rej = new QLabel(groupBox_logowanie);
        label_l_rej->setObjectName("label_l_rej");

        horizontalLayout_l_rej->addWidget(label_l_rej);

        pushButton_l_rej = new QPushButton(groupBox_logowanie);
        pushButton_l_rej->setObjectName("pushButton_l_rej");

        horizontalLayout_l_rej->addWidget(pushButton_l_rej);


        verticalLayout->addLayout(horizontalLayout_l_rej);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(20, 20, 771, 381));
        tab_wyborsamochodu = new QWidget();
        tab_wyborsamochodu->setObjectName("tab_wyborsamochodu");
        label_samochody = new QLabel(tab_wyborsamochodu);
        label_samochody->setObjectName("label_samochody");
        label_samochody->setGeometry(QRect(340, 0, 421, 21));
        groupBox_wybdate = new QGroupBox(tab_wyborsamochodu);
        groupBox_wybdate->setObjectName("groupBox_wybdate");
        groupBox_wybdate->setGeometry(QRect(10, 10, 311, 241));
        verticalLayout_3 = new QVBoxLayout(groupBox_wybdate);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_dataOd = new QHBoxLayout();
        horizontalLayout_dataOd->setObjectName("horizontalLayout_dataOd");
        label_dataOd = new QLabel(groupBox_wybdate);
        label_dataOd->setObjectName("label_dataOd");

        horizontalLayout_dataOd->addWidget(label_dataOd);

        dateEdit_dataOd = new QDateEdit(groupBox_wybdate);
        dateEdit_dataOd->setObjectName("dateEdit_dataOd");
        dateEdit_dataOd->setDateTime(QDateTime(QDate(2024, 4, 9), QTime(0, 0, 0)));
        dateEdit_dataOd->setTime(QTime(0, 0, 0));
        dateEdit_dataOd->setCurrentSection(QDateTimeEdit::DaySection);
        dateEdit_dataOd->setCalendarPopup(false);

        horizontalLayout_dataOd->addWidget(dateEdit_dataOd);


        verticalLayout_3->addLayout(horizontalLayout_dataOd);

        horizontalLayout_dataDo = new QHBoxLayout();
        horizontalLayout_dataDo->setObjectName("horizontalLayout_dataDo");
        label_dataDo = new QLabel(groupBox_wybdate);
        label_dataDo->setObjectName("label_dataDo");

        horizontalLayout_dataDo->addWidget(label_dataDo);

        dateEdit_dataDo = new QDateEdit(groupBox_wybdate);
        dateEdit_dataDo->setObjectName("dateEdit_dataDo");
        dateEdit_dataDo->setDateTime(QDateTime(QDate(2024, 4, 9), QTime(0, 0, 0)));
        dateEdit_dataDo->setTime(QTime(0, 0, 0));
        dateEdit_dataDo->setMinimumDateTime(QDateTime(QDate(1752, 9, 13), QTime(21, 0, 4)));

        horizontalLayout_dataDo->addWidget(dateEdit_dataDo);


        verticalLayout_3->addLayout(horizontalLayout_dataDo);

        horizontalLayout_rodzaj = new QHBoxLayout();
        horizontalLayout_rodzaj->setObjectName("horizontalLayout_rodzaj");
        label = new QLabel(groupBox_wybdate);
        label->setObjectName("label");

        horizontalLayout_rodzaj->addWidget(label);

        comboBox_rodzaj = new QComboBox(groupBox_wybdate);
        comboBox_rodzaj->setObjectName("comboBox_rodzaj");

        horizontalLayout_rodzaj->addWidget(comboBox_rodzaj);


        verticalLayout_3->addLayout(horizontalLayout_rodzaj);

        horizontalLayout_marka = new QHBoxLayout();
        horizontalLayout_marka->setObjectName("horizontalLayout_marka");
        label_2 = new QLabel(groupBox_wybdate);
        label_2->setObjectName("label_2");

        horizontalLayout_marka->addWidget(label_2);

        comboBox_marka = new QComboBox(groupBox_wybdate);
        comboBox_marka->setObjectName("comboBox_marka");

        horizontalLayout_marka->addWidget(comboBox_marka);


        verticalLayout_3->addLayout(horizontalLayout_marka);

        pushButton__wybdate_szukaj = new QPushButton(groupBox_wybdate);
        pushButton__wybdate_szukaj->setObjectName("pushButton__wybdate_szukaj");

        verticalLayout_3->addWidget(pushButton__wybdate_szukaj);

        listWidget = new QListWidget(tab_wyborsamochodu);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(330, 50, 431, 241));
        layoutWidget = new QWidget(tab_wyborsamochodu);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 298, 311, 31));
        horizontalLayout_wyloguj = new QHBoxLayout(layoutWidget);
        horizontalLayout_wyloguj->setObjectName("horizontalLayout_wyloguj");
        horizontalLayout_wyloguj->setContentsMargins(0, 0, 0, 0);
        pushButton_wyloguj = new QPushButton(layoutWidget);
        pushButton_wyloguj->setObjectName("pushButton_wyloguj");

        horizontalLayout_wyloguj->addWidget(pushButton_wyloguj);

        pushButton_wypozycz = new QPushButton(layoutWidget);
        pushButton_wypozycz->setObjectName("pushButton_wypozycz");
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(255, 63, 63, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(127, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(170, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush8(QColor(0, 0, 0, 127));
        brush8.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Active, QPalette::Accent, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Accent, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush9(QColor(127, 0, 0, 127));
        brush9.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        QBrush brush10(QColor(255, 76, 76, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Accent, brush10);
        pushButton_wypozycz->setPalette(palette);

        horizontalLayout_wyloguj->addWidget(pushButton_wypozycz);

        label_samochody_2 = new QLabel(tab_wyborsamochodu);
        label_samochody_2->setObjectName("label_samochody_2");
        label_samochody_2->setGeometry(QRect(340, 30, 401, 21));
        tabWidget->addTab(tab_wyborsamochodu, QString());
        tab_historia = new QWidget();
        tab_historia->setObjectName("tab_historia");
        listWidget_twojahistoria = new QListWidget(tab_historia);
        listWidget_twojahistoria->setObjectName("listWidget_twojahistoria");
        listWidget_twojahistoria->setGeometry(QRect(10, 30, 731, 261));
        label_twojahistoria = new QLabel(tab_historia);
        label_twojahistoria->setObjectName("label_twojahistoria");
        label_twojahistoria->setGeometry(QRect(10, 0, 731, 31));
        layoutWidget1 = new QWidget(tab_historia);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 300, 311, 31));
        horizontalLayout_wyloguj2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_wyloguj2->setObjectName("horizontalLayout_wyloguj2");
        horizontalLayout_wyloguj2->setContentsMargins(0, 0, 0, 0);
        pushButton_wyloguj_2 = new QPushButton(layoutWidget1);
        pushButton_wyloguj_2->setObjectName("pushButton_wyloguj_2");

        horizontalLayout_wyloguj2->addWidget(pushButton_wyloguj_2);

        pushButton_odswiez = new QPushButton(layoutWidget1);
        pushButton_odswiez->setObjectName("pushButton_odswiez");

        horizontalLayout_wyloguj2->addWidget(pushButton_odswiez);

        tabWidget->addTab(tab_historia, QString());
        klientWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(klientWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        klientWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(klientWindow);
        statusbar->setObjectName("statusbar");
        klientWindow->setStatusBar(statusbar);

        retranslateUi(klientWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(klientWindow);
    } // setupUi

    void retranslateUi(QMainWindow *klientWindow)
    {
        klientWindow->setWindowTitle(QCoreApplication::translate("klientWindow", "Wypozyczalnia Samochod\303\263w", nullptr));
        groupBox_rej->setTitle(QCoreApplication::translate("klientWindow", "Rejestracja:", nullptr));
        label_rej_imie->setText(QCoreApplication::translate("klientWindow", " Imi\304\231:        ", nullptr));
        label_rej_nazwisko->setText(QCoreApplication::translate("klientWindow", "Nazwisko:", nullptr));
        label_rej_pesel->setText(QCoreApplication::translate("klientWindow", "PESEL:      ", nullptr));
        label_rej_tel->setText(QCoreApplication::translate("klientWindow", "Nr tel.:      ", nullptr));
        label_rej_email->setText(QCoreApplication::translate("klientWindow", "E-mail:     ", nullptr));
        label_rej_haslo->setText(QCoreApplication::translate("klientWindow", "Has\305\202o:      ", nullptr));
        pushButton_rej->setText(QCoreApplication::translate("klientWindow", "Rejestracja", nullptr));
        pushButton_rej_powrot->setText(QCoreApplication::translate("klientWindow", "Powr\303\263t", nullptr));
        groupBox_logowanie->setTitle(QCoreApplication::translate("klientWindow", "Logowanie:", nullptr));
        label_l_email->setText(QCoreApplication::translate("klientWindow", "e-mail:", nullptr));
        label_l_haslo->setText(QCoreApplication::translate("klientWindow", "has\305\202o:  ", nullptr));
        pushButton_logowanie->setText(QCoreApplication::translate("klientWindow", "Zaloguj si\304\231", nullptr));
        label_l_rej->setText(QCoreApplication::translate("klientWindow", "Nie masz konta?", nullptr));
        pushButton_l_rej->setText(QCoreApplication::translate("klientWindow", "Zarejestruj si\304\231", nullptr));
        label_samochody->setText(QCoreApplication::translate("klientWindow", "Dost\304\231pne samochody:", nullptr));
        groupBox_wybdate->setTitle(QCoreApplication::translate("klientWindow", "Wyb\303\263r daty:", nullptr));
        label_dataOd->setText(QCoreApplication::translate("klientWindow", "Wypo\305\274yczenie od:", nullptr));
        label_dataDo->setText(QCoreApplication::translate("klientWindow", "Wypo\305\274yczenie do:", nullptr));
        label->setText(QCoreApplication::translate("klientWindow", "Rodzaj:", nullptr));
        label_2->setText(QCoreApplication::translate("klientWindow", "Marka: ", nullptr));
        pushButton__wybdate_szukaj->setText(QCoreApplication::translate("klientWindow", "Szukaj", nullptr));
        pushButton_wyloguj->setText(QCoreApplication::translate("klientWindow", "Wyloguj si\304\231", nullptr));
        pushButton_wypozycz->setText(QCoreApplication::translate("klientWindow", "Wypo\305\274ycz", nullptr));
        label_samochody_2->setText(QCoreApplication::translate("klientWindow", "TextLabel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_wyborsamochodu), QCoreApplication::translate("klientWindow", "Wypo\305\274yczenie samochodu:", nullptr));
        label_twojahistoria->setText(QCoreApplication::translate("klientWindow", "textLabel", nullptr));
        pushButton_wyloguj_2->setText(QCoreApplication::translate("klientWindow", "Wyloguj si\304\231", nullptr));
        pushButton_odswiez->setText(QCoreApplication::translate("klientWindow", "Od\305\233wie\305\274", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_historia), QCoreApplication::translate("klientWindow", "Historia wypo\305\274ycze\305\204:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class klientWindow: public Ui_klientWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KLIENTWINDOW_H
