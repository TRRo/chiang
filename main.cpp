#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen * scr= new QSplashScreen;
    scr->setPixmap(QPixmap("C:/Users/Talia/Desktop/codat_re/Logo.png"));
    scr->show();

    MainWindow w;
    w.show();
    scr->hide();
    int counter=1;
    while(counter<10){
        w.print();
        counter++;
    }
    return a.exec();
}
