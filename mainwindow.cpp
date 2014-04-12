#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QSqlRelationalTableModel>
#include <QStandardItemModel>
#include "searchsales.h"
#include "carsearchdialog.h"
#include "searchmaintenancedialog.h"
#include "searchcustomerdialog.h"
#include "logindialog.h"

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
    QVBoxLayout *layout = new QVBoxLayout(parent);
    sqlPtr = NULL;

//  connect(, SIGNAL(destroyed(QObject*)), this, SLOT(objectDestroyed(Qbject*)));
    connect(ui->btnAdd,SIGNAL(clicked()),this,SLOT(AddItem()));
    connect(ui->btnRemove,SIGNAL(clicked()),this,SLOT(RemoveItem()));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(SetTable()));
    connect(ui->radCar,SIGNAL(clicked()),this,SLOT(SetTable()));
    connect(ui->radSales,SIGNAL(clicked()),this,SLOT(SetTable()));
    connect(ui->actionSave,SIGNAL(triggered()),this,SLOT(saveData()));
    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(exitDatabase()));
    connect(ui->btnSearch,SIGNAL(clicked()),this, SLOT(OpenSearchDialog()));
    connect(ui->actionLogin,SIGNAL(triggered()),this,SLOT(Logout()));

    ui->btnAdd->setVisible(false);
    ui->btnRemove->setVisible(false);
    ui->btnSearch->setVisible(false);
    ui->radCar->setVisible(false);
    ui->radSales->setVisible(false);
<<<<<<< HEAD
=======
    ui->comboBox->setVisible(false);
>>>>>>> 4f3e42bfbdee489ff4d638520bf46ee00f6fc4c9

    mode = "";

    // setup combo box
    ui->comboBox->addItem( QString("Cars"));
    ui->comboBox->addItem( QString("Customer"));
    ui->comboBox->addItem( QString("Maintenence"));
    ui->comboBox->addItem( QString("Sales"));
    ui->comboBox->setCurrentIndex(SALES);
<<<<<<< HEAD
    ui->comboBox->setVisible(false);

    ui->tableView->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

//    layout->addWidget(ui->centralWidget);
//    layout->addWidget(ui->menuBar);
//    layout->addWidget(ui->mainToolBar);
//    layout->addWidget(ui->statusBar);
//    this->setLayout(layout);
=======

    LoginDialog* login = new LoginDialog();
    login->exec();

    if (login->GetUser() == 0)
        close();
    else
    {
        switch(login->GetUser())
        {
            case 1:
            {
                SetSales();
            }
                break;
            case 2:
            {
                SetMaintenence();
            }
                break;
            case 3:
            {
                SetSupervisor();
            }
        }
    }

>>>>>>> 4f3e42bfbdee489ff4d638520bf46ee00f6fc4c9
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
    int count = model->rowCount() -1;
    model->removeRow(count);
    //sqlPtr->deleteRow(/*table name*/, /*car_id from table*/);



}

void MainWindow::exitDatabase()
{
    QApplication::quit();
}

