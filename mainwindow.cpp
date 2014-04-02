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

//  connect(, SIGNAL(destroyed(QObject*)), this, SLOT(objectDestroyed(Qbject*)));
    connect(ui->btnAdd,SIGNAL(clicked()),this,SLOT(AddItem()));
    connect(ui->btnRemove,SIGNAL(clicked()),this,SLOT(RemoveItem()));
    connect(ui->actionSupervisor,SIGNAL(triggered()),this,SLOT(SetSupervisor()));
    connect(ui->actionSales,SIGNAL(triggered()),this,SLOT(SetSales()));
    connect(ui->actionMaintenence,SIGNAL(triggered()),this,SLOT(SetMaintenence()));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(SetTable()));
    connect(ui->radCar,SIGNAL(clicked()),this,SLOT(SetTable()));
    connect(ui->radSales,SIGNAL(clicked()),this,SLOT(SetTable()));

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

void MainWindow::AddItem()
{
    QStandardItemModel* model = (QStandardItemModel*)ui->tableView->model();

    model->insertRow(model->rowCount());
}

void MainWindow::RemoveItem()
{
    QStandardItemModel* model = (QStandardItemModel*)ui->tableView->model();
    model->removeRow(model->rowCount());

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

    ui->tableView->setModel(model);

    userMode = supervisor;
    ui->comboBox->setVisible(true);
    ui->btnAdd->setVisible(true);
    ui->btnRemove->setVisible(true);
    ui->btnSearch->setVisible(true);

}

void MainWindow::SetSales()
{
    QStandardItemModel* model = new QStandardItemModel(1,13,this);
    model->setHorizontalHeaderItem(0,new QStandardItem(QString("ID")));
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
    ui->tableView->setModel(model);

    userMode = sales;

    ui->comboBox->setVisible(false);
    ui->btnAdd->setVisible(true);
    ui->btnRemove->setVisible(false);
    ui->btnSearch->setVisible(true);
}

void MainWindow::SetMaintenence()
{
    QStandardItemModel* model = new QStandardItemModel(1,5,this);
    model->setHorizontalHeaderItem(0,new QStandardItem(QString("ID")));
    model->setHorizontalHeaderItem(1,new QStandardItem(QString("Damages")));
    model->setHorizontalHeaderItem(2,new QStandardItem(QString("Costs")));
    model->setHorizontalHeaderItem(3,new QStandardItem(QString("Start Date")));
    model->setHorizontalHeaderItem(4,new QStandardItem(QString("Finish Date")));

    ui->tableView->setModel(model);

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
            model->setHorizontalHeaderItem(0,new QStandardItem(QString("ID")));
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

            ui->tableView->setModel(model);
        }
            break;
        case MAINT:
        {
            QStandardItemModel* model = new QStandardItemModel(1,5,this);
            model->setHorizontalHeaderItem(0,new QStandardItem(QString("ID")));
            model->setHorizontalHeaderItem(1,new QStandardItem(QString("Damages")));
            model->setHorizontalHeaderItem(2,new QStandardItem(QString("Costs")));
            model->setHorizontalHeaderItem(3,new QStandardItem(QString("Start Date")));
            model->setHorizontalHeaderItem(4,new QStandardItem(QString("Finish Date")));

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
            ui->tableView->setModel(model);
        }
        else if (ui->radCar->isChecked() && (userMode == sales))
        {
            QStandardItemModel* model = new QStandardItemModel(1,13,this);
            model->setHorizontalHeaderItem(0,new QStandardItem(QString("ID")));
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
            ui->tableView->setModel(model);
        }

}
