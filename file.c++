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
    void write_User(User user, int index_user);
    void write_Travel(Travel travel, int index_user, int index_travel);
    void write_Travels(vector<Travel> travels, int index_user);
    void pushfile();
};

void Write_User::pushfile()
{
    m_output << j.dump(4);
}

void Write_User::write_Travel(Travel travel, int index_user, int index_travel)
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

void Write_User::write_Travels(vector<Travel> travels, int index_user)
{
    for (int i = 0; i < travels.size(); i++)
    {
        write_Travel(travels[i], index_user, i);
    }
}

void Write_User::write_Hotel(Hotel hotel, int index_user, int index_travel, int index_hotel)
{

    // m_output << "\t\t" << hotel.getName() << endl;
    // m_output << "\t\t" << hotel.getAddress() << endl;
    // m_output << "\t\t" << hotel.getTotalCost() << endl;
    j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["name"] = hotel.getName();
    j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["address"] = hotel.getAddress();
    j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["total cost"] = hotel.getTotalCost();
    for (int i = 0; i < hotel.getRooms().size(); i++)
    {
        write_Room(hotel.getRooms()[i], index_user, index_travel, index_hotel, i);
    }
}

void Write_User::write_Room(Room room, int index_user, int index_travel, int index_hotel, int index_room)
{
    // m_output << "\t\t\t" << room.getName() << endl;
    // m_output << "\t\t\t" << room.getTypeRoom() << endl;
    // m_output << "\t\t\t" << room.getStartTime() << endl;
    // m_output << "\t\t\t" << room.getEndTime() << endl;
    // m_output << "\t\t\t" << room.getCost() << endl;

    j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["Room" + to_string(index_room)]["name"] = room.getName();
    j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["Room" + to_string(index_room)]["type room"] = room.getTypeRoom();
    j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["Room" + to_string(index_room)]["start time"] = room.getStartTime();
    j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["Room" + to_string(index_room)]["end time"] = room.getEndTime();
    j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["Room" + to_string(index_room)]["cost"] = room.getCost();
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
    j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Transport" + to_string(index_transport)]["name"] = transport.get_name();
    j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Transport" + to_string(index_transport)]["brand"] = transport.get_brand();
    j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Transport" + to_string(index_transport)]["from"] = transport.get_from();
    j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Transport" + to_string(index_transport)]["destination"] = transport.get_destination();
    j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Transport" + to_string(index_transport)]["cost"] = transport.get_cost();
    j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Transport" + to_string(index_transport)]["time"] = transport.get_time();
}

void Write_User::write_Transports(vector<Transport> transports, int index_user, int index_travel)
{
    for (int i = 0; i < transports.size(); i++)
    {
        write_Transport(transports[i], index_user, index_travel, i);
    }
}
// Account|Password|Full Name|Address|Age|Num Member
//|Hotel Name|Room Name|Type Room|Total Cost
//|Transport Name|Brand|From|Destination|Cost|Time Start
void Write_User::write_User(User user, int index_user)
{

    j["User" + to_string(index_user)]["account"] = user.getAccount();
    j["User" + to_string(index_user)]["password"] = user.getPassword();
    j["User" + to_string(index_user)]["full name"] = user.getFullname();
    j["User" + to_string(index_user)]["address"] = user.getAddress();
    j["User" + to_string(index_user)]["age"] = user.getAge();
    j["User" + to_string(index_user)]["number member"] = user.getNumMember();
    for (int i = 0; i < user.getTravel().size(); i++)
    {
        write_Travels(user.getTravel(), index_user);
    }
}

void Write_User::write_Users(vector<User> users)
{
    for (int i = 0; i < users.size(); i++)
    {
        // m_output << "#User" << i << endl;
        write_User(users[i], i);
    }
}
class Read_User
{
    fstream m_input;
    json j;

public:
    Read_User(string file_name) { m_input.open(file_name, ios::in); }
    User read_User(int index_user);
    vector <User> read_Users();
    vector<Hotel> read_Hotels(int index_user, int index_travel);
    vector<Transport> read_Transports(int index_user, int index_travel);
    Travel read_Travel(int index_user, int index_travel);
    vector<Travel> read_Travels(int index_user);
    Hotel read_Hotel(int index_user, int index_travel, int index_hotel);
    Transport read_Transport(int index_user, int index_travel, int index_transport);
    Room read_Room(int index_user, int index_travel, int index_hotel, int index_room);
    void load_file();
    string test(int index);
};

vector <User> Read_User::read_Users()
{
    vector <User> users;
    int count_user = 0;
    for (auto &item : j.items())
    {
        if (item.key().rfind("User", 0) == 0)
        {
            count_user++;
        }
    }
    for (int i = 0; i < count_user; i++)
    {
        users.push_back(read_User(i));
    }
    return users;
}

