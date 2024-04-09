#ifndef HOTEL_H
#define HOTEL_H
#include <iostream>
#include <vector>
#include <iomanip>
#include "Room.h"
using namespace std;

class Hotel{
    vector <Room> rooms;
    string name;
    string address;
    int total_cost;
    public:
    Hotel operator=(const Hotel& obj);
    void showRoomInfo();
    void showRoomInfoBooked();
};
#endif // HOTEL_H