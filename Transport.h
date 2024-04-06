#ifndef TRANSPORT_H
#define TRANSPORT_H 
#include <iostream>
#include <vector>

using namespace std;

class Transport{
private:
    string name; // validate name
    string brand; // validate brand
    string from;   // validate from
    string destination; // validate destination
    int cost;
    string time; // hh/mm/dd/yyyy
public:
    friend bool operator > (Transport t1, Transport t2);
    friend bool operator < (Transport t1, Transport t2);
    friend bool operator == (Transport t1, Transport t2);
    int calCost(){
        return cost;
    };
};

#endif // TRANSPORT_H