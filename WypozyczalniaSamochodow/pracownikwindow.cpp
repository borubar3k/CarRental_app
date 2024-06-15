#include "pracownikwindow.h"
#include "ui_pracownikwindow.h"
#include "klientwindow.h"

pracownikWindow::pracownikWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::pracownikWindow)
{
    ui->setupUi(this);

    ui->tabWidget->setVisible(false);
    ui->label_zaczynamy->setText("Witaj");
    ui->label_zaczynamy_data->setText(QDate::currentDate().toString());

    QPixmap tloLogin("C:/Users/bruba/Documents/WypozyczalniaSamochodow/imagesWS/img1.jpg");
    tloLogin = tloLogin.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, tloLogin);
    this->setPalette(palette);

    ui->dateEdit_form_dataOd->setMinimumDate(QDate::currentDate());
    ui->dateEdit_form_dataDo->setMinimumDate(QDate::currentDate());

    ui->comboBox->addItem("Klienci zarejestrowani");
    ui->comboBox->addItem("Klienci niezarejestrowani");
    ui->comboBox_sam_oddzial->addItem(" ");
    ui->comboBox_sam_oddzial->addItem("ul. Hetmańska 73, Rzeszów");
    ui->comboBox_sam_oddzial->addItem("ul. Langiewicza 7A, Rzeszów");

    ui->comboBox_sam_rodzaj->addItem(" ");
    ui->comboBox_sam_rodzaj->addItem("SUV");
    ui->comboBox_sam_rodzaj->addItem("sedan");
    ui->comboBox_sam_rodzaj->addItem("kombi");
    ui->comboBox_sam_rodzaj->addItem("hatchback");

    ui->comboBox_sam_marka->addItem(" ");
    ui->comboBox_sam_marka->addItem("Volvo");
    ui->comboBox_sam_marka->addItem("Audi");
    ui->comboBox_sam_marka->addItem("BMW");
    ui->comboBox_sam_marka->addItem("Fiat");
    ui->comboBox_sam_marka->addItem("Ford");
    ui->comboBox_sam_marka->addItem("Honda");
    ui->comboBox_sam_marka->addItem("Hyundai");
    ui->comboBox_sam_marka->addItem("Mercedes");
    ui->comboBox_sam_marka->addItem("Opel");
    ui->comboBox_sam_marka->addItem("Seat");
    ui->comboBox_sam_marka->addItem("Skoda");
    ui->comboBox_sam_marka->addItem("Toyota");
    ui->comboBox_sam_marka->addItem("Volkswagen");

    ui->comboBox_pracownicy_oddzial->addItem(" ");
    ui->comboBox_pracownicy_oddzial->addItem("ul. Hetmańska 73, Rzeszów");
    ui->comboBox_pracownicy_oddzial->addItem("ul. Langiewicza 7A, Rzeszów");
    ustawComboBoxPrzelozony();
    ustawComboBoxStanowiska();
    ustawComboBoxStatystyki();

    ui->label_form->setText("Marka  |  Model  |  Rodzaj  |  Cena  |  Nr rejestracyjny");
    ui->label_listWyp->setText("Data wypożyczenia od/do  |  Marka  |  Model  |  Nr rejestracyjny  |  Należność  |  Czy oddany?  |  Imie  |  Nazwisko  |  PESEL  |  Nr telefonu  |  E-mail");
    ui->label_pracownicy->setText("Imie  |  Nazwisko  |  Oddział  |  Stanowisko  |  Przełożony  |  E-mail");
    ui->label_sam->setText("Oddział  |  Marka  |  Model  |  Nr rejestracyjny  |  Nr VIN  |  Rodzaj  |  Cena");
}
pracownikWindow::~pracownikWindow()
{
    delete ui;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////// Obsluga przyciskow //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void pracownikWindow::on_pushButton_listWyp_odswiez_clicked()
{
    klientWindow conn;
    QString wybierz = ui->comboBox->currentText();
    QList<QString> dane;
    conn.otwieraniePolaczenia();
    QString wybor;
    if(wybierz=="Klienci zarejestrowani")
        wybor="SELECT WYPOZYCZENIA.data_wypozyczenia_OD, WYPOZYCZENIA.data_wypozyczenia_DO, WYPOZYCZENIA.do_zaplaty, WYPOZYCZENIA.oddany, SAMOCHODY.id_samochodu, SAMOCHODY.marka, SAMOCHODY.model, SAMOCHODY.nr_rejestracyjny, KLIENCI.imie, KLIENCI.nazwisko, KLIENCI.adres_email, KLIENCI.nr_tel, KLIENCI.pesel FROM WYPOZYCZENIA JOIN KLIENCI ON WYPOZYCZENIA.id_klienta=KLIENCI.id_klienta JOIN SAMOCHODY ON WYPOZYCZENIA.id_samochodu=SAMOCHODY.id_samochodu WHERE SAMOCHODY.id_oddzialu=(SELECT id_oddzialu FROM PRACOWNICY WHERE adres_email='"+email+"');";
    else if(wybierz=="Klienci niezarejestrowani")
        wybor="SELECT WYPOZYCZENIA.data_wypozyczenia_OD, WYPOZYCZENIA.data_wypozyczenia_DO, WYPOZYCZENIA.do_zaplaty, WYPOZYCZENIA.oddany, SAMOCHODY.id_samochodu, SAMOCHODY.marka, SAMOCHODY.model, SAMOCHODY.nr_rejestracyjny, KLIENCI_NREJ.imie, KLIENCI_NREJ.nazwisko, KLIENCI_NREJ.adres_email, KLIENCI_NREJ.nr_tel, KLIENCI_NREJ.pesel FROM WYPOZYCZENIA JOIN KLIENCI_NREJ ON WYPOZYCZENIA.id_klienta_nrej=KLIENCI_NREJ.id_klienta JOIN SAMOCHODY ON WYPOZYCZENIA.id_samochodu=SAMOCHODY.id_samochodu WHERE SAMOCHODY.id_oddzialu=(SELECT id_oddzialu FROM PRACOWNICY WHERE adres_email='"+email+"');";
    QSqlQuery query(wybor);
    if(query.exec())
    {
        int idDataOd = query.record().indexOf("data_wypozyczenia_OD");
        int idDataDo = query.record().indexOf("data_wypozyczenia_DO");
        int idZaplata = query.record().indexOf("do_zaplaty");
        int idMarka = query.record().indexOf("marka");
        int idModel = query.record().indexOf("model");
        int idRej = query.record().indexOf("nr_rejestracyjny");
        int idOddanie = query.record().indexOf("oddany");
        int idImie = query.record().indexOf("imie");
        int idNazwisko = query.record().indexOf("nazwisko");
        int idPesel = query.record().indexOf("pesel");
        int idEmail = query.record().indexOf("adres_email");
        int idNrTel = query.record().indexOf("nr_tel");
        while (query.next())
        {
            QString dataOd = query.value(idDataOd).toString();
            QString dataDo = query.value(idDataDo).toString();
            QString zaplata = query.value(idZaplata).toString();
            QString marka = query.value(idMarka).toString();
            QString model = query.value(idModel).toString();
            QString nrRej = query.value(idRej).toString();
            QString oddanie = query.value(idOddanie).toString();
            QString imie = query.value(idImie).toString();
            QString nazwisko = query.value(idNazwisko).toString();
            QString pesel = query.value(idPesel).toString();
            QString email = query.value(idEmail).toString();
            QString nrTel = query.value(idNrTel).toString();
            QString dana = dataOd+"\t"+dataDo+"\t"+marka+"\t"+model+"\t"+nrRej+"\t"+zaplata+"\t"+oddanie+"\t"+imie+"\t"+nazwisko+"\t"+pesel+"\t"+nrTel+"\t"+email;
            dane.append(dana);
        }
        conn.zamykaniePolaczenia();
    }
    ui->listWidget_listaWyp->clear();
    for(int i=0; i<dane.length();i++)
    {
        ui->listWidget_listaWyp->addItem(dane.value(i));
    }
}
void pracownikWindow::on_pushButton_listWyp_wyloguj_clicked()
{
    QCoreApplication::quit();
}
void pracownikWindow::on_pushButton_anulujwyp_clicked()
{
    klientWindow conn;
    QListWidgetItem *item = ui->listWidget_listaWyp->currentItem();
    if(item)
    {
        item->setBackground(Qt::red);
        QString dane = item->text();
        QStringList daneWyp = dane.split("\t");

        QString dataOd = daneWyp[0];
        QString dataDo = daneWyp[1];
        QString nrRej = daneWyp[4];
        conn.otwieraniePolaczenia();
        QSqlQuery query;
        query.prepare("DELETE FROM WYPOZYCZENIA WHERE data_wypozyczenia_OD='"+dataOd+"' AND data_wypozyczenia_DO='"+dataDo+"' AND id_samochodu=(SELECT id_samochodu FROM SAMOCHODY WHERE nr_rejestracyjny='"+nrRej+"');");
        if(query.exec())
        {
            QMessageBox::about(this,"Usunięto wypożyczenie","Wypożyczenie usunięto pomyślnie");
        }
        else
        {
            QMessageBox::warning(this,"Błąd usuwania wypożyczenia","Wystąpił błąd podczas usuwania wypożyczenia");
        }
        query.prepare("DELETE adres_email, nr_tel FROM KLIENCI_NREJ WHERE WYPOZYCZENIA.id_klienta_nrej=KLIENCI_NREJ.id_klienta;");
        if(query.exec())
        {
            qDebug() << "Usunięto dane niezarejestrowanego klienta";
            conn.zamykaniePolaczenia();
        }
    }
    on_pushButton_listWyp_odswiez_clicked();
}
void pracownikWindow::on_pushButton_oddany_clicked()
{
    klientWindow conn;
    QListWidgetItem *item = ui->listWidget_listaWyp->currentItem();
    if(item)
    {
        item->setBackground(Qt::red);
        QString dane = item->text();
        QStringList daneWyp = dane.split("\t");

        QString dataOd = daneWyp[0];
        QString dataDo = daneWyp[1];
        QString nrRej = daneWyp[4];
        conn.otwieraniePolaczenia();
        QSqlQuery query;
        query.prepare("UPDATE WYPOZYCZENIA SET oddany='T' WHERE data_wypozyczenia_OD='"+dataOd+"' AND data_wypozyczenia_DO='"+dataDo+"' AND id_samochodu=(SELECT id_samochodu FROM SAMOCHODY WHERE nr_rejestracyjny='"+nrRej+"');");
        if(query.exec())
        {
            QMessageBox::about(this,"Zatwierdzono oddanie","Oddano wypożyczony samochód");
        }
        else
        {
            QMessageBox::warning(this,"Błąd oddania samochodu","Wystąpił błąd podczas oddawania samochodu");
        }
        query.prepare("DELETE adres_email, nr_tel FROM KLIENCI_NREJ WHERE WYPOZYCZENIA.id_klienta_nrej=KLIENCI_NREJ.id_klienta;");
        if(query.exec())
        {
            qDebug() << "Usunięto dane niezarejestrowanego klienta";
            conn.zamykaniePolaczenia();
        }
    }
    on_pushButton_listWyp_odswiez_clicked();
}
void pracownikWindow::on_pushButton_form_poka_clicked()
{
    klientWindow conn;
    dataOd = ui->dateEdit_form_dataOd->date();
    dataDo = ui->dateEdit_form_dataDo->date();

    conn.otwieraniePolaczenia();

    QList<QString> samochody;
    QSqlQuery query;
    query.prepare("SELECT marka, model, rodzaj, cena, nr_rejestracyjny FROM SAMOCHODY WHERE SAMOCHODY.id_oddzialu=(SELECT PRACOWNICY.id_oddzialu FROM PRACOWNICY WHERE PRACOWNICY.adres_email='"+email+"') AND NOT EXISTS (SELECT * FROM WYPOZYCZENIA WHERE SAMOCHODY.id_samochodu = WYPOZYCZENIA.id_samochodu AND ((data_wypozyczenia_OD <= '"+dataOd.toString("yyyy-MM-dd")+"' AND data_wypozyczenia_DO >= '"+dataDo.toString("yyyy-MM-dd")+"') OR (data_wypozyczenia_OD BETWEEN '"+dataOd.toString("yyyy-MM-dd")+"' AND '"+dataDo.toString("yyyy-MM-dd")+"') OR (data_wypozyczenia_DO BETWEEN '"+dataOd.toString("yyyy-MM-dd")+"' AND '"+dataDo.toString("yyyy-MM-dd")+"')));");
    if(query.exec())
    {
        int idMarka = query.record().indexOf("marka");
        int idModel = query.record().indexOf("model");
        int idRodzaj = query.record().indexOf("rodzaj");
        int idCena = query.record().indexOf("cena");
        int idRej = query.record().indexOf("nr_rejestracyjny");
        while (query.next())
        {
            QString marka = query.value(idMarka).toString();
            QString model = query.value(idModel).toString();
            QString rodzaj = query.value(idRodzaj).toString();
            QString cena = query.value(idCena).toString();
            QString nrRej = query.value(idRej).toString();
            QString samochod = marka + "\t" + model + "\t" + rodzaj + "\t" + cena + "zł/doba\t" + nrRej;
            samochody.append(samochod);
        }
        conn.zamykaniePolaczenia();
    }
    ui->listWidget_form->clear();
    for(int i=0; i<samochody.length(); i++)
    {
         ui->listWidget_form->addItem(samochody.value(i));
    }
}
void pracownikWindow::on_pushButton_form_wypozycz_clicked()
{
    klientWindow conn;
    QString imie = ui->lineEdit_form_imie->text();
    QString nazwisko = ui->lineEdit_form_nazwisko->text();
    QString pesel = ui->lineEdit_form_pesel->text();
    QString email = ui->lineEdit_form_email->text();
    QString tel = ui->lineEdit_form_tel->text();

    if(!sprawdzenieTelefonuPesel(tel,9) || !sprawdzanieEmaila(email) || !sprawdzenieTelefonuPesel(pesel, 11))
    {
        QMessageBox::critical(this, "Błędne dane", "Sprawdź poprawność wpisanych danych");
    }
    else
    {
        conn.otwieraniePolaczenia();
        QSqlQuery query;
        query.prepare("INSERT INTO KLIENCI_NREJ (imie, nazwisko, pesel, nr_tel, adres_email) VALUES ('"+imie+"','"+nazwisko+"','"+pesel+"', '"+tel+"','"+email+"');");
        if(query.exec())
        {
            qDebug() << "Zapisano dane klienta";
        }
        dataOd = ui->dateEdit_form_dataOd->date();
        dataDo = ui->dateEdit_form_dataDo->date();

        QListWidgetItem *item = ui->listWidget_form->currentItem();
        item->setBackground(Qt::red);
        QString dane = item->text();
        QStringList daneSamochodu = dane.split("\t");

        QString cena = daneSamochodu[3];
        cena.replace("zł/doba", "");
        int cena2 = cena.toInt()*(dataOd.daysTo(dataDo.addDays(1)));
        QString cena3= QString::number(cena2);

        QString nr_rejestracyjny = daneSamochodu[4];

        query.prepare("INSERT INTO WYPOZYCZENIA (id_klienta_nrej, id_samochodu, data_wypozyczenia_OD, data_wypozyczenia_DO, do_zaplaty) VALUES ((SELECT id_klienta FROM KLIENCI_NREJ WHERE adres_email='"+email+"'),(SELECT id_samochodu FROM SAMOCHODY WHERE nr_rejestracyjny='"+nr_rejestracyjny+"'),'"+dataOd.toString("yyyy-MM-dd")+"','"+dataDo.toString("yyyy-MM-dd")+"','"+cena3+"');");
        if(query.exec())
        {
            qDebug() << "Dodano wypozyczenie do bazy";
            QMessageBox::information(this,"Wypożyczono samochód","Wypożyczono samochód klientowi bez konta");
            conn.zamykaniePolaczenia();
        }
        else
        {
            qDebug() << "Błąd w wypozyczeniu";
        }
    }
    on_pushButton_listWyp_odswiez_clicked();
    on_pushButton_form_poka_clicked();
}
void pracownikWindow::on_pushButton_form_wyloguj_clicked()
{
    QCoreApplication::quit();
}
void pracownikWindow::on_pushButton_sam_wyloguj_clicked()
{
    QCoreApplication::quit();
}
void pracownikWindow::on_pushButton_sam_poka_clicked()
{
    klientWindow conn;
    conn.otwieraniePolaczenia();
    QList<QString> samochody;
    QSqlQuery query;
    int ilosc=1;
    query.prepare("SELECT ODDZIALY.adres_oddzialu, SAMOCHODY.marka, SAMOCHODY.model, SAMOCHODY.nr_rejestracyjny, SAMOCHODY.nr_vin, SAMOCHODY.rodzaj, SAMOCHODY.cena FROM SAMOCHODY JOIN ODDZIALY ON SAMOCHODY.id_oddzialu = ODDZIALY.id_oddzialu ORDER BY ODDZIALY.adres_oddzialu ASC, SAMOCHODY.nr_vin ASC, Samochody.marka ASC;");
    if(query.exec())
    {
        int idAdr = query.record().indexOf("adres_oddzialu");
        int idMarka = query.record().indexOf("marka");
        int idModel = query.record().indexOf("model");
        int idRej = query.record().indexOf("nr_rejestracyjny");
        int idVin = query.record().indexOf("nr_vin");
        int idRodzaj = query.record().indexOf("rodzaj");
        int idCena = query.record().indexOf("cena");
        while (query.next())
        {
            QString adres = query.value(idAdr).toString();
            QString marka = query.value(idMarka).toString();
            QString model = query.value(idModel).toString();
            QString nrRej = query.value(idRej).toString();
            QString nrVin = query.value(idVin).toString();
            QString rodzaj = query.value(idRodzaj).toString();
            QString cena = query.value(idCena).toString();
            QString il = QString::number(ilosc);
            ilosc++;
            QString samochod =il+"\t"+adres+"\t"+marka+"\t"+model+"\t"+nrRej+"\t"+nrVin+"\t"+rodzaj+"\t"+cena+"zł/doba\t";
            samochody.append(samochod);
        }
        conn.zamykaniePolaczenia();
        ui->listWidget_sam->clear();
        for(int i=0; i<samochody.length(); i++)
        {
            ui->listWidget_sam->addItem(samochody.value(i));
        }
    }
}
void pracownikWindow::on_pushButton_sam_dodaj_clicked()
{
    klientWindow conn;
    QString marka = ui->comboBox_sam_marka->currentText();
    QString model = ui->lineEdit_sam_model->text();
    QString rodzaj = ui->comboBox_sam_rodzaj->currentText();
    QString nrRej = ui->lineEdit_sam_nrrej->text();
    QString nrVIN = ui->lineEdit_sam_vin->text();
    QString cena = ui->lineEdit_sam_cena->text();
    QString oddzial = ui->comboBox_sam_oddzial->currentText();
    QString oddzial2;
    if(oddzial=="ul. Hetmańska 73, Rzeszów")
        oddzial2 = "1";
    else if(oddzial=="ul. Langiewicza 7A, Rzeszów")
        oddzial2 = "2";
    if(marka==" " || model=="" || rodzaj==" " || nrRej=="" || cena=="")
    {
        QMessageBox::critical(this,"Brak danych", "Uzupełnij brakujące dane");
    }
    else
    {
        while(true)
        {
            if(!sprawdzenieTelefonuPesel(nrVIN,17))
            {
                QMessageBox::critical(this, "Błędny VIN", "Podany numer VIN jest za krótki");
                break;
            }
            else
            {
                conn.otwieraniePolaczenia();
                QSqlQuery query;
                query.prepare("INSERT INTO SAMOCHODY (id_oddzialu, marka, model, nr_rejestracyjny, nr_vin, rodzaj, cena) VALUES ('"+oddzial2+"','"+marka+"','"+model+"', '"+nrRej+"','"+nrVIN+"', '"+rodzaj+"', '"+cena+"');");
                if(query.exec())
                {
                    QMessageBox::about(this,"Dodano samochód", "Dodano nowy samochód do bazy");
                    qDebug() << "Dodano samochód do bazy";
                    conn.zamykaniePolaczenia();
                }
                break;
            }
        }
        on_pushButton_sam_poka_clicked();
    }
}
void pracownikWindow::on_pushButton_pracownicy_odswiez_clicked()
{
    klientWindow conn;
    QList<QString> dane;
    conn.otwieraniePolaczenia();
    QSqlQuery query("SELECT PRACOWNICY.imie,PRACOWNICY.nazwisko,PRACOWNICY.adres_email,ODDZIALY.adres_oddzialu,STANOWISKA.stanowisko, (SELECT imie || ' ' || nazwisko FROM PRACOWNICY AS P WHERE P.id_pracownika = PRACOWNICY.id_przelozonego) AS PRZELOZONY FROM PRACOWNICY JOIN ODDZIALY ON PRACOWNICY.id_oddzialu = ODDZIALY.id_oddzialu JOIN STANOWISKA ON PRACOWNICY.id_stanowiska = STANOWISKA.id_stanowiska LEFT JOIN PRACOWNICY AS P2 ON PRACOWNICY.id_pracownika = P2.id_pracownika;");

    int idImie = query.record().indexOf("PRACOWNICY.imie");
    int idNazwisko = query.record().indexOf("PRACOWNICY.nazwisko");
    int idEmail = query.record().indexOf("PRACOWNICY.adres_email");
    int idOddzial = query.record().indexOf("ODDZIALY.adres_oddzialu");
    int iStanowisko = query.record().indexOf("STANOWISKA.stanowisko");
    int idPrzelozony = query.record().indexOf("PRZELOZONY");

    while (query.next())
    {
        QString imie = query.value(idImie).toString();
        QString nazwisko = query.value(idNazwisko).toString();
        QString aEmail = query.value(idEmail).toString();
        QString oddzial = query.value(idOddzial).toString();
        QString stanowisko = query.value(iStanowisko).toString();
        QString przelozony = query.value(idPrzelozony).toString();

        QString dana = imie+"\t"+nazwisko+"\t"+oddzial+"\t"+stanowisko+"\t"+przelozony+"\t"+aEmail;
        dane.append(dana);
    }
    conn.zamykaniePolaczenia();
    ui->listWidget_pracownicy->clear();
    for(int i=0; i<dane.length();i++)
    {
        ui->listWidget_pracownicy->addItem(dane.value(i));
    }
}
void pracownikWindow::on_pushButton_pracownicy_wyloguj_clicked()
{
    QCoreApplication::quit();
}
void pracownikWindow::on_pushButton_pracownicy_usun_clicked()
{
    klientWindow conn;
    QListWidgetItem *item = ui->listWidget_pracownicy->currentItem();
    if(item)
    {
        item->setBackground(Qt::red);
        QString dane = item->text();
        QStringList daneWyp = dane.split("\t");

        QString aEmail = daneWyp[5];
        conn.otwieraniePolaczenia();
        QSqlQuery query;
        query.prepare("DELETE FROM PRACOWNICY WHERE adres_email='"+aEmail+"';");
        if(query.exec())
        {
            QMessageBox::about(this,"Usunięto pracownika", "Usunięto pracownika z bazy danych");
            qDebug() << "Usunięto pracownika";
            conn.zamykaniePolaczenia();
        }
    }
    on_pushButton_pracownicy_odswiez_clicked();
}
void pracownikWindow::on_pushButton_pracownicy_dodaj_clicked()
{
    klientWindow conn;
    QString imie = ui->lineEdit_pracownicy_imie->text();
    QString nazwisko = ui->lineEdit_pracownicy_nazwisko->text();
    QString aEmail = ui->lineEdit_pracownicy_email->text();
    QString oddzial = ui->comboBox_pracownicy_oddzial->currentText();
    QString przelozony = ui->comboBox_pracownicy_przlozony->currentText();
    QString stanowisko = ui->comboBox_pacownicy_stanowisko->currentText();
    QString haslo = ui->lineEdit_pracownicy_haslo->text();
    QString oddzial2, przelozony2, stanowisko2;
    if(oddzial=="ul. Hetmańska 73, Rzeszów")
        oddzial2 = "1";
    else if(oddzial=="ul. Langiewicza 7A, Rzeszów")
        oddzial2 = "2";

    if(imie=="" || nazwisko=="" || aEmail=="" || przelozony==" " || stanowisko==" " || haslo=="")
    {
        QMessageBox::critical(this,"Brak danych", "Uzupełnij brakujące dane");
    }
    else
    {
        while(true)
        {
            QStringList danePrzelozonego = przelozony.split(" ");
            przelozony2 = danePrzelozonego[0];
            QStringList daneStanowiska = stanowisko.split(" ");
            stanowisko2 = daneStanowiska[0];

            {
                conn.otwieraniePolaczenia();
                QSqlQuery query;
                query.prepare("INSERT INTO PRACOWNICY (imie, nazwisko, adres_email, id_oddzialu, id_przelozonego, id_stanowiska, haslo) VALUES ('"+imie+"','"+nazwisko+"','"+aEmail+"', '"+oddzial2+"','"+przelozony2+"', '"+stanowisko2+"', '"+haslo+"');");
                if(query.exec())
                {
                    QMessageBox::about(this,"Dodano pracownika", "Dodano nowego pracownika do bazy danych");
                    qDebug() << "Dodano pracownika do bazy";
                    conn.zamykaniePolaczenia();
                }
                break;
            }
        }
        on_pushButton_pracownicy_odswiez_clicked();
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////// Reszta kodu /////////////////////////////////////////
void pracownikWindow::getEmail(const QString& email)
{
    this->email=email;
    qDebug() <<email;
}


void pracownikWindow::ustawComboBoxPrzelozony()
{
    klientWindow conn;
    ui->comboBox_pracownicy_przlozony->addItem(" ");
    conn.otwieraniePolaczenia();
    QSqlQuery query;
    query.prepare("SELECT id_pracownika, imie, nazwisko, id_stanowiska FROM PRACOWNICY WHERE id_stanowiska!='0' and id_stanowiska!='5' ;");
    if(query.exec())
    {
        int idId = query.record().indexOf("id_pracownika");
        int idImie = query.record().indexOf("imie");
        int idNazwisko = query.record().indexOf("nazwisko");
        int idIdS = query.record().indexOf("id_stanowiska");
        while(query.next())
        {
            QString imie = query.value(idImie).toString();
            QString nazwisko = query.value(idNazwisko).toString();
            QString id = query.value(idId).toString();
            QString idS = query.value(idIdS).toString();
            ui->comboBox_pracownicy_przlozony->addItem(id+" "+imie+" "+nazwisko+" "+idS);
        }
        conn.zamykaniePolaczenia();
    }
}
void pracownikWindow::ustawComboBoxStanowiska()
{
    klientWindow conn;
    ui->comboBox_pacownicy_stanowisko->addItem(" ");
    conn.otwieraniePolaczenia();
    QSqlQuery query;
    query.prepare("SELECT id_stanowiska, stanowisko FROM STANOWISKA WHERE id_stanowiska!='1' and id_stanowiska!='0';");
    if(query.exec())
    {
        int idId = query.record().indexOf("id_stanowiska");
        int idStanowisko = query.record().indexOf("stanowisko");
        while(query.next())
        {
            QString id = query.value(idId).toString();
            QString stanowisko = query.value(idStanowisko).toString();
            ui->comboBox_pacownicy_stanowisko->addItem(id+" "+stanowisko);
        }
        conn.zamykaniePolaczenia();
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////// Walidacja danych ////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool pracownikWindow::sprawdzenieTelefonuPesel(const QString& numer, int nr)
{
    if (numer.length() != nr) {
        return false;
    }
    for (QChar digit : numer) {
        if (digit < '0' || digit > '9') {
            return false;
        }
    }
    return true;
}
bool pracownikWindow::sprawdzanieEmaila(const QString& email)
{
    for (QChar znak : email) {
        if (znak == '@')
        {
            return true;
        }
    }
    return false;
}
void pracownikWindow::on_pushButton_zaczynamy_clicked()
{
    klientWindow conn;
    on_pushButton_listWyp_odswiez_clicked();
    on_pushButton_form_poka_clicked();
    on_pushButton_sam_poka_clicked();
    on_pushButton_pracownicy_odswiez_clicked();
    QString stanowisko;
    ui->pushButton_zaczynamy->setVisible(false);
    ui->label_zaczynamy->setVisible(false);
    ui->label_zaczynamy_data->setVisible(false);
    ui->tabWidget->setVisible(true);
    conn.otwieraniePolaczenia();
    QSqlQuery query;
    query.prepare("SELECT id_stanowiska FROM PRACOWNICY WHERE adres_email='"+email+"';");
    if(query.exec())
    {
        while(query.next())
        {
            stanowisko = query.value(0).toString();
        }
        conn.zamykaniePolaczenia();
    }
    if(stanowisko=="0" || stanowisko=="1")
    {
        ui->tabWidget->setTabVisible(3,true);
        ui->tabWidget->setTabVisible(4,true);
        on_pushButton_statystyki_odswiez_clicked();
    }
    else
    {
        ui->tabWidget->setTabVisible(3,false);
        ui->tabWidget->setTabVisible(4,false);
    }
}
void pracownikWindow::on_pushButton_statystyki_wyloguj_clicked()
{
    QCoreApplication::quit();
}
void pracownikWindow::ustawComboBoxStatystyki()
{
    for(QDate i = QDate(2024, 4, 1); i <= QDate::currentDate().addMonths(3); i = i.addMonths(1))
    {
        ui->comboBox_statystyki_miesiac->addItem(i.toString("yyyy-MM"));
    }
}
void pracownikWindow::on_pushButton_statystyki_odswiez_clicked()
{
    klientWindow conn;
    QDate data = QDate::fromString(ui->comboBox_statystyki_miesiac->currentText(), "yyyy-MM");
    int dni = data.daysInMonth();
    QString data2 = data.toString("yyyy-MM")+"-"+QString::number(dni);
    QString data3 = data.toString("yyyy-MM")+"-"+"01";
    QString iloscWyp;
    conn.otwieraniePolaczenia();
    QSqlQuery query;
    query.prepare("SELECT COUNT(id_wypozyczenia) FROM WYPOZYCZENIA;");
    if(query.exec())
    {
        while(query.next())
        {
            iloscWyp = query.value(0).toString();
        }
        ui->label_ilosc_wypozyczen->setText("Ilość wypożyczeń w historii firmy: "+iloscWyp+".");
    }
    query.prepare("SELECT COUNT(id_wypozyczenia) FROM WYPOZYCZENIA WHERE data_wypozyczenia_OD>='"+data3+"' AND data_wypozyczenia_OD <= '"+data2+"';");
    if(query.exec())
    {
        while(query.next())
        {
            iloscWyp = query.value(0).toString();
        }
        ui->label_ilosc_wyp_mies->setText("Ilość wypożyczonych samochodów w tym miesiącu: "+iloscWyp+".");
    }
    query.prepare("SELECT COUNT(WYPOZYCZENIA.id_wypozyczenia) FROM WYPOZYCZENIA JOIN SAMOCHODY ON WYPOZYCZENIA.id_samochodu=SAMOCHODY.id_samochodu WHERE data_wypozyczenia_OD>='"+data3+"' AND data_wypozyczenia_OD <= '"+data2+"' AND SAMOCHODY.id_oddzialu=1;");
    if(query.exec())
    {
        while(query.next())
        {
            iloscWyp=query.value(0).toString();
        }
        ui->label_ilosc_wyp_1->setText("Ilość wypożyczonych samochodów w tym miesiącu w oddziale przy ul.Hetmańskiej: "+iloscWyp+".");
    }
    query.prepare("SELECT COUNT(WYPOZYCZENIA.id_wypozyczenia) FROM WYPOZYCZENIA JOIN SAMOCHODY ON WYPOZYCZENIA.id_samochodu=SAMOCHODY.id_samochodu WHERE data_wypozyczenia_OD>='"+data3+"' AND data_wypozyczenia_OD <= '"+data2+"' AND SAMOCHODY.id_oddzialu=2;");
    if(query.exec())
    {
        while(query.next())
        {
            iloscWyp=query.value(0).toString();
        }
        ui->label_ilosc_wyp_2->setText("Ilość wypożyczonych samochodów w tym miesiącu w oddziale przy ul.Langiewicza: "+iloscWyp+".");
    }
    query.prepare("SELECT COUNT(id_wypozyczenia) FROM WYPOZYCZENIA WHERE data_wypozyczenia_OD>='"+data3+"' AND data_wypozyczenia_OD <= '"+data2+"' AND id_klienta_nrej IS NULL;");
    if(query.exec())
    {
        while(query.next())
        {
            iloscWyp=query.value(0).toString();
        }
        ui->label_ilosc_wyp_rej->setText("Ilość wypożyczonych samochodów przez klientów niezarejestrowanych w tym miesiącu: "+iloscWyp+".");
    }
    query.prepare("SELECT COUNT(id_wypozyczenia) FROM WYPOZYCZENIA WHERE data_wypozyczenia_OD>='"+data3+"' AND data_wypozyczenia_OD <= '"+data2+"' AND id_klienta IS NULL;");
    if(query.exec())
    {
        while(query.next())
        {
            iloscWyp=query.value(0).toString();
        }
        ui->label_ilosc_wyp_nrej->setText("Ilość wypożyczonych samochodów przez klientów zarejestrowanych w tym miesiącu: "+iloscWyp+".");
        conn.zamykaniePolaczenia();
    }
}
