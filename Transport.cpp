#include "Lib/Transport.h"

void Transport::input()
{
	cout << "Input transport Name: ";
	validate_name(name); // chỉ nhận chuỗi là Flight và Car
	cout << "Input Brand: ";
	validate_brand(brand); // chứa kí tự từ A->z và chứa cả dấu cách ,không chứa các kí tự đặc biệt
	cout << "Input From: ";
	validate_from(from); // chứa kí tự từ A->z và chứa cả dấu cách ,không chứa các kí tự đặc biệt
	cout << "Input Destination: ";
	validate_destination(destination); // chứa kí tự từ A->z và chứa cả dấu cách ,không chứa các kí tự đặc biệt
	cout << "Input Time(hh/dd/mm/yyyy): ";
	validate_time(time);
    cout<<"Input Cost: ";
    validate_cost(cost);
}
void Transport::validate_cost(int &a){
    while(1){
        if(cin>>a){
			cin.ignore();
            break;

        }
        else{
            cout<<"Input Cost: ";
            cin.clear(); // Xóa cờ lỗi
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // Xóa bộ nhớ đệm
        }
    }
}
void Transport::validate_time(string &t) {
	while (1) {
		getline(cin, t);
		if (t.length() != 13) {
			cout << "Input Time" << endl;
			continue;
		}
		if (t[2] != '/' || t[5] != '/' || t[8] != '/') {
			cout << "Input Time: ";
			continue;
		}

		for (int i = 0; i < t.length(); i++) {
			if (i != 2 || i != 5 || i != 8) {
				if (t[i] < '0' || t[i]>'9') {
					break;
				}
			}
		}
		int sum = 0, temp1 = 1, count = 0;
		// get hour,day,month,year
		for (int i = t.length() - 1; i >= 0; i--) {
			if (t[i] == '/') {
				count++;
				if (count == 1)
				{
					year = sum;
				}
				if (count == 2)
				{
					month = sum;
					if (sum > 12 || sum <= 0)
					{

						break;
					}
				}

				if (count == 3)
				{
					day = sum;
					if ((sum > 30 || sum <= 0) && (month == 4 || month == 6 || month == 9 || month == 11))
					{

						break;
					}
					if ((sum > 31 || sum <= 0) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
					{

						break;
					}
					if (year % 4 == 0 && (sum > 29 || sum <= 0) && month == 2)
					{
						break;
					}
					if (year % 4 == 1 && (sum > 28 || sum <= 0) && month == 2)
					{
						break;
					}
				}

				sum = 0;
				temp1 = 1;
			}
			else
			{
				if (i == 0)
				{
					count++;
				}
				sum += ((int)t[i] - 48) * temp1;
				temp1 *= 10;
			}
		}
		if (count == 4 && sum <= 24)
		{
			hour = sum;
			break;
		}
		cout << "Input Time: ";
	}
}
bool Transport::validate_string(string &s)
{
	getline(cin, s);
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			if (i == s.length() - 1)
			{
				return true;
			}
			continue;
		}
		if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
		{
			if (i == s.length() - 1)
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	return false;
}
void Transport::validate_name(string &s)
{
	while (1)
	{
		getline(cin, s);
		if (s == "Flight" || s == "Car")
		{
			break;
		}
		else
		{
			cout << "Input again Transport Name: ";
		}
	}
}
void Transport::validate_brand(string &s)
{
	while (1)
	{
		if (validate_string(s))
		{
			break;
		}
		else
		{
			cout << "Input again Brand:";
		}
	}
}
void Transport::validate_from(string &s)
{
	while (1)
	{
		if (validate_string(s))
		{
			break;
		}
		else
		{
			cout << "Input again From: ";
		}
	}
}
void Transport::validate_destination(string &s)
{
	while (1)
	{
		if (validate_string(s))
		{
			break;
		}
		else
		{
			cout << "Input agian Destination: ";
		}
	}
}
void Transport::output()
{
	cout << left << setw(20) << name << setw(20) << brand << setw(20)
		 << from << setw(20) << destination << setw(20) << time << setw(20) << cost << endl;
}
bool Transport::operator>(Transport &t)
{
	if (year > t.year)
	{
		return true;
	}
	else if (year == t.year)
	{
		if (month > t.month)
		{
			return true;
		}
		else if (month == t.month)
		{
			if (day > t.day)
			{
				return true;
			}
			else if (day == t.day)
			{
				if (hour > t.hour)
				{
					return true;
				}
			}
		}
	}
	return false;
}
bool Transport::operator < (Transport& t) {
	if (year < t.year) {
		return true;
	}
	else if (year == t.year) {
		if (month < t.month) {
			return true;
		}
		else if (month == t.month) {
			if (day < t.day) {
				return true;
			}
			else if (day == t.day) {
				if (hour < t.hour) {
					return true;
				}
			}
		}
	}
	return false;
}
void Transport::change_name(){
	string name1;
	cout<<"Input Transport Name: ";
	validate_name(name1);
	name=name1;
}
void Transport::change_brand(){
	string brand1;
	cout<<"Input Transport Brand: ";
	validate_brand(brand1);
	brand=brand1;
}
void Transport::change_from(){
	string from1;
	cout<<"Input Transport from: ";
	validate_from(from1);
	from=from1;
}
void Transport::change_destination(){
	string destination1;
	cout<<"Input Transport destination: ";
	validate_destination(destination1);
	destination=destination1;
}
void Transport::change_time(){
	string time1;
	cout<<"Input Transport time: ";
	validate_time(time1);
	time=time1;
	cout<<day<<month<<year;

}
void Transport::change_cost(){
	int cost1;
	cout<<"Input Transport destination: ";
	validate_cost(cost1);
	cost=cost1;
}
string Transport::get_name()
{
	return name;
}
string Transport::get_brand()
{
	return brand;
}
string Transport::get_from()
{
	return from;
}
string Transport::get_destination()
{
	return destination;
}
string Transport::get_time()
{
	return time;
}
int Transport::get_cost()
{
	return cost;
}

Transport::Transport(string name, string brand, string from, string destination, int cost , string time)
	: name{name}, brand{brand}, from{from}, destination{destination}, cost{cost}, time{time}
{
}
