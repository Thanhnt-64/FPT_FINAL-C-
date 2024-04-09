#ifndef HOTEL_H
#define HOTEL_H
#include <iostream>
#include <vector>
#include <iomanip>
#include "Room.h"
using namespace std;

class Hotel{
    vector<Room> rooms;
    string name;
    string address;
    int total_cost;
    public:
    Hotel operator=(const Hotel& obj);
    void showRoomInfo();
    void showRoomInfoBooked();
    string getHotelName(){return name;}
    string getHotelAddress(){return address;}
    vector<Room>& getRoomss(){return rooms;}
    void setHotelName(string name){name=name;}
    void setHotelAddr(string addr){address=addr;}
    void setTotalCost(int cost){total_cost=cost;}
};
#endif // HOTEL_H