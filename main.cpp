#include "Admin.c++"
#include "Hotel.c++"
#include "Room.cpp"
#include "System.c++"
#include "Travel.cpp"
#include "User.c++"
#include "File.cpp"
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
    Read_User read_user("user_database.json");
    Read_Service read_service("service_database.json");
    users=read_user.read_Users();
    travels=read_service.read_Travels();
    read_user.~Read_User();
    read_service.~Read_Service();

    vector<Room> rooms;
    User *user = nullptr;
    User u1;
    string account;
    int choose;
    while(1){
        cout << setw(5) << "Menu:\n";
        cout << setw(10) << "1. Login\n";
        cout << setw(10) << "2. Register\n";
        cout << setw(10) << "Choose 1 or 2\n";
        cin >> choose; cin.ignore();
        switch (choose)
        {
        case 1:
            cout << "Enter your account: "; getline(cin, account);
            if(checkAccountAdmin(account)){
                cout << "You are login as admin!\n";
                sys.logInAccount();
                sys.runAdmin(travels, users);
                break;
            }
            user = sys.logInAccount(users, u1);
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
        system("cls");
    }
    return 0;
}