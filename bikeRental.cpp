#include <iostream>
#include<stdexcept>
#include "client.h"
#include "admin.h"
#include "bikeRental.h"
#include "bike.h"
#include "rentalHistory.h"
#include <fstream>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <filesystem>
#include <cstdio>

Bike getBike(std::string bikeName)
{
    try
    {
        std::ifstream infile("bikes.dat");
        if(!infile)
        {
            throw("Data file for Bikes is not created");
        }
        else
        {
            std::string name;
            double cost;
            while (infile >> name >> cost)
            {
                if(name.compare(bikeName)==0)
                {
                    infile.close();
                    Bike bike(name,cost);
                    return bike;
                }
            }
        }
        throw("Bike is not present in the database!\n");
    }
    catch(char const* exc)
    {
        std::cerr<<"Exception occured when trying to get bikes\n";
        std::cerr<<exc;
        exit(1);
    }
    catch(...)
    {
        std::cerr<<"Exception occured when trying to get bikes\n";
        exit(1); 
    }
}

bool isBikePresent(std::string bikeName)
{
    try
    {
        std::ifstream infile("bikes.dat");
        if(!infile)
        {
            throw("Data file for Bikes is not created");
        }
        else
        {
            std::string name;
            double cost;
            while (infile >> name >> cost)
            {
                if(name.compare(bikeName)==0)
                {
                    infile.close();
                    return true;
                }
            }
        }
        return false;
    }
    catch(char const* exc)
    {
        std::cerr<<"Exception occured when trying to get bikes\n";
        std::cerr<<exc;
        exit(1);
    }
    catch(...)
    {
        std::cerr<<"Exception occured when trying to get bikes\n";
        exit(1); 
    }
}

std::vector<Bike> readAllBikes()
{
    try
    {
        std::vector<Bike> listOfBikes;
        std::ifstream infile("bikes.dat");
        if (infile.is_open()){   
            string name;
            double cost;
            while(infile >> name >> cost){
                Bike bike(name,cost); 
                listOfBikes.push_back(bike);
            }
            infile.close(); 
        }
        else{
            throw("Data file for Bikes is not created");
        }

        return listOfBikes;
    }
    catch(char const* exc)
    {
        std::cerr<<"Exception occured when trying to read bikes data\n";
        std::cerr<<exc;
        exit(1);
    }
    catch(...)
    {
        std::cerr<<"Exception occured when trying to read bikes data\n";
        exit(1); 
    }
    
}

bool isLocationPresent(std::string location)
{
    try
    {
        fstream newfile;
        newfile.open("operatingLocations.dat",ios::in); 
        if (newfile.is_open()){   
            string tp;
            while(getline(newfile, tp)){ 
                if(tp.compare(location)==0)
                    return true;
            }
            newfile.close(); 
        }
        else{
            throw("Data file for Operating Locations is not created");
        }

        return false;
    }
    catch(char const* exc)
    {
        std::cerr<<"Exception occured when trying to read operating locations data\n";
        std::cerr<<exc;
        exit(1);
    }
    catch(...)
    {
        std::cerr<<"Exception occured when trying to read operating locations data\n";
        exit(1); 
    }
}

std::vector<std::string> readAllLocations()
{
    try
    {
        std::vector<std::string> listOfLocations;
        fstream newfile;
        newfile.open("operatingLocations.dat",ios::in); 
        if (newfile.is_open()){   
            string tp;
            while(getline(newfile, tp)){ 
                listOfLocations.push_back(tp);
            }
            newfile.close(); 
        }
        else{
            throw("Data file for Operating Locations is not created");
        }

        return listOfLocations;
    }
    catch(char const* exc)
    {
        std::cerr<<"Exception occured when trying to read operating locations data\n";
        std::cerr<<exc;
        exit(1);
    }
    catch(...)
    {
        std::cerr<<"Exception occured when trying to read operating locations data\n";
        exit(1); 
    }
    
}

std::map<std::string,int> getAllClients()
{
    try{
        std::map<std::string,int> clientList;
        std::ifstream infile("client.idx");
        if(!infile)
        {
            throw("Index file for Client is not created");
        }
        else
        {
            std::string temp_name;
            int temp_pos;
            while (infile >> temp_name >> temp_pos)
            {
                clientList.insert(std::pair<std::string, int>(temp_name, temp_pos));
            }
            infile.close();
            return clientList;
        } 
    }
    catch(char const* exc)
    {
        std::cerr<<"Exception occured when trying to read all clients\n";
        std::cerr<<exc;
        exit(1);
    }
    catch(...)
    {
        std::cerr<<"Exception occured when trying to read all clients\n";
        exit(1); 
    }
}