bool MainWindow::saveData()
{
    int numRows;

    if(strcmp(mode.c_str(),"") == 0){
        cout << "***NO MODE SET. UNABLE TO SAVE***" << endl;
        return false;
    }
    else if(strcmp(mode.c_str(),"Maintenance") == 0){
        vector<MaintenanceContainer> vContainer;
        QStandardItemModel* model = (QStandardItemModel*)ui->tableView->model();
        QModelIndex index;
        numRows = model->rowCount();
        for(int j = 0; j < numRows; j++){
            MaintenanceContainer container1;
            for(int i = 0; i < 5; i++){
                index = model->index(j,i,QModelIndex());
                QString tableData = model->data(index).toString();
                switch(i)
                {
                case 0: container1.setCarId(tableData.toInt());
                    break;
                case 1: container1.setDamages(tableData.toStdString());
                    break;
                case 2: container1.setCosts(tableData.toInt());
                    break;
                case 3: container1.setStartDate(tableData.toStdString());
                    break;
                case 4: container1.setFinishDate(tableData.toStdString());
                    break;
                }
            }
            vContainer.push_back(container1);
        }
        sqlPtr->maintenanceInsert(vContainer,mode);
        return true;
    }
    else if(strcmp(mode.c_str(),"Sales") == 0){
        vector<SalesContainer> vContainer;
        QStandardItemModel* model = (QStandardItemModel*)ui->tableView->model();
        QModelIndex index;
        numRows = model->rowCount();

        for(int j = 0; j < numRows; j++){
            SalesContainer container2;
            for(int i = 0; i < 9; i++){
                index = model->index(j,i,QModelIndex());
                QString tableData = model->data(index).toString();
                switch(i)
                {
                case 0: container2.setCarId(tableData.toInt());
                    break;
                case 1: container2.setAvailability(tableData.toStdString());
                    break;
                case 2:  container2.setDeliveryDate(tableData.toStdString());
                    break;
                case 3: container2.setCost(tableData.toInt());
                    break;
                case 4:  container2.setDateSold(tableData.toStdString());
                    break;
                case 5:  container2.setFirstName(tableData.toStdString());
                    break;
                case 6:  container2.setLastName(tableData.toStdString());
                    break;
                case 7:  container2.setMake(tableData.toStdString());
                    break;
                case 8:  container2.setModel(tableData.toStdString());
                    break;
                }
            }
            vContainer.push_back(container2);
        }
        sqlPtr->salesInsert(vContainer, mode);
        return true;
    }
    else if(strcmp(mode.c_str(),"Cars") == 0){
        vector<CarContainer> vContainer;
        QStandardItemModel* model = (QStandardItemModel*)ui->tableView->model();
        QModelIndex index;
        numRows = model->rowCount();

        for(int j = 0; j < numRows; j++){
            CarContainer container3;
            for(int i = 0; i < 13; i++){
                index = model->index(j,i,QModelIndex());
                QString tableData = model->data(index).toString();
                switch(i)
                {
                case 0: container3.setCarId(tableData.toInt());
                    break;
                case 1: container3.setMake(tableData.toStdString());
                    break;
                case 2: container3.setModel(tableData.toStdString());
                    break;
                case 3: container3.setPerformance(tableData.toStdString());
                    break;
                case 4: container3.setHandeling(tableData.toStdString());
                    break;
                case 5: container3.setInstrumentation(tableData.toStdString());
                    break;
                case 6: container3.setSafetySecurity(tableData.toStdString());
                    break;
                case 7: container3.setDesign(tableData.toStdString());
                    break;
                case 8: container3.setAudio(tableData.toStdString());
                    break;
                case 9: container3.setComfort(tableData.toStdString());
                    break;
                case 10: container3.setMaintenance(tableData.toStdString());
                    break;
                case 11: container3.setWarranty(tableData.toStdString());
                    break;
                case 12: container3.setPackages(tableData.toStdString());
                    break;
                }
            }
            vContainer.push_back(container3);
        }
        sqlPtr->carInsert(vContainer, mode);
        return true;
    }
    else if(strcmp(mode.c_str(),"Customers") == 0){
        vector<CustomerContainer> vContainer;
        QStandardItemModel* model = (QStandardItemModel*)ui->tableView->model();
        QModelIndex index;
        numRows = model->rowCount();

        for(int j = 0; j < numRows; j++){
            CustomerContainer container4;
            for(int i = 0; i < 10; i++){
                index = model->index(j,i,QModelIndex());
                QString tableData = model->data(index).toString();
                switch(i)
                {
                case 0: container4.setCarId(tableData.toInt());
                    break;
                case 1: container4.setFirstName(tableData.toStdString());
                    break;
                case 2: container4.setLastName(tableData.toStdString());
                    break;
                case 3: container4.setAddress(tableData.toStdString());
                    break;
                case 4: container4.setState(tableData.toStdString());
                    break;
                case 5: container4.setZip(tableData.toInt());
                    break;
                case 6:
                    break;
                case 7: container4.setDeliveryDate(tableData.toStdString());
                    break;
                case 8: container4.setScheduledMaintenance(tableData.toStdString());
                    break;
                case 9: container4.setUnscheduledRepairs(tableData.toStdString());
                    break;
                }
            }
            vContainer.push_back(container4);
        }
        sqlPtr->customerInsert(vContainer, mode);
        return true;
    }else{
        cout << "***NO MATCHING MODE FOUND. UNABLE TO SAVE***" << endl;
        return false;
    }
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
    mode = "Customers";
    ui->tableView->setModel(model);

    userMode = supervisor;
    ui->comboBox->setVisible(true);
    ui->btnAdd->setVisible(true);
    ui->btnRemove->setVisible(true);
    ui->btnSearch->setVisible(true);
    ui->radCar->setVisible(false);
    ui->radSales->setVisible(false);

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
                model->setItem(j,12,firstRow);
                break;
            }
        }
    }

    statusBar()->showMessage(tr("Car Table"));
    ui->tableView->setModel(model);
    mode = "Cars";
    userMode = sales;

    ui->radCar->setVisible(true);
    ui->radSales->setVisible(true);
    ui->comboBox->setVisible(false);
    ui->btnAdd->setVisible(true);
    ui->btnRemove->setVisible(true);
    ui->btnSearch->setVisible(true);
    ui->radCar->setVisible(true);
    ui->radSales->setVisible(true);
    ui->radCar->setChecked(true);
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
    mode = "Maintenance";
    userMode = maintenance;

    ui->comboBox->setVisible(false);
    ui->btnAdd->setVisible(true);
    ui->btnRemove->setVisible(true);
    ui->btnSearch->setVisible(true);
    ui->radCar->setVisible(false);
    ui->radSales->setVisible(false);
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
            mode = "Cars";
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
            mode = "Customers";
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
            mode = "Maintenance";
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
            mode = "Sales";
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
            mode = "Sales";
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
            mode = "Cars";
            statusBar()->showMessage(tr("Car Table"));
            ui->tableView->setModel(model);
        }
}

