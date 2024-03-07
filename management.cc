#include <management.hh>
#include <cstring>
#include <cstdlib>
#include <iostream>

hotel::hotel(char *hotelsName){
    strcpy(hotelName, hotelsName);
    headGuest->nextGuest = NULL;
}

void hotel::addNewGuest(char *guestFirstName, char *guestLastName, int guestDaysTillCheckOut){
    guest *temp = headGuest;
    guest *newGuest = (guest*)malloc(sizeof(guest));
    if(newGuest == NULL)
    {
        std::cout <<"Failed to create new guest.\n";
        return;
    }
    strcpy(newGuest->firstName, guestFirstName);
    strcpy(newGuest->lastName, guestLastName);
    newGuest->guestId = idCounter + 1;
    idCounter++;
    newGuest->daysTillCheckOut = guestDaysTillCheckOut;
    newGuest->nextGuest = NULL;

    while(temp->nextGuest != NULL)
    {
        temp = temp->nextGuest;
    }
    temp->nextGuest = newGuest;
}

void hotel::deleteGuest(int guestId){
    guest *temp = headGuest;

    if(temp->nextGuest == NULL)
    {
        std::cout << "No element in list.\n";
        return;
    }

    while(temp->nextGuest != NULL)
    {
        if(temp->nextGuest->guestId == guestId)
        {
            temp->nextGuest = temp->nextGuest->nextGuest;
            free(temp->nextGuest);
            std::cout << "Guest deleted.\n";
            return;
        }
        temp = temp->nextGuest;
    }
}

void hotel::printGuestList(){
    guest *temp = headGuest;

    while(temp != NULL)
    {
        std::cout << "Guest ID: " << temp->guestId << " Name: " << temp->firstName << " Surname: " << temp->lastName << " Days until check-out: " << temp->daysTillCheckOut << std::endl;
        temp = temp->nextGuest;
    }
}

void hotel::updateGuestList(){
    guest *temp = headGuest->nextGuest;

    while(temp != NULL)
    {
        if(temp->daysTillCheckOut <= 0)
        {
            std::cout << "Guest ID: " << temp->guestId << " Guest name: " << temp->firstName << " " << temp->lastName << " checked out...\n";
            deleteGuest(temp->guestId);
        }
    }
}

void hotel::simulateDays(int daysToPass){
    guest *temp = headGuest->nextGuest;

    while(temp != NULL)
    {
        temp->daysTillCheckOut -= daysToPass;
    }
    updateGuestList();
}