#include "mainwindow.h"
#include <QApplication>
#include <QtSql>
#include <QSqlDatabase>
//#include <QTextCodec>


int main(int argc, char *argv[])
{




    QApplication a(argc, argv);




    MainWindow w;


    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setPort(5432);
    db.setDatabaseName("postgres_from_qt");
    db.setUserName("postgres");
    db.setPassword("Dfrfk.r2017");



    if(!db.open()){
        QMessageBox::warning(0,"DataBase Error",db.lastError().text());
        return false;
    }
    else {
        QMessageBox::information(0,"Succesfully", "Connection complited!");
        //return true; закоментил тк при закрытии месседж бокса закрывалось приложение
    }

    w.show();




    return a.exec();

}
