#ifndef CONECTION_H
#define CONECTION_H

#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>

inline bool createConnection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("postgres");
    db.setUserName("Andrey");
    db.setPassword("Dfrfk.r2017");
    db.setHostName("localhost");
    db.setPort(5432);

    if(!db.open()){
        QMessageBox::warning(0,"DataBase Error",db.lastError().text());
        return false;
    }
    else {
        QMessageBox::information(0,"Succesfully", "Connection complited!");
        return true;
    }
}

inline bool createTables(){
    QSqlQuery query;
    query.exec("CREATE TABLE passwords ("
               "id INTEGER PRIMARY KEY, "
               "login VARCHAR(10) NOT NULL, "
               "passwd VARCHAR(10) NOT NULL, "
               "datepass DATE NOT NULL)");
        return (1);
}





#endif // CONECTION_H
