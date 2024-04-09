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
void Admin::changeUser(User& user)
{
    /* Find the user in users list */
    auto it = find(users.begin(), users.end(), user);
    if (it != users.end()) {
        cout << "Enter new information for user:" << endl;
        string newFullname;
        int newAge;
        string newAddress;
        cout << "Fullname: ";
        getline(cin, newFullname);
        cout << "Age: ";
        cin >> newAge;
        cout << "Address: ";
        getline(cin, newAddress);
        it->setFullname(newFullname);
        it->setAge(newAge);
        it->setAddress(newAddress);
    } else {
        cout << "User not found." << endl;
    }
}

void Admin::deleteAccountUser(User& user) {
    /* Find the user in users list */
    auto it = find(users.begin(), users.end(), user);
    if (it != users.end()) {
        /* Delete the user from users list */
        users.erase(it);
        cout << "User account deleted." << endl;
    } else {
        cout << "User not found.\n";
    }
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