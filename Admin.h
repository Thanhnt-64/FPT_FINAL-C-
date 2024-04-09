#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include "User.h"
using namespace std;

class Admin : virtual public User
{
private:
    Admin() {
        
    }
    static Admin* instance;
public:
    static Admin& getInstance();
    void showListInfoUser(vector<User> &users);
    void changeUser(vector<User> &users);
    void deleteAccountUser(vector<User> &users);
    void editTravelInfo();
    void editHotelInfo();
    void viewServiceInfo();
    void addService();
    void deleteService();
    void loadData();
    void saveData();
};

#endif // ADMIN_H