#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QSqlRelationalTableModel>
#include <QStandardItemModel>

// macros
#define CAR      0
#define CUSTOMER 1
#define MAINT    2
#define SALES    3


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),userMode(supervisor)
{
    ui->setupUi(this);

    sqlPtr = NULL;

//  connect(, SIGNAL(destroyed(QObject*)), this, SLOT(objectDestroyed(Qbject*)));
    connect(ui->btnAdd,SIGNAL(clicked()),this,SLOT(AddItem()));
    connect(ui->btnRemove,SIGNAL(clicked()),this,SLOT(RemoveItem()));
    connect(ui->actionSupervisor,SIGNAL(triggered()),this,SLOT(SetSupervisor()));
    connect(ui->actionSales,SIGNAL(triggered()),this,SLOT(SetSales()));
    connect(ui->actionMaintenence,SIGNAL(triggered()),this,SLOT(SetMaintenence()));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(SetTable()));
    connect(ui->radCar,SIGNAL(clicked()),this,SLOT(SetTable()));
    connect(ui->radSales,SIGNAL(clicked()),this,SLOT(SetTable()));
    connect(ui->actionSave,SIGNAL(triggered()),this,SLOT(saveData()));
    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(exitDatabase()));

    ui->btnAdd->setVisible(false);
    ui->btnRemove->setVisible(false);
    ui->btnSearch->setVisible(false);

    // setup combo box
    ui->comboBox->addItem( QString("Car"));
    ui->comboBox->addItem( QString("Customer"));
    ui->comboBox->addItem( QString("Maintenence"));
    ui->comboBox->addItem( QString("Sales"));

    ui->comboBox->setCurrentIndex(SALES);
/*
    QStandardItem *firstRow = new QStandardItem(QString("ColumnValue"));
    model->setItem(0,0,firstRow);
*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setDatabasePointer(SqlInterface *ptr){
    sqlPtr = ptr;
}

void MainWindow::AddItem()
{
    QStandardItemModel* model = (QStandardItemModel*)ui->tableView->model();

    model->insertRow(model->rowCount());
}

void MainWindow::RemoveItem()
{
    QStandardItemModel* model = (QStandardItemModel*)ui->tableView->model();
    model->removeRow(model->rowCount());
    //sqlPtr->deleteRow(/*table name*/, /*car_id from table*/);



}

void MainWindow::exitDatabase()
{
    QApplication::quit();
}

void MainWindow::saveData()
{

}

