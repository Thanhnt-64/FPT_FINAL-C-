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
    Hotel(string name, string address, int total_cost, vector<Room> rooms)
        : name(name), address(address), total_cost(total_cost), rooms(rooms) {} 
    
    Hotel operator=(const Hotel& obj);
    void showRoomInfo();
    void showRoomInfoBooked();
    //get data
    string getName();
    string getAddress();
    int getTotalCost();
    vector<Room>& getRooms();
    void setName();//input name
    void setAddress();//input adress
    void setTotalCost();//input adress
    bool validateString(string &); //validate input data
};
#endif // HOTEL_H