std::vector<std::pair<std::string, int> > getSortedClientName()
{
    try{
        std::map<std::string,int> clientList=getAllClients();
        std::vector<std::pair<std::string, int> > sortedClientList;
        for (auto& it : clientList) {
            sortedClientList.push_back(it);
        }
        std::sort(sortedClientList.begin(), sortedClientList.end());
  
        return sortedClientList;
    }
    catch(char const* exc)
    {
        std::cerr<<"Exception occured when trying to read and sort all clients\n";
        std::cerr<<exc;
        exit(1);
    }
    catch(...)
    {
        std::cerr<<"Exception occured when trying to read and sort all clients\n";
        exit(1); 
    }
}



bool isAdminPresent(std::string name)
{
    try{
        std::ifstream infile("admin.dat");
        if(!infile)
        {
            throw("Data file for Admin is not created");
        }
        else
        {
            std::string temp_name;
            int temp_age;
            std::string temp_gender;
            std::string temp_password;
            while (infile >> temp_name >> temp_age >> temp_gender>>temp_password)
            {
                if(temp_name.compare(name)==0)
                {
                    infile.close();
                    return true;
                }
            }
            infile.close();
            return false;
        } 

    }
    catch(char const* exc)
    {
        std::cerr<<"Exception occured when trying to find if admin is present\n";
        std::cerr<<exc;
        exit(1);
    }
    catch(...)
    {
        std::cerr<<"Exception occured when trying to find if admin is present\n";
        exit(1); 
    }
}

Admin getAdmin(std::string adminName)
{
    try{
        if(!isAdminPresent(adminName))
        {
            throw("Admin is not present in the system");
        }
        
        
           std::ifstream infile("admin.dat");
            if(!infile)
            {
                throw("Data file for Admin is not created");
            }
            else
            {
                std::string name;
                int age;
                std::string gender;
                std::string password;
                while (infile >> name >> age >> gender>>password)
                {
                    if(name.compare(adminName)==0)
                    {
                        infile.close();
                        Admin admin(adminName,age,gender,password);
                        return admin;                            
                    }
                }
            }
        throw("Could not find admin in the system!\n");  
    }
    catch(char const* exc)
    {
        std::cerr<<"Exception occured when trying to get admin\n";
        std::cerr<<exc;
        exit(1);
    }
    catch(...)
    {
        std::cerr<<"Exception occured when trying to get admin\n";
        exit(1); 
    }
}



int isClientPresent(std::string name)
{
    try{
        std::ifstream infile("client.idx");
        if(!infile)
        {
            throw("Index file for Client is not created");
        }
        else
        {
            std::string temp_name;
            int temp_pos;
            while (infile >> temp_name >> temp_pos)
            {
                if(temp_name.compare(name)==0)
                {
                    infile.close();
                    return temp_pos;
                }
            }
            infile.close();
            return -1;
        } 
    }
    catch(char const* exc)
    {
        std::cerr<<"Exception occured when trying to find if client is present\n";
        std::cerr<<exc;
        exit(1);
    }
    catch(...)
    {
        std::cerr<<"Exception occured when trying to find if client is present\n";
        exit(1); 
    }
    
}

Client registerClient(std::string name,int age,std::string gender,std::string dlNo,string password)
{
    try{
        if(isClientPresent(name)!=-1)
        {
            throw("Client is already registered under the given name");
        }

        Client client(name,age,gender,dlNo,password);
        std::ofstream outfile;
        

        outfile.open("client.dat", std::ios_base::app); 
        outfile.seekp(0,ios::end);
        int pos=outfile.tellp(); 

        outfile<<name<<" "<<age<<" "<<gender<<" "<<dlNo<<" "<<password<<"\n";
        outfile.close();

        std::ofstream indexfile;
        indexfile.open("client.idx", std::ios_base::app); 

        indexfile<<name<<" "<<pos<<"\n";
        indexfile.close();

        return client;
    }
    catch(char const* exc)
    {
        std::cerr<<"Exception occured when trying to register client\n";
        std::cerr<<exc;
        exit(1);
    }
    catch(...){
        std::cerr<<"Exception occured when trying to register client\n";
        exit(1);
    }
    
    
}

