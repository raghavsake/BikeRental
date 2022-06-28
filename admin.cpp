#include "admin.h"

Admin::Admin(string name,int age,string gender)
    : name_(name), age_(age), gender_(gender)
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