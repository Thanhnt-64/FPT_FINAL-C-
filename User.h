#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
#include <iomanip>
#include "Travel.h"
using namespace std;

class User{
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
    User(string account, string password, string fullName, string address, int age, int numMember, vector<Travel>& myTravel)
    : account(account), password(password), fullName(fullName), address(address), age(age), numMember(numMember), myTravel(myTravel) {}
    /* Destructor */
    virtual ~User() {}
    /* Change user infomation */
    void setFullname(const string& newFullName) { fullName = newFullName; }
    void changeInfo();
    /* Displays traveling information */
    void showTravelInfo();
    /* Change traveling information */
    void changeTravelInfo();
    /* Cancel the travel */
    void cancelTravel();
    /* Input */
    void inputAccount() {getline(cin, account);}
    void inputPassword() {getline(cin, password);}
    void inputFullName() {getline(cin, fullName);}
    void inputAddress() {getline(cin, address);}
    void inputAge() {cin >> age; cin.ignore();}
    void inputNumMember() {cin >> numMember; cin.ignore();}
    /* Show user information */
    void showUserInfo();
    /* Getter and setter */
    const string& getAccount() const { return account; }
    const string& getPassword() const { return password; }
    void setPassword(const string& newPassword) { password = newPassword; }
    const string& getFullname() const { return fullName; }
    
    const string& getAddress() const { return address; }
    void setAddress(const string& newAddress) { address = newAddress; }
    int getAge() const { return age; }
    void setAge(int newAge) { age = newAge; }
    int getNumMember() const { return numMember; }
    void setNumMember(int newNumMember) { numMember = newNumMember; }
    vector <Travel>& getTravel() {return myTravel;}
};
#endif // USER_H