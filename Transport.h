#ifndef TRANSPORT_H
#define TRANSPORT_H 
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

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
    void validate(string&);
    void output();
	string get() {
		return name;
	}
	bool operator > (Transport& c);
	bool operator < (Transport& c);
};

#endif // TRANSPORT_H