void MainWindow::SetSupervisor()
{
    QStandardItemModel* model = new QStandardItemModel(1,10,this);
    model->setHorizontalHeaderItem(0,new QStandardItem(QString("Car ID")));
    model->setHorizontalHeaderItem(1,new QStandardItem(QString("First Name")));
    model->setHorizontalHeaderItem(2,new QStandardItem(QString("Last Name")));
    model->setHorizontalHeaderItem(3,new QStandardItem(QString("Address")));
    model->setHorizontalHeaderItem(4,new QStandardItem(QString("State")));
    model->setHorizontalHeaderItem(5,new QStandardItem(QString("Zip Code")));
    model->setHorizontalHeaderItem(6,new QStandardItem(QString("Phone Number")));
    model->setHorizontalHeaderItem(7,new QStandardItem(QString("Delivery Date")));
    model->setHorizontalHeaderItem(8,new QStandardItem(QString("Scheduled Maintenance")));
    model->setHorizontalHeaderItem(9,new QStandardItem(QString("Unscheduled Repairs")));

    vector<CustomerContainer> container = sqlPtr->getCustomerData();
    QStandardItem *firstRow;
    QString intToString;
    QString qStr;
    int temp;
    for(unsigned int j = 0; j < container.size(); j++){
        for(int i = 0; i < 10; i++){
            switch(i)
            {
            case 0: temp = container[j].getCarId();
                intToString = QString::number(temp);
                firstRow = new QStandardItem(intToString);
                model->setItem(j,0,firstRow);
                break;
            case 1: qStr = QString::fromStdString(container[j].getFirstName());
                firstRow = new QStandardItem(qStr);
                model->setItem(j,1,firstRow);
                break;
            case 2: qStr = QString::fromStdString(container[j].getLastName());
                firstRow = new QStandardItem(qStr);
                model->setItem(j,2,firstRow);
                break;
            case 3: qStr = QString::fromStdString(container[j].getAddress());
                firstRow = new QStandardItem(qStr);
                model->setItem(j,3,firstRow);
                break;
            case 4: qStr = QString::fromStdString(container[j].getState());
                firstRow = new QStandardItem(qStr);
                model->setItem(j,4,firstRow);
                break;
            case 5:temp = container[j].getZip();
                intToString = QString::number(temp);
                firstRow = new QStandardItem(intToString);
                model->setItem(j,5,firstRow);
                break;
            case 6:
                break;
            case 7: qStr = QString::fromStdString(container[j].getDeliveryDate());
                firstRow = new QStandardItem(qStr);
                model->setItem(j,7,firstRow);
                break;
            case 8: qStr = QString::fromStdString(container[j].getScheduledMaintenance());
                firstRow = new QStandardItem(qStr);
                model->setItem(j,8,firstRow);
                break;
            case 9: qStr = QString::fromStdString(container[j].getUnscheduledRepairs());
                firstRow = new QStandardItem(qStr);
                model->setItem(j,9,firstRow);
                break;
            }
        }
    }


    statusBar()->showMessage(tr("Customer Table"));
    ui->tableView->setModel(model);

    cout << statusBar();

    userMode = supervisor;
    ui->comboBox->setVisible(true);
    ui->btnAdd->setVisible(true);
    ui->btnRemove->setVisible(true);
    ui->btnSearch->setVisible(true);

}

void MainWindow::SetSales()
{
    QStandardItemModel* model = new QStandardItemModel(1,13,this);
    model->setHorizontalHeaderItem(0,new QStandardItem(QString("Car ID")));
    model->setHorizontalHeaderItem(1,new QStandardItem(QString("Make")));
    model->setHorizontalHeaderItem(2,new QStandardItem(QString("Model")));
    model->setHorizontalHeaderItem(3,new QStandardItem(QString("Performance")));
    model->setHorizontalHeaderItem(4,new QStandardItem(QString("Handeling")));
    model->setHorizontalHeaderItem(5,new QStandardItem(QString("Instrumentation")));
    model->setHorizontalHeaderItem(6,new QStandardItem(QString("Safety Security")));
    model->setHorizontalHeaderItem(7,new QStandardItem(QString("Design")));
    model->setHorizontalHeaderItem(8,new QStandardItem(QString("Audio")));
    model->setHorizontalHeaderItem(9,new QStandardItem(QString("Comfort")));
    model->setHorizontalHeaderItem(10,new QStandardItem(QString("Maintenance")));
    model->setHorizontalHeaderItem(11,new QStandardItem(QString("Warrenty")));
    model->setHorizontalHeaderItem(12,new QStandardItem(QString("Packages")));

    vector<CarContainer> container = sqlPtr->getCarData();
    QStandardItem *firstRow;
    QString intToString;
    QString qStr;
    int temp;
    for(unsigned int j = 0; j < container.size(); j++){
        for(int i = 0; i < 13; i++){
            switch(i)
            {
            case 0: temp = container[j].getCarId();
                intToString = QString::number(temp);
                firstRow = new QStandardItem(intToString);
                model->setItem(j,0,firstRow);
                break;
            case 1: qStr = QString::fromStdString(container[j].getMake());
                firstRow = new QStandardItem(qStr);
                model->setItem(j,1,firstRow);
                break;
            case 2: qStr = QString::fromStdString(container[j].getModel());
                firstRow = new QStandardItem(qStr);
                model->setItem(j,2,firstRow);
                break;
            case 3: qStr = QString::fromStdString(container[j].getPerformance());
                firstRow = new QStandardItem(qStr);
                model->setItem(j,3,firstRow);
                break;
            case 4: qStr = QString::fromStdString(container[j].getHandeling());
                firstRow = new QStandardItem(qStr);
                model->setItem(j,4,firstRow);
                break;
            case 5: qStr = QString::fromStdString(container[j].getInstrumentation());
                firstRow = new QStandardItem(qStr);
                model->setItem(j,5,firstRow);
                break;
            case 6: qStr = QString::fromStdString(container[j].getSafetySecurity());
                firstRow = new QStandardItem(qStr);
                model->setItem(j,6,firstRow);
                break;
            case 7: qStr = QString::fromStdString(container[j].getDesign());
                firstRow = new QStandardItem(qStr);
                model->setItem(j,7,firstRow);
                break;
            case 8: qStr = QString::fromStdString(container[j].getAudio());
                firstRow = new QStandardItem(qStr);
                model->setItem(j,8,firstRow);
                break;
            case 9: qStr = QString::fromStdString(container[j].getComfort());
                firstRow = new QStandardItem(qStr);
                model->setItem(j,9,firstRow);
                break;
            case 10: qStr = QString::fromStdString(container[j].getMaintenance());
                firstRow = new QStandardItem(qStr);
                model->setItem(j,10,firstRow);
                break;
            case 11: qStr = QString::fromStdString(container[j].getWarranty());
                firstRow = new QStandardItem(qStr);
                model->setItem(j,11,firstRow);
                break;
            case 12: qStr = QString::fromStdString(container[j].getPackages());
                firstRow = new QStandardItem(qStr);
                model->setItem(j,12,firstRow);;
                break;
            }
        }
    }

    statusBar()->showMessage(tr("Car Table"));
    ui->tableView->setModel(model);
    cout << statusBar();
    userMode = sales;

    ui->comboBox->setVisible(false);
    ui->btnAdd->setVisible(true);
    ui->btnRemove->setVisible(false);
    ui->btnSearch->setVisible(true);
}

