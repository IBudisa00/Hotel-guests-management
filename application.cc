#include <iostream>
#include <management.hh>
#include <map>
#include <utility>

int main(){
    char hotelName[MAX_SIZE];
    std::map<int, std::pair<char[], char[]>> guests;

    fillGuestMap(guests);
    std::cout << "Hotel's name: ";
    std::cin >> hotelName;
    hotel hotel(hotelName);

    registerGuests(hotel,guests);
    return 0;
}

void fillGuestMap(std::map<int, std::pair<char[], char[]>> &guestMap){
    //read file with data
}

void registerGuests(hotel &hotel, std::map<int, std::pair<char[], char[]>> &guestMap){
    std::map<int, std::pair<char[], char[]>>::iterator it = guestMap.begin();

    while(it != guestMap.end())
    {
        //change guestMap sturcutre of map
        hotel.addNewGuest();
        ++it;
    }
}