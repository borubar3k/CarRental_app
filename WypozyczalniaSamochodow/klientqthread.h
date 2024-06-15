#ifndef KLIENTQTHREAD_H
#define KLIENTQTHREAD_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QList>
#include <QThread>
#include <QSqlRecord>
#include <QDebug>

class klientQThread : public QObject
{
    Q_OBJECT
public:
    explicit klientQThread(QObject *parent = nullptr);
    ~klientQThread();

signals:
    void listaWypozyczenGotowa(const QList<QString> daneWypozyczen);
    void listaDostepnychSamochodowGotowa(const QList<QString> samochody);
public slots:
    void pobranyAdres(const QString& email);
    void pobierzDostepneSamochody(const QString& dataOd, const QString& dataDo, const QString& wybranyRodzaj, const QString& wybranaMarka);
private:
    QSqlDatabase bazaDanych;
};

#endif // KLIENTQTHREAD_H
