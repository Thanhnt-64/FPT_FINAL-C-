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
    //get data
    string getName();
    string getAddress();
    int getTotalCost();
    vector<Room>& getRooms();
    //input name
    void setName();
    //input adress
    void setAddress();
    //input cost
    void setTotalCost();
    //validate input data
    bool validateString(string &); 
};
#endif // HOTEL_H