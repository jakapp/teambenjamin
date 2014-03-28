#include "salescontainer.h"

SalesContainer::SalesContainer()
{
    car_id = 0;
    availability = "";
    delivery_date = "";
    cost = 0;
    date_sold = "";
    first_name = "";
    last_name = "";
    make = "";
    model = "";
}

SalesContainer::~SalesContainer()
{

}

void SalesContainer::setAvailability(string name){
    availability = name;
}

void SalesContainer::setCarId(int id){
    car_id = id;
}

void SalesContainer::setCost(int costs){
    cost = costs;
}

void SalesContainer::setDateSold(string name){
    date_sold = name;
}

void SalesContainer::setDeliveryDate(string name){
    delivery_date = name;
}

void SalesContainer::setFirstName(string name){
    first_name = name;
}

void SalesContainer::setLastName(string name){
    last_name = name;
}

void SalesContainer::setMake(string name){
    make = name;
}

void SalesContainer::setModel(string name){
    model = name;
}

string SalesContainer::getAvailability(){
    return availability;
}

int SalesContainer::getCarId(){
    return car_id;
}

int SalesContainer::getCost(){
    return cost;
}

string SalesContainer::getDateSold(){
    return date_sold;
}

string SalesContainer::getDeliveryDate(){
    return delivery_date;
}

string SalesContainer::getFirstName(){
    return first_name;
}

string SalesContainer::getLastName(){
    return last_name;
}

string SalesContainer::getMake(){
    return make;
}

string SalesContainer::getModel(){
        return model;
}
