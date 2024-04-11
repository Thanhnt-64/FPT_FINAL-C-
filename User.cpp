#include "Lib/User.h"

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
        cout << "____________________________________________________________________________" << endl;
    }
}

void User::changeTravelInfo()
{
    string namePlace1;
    int temp=-1;
    while(1){
        cout<<"Enter name place travel: ";
        getline(cin,namePlace1);
        for(int i=0;i<myTravel.size();i++){
            if(myTravel[i].getPlace()!=namePlace1){
                continue;
            }
            temp = i;
            break;
        }
        if(temp != -1){
            break;
        }
    }
    while(1){
        system("cls");
        cout<<"1.Change information Hotel"<<endl;
        cout<<"2.Change information Transport"<<endl;
        cout<<"3.Back"<<endl;
        int lc;
        cout<<"Enter your choose: ";
        cin>> lc; cin.ignore();
        switch(lc){
            case 1:{
                string hotel;
                cout<<"Enter your name hotel need to change: ";
                getline(cin,hotel);
                int temp1=-1;
                for(int i=0;i<myTravel[temp].getHotel().size();i++){
                    if(myTravel[temp].getHotel()[i].getName()!=hotel){
                        continue;
                    }
                    temp1 = i;
                    break;
                }
                if(temp1 == -1){
                    continue;
                }
                string room;
                cout<<"Enter your name room need to change: ";
                getline(cin,room);
                for(int i=0;i<myTravel[temp].getHotel()[temp1].getRooms().size();i++){
                    if(myTravel[temp].getHotel()[temp1].getRooms()[i].getName()==room){
                        cout<<"Enter new name for room: ";
                        getline(cin,room);
                        myTravel[temp].getHotel()[temp1].getRooms()[i].setName(room);
                        break;
                    }
                }
                break;
            }

            case 2:{
                string trans;
                cout<<"Enter your name trans need to change: ";
                getline(cin,trans);
                for(int i=0;i<myTravel[temp].getTransport().size();i++){
                    if(myTravel[temp].getTransport()[i].get_name()==trans){
                        myTravel[temp].getTransport()[i].input();
                        break;
                    }
                }
                break;
            }
            case 3:
                return;
            default: 
                break;
        }
    }
}
void User::cancelTravel()
{
    string location;
    cout << "Enter the location you want to cancel: ";
    getline(cin, location);
    for (int i = 0; i < myTravel.size(); i++)
    {
        if (myTravel[i].getPlace() == location)
        {
            myTravel.erase(myTravel.begin() + i);
            cout << "Travel to " << location << " has been canceled." << endl;
            cout << "Enter any key to continue...\n";
            getline(cin, location);
            return;
        }
    }
    cout << "Travel to " << location << " not found." << endl;
    cout << "Enter any key to continue...\n";
    getline(cin, location);
}