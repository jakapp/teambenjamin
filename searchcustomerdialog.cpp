#include "searchcustomerdialog.h"
#include "ui_searchcustomerdialog.h"

SearchCustomerDialog::SearchCustomerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchCustomerDialog)
{
    ui->setupUi(this);

    connect(ui->btnOk, SIGNAL(clicked()), this, SLOT(FillContainer()));
    connect(ui->btnCancel,SIGNAL(clicked()), this, SLOT(close()));

    m_container = new CustomerContainer();

}

SearchCustomerDialog::~SearchCustomerDialog()
{
    delete ui;

    if (m_container)
        delete m_container;
}

void SearchCustomerDialog::FillContainer()
{
    m_container->setCarId(ui->txtCarID->text().toInt());
    m_container->setFirstName(ui->txtFirstName->text().toStdString());
    m_container->setLastName(ui->txtLastName->text().toStdString());
    m_container->setAddress(ui->txtAddress->text().toStdString());
    m_container->setState(ui->txtState->text().toStdString());
    m_container->setZip(ui->txtZip->text().toInt());
    m_container->setPhone(ui->txtPhone->text().toStdString());
    m_container->setDeliveryDate(ui->txtDelivery->text().toStdString());
    m_container->setScheduledMaintenance(ui->txtScheduled->text().toStdString());
    m_container->setUnscheduledRepairs(ui->txtUnscheduled->text().toStdString());

    close();
}
