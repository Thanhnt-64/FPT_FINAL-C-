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
    read_user.load_file();
    read_service.load_file(); 
    users=read_user.read_Users();
    // cout << "error" << endl;
    travels=read_service.read_Travels();
    
    read_user.~Read_User();
    read_service.~Read_Service();

    vector<Room> rooms;
    User *user = nullptr;
    User u1;
    string account;
    int choose;
    while(1){
        system("cls");
        cout << setw(5) << "Menu:\n";
        cout << "1. Login\n";
        cout << "2. Register\n";
        cout << setw(10) << "Choose 1 or 2\n";
        cin >> choose; cin.ignore();
        switch (choose)
        {
        case 1:
            cout << "Account: "; getline(cin, account);
            u1 = {account, account};
            if(checkAccountAdmin(account)){
                cout << "You are login as admin!\n";
                sys.logInAccount();
                sys.runAdmin(travels, users);
                break;
            }
            user = sys.logInAccount(users, u1);
            sys.run(travels, user);
            break;
        case 2:
            user = sys.registerAccount(users, u1);
            cout << "Register successfully!\n";
            cout << "Please log in with your account!\n";
            user = sys.logInAccount(users, u1);
            sys.run(travels, user);
            break;
        default:
            break;
        }
        admin.saveData(users ,user->getTravel());
        system("cls");
    }
    return 0;
}
