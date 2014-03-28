#include "CustomerContainer.h"

CustomerContainer::CustomerContainer(){
    car_id = 0;
    first_name = "";
    last_name = "";
    address = "";
    state = "";
    zip = 0;
    phone = "";
    delivery_date = "";
    scheduled_maintenance = "";
    unscheduled_repairs = "";
}

CustomerContainer::~CustomerContainer(){

}

void CustomerContainer::setCarId(int id){
    car_id = id;
}

void CustomerContainer::setAddress(string name){
    address = name;
}

void CustomerContainer::setDeliveryDate(string name){
    delivery_date = name;
}

void CustomerContainer::setFirstName(string name){
    first_name = name;
}

void CustomerContainer::setLastName(string name){
    last_name = name;
}

void CustomerContainer::setPhone(string name){
    phone = name;
}

void CustomerContainer::setScheduledMaintenance(string name){
    scheduled_maintenance = name;
}

void CustomerContainer::setState(string name)
{
    state = name;
}

void CustomerContainer::setUnscheduledRepairs(string name){
    unscheduled_repairs = name;
}

void CustomerContainer::setZip(int name){
    zip = name;
}

int CustomerContainer::getCarId(){
    return car_id;
}

string CustomerContainer::getAddress(){
    return address;
}

string CustomerContainer::getDeliveryDate(){
    return delivery_date;
}

string CustomerContainer::getFirstName(){
    return first_name;
}

string CustomerContainer::getLastName(){
    return last_name;
}

string CustomerContainer::getPhone(){
    return phone;
}

string CustomerContainer::getScheduledMaintenance(){
    return scheduled_maintenance;
}

string CustomerContainer::getState(){
    return state;
}

string CustomerContainer::getUnscheduledRepairs(){
    return unscheduled_repairs;
}

int CustomerContainer::getZip(){
    return zip;
}
