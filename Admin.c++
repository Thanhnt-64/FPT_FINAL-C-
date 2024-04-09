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

void Admin::editTransportInfo(vector<Travel> &travels) {
    cout << "Enter name of travel you want to edit: ";
    string tral; getline(std::cin, tral);
    char choose;
    cout << "Enter name of vehicle you want to change:";
    string transport; getline(cin, transport);
    cout << "Change brand?__ ";
    string brand; getline(cin, brand);
    cout << "Change Starting point?__ ";
    string from; getline(cin, from);
    cout << "Change Destination?__ ";
    string destination; getline(cin, destination);
    vector<Travel>::iterator i;
    for(i = travels.begin(); i != travels.end(); i++) {
        if(i->getPlace() != tral) {
            continue;
        }
        for(int j = 0; j < i->getTransport().size(); j++) {
            if(i->getTransport()[j].get_name() == transport) {
                cout << "Do you want to change this vehicle?(Y/N)\n";
                cin >> choose; cin.ignore();
                if(choose == 'Y' || choose == 'y') {
                    i->getTransport()[j].change_brand(brand);
                    i->getTransport()[j].change_from(from);
                    i->getTransport()[j].change_destination(destination);
                    cout << "Done!\n";
                }
                else{
                    continue;
                }
            }
        }
    }
}

void Admin::editHotelInfo(vector<Travel> &travels) {
    cout << "Enter name of travel you want to edit: ";
    string tral; getline(std::cin, tral);
    cout << "Enter name of Hotel you want to edit: ";
    string hotel; getline(std::cin, hotel);
    char choose;
    vector<Travel>::iterator i;
    for(i = travels.begin(); i != travels.end(); i++) {
        if(i->getPlace() != tral) {
            continue;
        }
        for(int j = 0; j < i->getHotel().size(); j++) {
            if(i->getHotel()[j].getHotelName() == hotel) {
                cout << "Do you want to change this Hotel?(Y/N)\n";
                cin >> choose; cin.ignore();
                if(choose == 'Y' || choose == 'y') {
                    i->getTransport()[j].change_brand(brand);
                    i->getTransport()[j].change_from(from);
                    i->getTransport()[j].change_destination(destination);
                    cout << "Done!\n";
                }
                else{
                    continue;
                }
            }
        }
    }
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

