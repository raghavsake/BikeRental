#include "rentalHistory.h"
#include <iostream>
using namespace std;


RentalHistory::RentalHistory(string bike, string location, string clientName, string date, int nextHistory)
    : clientName_(clientName), location_(location), bike_(bike), date_(date), nextHistory_(nextHistory)
{

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