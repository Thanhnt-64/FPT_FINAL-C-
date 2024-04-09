#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include "User.h"
using namespace std;

class Admin : virtual public User
{
private:
    Admin( "admin", "Admin123") : setAccount(admin), setPassword(Admin123) {}
    static Admin* instance;
    vector<User> users;
    vector<Travel> travels;
public:
    static Admin& getInstance();
    void showListInfoUser();
    void changeUser(User& user);
    void deleteAccountUser(User& user);
    void editTravelInfo(Travel& travel);
    void editHotelInfo(Travel& travel);
    void viewServiceInfo();
    void addService(Travel& travel);
    void deleteService(Travel& travel);
    void loadData();
    void saveData();
};

#endif // ADMIN_H