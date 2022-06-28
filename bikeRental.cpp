#include <iostream>
#include<stdexcept>
#include "client.h"
#include "admin.h"
#include "bikeRental.h"
#include "rentalHistory.h"
#include <fstream>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <filesystem>
#include <cstdio>



bool isBikePresent(std::string bike)
{
    try
    {
        fstream newfile;
        newfile.open("bikesdata.txt",ios::in); 
        if (newfile.is_open()){   
            string tp;
            while(getline(newfile, tp)){ 
                if(tp.compare(bike)==0)
                    return true;
            }
            newfile.close(); 
        }
        else{
            throw("Data file for Bikes is not created");
        }

        return false;
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

std::vector<std::string> readAllBikes()
{
    try
    {
        std::vector<std::string> listOfBikes;
        fstream newfile;
        newfile.open("bikesdata.txt",ios::in); 
        if (newfile.is_open()){   
            string tp;
            while(getline(newfile, tp)){ 
                listOfBikes.push_back(tp);
            }
            newfile.close(); 
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
        newfile.open("operatingLocations.txt",ios::in); 
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
        newfile.open("operatingLocations.txt",ios::in); 
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
        std::ifstream infile("clientindex.txt");
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

std::vector<std::pair<std::string, int>> getSortedClientName()
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
        std::ifstream infile("admindata.txt");
        if(!infile)
        {
            throw("Data file for Admin is not created");
        }
        else
        {
            std::string temp_name;
            int temp_age;
            std::string temp_gender;
            while (infile >> temp_name >> temp_age >> temp_gender)
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
        if(isAdminPresent(adminName))
        {
           std::ifstream infile("admindata.txt");
            if(!infile)
            {
                throw("Data file for Admin is not created");
            }
            else
            {
                std::string name;
                int age;
                std::string gender;
                while (infile >> name >> age >> gender)
                {
                    if(name.compare(adminName)==0)
                    {
                        infile.close();
                        Admin admin(name,age,gender);
                        return admin;
                    }
                }
            }  
        }
        else
        {
            throw("Admin is not present in the system");
        }
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
        std::ifstream infile("clientindex.txt");
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

Client registerClient(std::string name,int age,std::string gender,std::string dlNo)
{
    try{
        if(isClientPresent(name)!=-1)
        {
            throw("Client is already registered under the given name");
        }

        Client client(name,age,gender,dlNo);
        std::ofstream outfile;
        

        outfile.open("clientdata.txt", std::ios_base::app); 
        auto pos=outfile.tellp(); 

        outfile<<name<<" "<<age<<" "<<gender<<" "<<dlNo<<"\n";
        outfile.close();

        std::ofstream indexfile;
        indexfile.open("clientindex.txt", std::ios_base::app); 

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
            std::ifstream datafile("clientdata.txt");
            if(!datafile)
            {
                throw("Data file does not exist");
            }
            else
            {
                datafile.seekg(pos,ios::beg);
                datafile>>name>>age>>gender>>dlNo;
                Client client(name,age,gender,dlNo);
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

int isRentalPresent(std::string clientName)
{
    try{
        std::ifstream infile("rentalhistoryindex.txt");
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

RentalHistory addRental(std::string clientName, std::string bike, std::string location, std::string date)
{
    try
    {
        int pos=isRentalPresent(clientName);
        if(pos==-1)
        {
            RentalHistory rentalHistory(bike,location,clientName,date,-1);

            std::ofstream outfile;
        

            outfile.open("rentalhistorydata.txt", std::ios_base::app); 
            auto pos=outfile.tellp(); 

            outfile<<bike<<" "<<location<<" "<<clientName<<" "<<date<<" "<<-1<<"\n";
            outfile.close();

            std::ofstream indexfile;
            indexfile.open("rentalhistoryindex.txt", std::ios_base::app); 

            indexfile<<clientName<<" "<<pos<<"\n";
            indexfile.close();

            return rentalHistory;
        }
        else
        {
           
            RentalHistory rentalHistory(bike,location,clientName,date,pos);

            std::ofstream outfile;
        
            outfile.open("rentalhistorydata.txt", std::ios_base::app); 
            auto writePos=outfile.tellp(); 

            outfile<<bike<<" "<<location<<" "<<clientName<<" "<<date<<" "<<pos<<"\n";
            outfile.close();

            std::ifstream filein("rentalhistoryindex.txt"); 
            std::ofstream fileout("rentalhistoryindextemp.txt"); 
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

            std::ifstream filein1("rentalhistoryindextemp.txt"); 
            std::ofstream fileout1("rentalhistoryindex.txt"); 
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
            
            char fileName[]="rentalhistoryindextemp.txt";
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

                std::ifstream filein("rentalhistorydata.txt");  
                filein.seekg(pos,ios::beg);
                filein>>bike>>location>>name>>date>>tempPos;
                RentalHistory rentalHistory(bike,location,name,date,tempPos);
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


