#include "maintenancecontainer.h"

MaintenanceContainer::MaintenanceContainer()
{
    car_id = 0;
    damages = "";
    cost = 0;
    start_date = "";
    finish_date = "";
}

MaintenanceContainer::~MaintenanceContainer(){

}

void MaintenanceContainer::setCarId(int id){
    car_id = id;
}

void MaintenanceContainer::setCosts(int costs){
    cost = costs;
}

void MaintenanceContainer::setDamages(string name){
    damages = name;
}

void MaintenanceContainer::setFinishDate(int name){
    finish_date = name;
}
void MaintenanceContainer::setStartDate(int name){
    start_date = name;
}

int MaintenanceContainer::getCarId(){
    return car_id;
}

int MaintenanceContainer::getCost(){
    return cost;
}

string MaintenanceContainer::getDamages(){
    return damages;
}

string MaintenanceContainer::getFinishDate(){
    return finish_date;
}

string MaintenanceContainer::getStartDate(){
    return start_date;
}