void MainWindow::SetMaintenence()
{
    QStandardItemModel* model = new QStandardItemModel(1,5,this);
    model->setHorizontalHeaderItem(0,new QStandardItem(QString("Car ID")));
    model->setHorizontalHeaderItem(1,new QStandardItem(QString("Damages")));
    model->setHorizontalHeaderItem(2,new QStandardItem(QString("Costs")));
    model->setHorizontalHeaderItem(3,new QStandardItem(QString("Start Date")));
    model->setHorizontalHeaderItem(4,new QStandardItem(QString("Finish Date")));

    vector<MaintenanceContainer> container = sqlPtr->getMaintenanceData();
    QStandardItem *firstRow;
    QString intToString;
    QString qStr;
    int temp;
    for(unsigned int j = 0; j < container.size(); j++){
        for(int i = 0; i < 5; i++){
            switch(i)
            {
            case 0: temp = container[j].getCarId();
                intToString = QString::number(temp);
                firstRow = new QStandardItem(intToString);
                model->setItem(j,0,firstRow);
                break;
            case 1: qStr = QString::fromStdString(container[j].getDamages());
                firstRow = new QStandardItem(qStr);
                model->setItem(j,1,firstRow);
                break;
            case 2: firstRow = new QStandardItem(container[j].getCost());
                model->setItem(j,2,firstRow);
                break;
            case 3: qStr = QString::fromStdString(container[j].getStartDate());
                firstRow = new QStandardItem(qStr);
                model->setItem(j,3,firstRow);
                break;
            case 4: qStr = QString::fromStdString(container[j].getFinishDate());
                firstRow = new QStandardItem(qStr);
                model->setItem(j,4,firstRow);
                break;
            }
        }
    }

    statusBar()->showMessage(tr("Maintenance Table"));
    ui->tableView->setModel(model);
    cout << &(*statusBar());
    userMode = maintenance;

    ui->comboBox->setVisible(false);
    ui->btnAdd->setVisible(true);
    ui->btnRemove->setVisible(false);
    ui->btnSearch->setVisible(true);
}

