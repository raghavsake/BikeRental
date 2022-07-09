#include "bike.h"

Bike::Bike(string name,double cost)
    : name_(name),cost_(cost)
{

}

string Bike::getName()
{
    return name_;
}

double Bike::getCost()
{
    return cost_;
}