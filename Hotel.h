#ifndef HOTEL_H
#define HOTEL_H
#include <iostream>
#include <vector>
#include <iomanip>
#include "Room.h"
#include <string>
#include <limits>
using namespace std;

class Hotel{
    vector<Room> rooms;
    string name;
    string address;
    int total_cost;
    public:
    Hotel(){}
    Hotel(string, string, int=0, vector<Room> = {});
    Hotel operator=(const Hotel& obj);
    void showRoomInfo();
    void showRoomInfoBooked();
    string getName();
    string getAddress();
    int getTotalCost();
    vector<Room>& getRooms();
    void setName();
    void setAddress();
    void setTotalCost();
    bool validateString(string &);
};
#endif // HOTEL_H