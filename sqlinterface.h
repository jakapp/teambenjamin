#include <iostream>
#include <string>
#include <occi.h>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include "maintenancecontainer.h"
#include "salescontainer.h"
#include "CustomerContainer.h"
#include "CarContainer.h"

using namespace std;
using namespace oracle::occi;

#ifndef SQLINTERFACE_H
#define SQLINTERFACE_H

class SqlInterface{
public:
    SqlInterface();
    ~SqlInterface();

    void connect(string user, string passwd, string db);

    MaintenanceContainer searchMaintenanceData(string query);
    CustomerContainer searchCustomerData(string query);
    CarContainer searchCarData(string query);
    SalesContainer searchSalesData(string query);

    vector<MaintenanceContainer> getMaintenanceData();
    vector<CustomerContainer> getCustomerData();
    vector<CarContainer> getCarData();
    vector<SalesContainer> getSalesData();

    void deleteRow(string table, int car_id);

    //  Depreciated Functions
    //    void insert();
    //    void select();
    //    void display();

    //    void createTable();
    //    void modifyRow();

private:
    string user;
    string passwd;
    string db;
    string query;
    string temp;
    Statement *stmt;
    Connection *conn;
    Environment *env;
};


#endif // SQLINTERFACE_H
