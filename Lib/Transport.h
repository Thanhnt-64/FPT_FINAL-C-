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
	string time;
	int hour, day, month, year;
public:
	Transport(){}
	Transport(string name,string brand,string from,string destination,int cost,string time);
	Transport(string name, string brand, string from, string destination, string time, int cost) :name(name)
		, brand(brand), from(from), destination(destination), time(time), cost(cost){}
	/*input name,brand,from,destination,time,cost and validate input*/ 
	void input();
	void validate_time(string&);
    bool validate_string(string&);
    void validate_name(string &);
    void validate_brand(string &);
    void validate_from(string &);
    void validate_destination(string &);
    void validate_cost(int&);
    void validate(string&);
	//change transport
	void change_name();
	void change_brand();
	void change_from();
	void change_destination();
	void change_time();
	void change_cost();
	//get data
	string get_name();
	string get_brand();
	string get_destination();
	string get_from();
	string get_time();
	int get_cost();
	// show infomation attribute
    void output();
	bool operator > (Transport& c);
	bool operator < (Transport& c);
};

#endif // TRANSPORT_H