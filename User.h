#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
#include "Travel.h"
using namespace std;

class User
{
private:
    string account;
    string password;
    string fullName;
    string address;
    int age;
    int numMember;
    vector<Travel> myTravel;
public:
    /* Constructor */
    User() {}
    User(string& account, string& password) : account(account), password(password) {}
    User(string& account, string& password, string& fullName, string& address, int age, int numMember, vector<Travel>& myTravel)
    : account(account), password(password), fullName(fullName), address(address), age(age), numMember(numMember), myTravel(myTravel) {}
    /* Destructor */
    virtual ~User() {}
    /* Change user infomation */
    void changeInfo();
    /* Displays traveling information */
    void showTravelInfo();
    /* Change traveling information */
    void changeTravelInfo(const Travel& travel);
    /* Cancel the travel */
    void cancelTravel(const Travel& travel);
    bool validateAccount() const;
    /* Getter and setter */
    const string& getAccount() const { return account; }
    const string& getPassword() const { return password; }
    void setPassword(const string& newPassword) { password = newPassword; }
    const string& getFullname() const { return fullName; }
    void setFullname(const string& newFullName) { fullName = newFullName; }
    const string& getAddress() const { return address; }
    void setAddress(const string& newAddress) { address = newAddress; }
    int getAge() const { return age; }
    void setAge(int newAge) { age = newAge; }
    int getNumMember() const { return numMember; }
    void setNumMember(int newNumMember) { numMember = newNumMember; }
};
#endif // USER_H