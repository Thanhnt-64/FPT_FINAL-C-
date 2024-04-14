#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include "User.h"
#include <memory>
using namespace std;

class Admin
{
private:
    Admin() {
        
    }
    static unique_ptr<Admin> instance;
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
    void viewServiceInfo(vector<Travel>& travels);
    /* Add service more */
    void addService(vector<Travel>& travels);
    /* Delete service */
    void deleteService(vector<Travel>& travels);
    /* Load and save data from file */
    void loadData(vector<User> &users, vector<Travel> &travels);
    void saveData(vector<User> &users, vector<Travel> &travels);
};

#endif // ADMIN_H