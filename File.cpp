#include "Lib/File.h"

void Write_User::pushfile()
{
    m_output << j.dump(4);
}

void Write_Travel::pushfile()
{
    m_output << j.dump(4);
}

void Write_Travel::write_Travel(Travel travel, int index_travel)
{
    for (int i = 0; i < travel.getHotel().size(); i++)
    {
        write_Hotels(travel.getHotel(), index_travel);
    }

    for (int i = 0; i < travel.getTransport().size(); i++)
    {
        write_Transports(travel.getTransport(), index_travel);
    }
    j["Travel" + to_string(index_travel)]["name place"] = travel.getPlace();
    j["Travel" + to_string(index_travel)]["travel cost"] = travel.getTravelCost();

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
    j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["name place"] = travel.getPlace();
    j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["travel cost"] = travel.getTravelCost();
}

void Write_Travel::write_Travels(vector<Travel> travels)
{
    for (int i = 0; i < travels.size(); i++)
    {
        write_Travel(travels[i], i);
    }
}

void Write_User::write_Travels(vector<Travel> travels, int index_user)
{
    for (int i = 0; i < travels.size(); i++)
    {
        write_Travel(travels[i], index_user, i);
    }
}

void Write_Travel::write_Hotel(Hotel hotel, int index_travel, int index_hotel)
{
    j["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["name"] = hotel.getName();
    j["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["address"] = hotel.getAddress();
    // j["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["total cost"] = hotel.getTotalCost();
    for (int i = 0; i < hotel.getRooms().size(); i++)
    {
        write_Room(hotel.getRooms()[i], index_travel, index_hotel, i);
    }
}
void Write_User::write_Hotel(Hotel hotel, int index_user, int index_travel, int index_hotel)
{

    j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["name"] = hotel.getName();
    j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["address"] = hotel.getAddress();
    j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["total cost"] = hotel.getTotalCost();
    for (int i = 0; i < hotel.getRooms().size(); i++)
    {
        write_Room(hotel.getRooms()[i], index_user, index_travel, index_hotel, i);
    }
}

void Write_Travel::write_Room(Room room, int index_travel, int index_hotel, int index_room)
{
    j["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["Room" + to_string(index_room)]["name"] = room.getName();
    j["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["Room" + to_string(index_room)]["type room"] = room.getTypeRoom();
    j["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["Room" + to_string(index_room)]["start time"] = room.getStartTime();
    j["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["Room" + to_string(index_room)]["end time"] = room.getEndTime();
    j["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["Room" + to_string(index_room)]["cost"] = room.getCost();
}

void Write_User::write_Room(Room room, int index_user, int index_travel, int index_hotel, int index_room)
{

    j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["Room" + to_string(index_room)]["name"] = room.getName();
    j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["Room" + to_string(index_room)]["type room"] = room.getTypeRoom();
    j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["Room" + to_string(index_room)]["start time"] = room.getStartTime();
    j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["Room" + to_string(index_room)]["end time"] = room.getEndTime();
    j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["Room" + to_string(index_room)]["cost"] = room.getCost();
}

void Write_Travel::write_Hotels(vector<Hotel> hotels, int index_travel)
{
    for (int i = 0; i < hotels.size(); i++)
    {
        write_Hotel(hotels[i], index_travel, i);
    }
}

void Write_User::write_Hotels(vector<Hotel> hotels, int index_user, int index_travel)
{
    for (int i = 0; i < hotels.size(); i++)
    {
        write_Hotel(hotels[i], index_user, index_travel, i);
    }
}

void Write_Travel::write_Transport(Transport transport, int index_travel, int index_transport)
{
    j["Travel" + to_string(index_travel)]["Transport" + to_string(index_transport)]["name"] = transport.get_name();
    j["Travel" + to_string(index_travel)]["Transport" + to_string(index_transport)]["brand"] = transport.get_brand();
    j["Travel" + to_string(index_travel)]["Transport" + to_string(index_transport)]["from"] = transport.get_from();
    j["Travel" + to_string(index_travel)]["Transport" + to_string(index_transport)]["destination"] = transport.get_destination();
    j["Travel" + to_string(index_travel)]["Transport" + to_string(index_transport)]["cost"] = transport.get_cost();
    j["Travel" + to_string(index_travel)]["Transport" + to_string(index_transport)]["time"] = transport.get_time();
}
void Write_User::write_Transport(Transport transport, int index_user, int index_travel, int index_transport)
{

    j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Transport" + to_string(index_transport)]["name"] = transport.get_name();
    j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Transport" + to_string(index_transport)]["brand"] = transport.get_brand();
    j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Transport" + to_string(index_transport)]["from"] = transport.get_from();
    j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Transport" + to_string(index_transport)]["destination"] = transport.get_destination();
    j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Transport" + to_string(index_transport)]["cost"] = transport.get_cost();
    j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["Transport" + to_string(index_transport)]["time"] = transport.get_time();
}

void Write_Travel::write_Transports(vector<Transport> transports, int index_travel)
{
    for (int i = 0; i < transports.size(); i++)
    {
        write_Transport(transports[i], index_travel, i);
    }
}
void Write_User::write_Transports(vector<Transport> transports, int index_user, int index_travel)
{
    for (int i = 0; i < transports.size(); i++)
    {
        write_Transport(transports[i], index_user, index_travel, i);
    }
}

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

vector<User> Read_User::read_Users()
{
    vector<User> users;
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
    vector<Travel> travels = read_Travels(index_user);
    User buf(account, password, fullname, address, age, num_member, travels);
    return buf;
}

vector<Travel> Read_Travel::read_Travels()
{
    vector<Travel> travels;
    int count_travel = 0;
    for (auto &item : j.items())
    {
        if (item.key().rfind("Travel", 0) == 0)
        {
            count_travel++;
        }
    }
    for (int i = 0; i < count_travel; i++)
    {
        travels.push_back(read_Travel(i));
    }
    return travels;
}
vector<Travel> Read_User::read_Travels(int index_user)
{
    vector<Travel> travels;
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
Travel Read_Travel::read_Travel(int index_travel)
{
    vector<Hotel> hotels = read_Hotels(index_travel);
    vector<Transport> transports = read_Transports(index_travel);
    string namePlace=j["Travel" + to_string(index_travel)]["name place"];
    int total_cost=j["Travel" + to_string(index_travel)]["travel cost"];

    return Travel(hotels, transports, namePlace, total_cost);
}
Travel Read_User::read_Travel(int index_user, int index_travel)
{
    vector<Hotel> hotels = read_Hotels(index_user, index_travel);
    vector<Transport> transports = read_Transports(index_user, index_travel);
    // j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["travel cost"] = travel.getTravelCost();
    // j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["name place"] = travel.getPlace();


    int total_cost=j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["travel cost"];
    string namePlace=j["User" + to_string(index_user)]["Travel" + to_string(index_travel)]["name place"];
    return Travel(hotels, transports, namePlace, total_cost);
}

vector<Hotel> Read_Travel::read_Hotels(int index_travel)
{
    vector<Hotel> hotels;
    int count_hotel = 0;
    for (auto &item : j["Travel" + to_string(index_travel)].items())
    {
        if (item.key().rfind("Hotel", 0) == 0)
        {
            count_hotel++;
        }
    }
    for (int i = 0; i < count_hotel; i++)
    {
        Hotel buf = read_Hotel(index_travel, i);
        hotels.push_back(buf);
    }
    return hotels;
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

vector<Transport> Read_Travel::read_Transports(int index_travel)
{
    vector<Transport> transports;
    int count_transport = 0;
    for (auto &item : j["Travel" + to_string(index_travel)].items())
    {
        if (item.key().rfind("Transport", 0) == 0)
        {
            count_transport++;
        }
    }

    for (int i = 0; i < count_transport; i++)
    {
        Transport buf = read_Transport(index_travel, i);
        transports.push_back(buf);
    }

    return transports;
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

Transport Read_Travel::read_Transport(int index_travel, int index_transport)
{
    string name, brand, from, destination;
    int cost;
    string time; // hh/mm/dd/yyyy;
    
    name = j["Travel" + to_string(index_travel)]["Transport" + to_string(index_transport)]["name"];
    brand = j["Travel" + to_string(index_travel)]["Transport" + to_string(index_transport)]["brand"];
    from = j["Travel" + to_string(index_travel)]["Transport" + to_string(index_transport)]["from"];
    destination = j["Travel" + to_string(index_travel)]["Transport" + to_string(index_transport)]["destination"];
    cost = j["Travel" + to_string(index_travel)]["Transport" + to_string(index_transport)]["cost"];
    time = j["Travel" + to_string(index_travel)]["Transport" + to_string(index_transport)]["time"];
    
    Transport buf(name, brand, from, destination, cost, time);
    return buf;
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

void Read_Travel::load_file()
{
    m_input >> j;
}

void Read_User::load_file()
{
    m_input >> j;
}

Hotel Read_Travel::read_Hotel(int index_travel, int index_hotel)
{
    vector<Room> rooms;
    Room room;
    string name;
    string address;
    int total_cost = 0;

    name = j["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["name"];
    address = j["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["address"];
    for (int i = 0; i < j["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)].size() - 3; i++)
    {
        room = read_Room(index_travel, index_hotel, i);
        rooms.push_back(room);
    }
    Hotel buf(name, address, total_cost, rooms);
    return buf;
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

Room Read_Travel::read_Room(int index_travel, int index_hotel, int index_room)
{
    string name;
    string startTime;
    string endTime;
    int cost;
    string typeRoom;

    name = j["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["Room" + to_string(index_room)]["name"];
    startTime = j["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["Room" + to_string(index_room)]["start time"];
    endTime = j["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["Room" + to_string(index_room)]["end time"];
    cost = j["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["Room" + to_string(index_room)]["cost"];
    typeRoom = j["Travel" + to_string(index_travel)]["Hotel" + to_string(index_hotel)]["Room" + to_string(index_room)]["type room"];
    Room buf(name, startTime, endTime, typeRoom, cost);
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
    Room buf(name, startTime, endTime, typeRoom, cost);
    return buf;
}

// int main()
// {
//     Read_Travel read("database_service.json");
//     // Write_Travel write("database_service.json");
//     vector<Room> rooms;
//     vector<Hotel> hotels;
//     vector<Transport> transports;
//     vector<Travel> travels;
//     vector<User> users;
//     int num = 2;
//     int num_user = 10;
//     int num_travel = 1;
//     int num_hotel = 1;
//     int num_room = 1;
//     int num_transport = 1;
//     //Read
//     read.load_file();
//     travels=read.read_Travels();
//     //  users[0].getAccount();
//     //  hotel = read.read_Hotel(0,0,0);
//     cout << travels[1].getPlace();

//     // Write
//     // for (int i = 0; i < num_room; i++)
//     // {
//     //     Room room("10" + to_string(i), "10/10/12/2024", "15/10/12/2024", "Vip" + to_string(i), 1000 + i);
//     //     rooms.push_back(room);
//     // }

//     // for (int i = 0; i < num_hotel; i++)
//     // {
//     //     Hotel hotel("10" + to_string(i), "10/10/12/2024", 1000 + i, rooms);
//     //     hotels.push_back(hotel);
//     // }

//     // for (int i = 0; i < num_transport; i++)
//     // {
//     //     Transport transport("Flight" + to_string(i), "Vietnam Airlines", "Ha Noi", "Hai Phong", 1000 + i, "10/15/12/2024");
//     //     transports.push_back(transport);
//     // }

//     // for (int i = 0; i < num_travel; i++)
//     // {
//     //     Travel travel(hotels, transports);
//     //     travels.push_back(travel);
//     // }

//     // for (int i = 0; i < num_user; i++)
//     // {
//     //     for (int j = 0; j < num_travel; j++)
//     //     {
//     //         for (int k = 0; k < num_hotel; k++)
//     //         {
//     //             for (int l = 0; l < num_room; l++)
//     //             {
//     //                 Room room("10" + to_string(i) + to_string(j) + to_string(k) + to_string(l), "10/10/12/2024", "15/10/12/2024", "Vip" + to_string(i) + to_string(j) + to_string(k) + to_string(l), 1000);
//     //                 rooms.push_back(room);
//     //             }
//     //             Hotel hotel("Rose" + to_string(i) + to_string(j) + to_string(k), "HaiPhong", 1000, rooms);
//     //             hotels.push_back(hotel);
//     //             Transport transport("Flight" + to_string(i)+ to_string(j) + to_string(k), "Vietnam Airlines"+ to_string(i)+ to_string(j) + to_string(k), "Ha Noi"+ to_string(i)+ to_string(j) + to_string(k), "Hai Phong"
//     //             , 1000 , "10/15/12/2024");
//     //             transports.push_back(transport);
//     //         }
//     //         Travel travel(hotels, transports,"Hai Phong", 1000);
//     //         travels.push_back(travel);
//     //     }
//     //     User user("ThanhTK" + to_string(i), "123456", "Thanh Truong " + to_string(i),"9"+to_string(i)+ " Ngo Tu Do", 20+i,i+1,travels);
//     //     users.push_back(user);
//     // }
//     // write.write_Travels(travels);
//     // write.pushfile();
// }
