#include "client.h"

Client::Client(string name,int age,string gender,string dlNo)
    : name_(name), age_(age), gender_(gender), dlNo_(dlNo)
    {

    }

string Client::getName()
{
    return name_;
}

string Client::getGender()
{
    return gender_;
}

int Client::getAge()
{
    return age_;
}

string Client::getDlNo()
{
    return dlNo_;
}