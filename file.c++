#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "json.hpp"

#include "User.c++"

#include "Travel.cpp"

#include "Room.cpp"
// #include "Room.h"

// #include "Hotel.h"
#include "Hotel.c++"
// #include "Transport.h"
#include "Transport.c++"

using namespace std;
using json = nlohmann::json;

class Write_User
{

    fstream m_output;
    json j;
public:
    Write_User(string file_name) { m_output.open(file_name, ios::out); }
    void write_Room(Room room, int index_user, int index_travel, int index_hotel, int index_room);
    void write_Hotel(Hotel hotel, int index_user, int index_travel, int index_hotel);
    void write_Hotels(vector<Hotel> hotels, int index_user, int index_travel);
    void write_Transport(Transport transport, int index_user, int index_travel, int index_transport);
    void write_Transports(vector<Transport> transports, int index_user, int index_travel);
    void write_Users(vector<User> users);
    void write_User(User user,int index_user);
    void write_Travel(Travel travel,int index_user, int index_travel);
    void write_Travels(vector<Travel> travels,int index_user);
    void pushfile();
};

void Write_User::pushfile()
{
    m_output << j.dump(4);
}

void Write_User::write_Travel(Travel travel,int index_user, int index_travel)
{
    for (int i = 0; i < travel.getHotel().size(); i++)
    {
        write_Hotels(travel.getHotel(), index_user, index_travel);
    }

    for (int i = 0; i < travel.getTransport().size(); i++)
    {
        write_Transports(travel.getTransport(), index_user, index_travel);
    }
}

void Write_User::write_Travels(vector<Travel> travels,int index_user)
{
    for (int i = 0; i < travels.size(); i++)
    {
        write_Travel(travels[i],index_user,i);
    }
}



void Write_User::write_Hotel(Hotel hotel, int index_user, int index_travel, int index_hotel)
{

    // m_output << "\t\t" << hotel.getName() << endl;
    // m_output << "\t\t" << hotel.getAddress() << endl;
    // m_output << "\t\t" << hotel.getTotalCost() << endl;
    j["User"+to_string(index_user)]["Travel"+to_string(index_travel)]["Hotel"+to_string(index_hotel)]["name"] = hotel.getName();
    j["User"+to_string(index_user)]["Travel"+to_string(index_travel)]["Hotel"+to_string(index_hotel)]["address"] = hotel.getAddress();
    j["User"+to_string(index_user)]["Travel"+to_string(index_travel)]["Hotel"+to_string(index_hotel)]["total cost"]=hotel.getTotalCost();
    for (int i = 0; i < hotel.getRooms().size(); i++)
    {
        write_Room(hotel.getRooms()[i],index_user,index_travel,index_hotel,i);
    }
    
}

void Write_User::write_Room(Room room, int index_user, int index_travel, int index_hotel, int index_room)
{
    // m_output << "\t\t\t" << room.getName() << endl;
    // m_output << "\t\t\t" << room.getTypeRoom() << endl;
    // m_output << "\t\t\t" << room.getStartTime() << endl;
    // m_output << "\t\t\t" << room.getEndTime() << endl;
    // m_output << "\t\t\t" << room.getCost() << endl;
   
    
    j["User"+to_string(index_user)]["Travel"+to_string(index_travel)]["Hotel"+to_string(index_hotel)]["Room"+to_string(index_room)]["name"]=room.getName();
    j["User"+to_string(index_user)]["Travel"+to_string(index_travel)]["Hotel"+to_string(index_hotel)]["Room"+to_string(index_room)]["type room"]=room.getTypeRoom();
    j["User"+to_string(index_user)]["Travel"+to_string(index_travel)]["Hotel"+to_string(index_hotel)]["Room"+to_string(index_room)]["start time"]=room.getStartTime();
    j["User"+to_string(index_user)]["Travel"+to_string(index_travel)]["Hotel"+to_string(index_hotel)]["Room"+to_string(index_room)]["end time"]=room.getEndTime();
    j["User"+to_string(index_user)]["Travel"+to_string(index_travel)]["Hotel"+to_string(index_hotel)]["Room"+to_string(index_room)]["cost"]=room.getCost();

   
}

