#ifndef ROOM_H
#define ROOM_H

#include <iostream>
using namespace std;

const string nonestring = "";
class Room
{
    string m_name;
    string m_startTime;
    string m_endTime;
    int m_cost;
    string m_typeRoom; // normal or vip
public:
    // Constructor
    Room(){}
    Room(string name, string startTime, string endTime, string typeRoom,int cost);
    // : m_name{name}, m_startTime{startTime}, m_endTime{endTime}, m_typeRoom{typeRoom}, m_cost{cost}{};
    // Rename of Room
    void setName(string);
    // Set start time that user book
    // Input is format: xx/yy/zz/gggg
    void setStartTime(string);
    //Set type of Room
    //Input is normal or vip
    void setTypeRoom(string);
    //Get type Room
    string getTypeRoom();
    // Set end time that user book
    // Input is format: xx/yy/zz/gggg
    void setEndTime(string);
    // Get info
    string getName();
    // Get Start time that user book
    // Output is format: xx/yy/zz/gggg
    string getStartTime();
    // Get End time that user book
    // Output is format: xx/yy/zz/gggg
    string getEndTime();
    //Get cost of Room
    int getCost();
};

#endif // ROOM_H