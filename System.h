#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <vector>
#include "User.h"
#include "Admin.h"
using namespace std;

class System{
private:
    Admin admin{"admin", "ThanhDz"};
    vector<User> users;
public:
    void validateAccount(User u1);
    void validatePassword(User u1);
    void validateName(User u1);
};

#endif // SYSTEM_H