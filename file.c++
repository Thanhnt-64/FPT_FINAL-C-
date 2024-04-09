#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "User.h"
#include "Admin.h"
#include "Travel.h"

using namespace std;

class WriteTitle
{
    fstream m_output;

public:
    WriteTitle(string file_name) { m_output.open(file_name, ios::out); }
    void writeTitle_Room();
    void writeTitle_Hotel();
    void writeTitle_Transport();
    void writeTitle_User();
};
// Transport Name |Brand |From |Destination |Cost |Time Start
void WriteTitle::writeTitle_Transport()
{

    m_output << setw(20) << left << "|Transport Name";
    m_output << setw(20) << left << "|Brand";
    m_output << setw(20) << left << "|From";
    m_output << setw(20) << left << "|Destination";
    m_output << setw(20) << left << "|Cost";
    m_output << setw(20) << left << "|Time Start";
}
void WriteTitle::writeTitle_Room()
{
    m_output << setw(20) << left << "|Room Name"
             << setw(20) << left << "|Type Room"
             << setw(20) << left << "|Total Cost";
}

void WriteTitle::writeTitle_Hotel()
{
    m_output << setw(20) << left << "|Hotel Name";
    writeTitle_Room();
}

void WriteTitle::writeTitle_User()
{
    m_output << setw(20) << left << "Account";
    m_output << setw(20) << left << "|Password";
    m_output << setw(20) << left << "|Full Name";
    m_output << setw(20) << left << "|Address";
    m_output << setw(20) << left << "|Age";
    m_output << setw(20) << left << "|Num Member";
    writeTitle_Hotel();
    writeTitle_Transport();
}

class Write
{

    fstream m_output;

public:
    Write(string file_name) { m_output.open(file_name, ios::app); }
    void write_Room(Room room);
    void write_Hotel(Hotel hotel);
    void write_Transport(Transport transport);
    void write_User(User user);
};

void Write::write_Room(Room room)
{
    m_output << "\t\t\t" << room.getName()<<endl;
    m_output << "\t\t\t" << room.getTypeRoom()<<endl;
    m_output << "\t\t\t" << room.getStartTime()<<endl;
    m_output << "\t\t\t" << room.getEndTime()<<endl;
    m_output << "\t\t\t" << room.getCost()<<endl;
}

void Write::write_Hotel(Hotel hotel)
{
    m_output << "\t\t\t" << hotel.getName();
    for(int i=0;i<hotel.getRooms().size();i++)
    {
        m_output << "\t\t\t" << "#Room" << i << endl;
        write_Room(hotel.getRooms()[i]);
    }
}

void Write::write_Transport(Transport transport)
{
    m_output << "\t\t\t" << transport.;
    m_output << "\t\t\t" << transport.;
    m_output << "\t\t\t" << transport.;
    m_output << "\t\t\t" << transport.;
    m_output << "\t\t\t" << transport.;
    m_output << "\t\t\t" << transport.;
}
// Account|Password|Full Name|Address|Age|Num Member
//|Hotel Name|Room Name|Type Room|Total Cost
//|Transport Name|Brand|From|Destination|Cost|Time Start
void Write::write_User(User user)
{
    m_output << setw(20) << left << user.getAccount()
             << setw(20) << left << user.getPassword()
             << setw(20) << left << user.getFullname()
             << setw(20) << left << user.getAddress()
             << setw(20) << left << user.getAge()
             << setw(20) << left << user.getNumMember();
    for (int i = 0; i < user.getTravel().size(); i++)
    {   
        //|Hotel Name|Room Name|Type Room|Total Cost
        for (int j = 0; j < user.getTravel()[i].getHotel().size(); j++)
        {
            m_output <<setw(20) <<left << user.getTravel()[i].getHotel()[j].getName();
            m_output <<setw(20) <<left << user.getTravel()[i].getHotel()[j].getName();
            m_output <<setw(20) <<left << user.getTravel()[i].getHotel()[j].getName();
            m_output <<setw(20) <<left << user.getTravel()[i].getHotel()[j].getName();

        }
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

int main()
{
}
