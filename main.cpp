#include "Admin.h"
#include "Hotel.h"
#include "Room.h"
#include "System.h"
#include "Travel.h"
#include "User.h"
#include "File.h"
bool checkAccountAdmin(const string &s){
    return s == "admin";
}
int main()
{
    System sys;
    Admin &admin = Admin::getInstance();
    vector<User> users;
    vector<Travel> travels;

    //Load data from files
    Read_User read_user("database_user.json");
    Read_Service read_service("database_service.json");
    users=read_user.read_Users();
    travels=read_service.read_Travels();
    read_user.~Read_User();
    read_service.~Read_Service();

    vector<Room> rooms;
    User *user = nullptr;
    User u1;
    string account;
    int choose;
    return 0;
}
