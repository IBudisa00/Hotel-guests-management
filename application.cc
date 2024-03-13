#include <iostream>
#include "management.hh"
#include <map>
#include <utility>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>

void registerGuestsFromFile(hotel &hotel);
void registerGuests(hotel& hotel, char *firstName, char *lastName, unsigned int daysToStay);
int checkIfNumber(std::string *inputLine);

int main(){
    char hotelName[MAX_SIZE];

    std::cout << "Hotel's name: ";
    std::cin >> hotelName;
    hotel hotel(hotelName);

    registerGuestsFromFile(hotel);
    hotel.printGuestList();
    hotel.simulateDays(3);
    hotel.printGuestList();

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
    int wordCounter = RESET;
    int invalidArgument = NO;

    guestsInfoFile.open("guests.txt");

    if(!guestsInfoFile.is_open())
    {
        std::cout << "ERROR! FILE NOT OPENED PROPERLY.\n";
        return;
    }

    while(!guestsInfoFile.eof())
    {
        std::getline(guestsInfoFile, inputLine);
        std::stringstream word (inputLine);
        while(std::getline(word, inputLine, ' '))
        {
            wordCounter++;
            if(wordCounter == FIRSTNAME)
            {
                strcpy(firstName, inputLine.c_str());
            }
            else if(wordCounter == LASTNAME)
            {
                strcpy(lastName, inputLine.c_str());
            }
            else if(wordCounter == DAYSTOSTAY)
            {
                if(checkIfNumber(&inputLine))
                    daysToStay = stoi(inputLine);
                else
                    invalidArgument = YES;

                wordCounter = RESET;
            }
        }
        if(!invalidArgument)
            registerGuests(hotel, firstName, lastName, daysToStay);
        invalidArgument = NO;
    }

    guestsInfoFile.close();
}

void registerGuests(hotel& hotel, char *firstName, char *lastName, unsigned int daysToStay){
    hotel.addNewGuest(firstName, lastName, daysToStay);
}

int checkIfNumber(std::string *inputLine){
    int numberDetected = YES;
    std::string::iterator it;
    for(it = inputLine->begin(); it != inputLine->end(); it++)
    {
        if(!isdigit(*it))
        {
            numberDetected = NO;
            break;
        }
    }
    return numberDetected;
}