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



    //mContainer = interface.searchMaintenanceData("select * from maintenance where costs=100");

//    cout << mContainer.getCarId() << setw(30) << mContainer.getDamages() << setw(30) << mContainer.getCost() << setw(30) << mContainer.getStartDate() << setw(30) << mContainer.getFinishDate();
//    cout << endl;

    //interface.getMaintenanceData();
    //interface.display();

        return a.exec();
}