User Read_User::read_User(int index_user)
{
    string account = j["User" + to_string(index_user)]["account"];
    string password = j["User" + to_string(index_user)]["password"];
    string fullname = j["User" + to_string(index_user)]["full name"];
    string address = j["User" + to_string(index_user)]["address"];
    int age = j["User" + to_string(index_user)]["age"];
    int num_member = j["User" + to_string(index_user)]["number member"];
    vector <Travel> travels = read_Travels(index_user);
    User buf(account, password, fullname, address, age, num_member,travels);
    return buf;
}
vector <Travel> Read_User::read_Travels(int index_user)
{
    vector <Travel> travels;
    int count_travel = 0;
    for (auto &item : j["User" + to_string(index_user)].items())
    {
        if (item.key().rfind("Travel", 0) == 0)
        {
            count_travel++;
        }
    }
    for (int i = 0; i < count_travel; i++)
    {
        Travel buf = read_Travel(index_user, i);
        travels.push_back(buf);
    }
    return travels;
}

Travel Read_User::read_Travel(int index_user, int index_travel)
{
    vector <Hotel> hotels = read_Hotels(index_user, index_travel);
    vector <Transport> transports = read_Transports(index_user, index_travel);
    return Travel(hotels, transports);

}

vector<Hotel> Read_User::read_Hotels(int index_user, int index_travel)
{
    vector<Hotel> hotels;
    int count_hotel = 0;
    for (auto &item : j["User" + to_string(index_user)]["Travel" + to_string(index_travel)].items())
    {
        if (item.key().rfind("Hotel", 0) == 0)
        {
            count_hotel++;
        }
    }
    for (int i = 0; i < count_hotel; i++)
    {
        Hotel buf = read_Hotel(index_user, index_travel, i);
        hotels.push_back(buf);
    }
    return hotels;
}

vector<Transport> Read_User::read_Transports(int index_user, int index_travel)
{
    vector<Transport> transports;
    int count_transport = 0;
    for (auto &item : j["User" + to_string(index_user)]["Travel" + to_string(index_travel)].items())
    {
        if (item.key().rfind("Transport", 0) == 0)
        {
            count_transport++;
        }
    }

    for (int i = 0; i < count_transport; i++)
    {
        Transport buf = read_Transport(index_user, index_travel, i);
        transports.push_back(buf);
    }

    return transports;
}
Transport Read_User::read_Transport(int index_user, int index_travel, int index_transport)
{
    string name, brand, from, destination;
    int cost;
    string time; // hh/mm/dd/yyyy;

    name = j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Transport" + to_string(index_transport)]["name"];
    brand = j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Transport" + to_string(index_transport)]["brand"];
    from = j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Transport" + to_string(index_transport)]["from"];
    destination = j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Transport" + to_string(index_transport)]["destination"];
    cost = j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Transport" + to_string(index_transport)]["cost"];
    time = j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Transport" + to_string(index_transport)]["time"];

    Transport buf(name, brand, from, destination, cost, time);
    return buf;
}

string Read_User::test(int index)
{
    return j["User" + to_string(index)]["account"];
}
void Read_User::load_file()
{
    m_input >> j;
}
Hotel Read_User::read_Hotel(int index_user, int index_travel, int index_hotel)
{
    vector<Room> rooms;
    Room room;
    string name;
    string address;
    int total_cost;

    name = j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["name"];
    address = j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["address"];
    total_cost = j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["total cost"];
    for (int i = 0; i < j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)].size() - 3; i++)
    {
        room = read_Room(index_user, index_travel, index_hotel, i);
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

    name = j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["Room" + to_string(index_room)]["name"];
    startTime = j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["Room" + to_string(index_room)]["start time"];
    endTime = j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["Room" + to_string(index_room)]["end time"];
    cost = j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["Room" + to_string(index_room)]["cost"];
    typeRoom = j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["Room" + to_string(index_room)]["type room"];
    // buf.setStartTime(startTime);
    // buf.setEndTime(endTime);
    // buf.setCost(cost);
    // buf.setTypeRoom(typeRoom);
    // buf.setName(name);
    Room buf(name, startTime, endTime, typeRoom, cost);
    return buf;
}

int main()
{
    Read_User read("example.json");
    Write_User write("write_ex.json");
    vector<Room> rooms;
    // Room buf[10];
    vector<Hotel> hotels;
    vector<Transport> transports;
    vector<Travel> travels;
    vector<User> users;
    int num = 2;
    // Room room;

    // fstream read1("example.json", ios ::in);
    // json j;
    // read1 >> j;
    // int count_hotel = 0;
    // for (auto &item : j["User0"]["Travel0"].items())
    // {
    //     if (item.key().rfind("Hotel", 0) == 0)
    //     { // Kiểm tra xem khóa có bắt đầu bằng "Hotel" không
    //         count_hotel++;
    //     }
    // // }
    // cout << count_hotel;
    read.load_file();
    
    users=read.read_Users();
    cout << users[1].getAccount();

    // Hotel hotel=read.read_Hotel(0,0,0);
    // cout << hotel.getName();
    // Room room = read.read_Room(0, 0, 0, 0);
    // cout << room.getName() << endl;
    // cout << read.test(0);
}
