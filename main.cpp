#include "client.h"
#include "bikeRental.h"
#include "rentalHistory.h"
#include "validation.h"
#include "admin.h"
#include "bike.h"
#include <vector>
#include <iostream>
#include <regex>


int main();

void viewProfile(Bike& bike)
{
    std::cout<<"Bike Name - "<<bike.getName()<<"\n";
    std::cout<<"Cost - "<<bike.getCost()<<"\n";
}

void viewProfile(Admin& admin)
{
    std::cout<<"\n\n Admin Profile \n\n";
    std::cout<<"Name - "<<admin.getName()<<"\n";
    std::cout<<"Age - "<<admin.getAge()<<"\n";
    std::cout<<"Gender - "<<admin.getGender()<<"\n";
    std::cout<<"----------------------------------\n";
    std::cout<<"\n\n";
}

void viewProfile(Client& client)
{
    std::cout<<"\n\n Client Profile \n\n";
    std::cout<<"Name - "<<client.getName()<<"\n";
    std::cout<<"Age - "<<client.getAge()<<"\n";
    std::cout<<"Gender - "<<client.getGender()<<"\n";
    std::cout<<"----------------------------------\n";
    std::cout<<"\n\n";
}

void viewDL(Client& client)
{
    std::cout<<"\n\nDL Information\n\n";
    std::cout<<"DL - "<<client.getDlNo()<<"\n";
    std::cout<<"-------------------------------\n\n";
}

void viewSortedClientInfo()
{
    std::cout<<"\n\nClient Info\n\n";

    std::vector<std::pair<std::string, int> > sortedClientList=getSortedClientName();

    if(sortedClientList.size()==0)
    {
        std::cout<<"There are no clients with the system\n";
        std::cout<<"\n\n";
        return;
    }

    int i=0;

    std::cout<<"\n\nThe client list is \n";

    for(auto& it:sortedClientList)
    {
        i++;
        cout<<i<<".Client Name - "<<it.first<<"\n";
    }
    std::cout<<"\nChoose the correct option to get detailed info about client\n";

    int choice;
    std::cin>>choice;

    if(choice>sortedClientList.size())
    {
        std::cout<<"\nYou have entered a wrong option!\n";
    }
    else
    {
        Client client=getClient(sortedClientList[choice-1].first);
        viewProfile(client);
    }
    std::cout<<"\n";


}

void viewAllBikeInfo()
{
    std::vector<Bike> listOfBikes= readAllBikes();
    std::cout<<"\n\nThe list of bikes available are\n";
    for(Bike it:listOfBikes)
    {
        viewProfile(it);
    }
    std::cout<<"------------------------------------\n";
    std::cout<<"\n\n";
}

void viewAllLocationsInfo()
{
    std::vector<std::string> listOfLocations= readAllLocations();
    std::cout<<"\n\nThe list of operating locations available are\n";
    for(std::string s:listOfLocations)
    {
        cout<<s<<"\n";
    }

    std::cout<<"----------------------------------------------\n\n\n";
}


