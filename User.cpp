#include "User.h"

void User::changeInfo()
{
    while(1){
        system("cls");
        int choice;
        cout << "1. Change full name" << endl;
        cout << "2. Change age" << endl;
        cout << "3. Change password" << endl;
        cout << "4. Change address" << endl;
        cout << "5. Back" << endl;
        cout << "Enter your choice: ";
        cin >> choice; cin.ignore();
        switch (choice)
        {
        case 1:
        {
            string newName;
            cout << "Enter new full name: ";
            getline(cin, newName);
            setFullname(newName);
            cout << "Full name changed successfully." << endl;
            break;
        }
        case 2:
        {
            int newAge;
            cout << "Enter new age: ";
            cin >> newAge; cin.ignore();
            setAge(newAge);
            cout << "Age changed successfully." << endl;
            break;
        }
        case 3:
        {
            string newPassword;
            cout << "Enter new password: ";
            cin >> newPassword; cin.ignore();
            setPassword(newPassword);
            cout << "Password changed successfully." << endl;
            break;
        }
        case 4:
        {
            string newAddress;
            cout << "Enter new address: ";
            cin.ignore(); // Clear the input buffer
            getline(cin, newAddress);
            setAddress(newAddress);
            cout << "Address changed successfully." << endl;
            break;
        }
        case 5:
        {
        // Do nothing, go back
            return;
        }
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }
}

void User::showUserInfo()
{
    cout << setw(20) << left << (string)("account")
         << setw(20) << left << (string)("fullName")
         << setw(20) << left << (string)("address")
         << setw(10) << left << (string)("age")
         << setw(10) << left << (string)("numMember") << endl;
    cout << setw(20) << left << account
         << setw(20) << left << fullName
         << setw(20) << left << address
         << setw(10) << left << age
         << setw(10) << left << numMember << endl;
}

void User::showTravelInfo()
{
    for (int i = 0; i < myTravel.size(); i++)
    {
        myTravel[i].showTravelInfo();
        cout << endl;
    }
}

void User::changeTravelInfo()
{
    string location;
    cout << "Enter the location you want to change: ";
    getline(cin, location);
    for (int i = 0; i < travels.size(); i++)
    {
        if (myTravel[i].getPlace() == location)
        {
            cout << "Enter name of Hotel you want to edit: ";
            string hotel; getline(cin, hotel);
            myTravel[i].getHotel()
        }
        else
        {
            cout << "Can not find the above location"
        }
    }
}
void User::cancelTravel()
{
    string location;
    cout << "Enter the location you want to cancel: ";
    getline(cin, location);
    for (int i = 0; i < travels.size(); i++)
    {
        if (myTravel[i].getPlace() == location)
        {
            myTravel.erase(myTravel.begin() + i);
            cout << "Travel to " << location << " has been canceled." << endl;
            return;
        }
        else
        {
            cout << "The travel you are trying to cancel does not exist in your travel list." << endl;
        }
    }
}