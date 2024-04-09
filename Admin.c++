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
void Admin::showListInfoUser(vector<User> &users)
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
void Admin::changeUser(vector<User> &users) {
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

void Admin::deleteAccountUser(vector<User> &users) {
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

void Admin::editTravelInfo() {
    cout << "Enter account of travel you want to edit: ";
    string transport; getline(cin, transport);
    
}

void Admin::editHotelInfo() {
    // Code to edit hotel information
}

void Admin::viewServiceInfo() {
    // Code to view service information (transportation, hotel, room type, car brand, etc.)
}

void Admin::addService() {
    // Code to add new service
}

void Admin::deleteService() {
    // Code to delete a service
}

void Admin::loadData() {
    // Code to load data from files
}

void Admin::saveData() {
    // Code to save data to files
}

