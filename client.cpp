#include "client.h"

Client::Client(string name,int age,string gender,string dlNo,string password)
    : name_(name), age_(age), gender_(gender), dlNo_(dlNo), password_(password)
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

string Client::getPassword()
{
    return password_;
}