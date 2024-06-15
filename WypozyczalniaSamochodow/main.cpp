#include "klientwindow.h"

#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap("C:/Users/bruba/Documents/WypozyczalniaSamochodow/imagesWS/img4.jpg"));
    splash->show();
    klientWindow w;
    w.setFixedSize(800, 450);
    w.setWindowIcon(QIcon("C:/Users/bruba/Documents/WypozyczalniaSamochodow/imagesWS/logoIcon.jpg"));
    QTimer::singleShot(2500,splash,SLOT(close()));
    QTimer::singleShot(2500,&w,SLOT(show()));
    return a.exec();
}
