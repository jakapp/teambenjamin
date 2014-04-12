#include "logindialog.h"
#include "ui_logindialog.h"
#include <qmessagebox.h>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    connect(ui->btnLogin, SIGNAL(clicked()), this, SLOT(Login()));
    connect(ui->btnCancel,SIGNAL(clicked()), this, SLOT(close()));
    ui->txtPassword->setEchoMode(QLineEdit::Password);
    user = 0;
}

LoginDialog::~LoginDialog()
{
    delete ui;
}


void LoginDialog::Login()
{
    QString username = ui->txtLogin->text();
    QString password = ui->txtPassword->text();
    bool result = false;

    if (strcmp(username.toStdString().c_str(),maintenanceUserName) == 0)
    {
        if (strcmp(password.toStdString().c_str(),maintenancePassword) == 0)
        {
            result = true;
            user = MAINT;
        }
    }
    else if(strcmp(username.toStdString().c_str(),salesUserName) == 0)
    {
        if (strcmp(password.toStdString().c_str(),salesPassword) == 0)
        {
            result = true;
            user = SALES;
        }
    }
    else if(strcmp(username.toStdString().c_str(),supervisorUserName) == 0)
    {
        if (strcmp(password.toStdString().c_str(),supervisorPassword) == 0)
        {
            result = true;
            user = SUPER;
        }
    }

    if (result)
        close();
    else
    {
        QMessageBox* m = new QMessageBox();
        m->setText("Username or password is incorrect.");
        m->exec();
        delete m;
    }

}
