#include "CarContainer.h"

CarContainer::CarContainer()
{
    car_id = 0;
    audio = "";
    comfort = "";
    design = "";
    handeling = "";
    intrumentation = "";
    maintenance = "";
    make = "";
    packages = "";
    performance = "";
    safey_security = "";
    warranty = "";
}

CarContainer::~CarContainer(){

}

void CarContainer::setAudio(string name){
    audio = name;
}

void CarContainer::setCarId(int id)
{
    car_id = id;
}

void CarContainer::setComfort(string name){
    comfort = name;
}

void CarContainer::setDesign(string name){
    design = name;
}

void CarContainer::setHandeling(string name){
    handeling = name;
}

void CarContainer::setInstrumentation(string name){
    intrumentation = name;
}

void CarContainer::setMaintenance(string name){
    maintenance = name;
}

void CarContainer::setMake(string name){
    make = name;
}

void CarContainer::setModel(string name){
    model = name;
}

void CarContainer::setPackages(string name){
    packages = name;
}

void CarContainer::setPerformance(string name){
    performance = name;
}

void CarContainer::setSafetySecurity(string name){
    safey_security = name;
}

void CarContainer::setWarranty(string name){
    warranty = name;
}

int CarContainer::getCarId(){
    return car_id;
}

string CarContainer::getAudio(){
    return audio;
}

string CarContainer::getComfort(){
    return comfort;
}

string CarContainer::getDesign(){
    return design;
}

string CarContainer::getHandeling(){
    return handeling;
}

string CarContainer::getInstrumentation(){
    return intrumentation;
}

string CarContainer::getMaintenance(){
    return maintenance;
}

string CarContainer::getMake(){
    return make;
}

string CarContainer::getModel(){
    return model;
}

string CarContainer::getPackages(){
    return packages;
}

string CarContainer::getPerformance(){
    return performance;
}

string CarContainer::getSafetySecurity(){
    return safey_security;
}

string CarContainer::getWarranty(){
    return warranty;
}