Client getClient(std::string clientName)
{
    try{
        int pos=isClientPresent(clientName);
        if(pos==-1)
        {
            throw("The client is not registered in the system");

        }
        else
        {
            std::string name;
            int age;
            std::string gender;
            std::string dlNo;
            std::string password;
            std::ifstream datafile("client.dat");
            if(!datafile)
            {
                throw("Data file does not exist");
            }
            else
            {
                datafile.seekg(pos,ios::beg);
                datafile>>name>>age>>gender>>dlNo>>password;
                Client client(name,age,gender,dlNo,password); //Buffering!
                return client;
            }
        }
    }
    catch(char const* exc)
    {
        std::cerr<<exc;
        std::cerr<<"Exception occured when trying to get the client info\n";
        exit(1);
    }
    catch(...)
    {
        std::cerr<<"Exception occured when trying to get the client info\n";
        exit(1); 
    } 
}

bool checkPassword(Client client,std::string password)
{
     if(client.getPassword().compare(password)==0)
        return true;
    return false;
}

bool checkPassword(Admin admin,std::string password)
{
     if(admin.getPassword().compare(password)==0)
        return true;
    return false;
}

int isRentalPresent(std::string clientName)
{
    try{
        std::ifstream infile("rentalhistory.idx");
        if(!infile)
        {
            throw("Index file for Rental History is not created");
        }
        else
        {
            std::string temp_name;
            int temp_pos;
            while (infile >> temp_name>> temp_pos)
            {
                if(temp_name.compare(clientName)==0)
                {
                    infile.close();
                    return temp_pos;
                }
            }
            infile.close();
            return -1;
        } 
    }
    catch(char const* exc)
    {
        std::cerr<<"Exception occured when trying to find if rental history is present\n";
        std::cerr<<exc;
        exit(1);
    }
    catch(...)
    {
        std::cerr<<"Exception occured when trying to find if rental history is present\n";
        exit(1); 
    }
}

RentalHistory deleteRental(RentalHistory& rentalHistory)
{
    std::cout<<"\n\n"<<rentalHistory.getDate()<<"\n\n";
    try
    {
        int pos=isRentalPresent(rentalHistory.getClientName());
        if(pos==-1)
        {
            throw("The rental history is not present in index file and cannot be deleted\n");
        }
        else
        {
            std::ofstream outfile;
        
            std::ifstream filein("rentalhistory.dat"); 
            std::ofstream fileout("rentalhistorydatatemp.dat"); 
            if(!filein || !fileout)
            {
                throw("Error opening files!\n");
            }

            std::string bike;
            std::string location;
            std::string clientName;
            std::string date;
            int status;
            int tempPos;
            double cost;

            
            while(filein>>bike>>location>>clientName>>date>>cost>>status>>tempPos)
            {
                RentalHistory rentalHistory2(bike,location,clientName,date,cost,status,tempPos);
                if(rentalHistory2==rentalHistory)
                {
                    status=2;
                    fileout<<bike<<" "<<location<<" "<<clientName<<" "<<date<<" "<<cost<<" "<<status<<" "<<tempPos<<"\n";
                }
                else 
                {
                    fileout<<bike<<" "<<location<<" "<<clientName<<" "<<date<<" "<<cost<<" "<<status<<" "<<tempPos<<"\n";
                }
            }
            filein.close();
            fileout.close();

            std::ifstream filein1("rentalhistorydatatemp.dat"); 
            std::ofstream fileout1("rentalhistory.dat"); 
            if(!filein1 || !fileout1)
            {
                throw("Error opening files!\n");
            }

            while(filein1>>bike>>location>>clientName>>date>>cost>>status>>tempPos)
            {
                    fileout1<<bike<<" "<<location<<" "<<clientName<<" "<<date<<" "<<cost<<" "<<status<<" "<<tempPos<<"\n";
            }
            filein1.close();
            fileout1.close();
            
            char fileName[]="rentalhistorydatatemp.dat";
            std::remove(fileName);

            return RentalHistory(rentalHistory.getBike(),rentalHistory.getLocation(),rentalHistory.getClientName(),rentalHistory.getDate(),rentalHistory.getCost(),2,rentalHistory.getNextHistory());
        }
    }
    catch(char const* exc)
    {
        std::cerr<<"Exception occured when trying to delete rental history\n";
        std::cerr<<exc;
        exit(1);
    }
    catch(...)
    {
        std::cerr<<"Exception occured when trying to delete rental history\n";
        exit(1); 
    }
    
}

