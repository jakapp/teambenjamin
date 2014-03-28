#include <string>

using namespace std;

#ifndef SALESCONTAINER_H
#define SALESCONTAINER_H

class SalesContainer
{
public:
    SalesContainer();
    ~SalesContainer();

    void setCarId(int id);
    void setAvailability(string name);
    void setDeliveryDate(string name);
    void setCost(int costs);
    void setDateSold(string name);
    void setFirstName(string name);
    void setLastName(string name);
    void setMake(string name);
    void setModel(string name);

    int getCarId();
    int getCost();
    string getAvailability();
    string getDeliveryDate();
    string getDateSold();
    string getFirstName();
    string getLastName();
    string getMake();
    string getModel();

private:
    int car_id;
    string availability;
    string delivery_date;
    int cost;
    string date_sold;
    string first_name;
    string last_name;
    string make;
    string model;
};

#endif // SALESCONTAINER_H
