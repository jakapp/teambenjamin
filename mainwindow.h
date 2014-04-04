#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <sqlinterface.h>
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setDatabasePointer(SqlInterface *ptr);
    ~MainWindow();
public slots:
    void AddItem();
    void RemoveItem();
    void SetSupervisor();
    void SetSales();
    void SetMaintenence();
    void SetTable();
    bool saveData();
    void exitDatabase();

private:
    Ui::MainWindow *ui;
    int userMode;
    static const int supervisor = 0;
    static const int sales = 1;
    static const int maintenance = 2;

    SqlInterface *sqlPtr;
    string mode;

    void LoadMaintenanceTable();
    void LoadSalesTable();
    void LoadCarTable();
    void LoadCustomerTable();
};

#endif // MAINWINDOW_H
