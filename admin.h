#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
using namespace std;


class Admin{
    public:
       Admin(string name,int age,string gender,string password);
       string getName();
       int getAge();
       string getGender();
       string getPassword();
    private:
        string name_;;
        int age_;
        string gender_;
        string password_;
};

#endif