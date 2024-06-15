#include "klientqthread.h"

klientQThread::klientQThread(QObject *parent) : QObject(parent) {}

klientQThread::~klientQThread(){}

void klientQThread::pobranyAdres(const QString& email)
{
    qDebug() << "Aktualny wątek: " << QThread::currentThreadId();
    QList<QString> daneWypozyczen;
    QSqlDatabase baza = QSqlDatabase::addDatabase("QSQLITE");
    baza.setDatabaseName(("C:/Users/bruba/Documents/WypozyczalniaSamochodow/WypozyczalniaSamochodow.db"));

    if(!baza.open())
    {
        qDebug() << "Not connected...";
    }
    else
    {
        qDebug() << "Connected...";
        QSqlQuery query;
        query.prepare("SELECT WYPOZYCZENIA.data_wypozyczenia_OD, WYPOZYCZENIA.data_wypozyczenia_DO, WYPOZYCZENIA.do_zaplaty, WYPOZYCZENIA.oddany, SAMOCHODY.marka, SAMOCHODY.model, SAMOCHODY.rodzaj, SAMOCHODY.nr_rejestracyjny,ODDZIALY.adres_oddzialu FROM WYPOZYCZENIA JOIN SAMOCHODY ON WYPOZYCZENIA.id_samochodu = SAMOCHODY.id_samochodu JOIN ODDZIALY ON SAMOCHODY.id_oddzialu = ODDZIALY.id_oddzialu WHERE WYPOZYCZENIA.id_klienta = (SELECT id_klienta FROM KLIENCI WHERE adres_email='"+email+"');");
        if(query.exec())
        {
            int idDataOd = query.record().indexOf("data_wypozyczenia_OD");
            int idDataDo = query.record().indexOf("data_wypozyczenia_DO");
            int idZaplata = query.record().indexOf("do_zaplaty");
            int idMarka = query.record().indexOf("marka");
            int idModel = query.record().indexOf("model");
            int idRodzaj = query.record().indexOf("rodzaj");
            int idRej = query.record().indexOf("nr_rejestracyjny");
            int idMiejsce = query.record().indexOf("adres_oddzialu");
            int idOddanie = query.record().indexOf("oddany");
            while (query.next())
            {
                QString dataOd = query.value(idDataOd).toString();
                QString dataDo = query.value(idDataDo).toString();
                QString zaplata = query.value(idZaplata).toString();
                QString marka = query.value(idMarka).toString();
                QString model = query.value(idModel).toString();
                QString rodzaj = query.value(idRodzaj).toString();
                QString nrRej = query.value(idRej).toString();
                QString miejsce = query.value(idMiejsce).toString();
                QString oddanie = query.value(idOddanie).toString();
                QString dana = dataOd + "\t" + dataDo + "\t" + marka + "\t" + model + "\t" + rodzaj + "\t" + nrRej + "\t" + miejsce + "\t" + zaplata + "\t" + oddanie;
                daneWypozyczen.append(dana);

            }
            baza.close();
            baza.removeDatabase(QSqlDatabase::defaultConnection);
            qDebug() << "...Disconnected";
            emit listaWypozyczenGotowa(daneWypozyczen);
        }
    }
}
void klientQThread::pobierzDostepneSamochody(const QString& dataOd, const QString& dataDo, const QString& wybranyRodzaj, const QString& wybranaMarka)
{
    qDebug() << "Aktualny wątek: " << QThread::currentThreadId();
    QSqlDatabase baza = QSqlDatabase::addDatabase("QSQLITE");
    baza.setDatabaseName(("C:/Users/bruba/Documents/WypozyczalniaSamochodow/WypozyczalniaSamochodow.db"));

    if(!baza.open())
    {
        qDebug() << "Not connected...";
    }
    else
    {
        qDebug() << "Connected...";
        QList<QString> samochody;
        QString wyszukiwanie;
        if(wybranyRodzaj=="wszystkie" && wybranaMarka=="wszystkie")
            wyszukiwanie="SELECT marka, model, rodzaj, cena, nr_rejestracyjny FROM SAMOCHODY WHERE NOT EXISTS (SELECT * FROM WYPOZYCZENIA WHERE SAMOCHODY.id_samochodu = WYPOZYCZENIA.id_samochodu AND ((data_wypozyczenia_OD <= '"+dataOd+"' AND data_wypozyczenia_DO >= '"+dataDo+"') OR (data_wypozyczenia_OD BETWEEN '"+dataOd+"' AND '"+dataDo+"') OR (data_wypozyczenia_DO BETWEEN '"+dataOd+"' AND '"+dataDo+"')));";
        else if(wybranyRodzaj!="wszystkie" && wybranaMarka=="wszystkie")
            wyszukiwanie="SELECT marka, model, rodzaj, cena, nr_rejestracyjny FROM SAMOCHODY WHERE rodzaj='"+wybranyRodzaj+"' AND NOT EXISTS (SELECT * FROM WYPOZYCZENIA WHERE SAMOCHODY.id_samochodu = WYPOZYCZENIA.id_samochodu AND ((data_wypozyczenia_OD <= '"+dataOd+"' AND data_wypozyczenia_DO >= '"+dataDo+"') OR (data_wypozyczenia_OD BETWEEN '"+dataOd+"' AND '"+dataDo+"') OR (data_wypozyczenia_DO BETWEEN '"+dataOd+"' AND '"+dataDo+"')));";
        else if(wybranyRodzaj=="wszystkie" && wybranaMarka!="wszystkie")
            wyszukiwanie="SELECT marka, model, rodzaj, cena, nr_rejestracyjny FROM SAMOCHODY WHERE marka='"+wybranaMarka+"' AND NOT EXISTS (SELECT * FROM WYPOZYCZENIA WHERE SAMOCHODY.id_samochodu = WYPOZYCZENIA.id_samochodu AND ((data_wypozyczenia_OD <= '"+dataOd+"' AND data_wypozyczenia_DO >= '"+dataDo+"') OR (data_wypozyczenia_OD BETWEEN '"+dataOd+"' AND '"+dataDo+"') OR (data_wypozyczenia_DO BETWEEN '"+dataOd+"' AND '"+dataDo+"')));";
        else if(wybranyRodzaj!="wszystkie" && wybranaMarka!="wszystkie")
            wyszukiwanie="SELECT marka, model, rodzaj, cena, nr_rejestracyjny FROM SAMOCHODY WHERE marka='"+wybranaMarka+"' AND rodzaj='"+wybranyRodzaj+"' AND NOT EXISTS (SELECT * FROM WYPOZYCZENIA WHERE SAMOCHODY.id_samochodu = WYPOZYCZENIA.id_samochodu AND ((data_wypozyczenia_OD <= '"+dataOd+"' AND data_wypozyczenia_DO >= '"+dataDo+"') OR (data_wypozyczenia_OD BETWEEN '"+dataOd+"' AND '"+dataDo+"') OR (data_wypozyczenia_DO BETWEEN '"+dataOd+"' AND '"+dataDo+"')));";
        QSqlQuery query(wyszukiwanie);
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
            baza.close();
            baza.removeDatabase(QSqlDatabase::defaultConnection);
            qDebug() << "...Disconnected";
            emit listaDostepnychSamochodowGotowa(samochody);
        }
    }
}

