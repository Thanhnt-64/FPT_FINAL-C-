#include "Admin.h"

Admin* Admin::instance = nullptr;
Admin& Admin::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Admin();
    }
    return *instance;
}

/* Show list of user information */
void Admin::showListInfoUser()
{
    cout<<setw(20)<<left<<"Account"
        <<setw(20)<<left<<"Full Name"
        <<setw(20)<<left<<"Address"
        <<setw(20)<<left<<"Age"
        <<setw(20)<<left<<"Num Member"<<endl;
    for(User i : users)
    {
        i.showUser();
    }
}
/*  */
void Admin::changeUser(User& user) {
    // Code to 
}

void Admin::deleteAccountUser(User& user) {
    // Code to delete a user account
}

void Admin::editTravelInfo(Travel& travel) {
    // Code to edit travel information
}

void Admin::editHotelInfo(Hotel& hotel) {
    // Code to edit hotel information
}

void Admin::viewServiceInfo() {
    // Code to view service information (transportation, hotel, room type, car brand, etc.)
}

void Admin::addService(Travel& travel, Hotel& hotel, Transport& transport) {
    // Code to add new service
}

void Admin::deleteService(Travel& travel, Hotel& hotel, Transport& transport) {
    // Code to delete a service
}

void Admin::loadData() {
    // Code to load data from files
}

void Admin::saveData() {
    // Code to save data to files
}