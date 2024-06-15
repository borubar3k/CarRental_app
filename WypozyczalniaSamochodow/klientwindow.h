#ifndef KLIENTWINDOW_H
#define KLIENTWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QWidget>
#include <QTimer>
#include <QDate>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include "pracownikwindow.h"
#include <QThread>
#include "klientQThread.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class klientWindow;
}
QT_END_NAMESPACE

class klientWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase wsBaza;
    bool otwieraniePolaczenia()
    {
        wsBaza = QSqlDatabase::addDatabase("QSQLITE");
        wsBaza.setDatabaseName(("C:/Users/bruba/Documents/WypozyczalniaSamochodow/WypozyczalniaSamochodow.db"));

        if(!wsBaza.open())
        {
            qDebug() << "Error: Not connected";
            return false;
        }
        else
        {
            qDebug() << "Connected...";
            return true;
        }
    }
    void zamykaniePolaczenia()
    {
        wsBaza.close();
        //wsBaza.removeDatabase("C:/Users/bruba/Documents/WypozyczalniaSamochodow/WypozyczalniaSamochodow.db");
        wsBaza.removeDatabase(QSqlDatabase::defaultConnection);
        qDebug() << "...Disconnected";
    }


public:
    explicit klientWindow(QWidget *parent = nullptr);
    ~klientWindow();


    ///////////////////////////////// Walidacja danych ///////////////////////////////////////////////////////////////////////////////
    bool sprawdzenieTelefonuPesel(const QString& numer, int nr);
    bool sprawdzanieEmaila(const QString& email);
    bool sprawdzanieHasla(const QString& haslo);
    QString zmianaLiteryNaDuza(QString& nazwa);
    bool sprawdzanieDanychRejestracja(const QString& pesel, const QString& email, const QString& tel);
signals:
    void sygnalEmail(const QString& email);
    void sygnalDostepne(const QString& dataOd, const QString& dataDo, const QString& wybranyRodzaj, const QString& wybranaMarka);
public slots:
    void listaWypozyczen(QList<QString>);
    void pobierzDostepne(QList<QString>);
private slots:

    void on_pushButton_logowanie_clicked();

    void on_pushButton_l_rej_clicked();

    void on_pushButton_rej_clicked();

    void on_pushButton_rej_powrot_clicked();

    void on_pushButton_wyloguj_clicked();

    void on_pushButton__wybdate_szukaj_clicked();

    void on_pushButton_wypozycz_clicked();

    void on_pushButton_wyloguj_2_clicked();

    void on_pushButton_odswiez_clicked();

private:
    Ui::klientWindow *ui;
    QDate dataOd, dataDo;
    QString email;
    pracownikWindow *pracownikwindow;

    QThread thread;
    klientQThread klientqthread;
};
#endif // KLIENTWINDOW_H
