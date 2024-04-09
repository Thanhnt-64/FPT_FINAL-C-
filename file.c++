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

class Write
{

    fstream m_output;
    json j;
public:
    Write(string file_name) { m_output.open(file_name, ios::out); }
    void write_Room(Room room);
    void write_Hotel(Hotel hotel);
    void write_Hotels(vector<Hotel> hotels);
    void write_Transport(Transport transport);
    void write_Transports(vector<Transport> transports);
    void write_Users(vector<User> users);
    void write_User(User user);
    void write_Travel(Travel travel);
    void write_Travels(vector<Travel> travels);
};

void Write::write_Travel(Travel travel)
{
    for (int i = 0; i < travel.getHotel().size(); i++)
    {
        write_Hotels(travel.getHotel());
    }

    for (int i = 0; i < travel.getTransport().size(); i++)
    {
        write_Transports(travel.getTransport());
    }
}

void Write::write_Travels(vector<Travel> travels)
{
    for (int i = 0; i < travels.size(); i++)
    {
        write_Travel(travels[i]);
    }
}

void Write::write_Room(Room room)
{
    // m_output << "\t\t\t" << room.getName() << endl;
    // m_output << "\t\t\t" << room.getTypeRoom() << endl;
    // m_output << "\t\t\t" << room.getStartTime() << endl;
    // m_output << "\t\t\t" << room.getEndTime() << endl;
    // m_output << "\t\t\t" << room.getCost() << endl;

    j["Travel"]["Hotel"]["Room"]["name"]=room.getName();
    j["Travel"]["Hotel"]["Room"]["type room"]=room.getTypeRoom();
    j["Travel"]["Hotel"]["Room"]["start time"]=room.getStartTime();
    j["Travel"]["Hotel"]["Room"]["end time"]=room.getEndTime();
    j["Travel"]["Hotel"]["Room"]["cost"]=room.getCost();
}

void Write::write_Hotel(Hotel hotel)
{
    // m_output << "\t\t" << hotel.getName() << endl;
    // m_output << "\t\t" << hotel.getAddress() << endl;
    // m_output << "\t\t" << hotel.getTotalCost() << endl;
    j["Travel"]["Hotel"]["name"]=hotel.getName();
    j["Travel"]["Hotel"]["address"]=hotel.getAddress();
    // j["Travel"]["Hotel"]["total cost"]=hotel.getTotalCost();
    for (int i = 0; i < hotel.getRooms().size(); i++)
    {
        write_Room(hotel.getRooms()[i]);
    }
}

void Write::write_Hotels(vector<Hotel> hotels)
{
    for (int i = 0; i < hotels.size(); i++)
    {
        write_Hotel(hotels[i]);
    }
}
void Write::write_Transport(Transport transport)
{
    // m_output << "\t\t" << transport.get_name() << endl;
    // m_output << "\t\t" << transport.get_brand() << endl;
    // m_output << "\t\t" << transport.get_from() << endl;
    // m_output << "\t\t" << transport.get_destination() << endl;
    // m_output << "\t\t" << transport.get_cost() << endl;
    // m_output << "\t\t" << transport.get_time() << endl;
    j["Travel"]["Transport"]["name"]=transport.get_name();
    j["Travel"]["Transport"]["brand"]=transport.get_brand();
    j["Travel"]["Transport"]["from"]=transport.get_from();
    j["Travel"]["Transport"]["destination"]=transport.get_destination();
    j["Travel"]["Transport"]["cost"]=transport.get_cost();
    j["Travel"]["Transport"]["time"]=transport.get_time();

}

void Write::write_Transports(vector<Transport> transports)
{
    for (int i = 0; i < transports.size(); i++)
    {
        write_Transport(transports[i]);
    }
}
// Account|Password|Full Name|Address|Age|Num Member
//|Hotel Name|Room Name|Type Room|Total Cost
//|Transport Name|Brand|From|Destination|Cost|Time Start
void Write::write_User(User user)
{
    // m_output << user.getAccount() << endl;
    // m_output << user.getPassword() << endl;
    // m_output << user.getFullname() << endl;
    // m_output << user.getAddress() << endl;
    // m_output << user.getAge() << endl;
    // m_output << user.getNumMember() << endl;
    // for (int i = 0; i < user.getTravel().size(); i++)
    // {
    //     write_Travels(user.getTravel());
    // }
    j["account"] = user.getAccount();
    j["password"] = user.getPassword();
    j["full name"] =user.getFullname();
    j["address"] =user.getAddress();
    j["age"] =user.getAge();
    j["number member"] =user.getNumMember();
    for (int i = 0; i < user.getTravel().size(); i++)
    {
        write_Travels(user.getTravel());
    }
    

}

void Write::write_Users(vector<User> users)
{
    for (int i = 0; i < users.size(); i++)
    {
        // m_output << "#User" << i << endl;
        write_User(users[i]);
    }
}
class Read
{
    fstream m_input;

public:
    Read(string file_name) { m_input.open(file_name, ios::in); }
    void read_User();
    void reade_Hotel();
    void read_Transport();
    void read_Room();
};

using json = nlohmann::json;

int main()
{



    fstream f;
    json ex1;
    f.open("example.json", ios::out);
    ex1["name"] = "ThanhTK";
    ex1["age"] = 20;
    ex1["account"] = "ThanhTK3";
    ex1["travel"]["hotel"]["name"] = "Phuong Nam";

    // f << ex1.dump(4);

    json ex;
    ex["name"] = "ThanhTK1";
    ex["age"] = 21;
    ex["account"] = "ThanhTK31";
    ex["travel"]["hotel"]["name"] = "Phuong Nam1";

    json j;
    j.push_back(ex1);
    j.push_back(ex);

    f << j.dump(4);

}
