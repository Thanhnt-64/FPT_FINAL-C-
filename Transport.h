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
    void validate(string&);
	void change_name(string &);
	void change_brand(string&);
	void change_from(string&);
	void change_destination(string &);
	void change_time(string &);
	void change_cost(int &);
	string get_name();
	string get_brand();
	string get_destination();
	string get_from();
	string get_time();
	int get_cost();
	//Transport Name |Brand |From |Destination |Cost |Time
	//20 digit      |20 digit |20 digit |20 digit |20 digit |20 digit
    void output();
	bool operator > (Transport& c);
	bool operator < (Transport& c);
};

#endif // TRANSPORT_H