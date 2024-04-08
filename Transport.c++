#include "Transport.h"


void Transport::input(){
	cout << "Input vehicle name: ";
	validate_name(name);
	cout << "Input brand: ";
	validate_brand(brand);
	cout << "Input from: ";
	validate_from(from);
	cout << "Input destination: ";
	validate_destination(destination);
	cout << "Input time(hh/dd/mm/yyyy): ";
	validate_time();
    cout<<"Input cost: ";
    validate_cost();
}
void Transport::validate_cost(){
    while(1){
        if(cin>>cost){
            break;
        }
        else{
            cout<<"Input cost: ";
            cin.clear(); // Xóa cờ lỗi
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // Xóa bộ nhớ đệm
        }
    }
}
void Transport::validate_time() {
	while (1) {
		getline(cin, time);
		if (time.length() != 13) {
			cout << "Input time" << endl;
			continue;
		}
		if (time[2] != '/' || time[5] != '/' || time[8] != '/') {
			cout << "Input time: ";
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

		cout << "input time: ";
	}
}
bool Transport::validate_string(string &s) {
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
        if(s[i] == ' '){
            if(i==s.length()-1){
                 return true;
               }
            continue;
        }
		if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
			if (i == s.length() - 1) {
				return true;
			}
		}
        else{
            return false;
        }   
    } 
    return false;	
}
void Transport::validate_name(string &s){
    while(1){
        if(validate_string(s)){
            break;
        }
        else{
            cout<<"Input again name: ";
        }
    }
}
void Transport::validate_brand(string &s){
    while(1){
        if(validate_string(s)){
            break;
        }
        else{
            cout<<"Input again brand:";
        }
    }
}
void Transport::validate_from(string &s){
    while(1){
        if(validate_string(s)){
            break;
        }
        else{
            cout<<"Input again from: ";
        }
    }
}
void Transport::validate_destination(string &s){
    while(1){
        if(validate_string(s)){
            break;
        }
        else{
            cout<<"Input agian destination: ";
        }
    }
}
void Transport::output(){
    cout<<left<<setw(20)<<name<<setw(20)<<brand<<setw(20)
        <<from<<setw(20)<<destination<<setw(20)<<time<<setw(25)<<cost<<endl;
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

int main(){
    Transport t;
    t.input();
    t.output();

}
