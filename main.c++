#include "Admin.h"
#include "Hotel.h"
#include "Room.h"
#include "System.h"
#include "Travel.h"
#include "User.h"
#include <iomanip>
int main()
{
    System sys;
    Admin &admin = Admin::getInstance();
    vector<User> users;
    vector<Travel> travels;
    vector<Room> rooms;
    User *user = nullptr;
    User u1;
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
            user = sys.logInAccount(users, u1);
            system("cls");
            if(user != nullptr){
                cout << setw(5) << "Menu:\n";
                sys.listPlace(travels);
                cout << setw(10) << "Choose one travel to see details\n";
                cin >> choose; cin.ignore();
                travels[choose-1].showTravelInfo();
            }
            break;
        default:
            break;
        }
    }
    return 0;
}
