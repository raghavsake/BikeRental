#ifndef BIKE_H
#define BIKE_H

#include <iostream>
using namespace std;

class Bike{
    public:
       Bike(string name,double cost);
       string getName();
       double getCost();
    private:
        string name_;;
        double cost_;
};

#endif