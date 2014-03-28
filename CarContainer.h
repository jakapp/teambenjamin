#include <string>

using namespace std;

#ifndef CARCONTAINER_H
#define CARCONTAINER_H

class CarContainer{
public:
    CarContainer();
    ~CarContainer();

    void setCarId(int id);
    void setMake(string name);
    void setModel(string name);
    void setPerformance(string name);
    void setHandeling(string name);
    void setInstrumentation(string name);
    void setSafetySecurity(string name);
    void setDesign(string name);
    void setAudio(string name);
    void setComfort(string name);
    void setMaintenance(string name);
    void setWarranty(string name);
    void setPackages(string name);\

    int getCarId();
    string getMake();
    string getModel();
    string getPerformance();
    string getHandeling();
    string getInstrumentation();
    string getSafetySecurity();
    string getDesign();
    string getAudio();
    string getComfort();
    string getMaintenance();
    string getWarranty();
    string getPackages();\

private:
    int car_id;
    string make;
    string model;
    string performance;
    string handeling;
    string intrumentation;
    string safey_security;
    string design;
    string audio;
    string comfort;
    string maintenance;
    string warranty;
    string packages;

};

#endif // CARCONTAINER_H
