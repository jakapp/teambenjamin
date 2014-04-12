#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
    int GetUser() { return user; }
private:
    const char* salesUserName = "Scott";
    const char* salesPassword = "password";

    const char* maintenanceUserName = "John";
    const char* maintenancePassword = "password";

    const char* supervisorUserName = "Batman";
    const char* supervisorPassword = "password";
    enum { SALES = 1, MAINT, SUPER };
    int user;
    Ui::LoginDialog *ui;
public slots:
    void Login();
};

#endif // LOGINDIALOG_H
