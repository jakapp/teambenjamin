#include <string>

using namespace std;

#ifndef CUSTOMERCONTAINER_H
#define CUSTOMERCONTAINER_H

class CustomerContainer{
public:
    CustomerContainer();
    ~CustomerContainer();

    void setCarId(int id);
    void setFirstName(string name);
    void setLastName(string name);
    void setAddress(string name);
    void setState(string name);
    void setZip(int name);
    void setPhone(string name);
    void setDeliveryDate(string name);
    void setScheduledMaintenance(string name);
    void setUnscheduledRepairs(string name);

    int getCarId();
    string getFirstName();
    string getLastName();
    string getAddress();
    string getState();
    int getZip();
    string getPhone();
    string getDeliveryDate();
    string getScheduledMaintenance();
    string getUnscheduledRepairs();

private:
    int car_id;
    string first_name;
    string last_name;
    string address;
    string state;
    int zip;
    string phone;
    string delivery_date;
    string scheduled_maintenance;
    string unscheduled_repairs;
};

#endif // CUSTOMERCONTAINER_H
