#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include "User.h"
using namespace std;

class Admin : public User{
private:
    
public:
    Admin(){}
    Admin(string account, string password):User(account, password){}
    void showListInfoUser();
    void changeUser();
    void deleteAccountUser();
    void changeInfoTravel();
    void changeInfoHotel();
};

#endif // ADMIN_H