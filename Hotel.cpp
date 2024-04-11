#include "Lib/Hotel.h"

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
        cout << setw(20) << left << rooms[i].getCost() << endl;
    }
}

Hotel Hotel::operator=(const Hotel& obj)
{
    name = obj.name;
    address=obj.address;
    total_cost=obj.total_cost;

    rooms.resize(obj.rooms.size());
    for(int i=0;i<obj.rooms.size();i++)
    {
        rooms[i]=obj.rooms[i];
    }
    
    return *this;
}

string Hotel::getName()
{
    return name;
}

string Hotel::getAddress()
{
    return  address;
}

int Hotel::getTotalCost()
{
    return total_cost;
}

vector <Room>& Hotel::getRooms()
{
    return rooms;
}
bool Hotel::validateString(string &s){
    while(1){
        getline(cin, s);
	    for (int i = 0; i < s.length(); i++) {
            if(s[i] == ' '){
                if(i==s.length()-1){
                     return true;
                }
                continue;
            }
		    if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
			    if (i == s.length() - 1) {
		    		return true;
			    }
	    	}
            else{
                return false;
            }   
        } 
        return false;	
        }
}
void Hotel::setName(){
    cout<<"Input Name: ";
    while(1){
        if(validateString(name)){
            break;
        }
        else{
            cout<<"Input again Name: ";
        }
    }
}

void Hotel::setAddress(){
    cout<<"Input Adress: ";
    while(1){
        if(validateString(address)){
            break;
        }
        else{
            cout<<"Input again Adress: ";
        }
    }
}

void Hotel::setTotalCost(){
    cout<<"Input Cost: ";
    while(1){
        if(cin>>total_cost){
			cin.ignore();
            break;

        }
        else{
            cout<<"Input again Cost: ";
            cin.clear(); // Xóa cờ lỗi
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // Xóa bộ nhớ đệm
        }
    }
}
