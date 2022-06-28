#include "client.h"
#include "bikeRental.h"
#include "rentalHistory.h"
#include "admin.h"
#include <vector>
#include <iostream>
#include <regex>

// bool validateDate(std::string date)
// {
//     return true;
// }

void viewProfile(Admin& admin)
{
    std::cout<<"Name - "<<admin.getName()<<"\n";
    std::cout<<"Age - "<<admin.getAge()<<"\n";
    std::cout<<"Gender - "<<admin.getGender()<<"\n";
}

void viewProfile(Client& client)
{
    std::cout<<"Name - "<<client.getName()<<"\n";
    std::cout<<"Age - "<<client.getAge()<<"\n";
    std::cout<<"Gender - "<<client.getGender()<<"\n";
}

void viewDL(Client& client)
{
    std::cout<<"DL - "<<client.getDlNo()<<"\n";
}


void displayAdminMenu(Admin& admin)
{
    std::cout<<"\n\n\nEnter option\n";
    std::cout<<"1.Admin Profile\n";
    std::cout<<"2.Client Info\n";
    std::cout<<"3.Bikes In Inventory\n";
    std::cout<<"4.Operating Locations\n";

    int choice;
    std::cin>>choice;

    switch (choice)
    {
        case 1:
        {
            viewProfile(admin);
            std::cout<<"Going Back to Main Menu\n";
            displayAdminMenu(admin);
            break;
        }
        case 2:
        {
            std::vector<std::pair<std::string, int>> sortedClientList=getSortedClientName();
            int i=0;
            for(auto& it:sortedClientList)
            {
                i++;
                cout<<i<<".Client Name - "<<it.first<<"\n";
            }
            std::cout<<"\nChoose the correct option to get detailed info about client\n";

            int choice;
            std::cin>>choice;

            if(choice>=sortedClientList.size())
            {
                std::cout<<"\nYou have entered a wrong option!\n";
            }
            else
            {
                Client client=getClient(sortedClientList[choice-1].first);
                viewProfile(client);
            }

            std::cout<<"\nGoing Back to Main Menu\n";
            displayAdminMenu(admin);
            break;
        }
        case 3:
        {
            std::vector<std::string> listOfBikes= readAllBikes();
            std::cout<<"\nThe list of bikes available are\n";
            for(auto it:listOfBikes)
            {
                cout<<it<<"\n";
            }
            std::cout<<"\nGoing Back to Main Menu\n";
            displayAdminMenu(admin);
            break;
        }
        case 4:
        {
            std::vector<std::string> listOfLocations= readAllLocations();
            std::cout<<"\nThe list of operating locations available are\n";
            for(std::string s:listOfLocations)
            {
                cout<<s<<"\n";
            }
            std::cout<<"\nGoing Back to Main Menu\n";
            displayAdminMenu(admin);
            break;
        }
        default:
        {
            std::cout<<"\nWrong choice entered\n";
            std::cout<<"Going Back to Main Menu\n";
            displayAdminMenu(admin);
            break;
        }
    }


}

