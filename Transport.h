#ifndef TRANSPORT_H
#define TRANSPORT_H 
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;
class Transport{
private:
	string name, brand, from, destination;
	int cost;
	string time;//hh/mm/dd/yyyy;
	int hour, day, month, year;
public:
	Transport() {}
	Transport(string name, string brand, string from, string destination, string time, int cost) :name(name)
		, brand(brand), from(from), destination(destination), time(time), cost(cost){}
	void input();//input name,brand,from,destination,time;
	void validate_time();
    bool validate_string(string&);
    void validate_name(string &);
    void validate_brand(string &);
    void validate_from(string &);
    void validate_destination(string &);
    void validate_cost();
    void output();
	bool operator > (Transport& c);
	bool operator < (Transport& c);
};

#endif // TRANSPORT_H