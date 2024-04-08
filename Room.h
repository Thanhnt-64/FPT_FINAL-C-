#ifndef ROOM_H
#define ROOM_H

#include <iostream>
using namespace std;

class Room{
    string name;
    string startTime;
    string endTime;
    public:
        Room(string, string, string);
        Room(){}
        void setName(string);
        void setStartTime(string);
        void setEndTime(string);
        string getName();
        string getStartTime();
        string getEndTime();
};

#endif // ROOM_H