RentalHistory addRental(std::string clientName, std::string bike, std::string location, std::string date, double cost, int status)
{
    try
    {
        int pos=isRentalPresent(clientName);
        if(pos==-1)
        {
            RentalHistory rentalHistory(bike,location,clientName,date,cost,status,-1);

            std::ofstream outfile;
        

            outfile.open("rentalhistory.dat", std::ios_base::app); 
            outfile.seekp(0,ios::end);
            auto pos=outfile.tellp(); 

            outfile<<bike<<" "<<location<<" "<<clientName<<" "<<date<<" "<<cost<<" "<<status<<" "<<-1<<"\n";
            outfile.close();

            std::ofstream indexfile;
            indexfile.open("rentalhistory.idx", std::ios_base::app); 

            indexfile<<clientName<<" "<<pos<<"\n";
            indexfile.close();

            return rentalHistory;
        }
        else
        {
           
            RentalHistory rentalHistory(bike,location,clientName,date,cost,status,pos);

            std::ofstream outfile;
        
            outfile.open("rentalhistory.dat", std::ios_base::app); 
            outfile.seekp(0,ios::end);
            auto writePos=outfile.tellp(); 

            outfile<<bike<<" "<<location<<" "<<clientName<<" "<<date<<" "<<cost<<" "<<status<<" "<<pos<<"\n";
            outfile.close();

            std::ifstream filein("rentalhistory.idx"); 
            std::ofstream fileout("rentalhistoryindextemp.idx"); 
            if(!filein || !fileout)
            {
                throw("Error opening files!\n");
            }

            std::string tempClientName1;
            int tempPos1;
            while(filein >> tempClientName1 >> tempPos1)
            {
                if(tempClientName1.compare(clientName)==0)
                {
                    fileout<<tempClientName1<<" "<<writePos<<"\n";
                }
                else 
                {
                    fileout<<tempClientName1<<" "<<tempPos1<<"\n";
                }
            }
            filein.close();
            fileout.close();

            std::ifstream filein1("rentalhistoryindextemp.idx"); 
            std::ofstream fileout1("rentalhistory.idx"); 
            if(!filein1 || !fileout1)
            {
                throw("Error opening files!\n");
            }

            while(filein1 >> tempClientName1 >> tempPos1)
            {
                    fileout1<<tempClientName1<<" "<<tempPos1<<"\n";
            }
            filein1.close();
            fileout1.close();
            
            char fileName[]="rentalhistoryindextemp.idx";
            std::remove(fileName);

            return rentalHistory;
        }
        
    }
    catch(char const* exc)
    {
        std::cerr<<"Exception occured when trying to add rental history\n";
        std::cerr<<exc;
        exit(1);
    }
    catch(...)
    {
        std::cerr<<"Exception occured when trying to add rental history\n";
        exit(1); 
    }
}

std::vector<RentalHistory> getAllRentalHistory(std::string clientName)
{
    try
    {
        std::vector<RentalHistory> rentalList;
        int pos=isRentalPresent(clientName);
        if(pos==-1)
        {
            return rentalList;
        }
        else
        {   
            while(pos!=-1)
            {
                std::string bike;
                std::string location;
                std::string name;
                std::string date;
                int tempPos;
                int status;
                double cost;

                std::ifstream filein("rentalhistory.dat");  
                filein.seekg(pos,ios::beg);
                filein>>bike>>location>>name>>date>>cost>>status>>tempPos;
                RentalHistory rentalHistory(bike,location,name,date,cost,status,tempPos);
                rentalList.push_back(rentalHistory);
                pos=tempPos;
            }
            return rentalList;
        }
    }
    catch(char const* exc)
    {
        std::cerr<<"Exception occured when trying to read all rental history\n";
        std::cerr<<exc;
        exit(1);
    }
    catch(...)
    {
        std::cerr<<"Exception occured when trying to read all rental history\n";
        exit(1); 
    }
}


