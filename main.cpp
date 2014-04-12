#include "sqlinterface.h"
#include "mainwindow.h"
#include <QApplication>


//    user = "scott";
//    passwd = "password";
//    db = "localhost:1521/skynetdb";

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    SqlInterface interface;
    MaintenanceContainer mContainer;
    MainWindow w;

    interface.connect("scott","password","localhost:1521/skynetdb");

    w.setDatabasePointer(&interface);
    w.show();

    return a.exec();
}
