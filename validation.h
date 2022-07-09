#ifndef VALIDATION_H
#define VALIDATION_H
#include <sstream>
#include <ctime>


#include <iostream>

bool isAgeValid(int age);
bool isGenderValid(std::string gender);
bool isDLValid(std::string dlNo);
bool isPasswordValid(std::string password);
bool isNameValid(std::string name);
bool isValidDate(std::string date);
bool isValidFutureDate(std::string date);
bool isValidPastDate(std::string date);
#endif