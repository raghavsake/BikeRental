#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
using namespace std;


class Admin{
    public:
       Admin(string name,int age,string gender);
       string getName();
       int getAge();
       string getGender();
    private:
        string name_;
        int age_;
        string gender_;
};

#endif