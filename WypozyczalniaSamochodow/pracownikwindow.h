#ifndef PRACOWNIKWINDOW_H
#define PRACOWNIKWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDate>

namespace Ui {
class pracownikWindow;
}

class pracownikWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit pracownikWindow(QWidget *parent = nullptr);
    ~pracownikWindow();
    void getEmail(const QString& email);
    ////////////////////////////////////
    bool sprawdzanieEmaila(const QString& email);
    bool sprawdzenieTelefonuPesel(const QString& numer, int nr);
    void ustawComboBoxPrzelozony();
    void ustawComboBoxStanowiska();
    void ustawComboBoxStatystyki();
private slots:

    void on_pushButton_listWyp_odswiez_clicked();

    void on_pushButton_listWyp_wyloguj_clicked();

    void on_pushButton_anulujwyp_clicked();

    void on_pushButton_oddany_clicked();

    void on_pushButton_form_wypozycz_clicked();

    void on_pushButton_form_poka_clicked();

    void on_pushButton_form_wyloguj_clicked();

    void on_pushButton_sam_wyloguj_clicked();

    void on_pushButton_sam_poka_clicked();

    void on_pushButton_sam_dodaj_clicked();

    void on_pushButton_pracownicy_wyloguj_clicked();

    void on_pushButton_pracownicy_odswiez_clicked();

    void on_pushButton_pracownicy_usun_clicked();

    void on_pushButton_pracownicy_dodaj_clicked();

    void on_pushButton_zaczynamy_clicked();

    void on_pushButton_statystyki_wyloguj_clicked();

    void on_pushButton_statystyki_odswiez_clicked();

private:
    Ui::pracownikWindow *ui;
    QString email, stanowisko;
    QDate dataOd, dataDo;
};

#endif // PRACOWNIKWINDOW_H