void displayClientMenu(Client& client)
{
    std::cout<<"\n\n\nEnter option\n";
    std::cout<<"1.Client Profile\n";
    std::cout<<"2.View DL\n";
    std::cout<<"3.Rent Bike\n";
    std::cout<<"4.Rental History\n";
    std::cout<<"5.View Bikes Available to Rent\n";
    std::cout<<"6.View Locations Available\n";

    int choice;
    std::cin>>choice;

    switch (choice)
    {
        case 1:
        {
            viewProfile(client);
            std::cout<<"Going Back to Main Menu\n";
            displayClientMenu(client);
            break;
        }
        case 2:
        {
            viewDL(client);
            std::cout<<"Going Back to Main Menu\n";
            displayClientMenu(client);
            break;
        }
        case 3:
        {
            std::string bike;
            std::string location;
            std::string date;

            std::cout<<"\nEnter Bike Name\n";
            std::cin>>bike;
            std::cout<<"\nEnter Location\n";
            std::cin>>location;
            std::cout<<"\nEnter date in dd-mm-yyyy format\n";
            std::cin>>date;

            if(!isBikePresent(bike))
            {
                std::cout<<"The bike is not present in inventory\n";
            }
            else if(!isLocationPresent(location))
            {
                std::cout<<"We don't serve in that location\n";
            }
            // else if(!validateDate(date))
            // {
            //     std::cout<<"Please enter date in dd-mm-yyyy format only!\n";
            // }
            else
            {
                RentalHistory rentalHistory=addRental(client.getName(),bike,location,date);
                std::cout<<"Succesfully registered a ticket for your rental!\n";
            }
            std::cout<<"\nGoing Back to Main Menu\n";
            displayClientMenu(client);
            break;
        }
        case 4:
        {
            std::vector<RentalHistory> rentalList=getAllRentalHistory(client.getName());
            int i=0;
            for(RentalHistory rentalHistory:rentalList)
            {
                i++;
                std::cout<<"\n\n Rental Number - "<<i;
                std::cout<<"\n"<<"Date - "<<rentalHistory.getDate()<<"\n";
                std::cout<<"Location - "<<rentalHistory.getLocation()<<"\n";
                std::cout<<"Bike - "<<rentalHistory.getBike()<<"\n";
            }
            std::cout<<"\nGoing Back to Main Menu\n";
            displayClientMenu(client);
            break;
        }
        case 5:
        {
            std::vector<std::string> listOfBikes= readAllBikes();
            std::cout<<"\nThe list of bikes available are\n";
            for(auto it:listOfBikes)
            {
                cout<<it<<"\n";
            }
            std::cout<<"\nGoing Back to Main Menu\n";
            displayClientMenu(client);
            break;
        }
        case 6:
        {
            std::vector<std::string> listOfLocations= readAllLocations();
            std::cout<<"\nThe list of operating locations available are\n";
            for(std::string s:listOfLocations)
            {
                cout<<s<<"\n";
            }
            std::cout<<"\nGoing Back to Main Menu\n";
            displayClientMenu(client);
            break;
        }
        default:
        {
            std::cout<<"Wrong choice entered\n";
            std::cout<<"Going Back to Main Menu\n";
            displayClientMenu(client);
            break;
        }
    }
}

int main()
{
    std::cout<<"\n\n\nEnter option\n";
    std::cout<<"1.Login as Admin\n";
    std::cout<<"2.Login as Client\n";
    std::cout<<"3.Register as Client\n";

    int choice;
    std::cin>>choice;
    switch (choice)
    {
    case 1:
    {
        std::cout<<"Enter name\n";
        std::string name;
        std::cin>>name;
        if(isAdminPresent(name))
        {
            Admin admin=getAdmin(name);
            std::cout<<"Successfully Logged On!\n";
            displayAdminMenu(admin);
        }
        else
        {
            std::cout<<"Admin not registered with system. Cannot login\n";
            std::cout<<"Going Back to Main Menu\n";
            main();
        }
        break;
    }
    case 2:
    {
        std::cout<<"Enter name\n";
        std::string name;
        std::cin>>name;
        if(isClientPresent(name)==-1)
        {
            std::cout<<"Client not registered with system. Cannot login\n";
            std::cout<<"Going Back to Main Menu\n";
            main();
        }
        else
        {
            Client client=getClient(name);
            std::cout<<"Successfully Logged On!\n";
            displayClientMenu(client);
        }

        break;
    }
    case 3:
    {
        std::cout<<"Enter name\n";
        std::string name;
        std::cin>>name;
        std::cout<<"Enter age\n";
        int age;
        std::cin>>age;
        std::cout<<"Enter gender\n";
        std::string gender;
        std::cin>>gender;
        std::cout<<"Enter DL Number\n";
        std::string dlNo;
        std::cin>>dlNo;
        if(isClientPresent(name)==-1)
        {
            Client client=registerClient(name,age,gender,dlNo);
            std::cout<<"Successfully Registered!\n";
            displayClientMenu(client);
        }
        else
        {
            std::cout<<"Client already registered with system. Cannot register\n";
            std::cout<<"Going Back to Main Menu\n";
            main();
        }
        break;
    }
    default:
        std::cout<<"Wrong choice entered\n";
        std::cout<<"Going Back to Main Menu\n";
        main();
        break;
    }
    return 0;
}
