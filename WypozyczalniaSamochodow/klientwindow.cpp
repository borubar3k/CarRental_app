#include "klientwindow.h"
#include "ui_klientwindow.h"


klientWindow::klientWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::klientWindow)
{
    qDebug() << "Wątek klientWindow: " << QThread::currentThreadId();
    ui->setupUi(this);
    QPixmap tloLogin("C:/Users/bruba/Documents/WypozyczalniaSamochodow//imagesWS/img3.jpg");
    tloLogin = tloLogin.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, tloLogin);
    this->setPalette(palette);
    /////////////////////////////////////////// klientQThread  ///////////////////////////////////////////////////////////
    connect(&klientqthread, &klientQThread::listaWypozyczenGotowa, this, &klientWindow::listaWypozyczen);
    connect(this, &klientWindow::sygnalEmail, &klientqthread, &klientQThread::pobranyAdres);
    connect(&klientqthread, &klientQThread::listaDostepnychSamochodowGotowa,this, &klientWindow::pobierzDostepne);
    connect(this, &klientWindow::sygnalDostepne, &klientqthread, &klientQThread::pobierzDostepneSamochody);
    klientqthread.moveToThread(&thread);
    thread.start();




    ui->groupBox_rej->setVisible(false);
    ui->tabWidget->setVisible(false);

    ui->dateEdit_dataOd->setMinimumDate(QDate::currentDate());
    ui->dateEdit_dataDo->setMinimumDate(QDate::currentDate());
    while((ui->dateEdit_dataDo->date())<(ui->dateEdit_dataOd->date()))
    {
        ui->dateEdit_dataDo->setDate(ui->dateEdit_dataOd->date());
    }

    ui->label_samochody_2->setText(" Marka              Model               Rodzaj              Cena/dobę          Nr rej");
    ui->label_twojahistoria->setText("Data wypożyczenia od/do          Marka           Model                Rodzaj                 Nr rej.                  Oddział                      Zapłata         Oddany");

    ui->comboBox_rodzaj->addItem("wszystkie");
    ui->comboBox_rodzaj->addItem("SUV");
    ui->comboBox_rodzaj->addItem("sedan");
    ui->comboBox_rodzaj->addItem("kombi");
    ui->comboBox_rodzaj->addItem("hatchback");

    ui->comboBox_marka->addItem("wszystkie");
    ui->comboBox_marka->addItem("Volvo");
    ui->comboBox_marka->addItem("Audi");
    ui->comboBox_marka->addItem("BMW");
    ui->comboBox_marka->addItem("Fiat");
    ui->comboBox_marka->addItem("Ford");
    ui->comboBox_marka->addItem("Honda");
    ui->comboBox_marka->addItem("Hyundai");
    ui->comboBox_marka->addItem("Mercedes");
    ui->comboBox_marka->addItem("Opel");
    ui->comboBox_marka->addItem("Seat");
    ui->comboBox_marka->addItem("Skoda");
    ui->comboBox_marka->addItem("Toyota");
    ui->comboBox_marka->addItem("Volkswagen");
}
klientWindow::~klientWindow()
{
    delete ui;
    //delete pracownikwindow;
    if(!thread.isFinished())
    {
        thread.quit();
        thread.wait();
        thread.deleteLater();
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////// Obsluga przyciskow //////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void klientWindow::on_pushButton_logowanie_clicked()
{
    email = ui->lineEdit_l_email->text();
    QString haslo = ui->lineEdit_l_haslo->text();

    if(otwieraniePolaczenia())
    {
        QSqlQuery query;
        query.prepare("SELECT * FROM KLIENCI WHERE adres_email='"+email+"' and haslo='"+haslo+"';");
        if (query.exec())
        {
            int count=0;
            while(query.next())
            {
                count++;
            }
            if(count==1)
            {
                ui->groupBox_logowanie->setVisible(false);
                ui->tabWidget->setVisible(true);

                zamykaniePolaczenia();
                QPixmap tloLogin("C:/Users/bruba/Documents/WypozyczalniaSamochodow//imagesWS/img2.jpg");
                tloLogin = tloLogin.scaled(this->size(), Qt::IgnoreAspectRatio);
                QPalette palette;
                palette.setBrush(QPalette::Window, tloLogin);
                this->setPalette(palette);

                on_pushButton__wybdate_szukaj_clicked();
                on_pushButton_odswiez_clicked();
            }
            else
            {
                query.prepare("SELECT * FROM PRACOWNICY WHERE adres_email='"+email+"' and haslo='"+haslo+"';");
                if (query.exec())
                {
                    while(query.next())
                    {
                        count+=2;
                    }
                    if(count==2)
                    {
                        ui->groupBox_logowanie->setVisible(true);
                        ui->tabWidget->setVisible(false);
                        zamykaniePolaczenia();
                        qDebug() << "Wątek pracownikWindow: " << QThread::currentThreadId();
                        pracownikwindow = new pracownikWindow(this);
                        pracownikwindow->setFixedSize(960, 540);
                        pracownikwindow->setWindowIcon(QIcon("C:/Users/bruba/Documents/WypozyczalniaSamochodow/imagesWS/logoIcon.jpg"));
                        pracownikwindow->setWindowModality(Qt::ApplicationModal);
                        pracownikwindow->show();
                        pracownikwindow->getEmail(email);
                    }
                    else
                    {
                        QMessageBox::critical(this,"Błąd logowania","Podano nieprawidłowe login lub hasło");
                        zamykaniePolaczenia();
                    }
                }
            }
        }
    }
}
void klientWindow::on_pushButton_l_rej_clicked()
{
    ui->groupBox_logowanie->setVisible(false);
    ui->groupBox_rej->setVisible(true);
}
void klientWindow::on_pushButton_rej_clicked()
{
    QString imie = ui->lineEdit_rej_imie->text();
    QString nazwisko = ui->lineEdit_rej_nazwisko->text();
    QString pesel = ui->lineEdit_rej_pesel->text();
    email = ui->lineEdit_rej_email->text();
    QString tel = ui->lineEdit_rej_tel->text();
    QString haslo = ui->lineEdit_rej_haslo->text();

    if(!sprawdzenieTelefonuPesel(tel,9) || !sprawdzanieEmaila(email) || !sprawdzenieTelefonuPesel(pesel, 11) || !sprawdzanieHasla(haslo))
    {
        QMessageBox::critical(this, "Błędne dane", "Wygląda na to że podałeś błędne dane. Sprawdź jeszcze raz ich poprawność. (Haslo musi zawierać co najmniej 5 znaków.)");
    }
    else
    {
        if(!sprawdzanieDanychRejestracja(pesel,email,tel))
            QMessageBox::critical(this,"Błąd rejestracji","Twoje dane znajdują się już w naszej bazie danych.");
        else
        {
            otwieraniePolaczenia();
            QSqlQuery query;
            query.prepare("INSERT INTO KLIENCI (imie, nazwisko, pesel, nr_tel, adres_email, haslo) VALUES ('"+zmianaLiteryNaDuza(imie)+"','"+zmianaLiteryNaDuza(nazwisko)+"','"+pesel+"', '"+tel+"','"+email+"','"+haslo+"');");
            if(query.exec())
            {
                qDebug() << "Dodano klienta do bazy";
                QMessageBox::information(this,"Zarejestrowano pomyślnie","Rejestracja przebiegła pomyślnie, witamy w wypożyczalni.");
                ui->groupBox_logowanie->setVisible(true);
                ui->groupBox_rej->setVisible(false);
                zamykaniePolaczenia();
            }
            ui->lineEdit_l_email->setText(email);
        }
    }
}
void klientWindow::on_pushButton_rej_powrot_clicked()
{
    ui->groupBox_logowanie->setVisible(true);
    ui->groupBox_rej->setVisible(false);
}
void klientWindow::on_pushButton_wyloguj_clicked()
{
    ui->lineEdit_l_email->clear();
    ui->lineEdit_l_haslo->clear();

    ui->tabWidget->setVisible(false);
    ui->groupBox_logowanie->setVisible(true);

    QPixmap tloLogin("C:/Users/bruba/Documents/WypozyczalniaSamochodow//imagesWS/img2.jpg");
    tloLogin = tloLogin.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, tloLogin);
    this->setPalette(palette);
}
void klientWindow::on_pushButton__wybdate_szukaj_clicked()
{

    dataOd = ui->dateEdit_dataOd->date();
    dataDo = ui->dateEdit_dataDo->date();
    QString wybranyRodzaj = ui->comboBox_rodzaj->currentText();
    QString wybranaMarka = ui->comboBox_marka->currentText();
    if(dataOd>dataDo)
        QMessageBox::critical(this,"Zła data","Wprowadzono zły zakres dat.");
    else
    {
        emit sygnalDostepne(dataOd.toString("yyyy-MM-dd"),dataDo.toString("yyyy-MM-dd"),wybranyRodzaj,wybranaMarka);
    }
}
void klientWindow::on_pushButton_wypozycz_clicked()
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    if(item)
    {
        dataOd = ui->dateEdit_dataOd->date();
        dataDo = ui->dateEdit_dataDo->date();

        QListWidgetItem *item = ui->listWidget->currentItem();
        item->setBackground(Qt::red);
        QString dane = item->text();
        QStringList daneSamochodu = dane.split("\t");

        QString cena = daneSamochodu[3];
        cena.replace("zł/doba", "");
        int cena2 = (cena.toInt()*(dataOd.daysTo(dataDo.addDays(1)))*0.95);
        QString cena3= QString::number(cena2);

        QString nr_rejestracyjny = daneSamochodu[4];
        QString miejsce;

        otwieraniePolaczenia();
        QSqlQuery query;
        query.prepare("SELECT adres_oddzialu FROM ODDZIALY WHERE id_oddzialu = (SELECT id_oddzialu FROM SAMOCHODY WHERE nr_rejestracyjny = '"+nr_rejestracyjny+"');");
        if(query.exec())
        {
            if(query.next())
            {
                miejsce = query.value(0).toString();
            }
        }
        query.prepare("INSERT INTO WYPOZYCZENIA (id_klienta, id_samochodu, data_wypozyczenia_OD, data_wypozyczenia_DO, do_zaplaty) VALUES ((SELECT id_klienta FROM KLIENCI WHERE adres_email='"+email+"'),(SELECT id_samochodu FROM SAMOCHODY WHERE nr_rejestracyjny='"+nr_rejestracyjny+"'),'"+dataOd.toString("yyyy-MM-dd")+"','"+dataDo.toString("yyyy-MM-dd")+"','"+cena3+"');");
        if(query.exec())
            qDebug() << "Dodano wypozyczenie do bazy";
        else
            qDebug() << "Błąd w wypozyczeniu";
        zamykaniePolaczenia();
        QMessageBox::information(this,"Wypożyczono samochód","Wypozyczony samochód "+daneSamochodu[0]+" "+daneSamochodu[1]+" o numerze rejestracyjnym "+daneSamochodu[4]+" w dniach od "+dataOd.toString("dd-MM-yyyy")+" do "+dataDo.toString("dd-MM-yyyy")+". Proszę przygotować "+cena3+" PLN i zjawić się w naszym oddziale, pod adresem "+miejsce+".");

        on_pushButton__wybdate_szukaj_clicked();
        on_pushButton_odswiez_clicked();
    }
    else
    {
        QMessageBox::warning(this, "Nie wybrano samochodu", "Proszę wybrać samochód, który chcesz wypożyczyć.");
    }
}
void klientWindow::on_pushButton_wyloguj_2_clicked()
{
    ui->tabWidget->setVisible(false);
    ui->groupBox_logowanie->setVisible(true);
    ui->lineEdit_l_email->clear();
    ui->lineEdit_l_haslo->clear();

    QPixmap tloLogin("C:/Users/bruba/Documents/WypozyczalniaSamochodow//imagesWS/img2.jpg");
    tloLogin = tloLogin.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, tloLogin);
    this->setPalette(palette);
}
void klientWindow::on_pushButton_odswiez_clicked()
{
    QString email2 = this->email;
    emit sygnalEmail(email2);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////// Sprawdzanie danych //////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool klientWindow::sprawdzanieDanychRejestracja(const QString& pesel, const QString& email, const QString& tel)
{
    otwieraniePolaczenia();

    QSqlQuery query;
    query.prepare("SELECT * FROM KLIENCI WHERE pesel='"+pesel+"' and adres_email='"+email+"' and nr_tel='"+tel+"';");
    if(query.exec())
    {
        if(query.next())
        {
            zamykaniePolaczenia();
            return false;
        }
        else
        {
            zamykaniePolaczenia();
            return true;
        }
    }
    else
    {
        zamykaniePolaczenia();
        return false;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////// Walidacja danych ////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool klientWindow::sprawdzenieTelefonuPesel(const QString& numer, int nr)
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
bool klientWindow::sprawdzanieEmaila(const QString& email)
{
    for (QChar znak : email) {
        if (znak == '@') {
            return true;
        }
    }
    return false;
}
bool klientWindow::sprawdzanieHasla(const QString& haslo)
{
    int dlugoscHasla=0;
    for(QChar znak : haslo)
    {
        if(!znak.isNull())
            dlugoscHasla++;
    }
    if(dlugoscHasla<5)
        return false;
    else
        return true;
}
QString klientWindow::zmianaLiteryNaDuza(QString& nazwa)
{
    std::string naz = nazwa.toStdString();
    if (naz[0] >= 'a' && nazwa[0] <= 'z')
    {
        naz[0] -= ('a' - 'A');
    }
    return QString::fromStdString(naz);
}
void klientWindow::listaWypozyczen(QList<QString> daneWypozyczen)
{
    ui->listWidget_twojahistoria->clear();
    for(int i = 0; i < daneWypozyczen.length(); i++) {
        ui->listWidget_twojahistoria->addItem(daneWypozyczen.at(i));
    }
}

void klientWindow::pobierzDostepne(QList<QString> samochody)
{
    ui->listWidget->clear();
    for(int i=0; i<samochody.length(); i++)
    {
        ui->listWidget->addItem(samochody.value(i));
    }
}
