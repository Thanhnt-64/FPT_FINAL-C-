#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include "User.h"
using namespace std;

class Admin : virtual public User
{
private:
    Admin() : User("admin", "Admin123") {}
    static Admin* instance;
    vector<User> users;
    vector<Travel> travels;
    vector<Hotel> hotels;
    vector<Transport> transports;
public:

    static Admin& getInstance();
    void showListInfoUser();
    void changeUser(User& user);
    void deleteAccountUser(User& user);
    void editTravelInfo(Travel& travel);
    void editHotelInfo(Hotel& hotel);
    void viewServiceInfo();
    void addService(Travel& travel, Hotel& hotel, Transport& transport);
    void deleteService(Travel& travel, Hotel& hotel, Transport& transport);
    void loadData();
    void saveData();

};

#endif // ADMIN_H