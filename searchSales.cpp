#include "searchsales.h"
#include "ui_searchsales.h"

SalesDialog::SalesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchDialog)
{
    ui->setupUi(this);

    connect(ui->btnOk, SIGNAL(clicked()), this, SLOT(FillContainer()));
    connect(ui->btnCancel,SIGNAL(clicked()), this, SLOT(close()));
    m_sales = new SalesContainer();
}

SalesDialog::~SalesDialog()
{
    delete ui;

    if (m_sales)
        delete m_sales;
}

void SalesDialog::FillContainer()
{
    m_sales->setCarId(ui->txtCarID->text().toInt());
    m_sales->setAvailability(ui->txtAvailability->text().toStdString());
    m_sales->setDeliveryDate(ui->txtDelivery->text().toStdString());
    m_sales->setCost(ui->txtCost->text().toInt());
    m_sales->setDateSold(ui->txtSold->text().toStdString());
    m_sales->setFirstName(ui->txtFirstName->text().toStdString());
    m_sales->setLastName(ui->txtLastName->text().toStdString());
    m_sales->setMake(ui->txtMake->text().toStdString());
    m_sales->setModel(ui->txtModel->text().toStdString());
    this->close();

}