void MainWindow::SetTable()
{

        switch(ui->comboBox->currentIndex())
        {
        case CAR:
        {
            QStandardItemModel* model = new QStandardItemModel(1,13,this);
            model->setHorizontalHeaderItem(0,new QStandardItem(QString("Car ID")));
            model->setHorizontalHeaderItem(1,new QStandardItem(QString("Make")));
            model->setHorizontalHeaderItem(2,new QStandardItem(QString("Model")));
            model->setHorizontalHeaderItem(3,new QStandardItem(QString("Performance")));
            model->setHorizontalHeaderItem(4,new QStandardItem(QString("Handeling")));
            model->setHorizontalHeaderItem(5,new QStandardItem(QString("Instrumentation")));
            model->setHorizontalHeaderItem(6,new QStandardItem(QString("Safety Security")));
            model->setHorizontalHeaderItem(7,new QStandardItem(QString("Design")));
            model->setHorizontalHeaderItem(8,new QStandardItem(QString("Audio")));
            model->setHorizontalHeaderItem(9,new QStandardItem(QString("Comfort")));
            model->setHorizontalHeaderItem(10,new QStandardItem(QString("Maintenance")));
            model->setHorizontalHeaderItem(11,new QStandardItem(QString("Warrenty")));
            model->setHorizontalHeaderItem(12,new QStandardItem(QString("Packages")));

            vector<CarContainer> container = sqlPtr->getCarData();
            QStandardItem *firstRow;
            QString intToString;
            QString qStr;
            int temp;
            for(unsigned int j = 0; j < container.size(); j++){
                for(int i = 0; i < 13; i++){
                    switch(i)
                    {
                    case 0: temp = container[j].getCarId();
                        intToString = QString::number(temp);
                        firstRow = new QStandardItem(intToString);
                        model->setItem(j,0,firstRow);
                        break;
                    case 1: qStr = QString::fromStdString(container[j].getMake());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,1,firstRow);
                        break;
                    case 2: qStr = QString::fromStdString(container[j].getModel());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,2,firstRow);
                        break;
                    case 3: qStr = QString::fromStdString(container[j].getPerformance());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,3,firstRow);
                        break;
                    case 4: qStr = QString::fromStdString(container[j].getHandeling());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,4,firstRow);
                        break;
                    case 5: qStr = QString::fromStdString(container[j].getInstrumentation());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,5,firstRow);
                        break;
                    case 6: qStr = QString::fromStdString(container[j].getSafetySecurity());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,6,firstRow);
                        break;
                    case 7: qStr = QString::fromStdString(container[j].getDesign());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,7,firstRow);
                        break;
                    case 8: qStr = QString::fromStdString(container[j].getAudio());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,8,firstRow);
                        break;
                    case 9: qStr = QString::fromStdString(container[j].getComfort());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,9,firstRow);
                        break;
                    case 10: qStr = QString::fromStdString(container[j].getMaintenance());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,10,firstRow);
                        break;
                    case 11: qStr = QString::fromStdString(container[j].getWarranty());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,11,firstRow);
                        break;
                    case 12: qStr = QString::fromStdString(container[j].getPackages());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,12,firstRow);;
                        break;
                    }
                }
            }

            statusBar()->showMessage(tr("Car Table"));
            ui->tableView->setModel(model);
        }
            break;
        case CUSTOMER:
        {
            QStandardItemModel* model = new QStandardItemModel(1,10,this);
            model->setHorizontalHeaderItem(0,new QStandardItem(QString("Car ID")));
            model->setHorizontalHeaderItem(1,new QStandardItem(QString("First Name")));
            model->setHorizontalHeaderItem(2,new QStandardItem(QString("Last Name")));
            model->setHorizontalHeaderItem(3,new QStandardItem(QString("Address")));
            model->setHorizontalHeaderItem(4,new QStandardItem(QString("State")));
            model->setHorizontalHeaderItem(5,new QStandardItem(QString("Zip Code")));
            model->setHorizontalHeaderItem(6,new QStandardItem(QString("Phone Number")));
            model->setHorizontalHeaderItem(7,new QStandardItem(QString("Delivery Date")));
            model->setHorizontalHeaderItem(8,new QStandardItem(QString("Scheduled Maintenance")));
            model->setHorizontalHeaderItem(9,new QStandardItem(QString("Unscheduled Repairs")));

            vector<CustomerContainer> container = sqlPtr->getCustomerData();
            QStandardItem *firstRow;
            QString intToString;
            QString qStr;
            int temp;
            for(unsigned int j = 0; j < container.size(); j++){
                for(int i = 0; i < 10; i++){
                    switch(i)
                    {
                    case 0: temp = container[j].getCarId();
                        intToString = QString::number(temp);
                        firstRow = new QStandardItem(intToString);
                        model->setItem(j,0,firstRow);
                        break;
                    case 1: qStr = QString::fromStdString(container[j].getFirstName());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,1,firstRow);
                        break;
                    case 2: qStr = QString::fromStdString(container[j].getLastName());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,2,firstRow);
                        break;
                    case 3: qStr = QString::fromStdString(container[j].getAddress());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,3,firstRow);
                        break;
                    case 4: qStr = QString::fromStdString(container[j].getState());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,4,firstRow);
                        break;
                    case 5:temp = container[j].getZip();
                        intToString = QString::number(temp);
                        firstRow = new QStandardItem(intToString);
                        model->setItem(j,5,firstRow);
                        break;
                    case 6:
                        break;
                    case 7: qStr = QString::fromStdString(container[j].getDeliveryDate());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,7,firstRow);
                        break;
                    case 8: qStr = QString::fromStdString(container[j].getScheduledMaintenance());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,8,firstRow);
                        break;
                    case 9: qStr = QString::fromStdString(container[j].getUnscheduledRepairs());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,9,firstRow);
                        break;
                    }
                }
            }
            statusBar()->showMessage(tr("Customer Table"));
            ui->tableView->setModel(model);
        }
            break;
        case MAINT:
        {
            QStandardItemModel* model = new QStandardItemModel(1,5,this);
            model->setHorizontalHeaderItem(0,new QStandardItem(QString("Car ID")));
            model->setHorizontalHeaderItem(1,new QStandardItem(QString("Damages")));
            model->setHorizontalHeaderItem(2,new QStandardItem(QString("Costs")));
            model->setHorizontalHeaderItem(3,new QStandardItem(QString("Start Date")));
            model->setHorizontalHeaderItem(4,new QStandardItem(QString("Finish Date")));

            vector<MaintenanceContainer> container = sqlPtr->getMaintenanceData();
            QStandardItem *firstRow;
            QString intToString;
            QString qStr;
            int temp;
            for(unsigned int j = 0; j < container.size(); j++){
                for(int i = 0; i < 5; i++){
                    switch(i)
                    {
                    case 0: temp = container[j].getCarId();
                        intToString = QString::number(temp);
                        firstRow = new QStandardItem(intToString);
                        model->setItem(j,0,firstRow);
                        break;
                    case 1: qStr = QString::fromStdString(container[j].getDamages());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,1,firstRow);
                        break;
                    case 2: firstRow = new QStandardItem(container[j].getCost());
                        model->setItem(j,2,firstRow);
                        break;
                    case 3: qStr = QString::fromStdString(container[j].getStartDate());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,3,firstRow);
                        break;
                    case 4: qStr = QString::fromStdString(container[j].getFinishDate());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,4,firstRow);
                        break;
                    }
                }
            }

            statusBar()->showMessage(tr("Maintenance Table"));
            ui->tableView->setModel(model);
        }
            break;
        case SALES:
        {
            QStandardItemModel* model = new QStandardItemModel(1,9,this);
            model->setHorizontalHeaderItem(0,new QStandardItem(QString("Car ID")));
            model->setHorizontalHeaderItem(1,new QStandardItem(QString("Availability")));
            model->setHorizontalHeaderItem(2,new QStandardItem(QString("Delivery Date")));
            model->setHorizontalHeaderItem(3,new QStandardItem(QString("Cost")));
            model->setHorizontalHeaderItem(4,new QStandardItem(QString("Date Sold")));
            model->setHorizontalHeaderItem(5,new QStandardItem(QString("First Name")));
            model->setHorizontalHeaderItem(6,new QStandardItem(QString("Last Name")));
            model->setHorizontalHeaderItem(7,new QStandardItem(QString("Make")));
            model->setHorizontalHeaderItem(8,new QStandardItem(QString("Model")));

            vector<SalesContainer> container = sqlPtr->getSalesData();
            QStandardItem *firstRow;
            QString intToString;
            QString qStr;
            int temp;
            for(unsigned int j = 0; j < container.size(); j++){
                for(int i = 0; i < 9; i++){
                    switch(i)
                    {
                    case 0: temp = container[j].getCarId();
                        intToString = QString::number(temp);
                        firstRow = new QStandardItem(intToString);
                        model->setItem(j,0,firstRow);
                        break;
                    case 1: qStr = QString::fromStdString(container[j].getAvailability());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,1,firstRow);
                        break;
                    case 2: qStr = QString::fromStdString(container[j].getDeliveryDate());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,2,firstRow);
                        break;
                    case 3: temp = container[j].getCost();
                        intToString = QString::number(temp);
                        firstRow = new QStandardItem(intToString);
                        model->setItem(j,3,firstRow);
                        break;
                    case 4: qStr = QString::fromStdString(container[j].getDateSold());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,4,firstRow);
                        break;
                    case 5: qStr = QString::fromStdString(container[j].getFirstName());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,5,firstRow);
                        break;
                    case 6: qStr = QString::fromStdString(container[j].getLastName());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,6,firstRow);
                        break;
                    case 7: qStr = QString::fromStdString(container[j].getMake());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,7,firstRow);
                        break;
                    case 8: qStr = QString::fromStdString(container[j].getModel());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,8,firstRow);
                        break;
                    }
                }
            }

            statusBar()->showMessage(tr("Sales Table"));
            ui->tableView->setModel(model);
        }
            break;
        default:
            return;
            break;
        }
        if(ui->radSales->isChecked() && (userMode == sales))
        {
            QStandardItemModel* model = new QStandardItemModel(1,9,this);
            model->setHorizontalHeaderItem(0,new QStandardItem(QString("Car ID")));
            model->setHorizontalHeaderItem(1,new QStandardItem(QString("Availability")));
            model->setHorizontalHeaderItem(2,new QStandardItem(QString("Delivery Date")));
            model->setHorizontalHeaderItem(3,new QStandardItem(QString("Cost")));
            model->setHorizontalHeaderItem(4,new QStandardItem(QString("Date Sold")));
            model->setHorizontalHeaderItem(5,new QStandardItem(QString("First Name")));
            model->setHorizontalHeaderItem(6,new QStandardItem(QString("Last Name")));
            model->setHorizontalHeaderItem(7,new QStandardItem(QString("Make")));
            model->setHorizontalHeaderItem(8,new QStandardItem(QString("Model")));

            vector<SalesContainer> container = sqlPtr->getSalesData();
            QStandardItem *firstRow;
            QString intToString;
            QString qStr;
            int temp;
            for(unsigned int j = 0; j < container.size(); j++){
                for(int i = 0; i < 9; i++){
                    switch(i)
                    {
                    case 0: temp = container[j].getCarId();
                        intToString = QString::number(temp);
                        firstRow = new QStandardItem(intToString);
                        model->setItem(j,0,firstRow);
                        break;
                    case 1: qStr = QString::fromStdString(container[j].getAvailability());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,1,firstRow);
                        break;
                    case 2: qStr = QString::fromStdString(container[j].getDeliveryDate());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,2,firstRow);
                        break;
                    case 3: temp = container[j].getCost();
                        intToString = QString::number(temp);
                        firstRow = new QStandardItem(intToString);
                        model->setItem(j,3,firstRow);
                        break;
                    case 4: qStr = QString::fromStdString(container[j].getDateSold());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,4,firstRow);
                        break;
                    case 5: qStr = QString::fromStdString(container[j].getFirstName());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,5,firstRow);
                        break;
                    case 6: qStr = QString::fromStdString(container[j].getLastName());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,6,firstRow);
                        break;
                    case 7: qStr = QString::fromStdString(container[j].getMake());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,7,firstRow);
                        break;
                    case 8: qStr = QString::fromStdString(container[j].getModel());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,8,firstRow);
                        break;
                    }
                }
            }

            statusBar()->showMessage(tr("Sales Table"));
            ui->tableView->setModel(model);
        }
        else if (ui->radCar->isChecked() && (userMode == sales))
        {
            QStandardItemModel* model = new QStandardItemModel(1,13,this);
            model->setHorizontalHeaderItem(0,new QStandardItem(QString("Car ID")));
            model->setHorizontalHeaderItem(1,new QStandardItem(QString("Make")));
            model->setHorizontalHeaderItem(2,new QStandardItem(QString("Model")));
            model->setHorizontalHeaderItem(3,new QStandardItem(QString("Performance")));
            model->setHorizontalHeaderItem(4,new QStandardItem(QString("Handeling")));
            model->setHorizontalHeaderItem(5,new QStandardItem(QString("Instrumentation")));
            model->setHorizontalHeaderItem(6,new QStandardItem(QString("Safety Security")));
            model->setHorizontalHeaderItem(7,new QStandardItem(QString("Design")));
            model->setHorizontalHeaderItem(8,new QStandardItem(QString("Audio")));
            model->setHorizontalHeaderItem(9,new QStandardItem(QString("Comfort")));
            model->setHorizontalHeaderItem(10,new QStandardItem(QString("Maintenance")));
            model->setHorizontalHeaderItem(11,new QStandardItem(QString("Warrenty")));
            model->setHorizontalHeaderItem(12,new QStandardItem(QString("Packages")));

            vector<CarContainer> container = sqlPtr->getCarData();
            QStandardItem *firstRow;
            QString intToString;
            QString qStr;
            int temp;
            for(unsigned int j = 0; j < container.size(); j++){
                for(int i = 0; i < 13; i++){
                    switch(i)
                    {
                    case 0: temp = container[j].getCarId();
                        intToString = QString::number(temp);
                        firstRow = new QStandardItem(intToString);
                        model->setItem(j,0,firstRow);
                        break;
                    case 1: qStr = QString::fromStdString(container[j].getMake());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,1,firstRow);
                        break;
                    case 2: qStr = QString::fromStdString(container[j].getModel());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,2,firstRow);
                        break;
                    case 3: qStr = QString::fromStdString(container[j].getPerformance());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,3,firstRow);
                        break;
                    case 4: qStr = QString::fromStdString(container[j].getHandeling());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,4,firstRow);
                        break;
                    case 5: qStr = QString::fromStdString(container[j].getInstrumentation());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,5,firstRow);
                        break;
                    case 6: qStr = QString::fromStdString(container[j].getSafetySecurity());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,6,firstRow);
                        break;
                    case 7: qStr = QString::fromStdString(container[j].getDesign());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,7,firstRow);
                        break;
                    case 8: qStr = QString::fromStdString(container[j].getAudio());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,8,firstRow);
                        break;
                    case 9: qStr = QString::fromStdString(container[j].getComfort());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,9,firstRow);
                        break;
                    case 10: qStr = QString::fromStdString(container[j].getMaintenance());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,10,firstRow);
                        break;
                    case 11: qStr = QString::fromStdString(container[j].getWarranty());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,11,firstRow);
                        break;
                    case 12: qStr = QString::fromStdString(container[j].getPackages());
                        firstRow = new QStandardItem(qStr);
                        model->setItem(j,12,firstRow);;
                        break;
                    }
                }
            }

            statusBar()->showMessage(tr("Car Table"));
            ui->tableView->setModel(model);
        }
}