void MainWindow::OpenSearchDialog()
{
    char* c = const_cast<char*>(mode.c_str());

    if (strcmp(c,"Sales") == 0)
    {
        SalesDialog* salesDialog;
        salesDialog = new SalesDialog();
        salesDialog->exec();

        SalesContainer* container = salesDialog->GetSalesContainer();

        // PREFORM SEARCH....



        delete salesDialog;

    }
    else if(strcmp(c,"Cars") == 0)
    {
        CarSearchDialog* csd = new CarSearchDialog();
        csd->exec();

        CarContainer* container = csd->GetContainer();

        //PERFORM SEARCH



        delete csd;
    }
    else if(strcmp(c,"Maintenance") == 0)
    {
        SearchMaintenanceDialog* msd = new SearchMaintenanceDialog();
        msd->exec();

        MaintenanceContainer* container = msd->GetContainer();

        //PERFORM SEARCH



        delete msd;
    }
    else if(strcmp(c,"Customers") == 0)
    {
        SearchCustomerDialog* csd = new SearchCustomerDialog();
        csd->exec();

        CustomerContainer* container = csd->GetContainer();

        //PERFORM SEARCH



        delete csd;
    }
}

void MainWindow::Logout()
{
    ui->btnAdd->setVisible(false);
    ui->btnRemove->setVisible(false);
    ui->btnSearch->setVisible(false);
    ui->radCar->setVisible(false);
    ui->radSales->setVisible(false);
    ui->comboBox->setVisible(false);

    mode = "";

    LoginDialog* login = new LoginDialog();
    login->exec();

    if (login->GetUser() == 0)
        close();
    else
    {
        switch(login->GetUser())
        {
            case 1:
            {
                SetSales();
            }
                break;
            case 2:
            {
                SetMaintenence();
            }
                break;
            case 3:
            {
                SetSupervisor();
            }
        }
    }
}
