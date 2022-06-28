#ifndef BIKERENTAL_H
#define BIKERENTAL_H

#include <iostream>
#include "client.h"
#include "admin.h"
#include "rentalHistory.h"
#include <vector>
#include <map>
#include <iterator>


Client getClient(std::string clientName);
Client registerClient(std::string name,int age,std::string gender,std::string dlNo);
int isClientPresent(std::string name);
bool isAdminPresent(std::string name);
Admin getAdmin(std::string adminName);
std::vector<std::string> readAllBikes();
std::vector<std::string> readAllLocations();
std::map<std::string,int> getAllClients();
std::vector<std::pair<std::string, int>> getSortedClientName();
int isRentalPresent(std::string clientName);
RentalHistory addRental(std::string clientName, std::string bike, std::string location, std::string date);
bool isLocationPresent(std::string location);
bool isBikePresent(std::string bike);
std::vector<RentalHistory> getAllRentalHistory(std::string clientName);

#endif