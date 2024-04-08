#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <vector>
#include "User.h"
#include "Admin.h"
#include <iomanip>
using namespace std;

class System{
private:
    Admin admin;
    vector<User> users;
public:
    User* logInAccount(User &u1);
    User* registerAccount(User &u1);
    void signOut();
    void searchRoom();
    void searchVehicle();
    void listPlace();
    bool validateAccount(const string &s);
    bool validatePassword(const string &s);
    bool validateName(const string &s);
    bool searchAccount(const string &s);
    bool searchPassword(const string &s);
    void run();
};

#endif // SYSTEM_H