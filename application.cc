#include <iostream>
#include <management.hh>
#include <map>
#include <utility>
#include <fstream>
#include <string>

void registerGuestsFromFile(hotel &hotel);
void registerGuests(hotel& hotel, char *firstName, char *lastName, unsigned int daysToStay);

int main(){
    char hotelName[MAX_SIZE];

    std::cout << "Hotel's name: ";
    std::cin >> hotelName;
    hotel hotel(hotelName);

    registerGuestsFromFile(hotel);

    return 0;
}

void registerGuestsFromFile(hotel &hotel){
    //file structure is name surname daysToStay
    std::ifstream guestsInfoFile;
    char guestInput[MAX_INPUT];
    std::string inputLine;
    char firstName[MAX_SIZE];
    char lastName[MAX_SIZE];
    unsigned int daysToStay;

    guestsInfoFile.open("guests.txt");

    if(!guestsInfoFile.is_open())
    {
        std::cout << "ERROR! FILE NOT OPENED PROPERLY.\n";
        return;
    }

    while(!guestsInfoFile.eof())
    {
        std::getline(guestsInfoFile, inputLine);
        while(std::getline(guestsInfoFile, inputLine, ' ') != "\n")
        {
            strcpy(firstName, inputLine.c_str());
            strcpy(lastName, inputLine.c_str());
            daysToStay = inputLine;
            registerGuests(hotel, firstName, lastName, daysToStay);
        }
    }

    guestsInfoFile.close();
}

void registerGuests(hotel& hotel, char *firstName, char *lastName, unsigned int daysToStay){
    hotel.addNewGuest(firstName, lastName, daysToStay);
}