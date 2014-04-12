#include "carsearchdialog.h"
#include "ui_carsearchdialog.h"

CarSearchDialog::CarSearchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CarSearchDialog)
{
    ui->setupUi(this);

    connect(ui->btnOk, SIGNAL(clicked()), this, SLOT(FillContainer()));
    connect(ui->btnCancel,SIGNAL(clicked()), this, SLOT(close()));

    m_container = new CarContainer();
}

CarSearchDialog::~CarSearchDialog()
{
    delete ui;

    if (m_container)
        delete m_container;
}

void CarSearchDialog::FillContainer()
{
    m_container->setCarId(ui->txtCarID->text().toInt());
    m_container->setMake(ui->txtMake->text().toStdString());
    m_container->setModel(ui->txtModel->text().toStdString());
    m_container->setPerformance(ui->txtPerformance->text().toStdString());
    m_container->setHandeling(ui->txtHandeling->text().toStdString());
    m_container->setInstrumentation(ui->txtinstrumentation->text().toStdString());
    m_container->setSafetySecurity(ui->txtSaftey->text().toStdString());
    m_container->setDesign(ui->txtDesign->text().toStdString());
    m_container->setAudio(ui->txtAudio->text().toStdString());
    m_container->setComfort(ui->txtComfort->text().toStdString());
    m_container->setMaintenance(ui->txtMaintenance->text().toStdString());
    m_container->setWarranty(ui->txtWarrenty->text().toStdString());
    m_container->setPackages(ui->txtPackages->text().toStdString());

    close();
}
