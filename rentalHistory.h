#ifndef RENTALHISTORY_H
#define RENTALHISTORY_H

#include <iostream>
using namespace std;


class RentalHistory{
    public:
        RentalHistory(string bike, string location, string clientName, string date, double cost,int statusNo, int nextHistory);
        string getBike();
        string getLocation();
        string getClientName();
        string getDate();
        int getNextHistory();
        string getStatus();
        double getCost();
        bool operator==(RentalHistory& rentalhistory);
    private:
        string bike_;
        string location_;
        string clientName_;
        string date_;
        int nextHistory_;
        int statusNo_;
        double cost_;
};

#endif