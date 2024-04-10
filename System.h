#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <vector>
#include "User.h"
#include "Admin.h"
#include <iomanip>
#include <algorithm>
using namespace std;

class System{
private:
    // Admin admin = Admin::getInstance();
    // vector<User> users;
    // vector<Travel> travels;
public:
    System(){}
    /* Login in the system*/
    User* logInAccount(vector<User> &users, User &u1);
    void logInAccount();
    /* Register new account*/
    User* registerAccount(vector<User> &users, User &u1);
    /* Exit main system, comeback to main menu*/
    void signOut();
    /* Search room in a specific place*/
    void searchRoomByPlace(vector<Travel> &travels);
    /* Search vehicle in a specific place*/
    void searchVehicleByPlace(vector<Travel> &travels);
    /* List all Place support by system*/
    void listPlace(vector<Travel> &travels);
    /* Validate account: format check*/
    bool validateAccount(const string &s);
    /* Validate password: format check*/
    bool validatePassword(const string &s);
    /* Validate name: format check*/
    bool validateName(const string &s);
    /* Double check account when register new account*/
    bool doubleCheckAccount(vector<User> &users, const string &s);
    /* Search account in database*/
    bool searchAccount(vector<User> &users, const string &s);
    /* Search password to check valid when login*/
    bool searchPassword(vector<User> &users, const string &s);
    /* Run system*/
    void run(vector<Travel> &travels, User *user);
    void runAdmin(vector<Travel> &travels, vector<User> &users);
    /* Search (Hotel and room) or transport by place*/
    void searchByPlace(vector<Travel> &travels);
};
/* Choose type of sort the travel: cost or time*/
void sortTravel(vector<Travel> &travels);
/* Sort travel with cost (for Hotel ofject)*/
void sortWithCost(vector<Travel> &travels, int low, int high);
static int partitionInt(vector<Travel> &travels, int low, int high);
static int paritionTime(vector<Travel> &travels, int low, int high);
/* Sort travel with time (for Transport ofject)*/
void sortWithTime(vector<Travel> &travels, int low, int high);
/* Choose: Show or change User infor*/
void showChangeInfo(User *user);
#endif // SYSTEM_H