void Write_User::write_Hotels(vector<Hotel> hotels, int index_user, int index_travel)
{
    for (int i = 0; i < hotels.size(); i++)
    {
        write_Hotel(hotels[i], index_user, index_travel, i);
    }
}
void Write_User::write_Transport(Transport transport, int index_user, int index_travel, int index_transport)
{ 
    // m_output << "\t\t" << transport.get_name() << endl;
    // m_output << "\t\t" << transport.get_brand() << endl;
    // m_output << "\t\t" << transport.get_from() << endl;
    // m_output << "\t\t" << transport.get_destination() << endl;
    // m_output << "\t\t" << transport.get_cost() << endl;
    // m_output << "\t\t" << transport.get_time() << endl;
    j["User"+to_string(index_user)]["Travel"+to_string(index_travel)]["Transport"+to_string(index_transport)]["name"]=transport.get_name();
    j["User"+to_string(index_user)]["Travel"+to_string(index_travel)]["Transport"+to_string(index_transport)]["brand"]=transport.get_brand();
    j["User"+to_string(index_user)]["Travel"+to_string(index_travel)]["Transport"+to_string(index_transport)]["from"]=transport.get_from();
    j["User"+to_string(index_user)]["Travel"+to_string(index_travel)]["Transport"+to_string(index_transport)]["destination"]=transport.get_destination();
    j["User"+to_string(index_user)]["Travel"+to_string(index_travel)]["Transport"+to_string(index_transport)]["cost"]=transport.get_cost();
    j["User"+to_string(index_user)]["Travel"+to_string(index_travel)]["Transport"+to_string(index_transport)]["time"]=transport.get_time();

 

}

void Write_User::write_Transports(vector<Transport> transports, int index_user, int index_travel)
{
    for (int i = 0; i < transports.size(); i++)
    {
        write_Transport(transports[i],index_user,index_travel,i);
    }
}
// Account|Password|Full Name|Address|Age|Num Member
//|Hotel Name|Room Name|Type Room|Total Cost
//|Transport Name|Brand|From|Destination|Cost|Time Start
void Write_User::write_User(User user, int index_user)
{   
    
    j["User"+to_string(index_user)]["account"] = user.getAccount();
    j["User"+to_string(index_user)]["password"] = user.getPassword();
    j["User"+to_string(index_user)]["full name"] =user.getFullname();
    j["User"+to_string(index_user)]["address"] =user.getAddress();
    j["User"+to_string(index_user)]["age"] =user.getAge();
    j["User"+to_string(index_user)]["number member"] =user.getNumMember();
    for (int i = 0; i < user.getTravel().size(); i++)
    {
        write_Travels(user.getTravel(),index_user);
    }
    
   
}

