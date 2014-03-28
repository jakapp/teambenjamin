#include <string>

using namespace std;

#ifndef MAINTENANCECONTAINER_H
#define MAINTENANCECONTAINER_H

class MaintenanceContainer
{
public:
    MaintenanceContainer();
    ~MaintenanceContainer();

    void setCarId(int id);
    void setDamages(string name);
    void setCosts(int costs);
    void setStartDate(int name);
    void setFinishDate(int name);

    int getCarId();
    string getDamages();
    int getCost();
    string getStartDate();
    string getFinishDate();

private:
    int car_id;
    string damages;
    int cost;
    string start_date;
    string finish_date;

};

#endif // MAINTENANCECONTAINER_H
