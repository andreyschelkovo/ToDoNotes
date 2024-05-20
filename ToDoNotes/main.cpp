#include "mainwindow.h"
#include "conection.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    if(!createConnection()){
        return 1;
    }
    if (!createTables()){//если нет таблицы то создаём
        return 1;
    }




    w.show();
    return a.exec();

}
