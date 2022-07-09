#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
using namespace std;


class Client{
    public:
        Client(string name,int age,string gender,string dlNo,string password);
        string getName();
        int getAge();
        string getGender();
        string getDlNo();
        string getPassword();



    private:
        string name_;
        int age_;
        string gender_;
        string dlNo_;
        string password_;
};

#endif