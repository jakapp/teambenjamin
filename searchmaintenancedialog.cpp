#include "searchmaintenancedialog.h"
#include "ui_searchmaintenancedialog.h"

SearchMaintenanceDialog::SearchMaintenanceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchMaintenanceDialog)
{
    ui->setupUi(this);
    connect(ui->btnOk, SIGNAL(clicked()), this, SLOT(FillContainer()));
    connect(ui->btnCancel,SIGNAL(clicked()), this, SLOT(close()));

    m_container = new MaintenanceContainer();
}

SearchMaintenanceDialog::~SearchMaintenanceDialog()
{
    delete ui;


    if (m_container)
        delete m_container;
}

void SearchMaintenanceDialog::FillContainer()
{
    m_container->setCarId(ui->txtCarID->text().toInt());
    m_container->setDamages(ui->txtDamages->text().toStdString());
    m_container->setCosts(ui->txtCosts->text().toInt());
    m_container->setStartDate(ui->txtStart->text().toStdString());
    m_container->setFinishDate(ui->txtFinish->text().toStdString());

    close();
}
