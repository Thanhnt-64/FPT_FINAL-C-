#include "Transport.h"


void Transport::input(){
	cout << "input vehicle name: ";
	validate(name);
	cout << "input brand: ";
	validate(brand);
	cout << "input from: ";
	validate(from);
	cout << "input destination: ";
	validate(destination);
	cout << "nhap thoi gian(hh/dd/mm/yyyy): ";
	validate_time();
	
}

void Transport::validate_time() {
	while (1) {
		getline(cin, time);
		if (time.length() != 13) {
			cout << "nhap lai" << endl;
			continue;
		}
		if (time[2] != '/' || time[5] != '/' || time[8] != '/') {
			cout << "nhap lai: ";
			continue;
		}

		for (int i = 0; i < time.length(); i++) {
			if (i != 2 || i != 5 || i != 8) {
				if (time[i] < '0' || time[i]>'9') {
					break;
				}

			}
		}
		int sum = 0, temp1 = 1, count = 0;
		for (int i = time.length() - 1; i >= 0; i--) {
			if (time[i] == '/') {
				count++;
				if (count == 1) {
					year = sum;
				}
				if (count == 2) {
					month = sum;
					if (sum > 12 || sum < 0) {

						break;
					}
				}

				if (count == 3) {
					if ((sum > 30 || sum < 0) && (month == 4 || month == 6 || month == 9 || month == 11)) {

						break;
					}
					if ((sum > 31 || sum < 0) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8)) {

						break;
					}
					if (year % 4 == 0 && sum > 29 && month == 2) {
						break;
					}
					if (year % 4 == 1 && sum > 28 && month == 2) {
						break;
					}
				}
				day = sum;
				sum = 0;
				temp1 = 1;

			}
			else
			{
				if (i == 0) {
					count++;
				}
				sum += ((int)time[i] - 48) * temp1;
				temp1 *= 10;
			}
		}
		if (count == 4 && sum <= 24) {
			hour = sum;
			break;
		}

		cout << "nhap lai: ";
	}
}
void Transport::validate(string &s) {
	while (1) {
		getline(cin, s);
		for (int i = 0; i < s.length(); i++) {
            if(s[i] == ' '){
                if(i==s.length()-1){
                    return;
                }
                continue;
            }
			if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
				if (i == s.length() - 1) {
					return;
				}
			}
			else {
				cout << "nhap lai : ";
				break;
			}
		}
        
	}
}
void Transport::output(){
    cout<<left<<setw(25)<<name<<setw(25)<<brand<<setw(25)
        <<from<<setw(25)<<destination<<setw(25)<<time<<endl;
}
bool Transport::operator > (Transport& t) {
	if (year > t.year) {
		return true;
	}
	else if (year == t.year) {
		if (month > t.month) {
			return true;
		}
		else if (month == t.month) {
			if (day > t.day) {
				return true;
			}
			else if (day == t.day) {
				if (hour > t.hour) {
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

int main()
{
	Transport t;
	t.input();
	t.output();
}

