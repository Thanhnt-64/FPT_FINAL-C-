#include <Hotel.h>

void Hotel::showRoomInfo()
{
    // Hotel Name: Phuong Nam
    cout << "Hotel Name: " << name << endl;
    // Room Name   |Type Room         |Cost
    // 20digit     |20 digit          |20 digit
    cout << setw(20) << left << "Room Name"
         << setw(20) << left << "|Type Room" << setw(20) << left
         << "|Cost" << endl;

    for (int i = 0; i < rooms.size(); i++)
    {
        cout << setw(20) << left << rooms[i].getName();
        cout << setw(20) << left << rooms[i].getTypeRoom();
        cout << setw(20) << left << rooms[i].getCost() << endl;
    }
}

void Hotel::showRoomInfoBooked()
{
    // Hotel Name: Phuong Nam
    
    // Hotel Name|Room Name |Type Room |Start Time  |End Time  |Cost
    // 20digit   |20digit   |20digit   |20 digit    |20 digit  |20 digit

    for (int i = 0; i < rooms.size(); i++)
    {   
        cout << setw(20) << left << name;
        cout << setw(20) << left << rooms[i].getName();
        cout << setw(20) << left << rooms[i].getTypeRoom();
        cout << setw(20) << left << rooms[i].getStartTime();
        cout << setw(20) << left << rooms[i].getEndTime();
        cout << setw(20) << left << rooms[i].getCost();
    }
}

