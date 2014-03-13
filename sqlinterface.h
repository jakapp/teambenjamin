#include <iostream>
#include <string>
#include <occi.h>
#include <vector>
#include <iomanip>

using namespace std;
using namespace oracle::occi;

#ifndef SQLINTERFACE_H
#define SQLINTERFACE_H

class SqlInterface{
public:
    SqlInterface();
    ~SqlInterface();

    void connect();
    void insert();
    void select();
    void display();
    void deleteRow();
    void createTable();
    void modifyRow();

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
