#include "Admin.h"
#include "Hotel.h"
#include "Room.h"
#include "System.h"
#include "Travel.h"
#include "User.h"
#include <iomanip>
int main()
{
    //
    int menu;
    // Display menu
    do
    {
        cout << "Menu" << endl;
        cout << setw(10) << right << "";
        cout << "1: Login" << endl;
        cout << setw(10) << right << "";
        cout << "2: Sign Up" << endl;
        cout << "Enter number in range 1-2: ";
        cin >> menu;
    } while (menu != 1 && menu != 2);

    

}
