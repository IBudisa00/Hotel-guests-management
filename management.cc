#include "management.hh"
#include <cstring>
#include <cstdlib>
#include <iostream>

hotel::hotel(char *hotelsName){
    strcpy(hotelName, hotelsName);
    headGuest = NULL;
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

    if(temp == NULL)
    {
        headGuest = newGuest;
        return;
    }

    while(temp->nextGuest != NULL)
    {
        temp = temp->nextGuest;
    }
    temp->nextGuest = newGuest;
}

void hotel::deleteGuest(int guestId){
    guest *temp = headGuest;
    guest *prev = headGuest;
    bool movePrev = false;

    if(temp == NULL)
    {
        std::cout << "List is empty.\n";
        return;
    }
    //check first element of list
    if(temp->guestId == guestId)
    {
        headGuest = temp->nextGuest;
        free(temp);
        std::cout << "Guest deleted.\n";
        return;
    }

    while(temp != NULL)
    {
        if(temp->guestId == guestId)
        {
            prev->nextGuest = temp->nextGuest;
            free(temp);
            std::cout << "Guest deleted.\n";
            return;
        }
        if(movePrev)
            prev = temp;
        else
            movePrev = true;
        temp = temp->nextGuest;
    }
}

void hotel::printGuestList(){
    guest *temp = headGuest;

    while(temp != NULL)
    {
        std::cout << "Guest ID: " << temp->guestId << "\tName: " << temp->firstName << " " << temp->lastName << "\tDays until check-out: " << temp->daysTillCheckOut << std::endl;
        temp = temp->nextGuest;
    }
}

void hotel::updateGuestList(){
    guest *temp = headGuest;
    guest *nextTemp;

    while(temp != NULL)
    {
        if(temp->daysTillCheckOut <= 0)
        {
            nextTemp = temp->nextGuest;
            deleteGuest(temp->guestId);
            temp = nextTemp;
        }
        else
            temp = temp->nextGuest;
    }
}

void hotel::simulateDays(int daysToPass){
    guest *temp = headGuest;

    while(temp != NULL)
    {
        temp->daysTillCheckOut -= daysToPass;
        temp = temp->nextGuest;
    }
    updateGuestList();
}