void displayAdminMenu(Admin& admin)
{
    std::cout<<"\nMenu\n";
    std::cout<<"1.Admin Profile\n";
    std::cout<<"2.Client Info\n";
    std::cout<<"3.Bikes In Inventory\n";
    std::cout<<"4.Operating Locations\n";
    std::cout<<"5.Logout\n";
    std::cout<<"\nEnter the right option\n";


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
            viewSortedClientInfo();
            std::cout<<"\nGoing Back to Main Menu\n";
            displayAdminMenu(admin);
            break;
        }
        case 3:
        {
            viewAllBikeInfo();
            std::cout<<"\nGoing Back to Main Menu\n";
            displayAdminMenu(admin);
            break;
        }
        case 4:
        {
            viewAllLocationsInfo();
            std::cout<<"\nGoing Back to Main Menu\n";
            displayAdminMenu(admin);
            break;
        }
        case 5:
        {
            std::cout<<"\nLogging you out!\n";
            main();
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

void viewRentBike(Client& client)
{
    std::string bikeName;
    std::string location;
    std::string date;
    int noOfDays;

    std::cout<<"\nEnter Bike Name\n";
    std::cin>>bikeName;
    if(!isBikePresent(bikeName))
    {
        std::cout<<"\nThe bike is not present in inventory\n";
        return;
    }

    std::cout<<"\nEnter Location\n";
    std::cin>>location;

    if(!isLocationPresent(location))
    {
        std::cout<<"\nWe don't serve in that location\n";
        return;
    }

    std::cout<<"\nEnter date in dd-mm-yyyy format\n";
    std::cin>>date;

    if(!isValidDate(date))
    {
        std::cout<<"\nNot a Valid Date! Please try again\n";
        return;
    }
    if(!isValidFutureDate(date))
    {
        std::cout<<"\nThe date is valid but booking cannot be done for past dates! Please try again\n";
        return;
    }

    std::cout<<"\nEnter the number of days you want the bike for\n";
    std::cin>>noOfDays;

    
    
    
    Bike bike=getBike(bikeName);
    double cost=noOfDays*bike.getCost();
    RentalHistory rentalHistory=addRental(client.getName(),bikeName,location,date,cost,1);

    std::cout<<"------------------------------------------------------------------------\n\n";
    std::cout<<"                 INVOICE\n\n";
    std::cout<<"The number of days you want "<<bike.getName()<<" is "<<noOfDays<<" days\n";
    std::cout<<"Your approximate total cost of this rental is "<<cost<<"\n";
    std::cout<<"Succesfully registered a ticket for your rental!\n";
    std::cout<<"------------------------------------------------------------------------\n\n";

}

void viewAllRentalHistory(Client& client)
{

    std::cout<<"\n\n All Rental History\n\n";
    std::vector<RentalHistory> rentalList=getAllRentalHistory(client.getName());
    int i=0;

    if(rentalList.size()==0)
    {
        std::cout<<"You have not rented any bikes uptil now\n";
    }

    for(RentalHistory rentalHistory:rentalList)
    {
        i++;
        std::cout<<"\n\n Rental Number - "<<i;
        std::cout<<"\n"<<"Date - "<<rentalHistory.getDate()<<"\n";
        std::cout<<"Location - "<<rentalHistory.getLocation()<<"\n";
        std::cout<<"Bike - "<<rentalHistory.getBike()<<"\n";
        std::cout<<"Status - "<<rentalHistory.getStatus()<<"\n";
        std::cout<<"Cost - "<<rentalHistory.getCost()<<"\n";
    }
    std::cout<<"------------------------------------------\n\n";
}

void viewDeleteRental(Client& client)
{
    std::cout<<"\n\nDelete Rental\n\n";
    std::vector<RentalHistory> rentalList=getAllRentalHistory(client.getName());
    std::cout<<rentalList.size();
    
    if(rentalList.size()==0)
    {
        std::cout<<"\nYou have not rented any bikes uptil now\n";
        return;
    }
    int i=0;
    int count=0;
    for(RentalHistory rentalHistory:rentalList)
    {
        i++;

        if(isValidPastDate(rentalHistory.getDate()))
            continue;
        
        if(rentalHistory.getStatus().compare("Cancelled")==0)
            continue;

        count++;
        std::cout<<"\n\nRental Number - "<<i;
        std::cout<<"\n"<<"Date - "<<rentalHistory.getDate()<<"\n";
        std::cout<<"Location - "<<rentalHistory.getLocation()<<"\n";
        std::cout<<"Bike - "<<rentalHistory.getBike()<<"\n";
    }

    if(count==0)
    {
        std::cout<<"\nYou do not have any future rentals to cancel\n";
        return;
    }

    std::cout<<"\nEnter the Rental Number to Cancel\n";
    int choice2;
    std::cin>>choice2;

    if(isValidPastDate(rentalList[choice2-1].getDate()))
    {
        std::cout<<"\nYou have entered a wrong option!\n";
    }
    else if(choice2<=0|| choice2>rentalList.size())
    {
        std::cout<<"\nYou have entered a wrong option!\n";
    }
    else if(rentalList[choice2-1].getStatus().compare("Cancelled")==0)
    {
        std::cout<<"\nYou have entered a wrong option!\n";
    }
    else
    {
        deleteRental(rentalList[choice2-1]);
        std::cout<<"\nRental successfully cancelled!\n";
    }
}

void displayClientMenu(Client& client)
{
    std::cout<<"\n\n\nEnter option\n";
    std::cout<<"1.Client Profile\n";
    std::cout<<"2.View DL\n";
    std::cout<<"3.Rent Bike\n";
    std::cout<<"4.Rental History\n";
    std::cout<<"5.Cancel Rental\n";
    std::cout<<"6.View Bikes Available to Rent\n";
    std::cout<<"7.View Locations Available\n";
    std::cout<<"8.Logout\n";


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
            viewRentBike(client);
            std::cout<<"\nGoing Back to Main Menu\n";
            displayClientMenu(client);
            break;
        }
        case 4:
        {
            viewAllRentalHistory(client);
            std::cout<<"\nGoing Back to Main Menu\n";
            displayClientMenu(client);
            break;
        }
        case 5:
        {
            viewDeleteRental(client);
            std::cout<<"\nGoing Back to Main Menu\n";
            displayClientMenu(client);
            break; 
        }
        case 6:
        {
            viewAllBikeInfo();
            std::cout<<"\nGoing Back to Main Menu\n";
            displayClientMenu(client);
            break;
        }
        case 7:
        {
            viewAllLocationsInfo();
            std::cout<<"\nGoing Back to Main Menu\n";
            displayClientMenu(client);
            break;
        }
        case 8:
        {
            std::cout<<"\nLogging you out!\n";
            main();
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

    std::cout<<"\n\n\nMain Menu\n";
    std::cout<<"1.Login as Admin\n";
    std::cout<<"2.Login as Client\n";
    std::cout<<"3.Register as Client\n";
    std::cout<<"4.Exit Application\n";
    std::cout<<"\nEnter the right option\n";


    int choice;
    std::cin>>choice;
    switch (choice)
    {
    case 1:
    {
        std::cout<<"\nEnter name\n";
        std::string name;
        std::cin>>name;
        
        std::cout<<"\nEnter password\n";
        std::string password;
        std::cin>>password;

        if(isAdminPresent(name))
        {
            Admin admin=getAdmin(name);
            if(checkPassword(admin,password))
            {
                std::cout<<"\n\nSuccessfully Logged On!\n\n";
                displayAdminMenu(admin);
            }
            else{
                std::cout<<"\nPassword Incorrect. Cannot login\n";
                std::cout<<"\nGoing Back to Main Menu\n";
                main();
            }

           
        }
        else
        {
            std::cout<<"\n\nAdmin not registered with system. Cannot login\n";
            std::cout<<"\nGoing Back to Main Menu\n";
            main();
        }
        break;
    }
    case 2:
    {
        std::cout<<"\nEnter name\n";
        std::string name;
        std::cin>>name;

        std::cout<<"\nEnter password\n";
        std::string password;
        std::cin>>password;


    
        if(isClientPresent(name)==-1)
        {
            std::cout<<"\nClient not registered with system. Cannot login\n";
            std::cout<<"\nGoing Back to Main Menu\n";
            main();
        }
        else
        {
            Client client=getClient(name);
            if(checkPassword(client,password))
            {
                std::cout<<"\n\nSuccessfully Logged On!\n";
                displayClientMenu(client);
            }
            else
            {
                std::cout<<"\n\nPassword Incorrect. Cannot login\n";
                std::cout<<"\nGoing Back to Main Menu\n";
                main();
            }
            
        }

        break;
    }
    case 3:
    {
        std::cout<<"\nEnter name\n";
        std::string name;
        std::cin>>name;

        if(!isNameValid(name))
        {
            std::cout<<"\nName should not contain spaces or digits! Please try again\n";
            std::cout<<"\nGoing Back to Main Menu\n";
            main();
            break;
        }


        std::cout<<"\nEnter age\n";
        int age;
        std::cin>>age;

        if(!isAgeValid(age))
        {
            std::cout<<"\nAge should be between 18-120! Please try again\n";
            std::cout<<"\nGoing Back to Main Menu\n";
            main();
            break;
        }

        std::cout<<"\nEnter gender\n";
        std::string gender;
        std::cin>>gender;

        if(!isGenderValid(gender))
        {
            std::cout<<"\nGender should either be Male or Female! Please try again\n";
            std::cout<<"\nGoing Back to Main Menu\n";
            main();
            break;
        }

        std::cout<<"\nEnter DL Number\n";
        std::string dlNo;
        std::cin>>dlNo;

        if(!isDLValid(dlNo))
        {
            std::cout<<"\nDL No should have only 7 characters! Please try again\n";
            std::cout<<"\nGoing Back to Main Menu\n";
            main();
            break;
        }

        std::cout<<"\nEnter Password\n";
        std::string password;
        std::cin>>password;

        if(!isPasswordValid(password))
        {
            std::cout<<"\nPassword should be minimum 8 characters and maximum 32 characters. Password cannot contain spaces! Please try again\n";
            std::cout<<"\nGoing Back to Main Menu\n";
            main();
            break;
        }

        if(isClientPresent(name)==-1)
        {
            Client client=registerClient(name,age,gender,dlNo,password);
            std::cout<<"\n\nSuccessfully Registered!\n";
            displayClientMenu(client);
        }
        else
        {
            std::cout<<"\nClient already registered with system. Cannot register\n";
            std::cout<<"\nGoing Back to Main Menu\n";
            main();
        }
        break;
    }
    case 4:
    {
        std::cout<<"\n\nExiting Application\n";
        exit(0);
    }
    default:
        std::cout<<"\nWrong choice entered\n";
        std::cout<<"\nGoing Back to Main Menu\n";
        main();
        break;
    }
    return 0;
}