void Write_User::write_Users(vector<User> users)
{
    for (int i = 0; i < users.size(); i++)
    {
        // m_output << "#User" << i << endl;
        write_User(users[i],i);
    }
}
class Read_User
{
    fstream m_input;
    json j;

public:
    Read_User(string file_name) { m_input.open(file_name, ios::in); }
    User read_User(int index_user);
    Hotel read_Hotel(int index_user, int index_travel, int index_hotel);
    Transport read_Transport(int index_user, int index_travel, int index_transport);
    Room read_Room(int index_user, int index_travel, int index_hotel, int index_room);
    void load_file();
};
Hotel Read_User::read_Hotel(int index_user, int index_travel, int index_hotel)
{
    vector <Room> rooms;
    Room room;
    string name;
    string address;
    int total_cost;
    
    name=j["User"+to_string(index_user)]["Travel"+to_string(index_travel)]["Hotel"+to_string(index_hotel)]["name"];
    address=j["User"+to_string(index_user)]["Travel"+to_string(index_travel)]["Hotel"+to_string(index_hotel)]["address"];
    total_cost=j["User"+to_string(index_user)]["Travel"+to_string(index_travel)]["Hotel"+to_string(index_hotel)]["total cost"];
    for (int i = 0; i < j["User"+to_string(index_user)]["Travel"+to_string(index_travel)]["Hotel"+to_string(index_hotel)].size(); i++)
    {
        room=read_Room(index_user,index_travel,index_hotel,i);
        rooms.push_back(room);
    }
    Hotel buf(name, address, total_cost, rooms);
    return buf;
}
Room Read_User::read_Room(int index_user, int index_travel, int index_hotel, int index_room)
{   
    string name;
    string startTime;
    string endTime;
    int cost;
    string typeRoom; 
    Room buf;
    name = j["User"+to_string(index_user)]["Travel"+to_string(index_travel)]["Hotel"+to_string(index_hotel)]["Room"+to_string(index_room)]["name"];
    startTime=j["User"+to_string(index_user)]["Travel"+to_string(index_travel)]["Hotel"+to_string(index_hotel)]["Room"+to_string(index_room)]["startTime"];
    endTime=j["User"+to_string(index_user)]["Travel"+to_string(index_travel)]["Hotel"+to_string(index_hotel)]["Room"+to_string(index_room)]["endTime"];
    cost=j["User"+to_string(index_user)]["Travel"+to_string(index_travel)]["Hotel"+to_string(index_hotel)]["Room"+to_string(index_room)]["cost"];
    typeRoom=j["User"+to_string(index_user)]["Travel"+to_string(index_travel)]["Hotel"+to_string(index_hotel)]["Room"+to_string(index_room)]["type room"];
    buf.setStartTime(startTime);
    buf.setEndTime(endTime);
    buf.setCost(cost);
    buf.setTypeRoom(typeRoom);
    buf.setName(name);

    return buf;  
}

int main()
{
    Write_User write("example.json");
    
    vector <Room> rooms;
    // Room buf[10];
    vector <Hotel> hotels;
    vector <Transport> transports;
    vector <Travel> travels;
    vector <User> users;
    int num=2;
    for(int i=0;i<num;i++)
    {
        Room buff("10"+to_string(i), "10/10/12/2024", "15/10/12/2024", "Standard", 100);
        rooms.push_back(buff);
        
    }

    for(int i=0;i<num;i++)
    {
        Hotel hotelbuf("Phuong Nam"+to_string(i), "HCM", 10000, rooms);
        hotels.push_back(hotelbuf);
    }
    
    for(int i=0;i<num;i++)
    {
        Transport transportbuf("Flight"+to_string(i), "Viet Nam Airline", "HCM", "HCM", 1000, "8/10/12/2024");
        transports.push_back(transportbuf);
    }

    for(int i=0;i<num;i++)
    {
        Travel travelbuf(hotels, transports);
        travels.push_back(travelbuf);
    }

    for(int i=0;i<num;i++)
    {
        User userbuf("ThanhTK"+to_string(i), "291004", "Truong Khanh Thanh"+to_string(i), "96 Ngo Tu Do", 20, 1, travels);
        users.push_back(userbuf);
    }
    write.write_Users(users);
    write.pushfile();

    // Room room1("102", "10/10/12/2024", "15/10/12/2024", "Standard", 1000);
    // // cout << room1.getCost();
    // vector<Room> rooms;
    // rooms.push_back(room1);
    // Hotel hotel1("Phuong Nam", "HCM", 10000, rooms);

    // // cout << hotel1.getAddress();
    // vector<Hotel> hotels;
    // hotels.push_back(hotel1);

    // Transport tran1("Flight", "Viet Nam Airline", "HCM", "HCM", 1000, "8/10/12/2024");
    // vector<Transport> trans;
    // trans.push_back(tran1);
    // // cout << tran1.get_brand();
    // Travel travel(hotels, trans);
    // // travel.showTravelInfo();

    // vector<Travel> travels;
    // travels.push_back(travel);

    // User user1("ThanhTK", "291004", "Truong Khanh Thanh", "96 Ngo Tu Do", 20, 1, travels);
    // vector<User> users;
    // users.push_back(user1);
    // // cout << user1.getPassword();

    
    // Write write("example.json");
    // fstream output("example.json", ios::out);
    // json j;
    // j["Travel"]["Hotel"]["name"]["1"] = "Phuong Nam";
    // j["Travel"]["Hotel"]["name"]["2"] = "HCM";

    // output << j.dump(4);

}
