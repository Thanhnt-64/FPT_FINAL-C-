#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "json.hpp"

#include "User.h"

#include "Travel.h"

#include "Room.h"
// #include "Room.h"

// #include "Hotel.h"
#include "Hotel.h"
// #include "Transport.h"
#include "Transport.h"

using namespace std;
using json = nlohmann::json;

class Write_User
{

    fstream m_output;
    json j;

public:
    ~Write_User(){m_output.close();}

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

class Write_Travel
{
    fstream m_output;
    json j;

public:
    ~Write_Travel(){m_output.close();}
    Write_Travel(string file_name) { m_output.open(file_name, ios::out); }
    void write_Room(Room room, int index_travel, int index_hotel, int index_room);
    void write_Hotel(Hotel hotel, int index_travel, int index_hotel);
    void write_Hotels(vector<Hotel> hotels, int index_travel);
    void write_Transport(Transport transport, int index_travel, int index_transport);
    void write_Transports(vector<Transport> transports, int index_travel);
    void write_Travel(Travel travel, int index_travel);
    void write_Travels(vector<Travel> travels);
    void pushfile();
};

class Read_User
{
    fstream m_input;
    json j;

public:
    ~Read_User(){m_input.close();}
    Read_User(string file_name) { m_input.open(file_name, ios::in); }
    User read_User(int index_user);
    vector<User> read_Users();
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

class Read_Travel
{
    fstream m_input;
    json j;

public:
    ~Read_Travel(){m_input.close();}
    Read_Travel(string file_name) { m_input.open(file_name, ios::in); }
    vector<Hotel> read_Hotels( int index_travel);
    vector<Transport> read_Transports( int index_travel);
    Travel read_Travel( int index_travel);
    vector<Travel> read_Travels();
    Hotel read_Hotel( int index_travel, int index_hotel);
    Transport read_Transport( int index_travel, int index_transport);
    Room read_Room( int index_travel, int index_hotel, int index_room);
    void load_file();
    // string test(int index);
};
typedef Read_Travel Read_Service;
typedef Write_Travel Write_Service;

#endif // FILE_H