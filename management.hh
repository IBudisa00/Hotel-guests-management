#include <vector>
#include <map>
#include "defines.hh"


struct guest{
    char firstName[MAX_SIZE];
    char lastName[MAX_SIZE];
    int guestId;
    int daysTillCheckOut;
    guest *nextGuest;
};

class hotel{
    private:
        guest *headGuest;
        char hotelName[MAX_SIZE];
        int idCounter = 0;
    public:
        hotel(char *hotelsName);
        void addNewGuest(char *guestFirstName, char *guestLastName, int guestDaysTillCheckOut);
        void deleteGuest(int guestId);
        void printGuestList();
        void updateGuestList();
        void simulateDays(int daysToPass);
};
