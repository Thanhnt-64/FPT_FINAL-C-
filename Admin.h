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
    /* Show List Infomation of all Users in database*/
    void showListInfoUser(vector<User> &users);
    /* Change user infomation from account entered from keyboard*/
    void changeUser(vector<User> &users);
    /* Delete User from database: input: account enter from keyboard*/
    void deleteAccountUser(vector<User> &users);
    /* Edit transport infomation follow your choice*/
    void editTransportInfo(vector<Travel> &travels);
    /* Edit hotel infomation follow your choice*/
    void editHotelInfo(vector<Travel> &travels);
    /* View service infomation*/
    void viewServiceInfo();
    void addService();
    void deleteService();
    void loadData();
    void saveData();
};

#endif // ADMIN_H