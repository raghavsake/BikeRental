#include "validation.h"


bool isAgeValid(int age)
{
    if(age<18||age>120)
        return false;
    return true;
}

bool isGenderValid(std::string gender)
{
    if(gender.compare("Male")==0 || gender.compare("Female")==0)
    {
        return true;
    }
    return false;
}

bool isDLValid(std::string dlNo)
{
    if(dlNo.length()!=7)
        return false;
    return true;
}

bool isPasswordValid(std::string password)
{
    if(password.length()<8||password.length()>32)
        return false;
    for(int i=0;i<password.length();i++)
    {
        if (isspace(password[i]))
            return false;
    }
    return true;
}

bool isNameValid(std::string name)
{
    for(int i=0;i<name.length();i++)
    {
        if (isspace(name[i]))
            return false;
        if (isdigit(name[i]))
            return false;
    }
    return true;
}



bool isValidFutureDate(std::string date)
{
    std::string year_s=date.substr(6, 4);
    std::string day_s=date.substr(0, 2);
    std::string month_s=date.substr(3, 2);

    int year =std::stoi(year_s);
    int day =std::stoi(day_s);
    int month=std::stoi(month_s);


    time_t now = time(0);
    tm *ltm = localtime(&now);   
    if(year > (1900 + ltm->tm_year)) {
        return true;
    }
    else if(year == (1900 + ltm->tm_year)) { 
            
        if(month > 1 + ltm->tm_mon) {
            return true;
        }
        else if(month == 1 + ltm->tm_mon) {
            
            if(day > ltm->tm_mday) {
                return true;
            }
            else {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool isValidPastDate(std::string date)
{
    std::string year_s=date.substr(6, 4);
    std::string day_s=date.substr(0, 2);
    std::string month_s=date.substr(3, 2);

    int year =std::stoi(year_s);
    int day =std::stoi(day_s);
    int month=std::stoi(month_s);


    time_t now = time(0);
    tm *ltm = localtime(&now);   
    if(year < (1900 + ltm->tm_year)) {
  
        return true;
    }

    else if(year == (1900 + ltm->tm_year)) { 
            
        if(month < 1 + ltm->tm_mon) {
            return true;
        }
        else if(month == 1 + ltm->tm_mon) {
            
            if(day < ltm->tm_mday) {
                return true;
            }
            else {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool isValidDate(std::string date){
    int d;
    int m;
    int y;

    std::istringstream is(date);
    char delimiter;
    if (is >> d >> delimiter >> m >> delimiter >> y) {
        struct tm t = {0};
        t.tm_mday = d;
        t.tm_mon = m - 1;
        t.tm_year = y - 1900;
        t.tm_isdst = -1;
        time_t when = mktime(&t);
        const struct tm *norm = localtime(&when);
        return (norm->tm_mday == d    &&
                norm->tm_mon  == m - 1 &&
                norm->tm_year == y - 1900);
    }
    return false;
}