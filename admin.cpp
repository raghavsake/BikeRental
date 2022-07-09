#include "admin.h"

Admin::Admin(string name,int age,string gender, string password)
    : name_(name), age_(age), gender_(gender), password_(password)
    {

    }

string Admin::getName()
{
    return name_;
}

string Admin::getGender()
{
    return gender_;
}

int Admin::getAge()
{
    return age_;
}

string Admin::getPassword()
{
    return password_;
}