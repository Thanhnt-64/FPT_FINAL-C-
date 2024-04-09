#include "Admin.h"
#include <algorithm>
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
    cout << "Enter account of user you want to change:\n";
    string account; getline(cin, account);
    vector<User>::iterator i;
    for(i = users.begin(); i != users.end(); i++) {
        if(i->getAccount() == account){
            break;
        }
    }
    cout << "Change Info you want:\n";
    i->changeInfo();
}

void Admin::deleteAccountUser(User& user) {
    cout << "Enter account of user you want to delete:\n";
    string account; getline(cin, account);
    vector<User>::iterator i;
    for(i = users.begin(); i != users.end(); i++) {
        if(i->getAccount() == account){
            break;
        }
    }
    users.erase(i);
}

void Admin::editTravelInfo(Travel& travel) {
    cout << "Enter account of travel you want to edit:\n";
    string transport; getline(cin, transport);
    vector<Travel>::iterator i;
    vector<Transport>::iterator j;
    for(i = travels.begin(); i != travels.end(); i++) {
        j = i->getTransportPtr();
        for(j = j->i->getTransportPtr().begin(); j != j->getTransportPtr().end(); j++) {
            if(j->getTransportPtr() == transport){
                break;
            }
        }
    }
    cout << "Edit Info you want:\n";
    i->editInfo();
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

