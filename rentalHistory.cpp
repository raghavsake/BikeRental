#include "rentalHistory.h"
#include <iostream>
using namespace std;


RentalHistory::RentalHistory(string bike, string location, string clientName, string date, double cost, int statusNo, int nextHistory)
    : clientName_(clientName), location_(location), bike_(bike), date_(date), nextHistory_(nextHistory), statusNo_(statusNo), cost_(cost)
{

}

string RentalHistory::getStatus()
{
    if (statusNo_==2)
        return "Cancelled";
    else
        return "Active";
}

string RentalHistory::getBike()
{
    return bike_;
}

string RentalHistory::getClientName()
{
    return clientName_;    
}

string RentalHistory::getDate()
{
    return date_;
}

string RentalHistory::getLocation()
{
    return location_;
}

int RentalHistory::getNextHistory()
{
    return nextHistory_;
}

double RentalHistory::getCost()
{
    return cost_;
}

bool RentalHistory::operator==(RentalHistory& rentalHistory)
{
    if(bike_.compare(rentalHistory.getBike())!=0)
        return false;
    if(clientName_.compare(rentalHistory.getClientName())!=0)
        return false;
    if(location_.compare(rentalHistory.getLocation())!=0)
        return false;
    if(date_.compare(rentalHistory.getDate())!=0)
        return false;
    if(statusNo_!=rentalHistory.statusNo_)
        return false;
    if(cost_!=rentalHistory.cost_)
        return false;
    return true;

    
}