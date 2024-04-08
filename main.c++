#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <sstream>

using namespace std;

class Time {
private:
    int hour;
    int day;
    int month;
    int year;

public:
    Time(){}
    Time(string timeInput) {
        stringstream ss(timeInput);
        char delimiter;

        ss >> hour >> delimiter >> day >> delimiter >> month >> delimiter >> year;

        // Kiểm tra lỗi dữ liệu đầu vào nếu cần
        if (ss.fail() || ss.get() != EOF) {
            cerr << "Invalid input format!" << endl;
            // Xử lý ngoại lệ tùy theo yêu cầu
        }
    }

    void displayTime() {
        cout << hour << " : " << day << " : " << month << " : " << year << endl;
    }
    friend bool operator<(const Time &t1, const Time &t2);
    friend bool operator>(const Time &t1, const Time &t2);
    friend bool operator==(const Time &t1, const Time &t2);
    friend istream &operator>>(istream &in, Time &t2);
};

istream &operator>>(istream &in, Time &t2){
    char delimiter;
        in >> t2.hour >> delimiter >> t2.day 
            >> delimiter >> t2.month >> delimiter >> t2.year;
    return in;
}
bool operator<(const Time &t1, const Time &t2) {
    if(t1.year < t2.year) return true;
    if(t1.year == t2.year) {
        if(t1.month < t2.month) return true;
        if(t1.month == t2.month) {
            if(t1.day < t2.day) return true;
            if(t1.day == t2.day) {
                if(t1.hour < t2.hour) return true;
            }
        }
    }
    return false;
}

bool operator>(const Time &t1, const Time &t2) {
    if(t1.year > t2.year) return true;
    if(t1.year == t2.year) {
        if(t1.month > t2.month) return true;
        if(t1.month == t2.month) {
            if(t1.day > t2.day) return true;
            if(t1.day == t2.day) {
                if(t1.hour > t2.hour) return true;
            }
        }
    }
    return false;
}
bool operator==(const Time &t1, const Time &t2) {
    if(t1.year == t2.year && t1.month == t2.month && t1.day == t2.day && t1.hour == t2.hour) 
    {
        return true;
    }
    return false;
}

bool checkFormat(string s){
    if(s.length() != 13){
        cout << "Sai format\n";
        return false;
    }
    if(s[2] != '/' || s[5] != '/' || s[8] != '/'){
        return false;
    }
    for(auto i:s){
        if (i == '/'){
            continue;
        }
        if(i < 48 || i > 57)
        {
            return false;
        }
    }
    return true;
}
bool validateCheckAge(const int &age){
    if(age < 1 || age > 100){
        cout << "Tuoi khong hop le\n";
        return false;
    }
    if(age < 16 || age > 80){
        cout << "Ban chua du tuoi hoac qua gia de su dung dich vu\n";
        return false;
    }
    return true;
}
bool validateCheckName(const string &s){
    for(auto i:s){
        if(i == 32){
            continue;
        }
        if((i < 65 || (i > 90 && i < 97) || i > 122)){
            cout << "Ten khong hop le\n";
            return false;
        }
    }
    return true;
}

/* Using Binary Search*/
bool doubleCheckAccount(const string &s, vector<string> &m_list){
    int r = m_list.size() - 1;
    int l = 0;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(s == m_list[mid]){
            return true;
        }
        if(s < m_list[mid]){
            r = mid - 1;
        }
        if(s > m_list[mid]){
            l = mid + 1;
        }
    }
    return false;
}

bool validateCheckAccount(const string &s){
    for (auto i : s){
        if((i < 48 || (i > 57 && i < 65) ||( i > 90 && i < 97 )|| i > 122)){
            return false;
        }
    }
    return true;
}
bool validateCheckPassword(const string &s){
    int numNums = 0;
    int numLower = 0;
    int numUpper = 0;
    int numSpecial = 0;
    if(s.length() < 8){
        cout << "Do dai mat khau it nhat la 8 ky tu\n";
        return false;
    }
    for(auto i:s){
        if(i >= 48 && i <= 57){
            numNums++;
        }
        if(i >= 65 && i <= 90){
            numUpper++;
        }
        if(i >= 97 && i <= 122){
            numLower++;
        }
        if(i == 33 || (i >= 35 && i <= 38) || i == 64){
            numSpecial++;
        }
    }
    if(numNums && numUpper && numLower &&numSpecial){
        return true;
    }
    cout << "Password bao gom it nhat 1 ky tu hoa, 1 ky tu thuong, 1 ky tu so va 1 ky tu dac biet (! # $ % & @)\n";
    return false;
}


void searchHotelInPlace(vector<string> &m_list){

}
void searchVehicleInPlace(vector<string> &m_list){

}
/* Using quick sort*/
static int parition(vector<Time> &m_list, int low, int high){
    Time pivot = m_list[high];
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && m_list[left] < pivot) left ++;
        while(left <= right && m_list[right] > pivot) right ++;
        if(left > right){
            break;
        }
        swap(m_list[left], m_list[right]);
        left ++;
        right --;
    }
    swap(m_list[left], m_list[right]);
    return left;
}
void sortWithTime(vector<Time> &m_list, int low, int high){
    if(low < high){
        int pi = parition(m_list, low, high);
        sortWithTime(m_list, low, pi - 1);
        sortWithTime(m_list, pi + 1, high);
    }
}

static int partitionInt(vector<int> &m_list, int low, int high){
    int pivot = m_list[high];
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && m_list[left] < pivot) left++;
        while(left <= right && m_list[right] > pivot) right--;
        if(left >= right) break;
        swap(m_list[left], m_list[right]);
        left++;
        right--;
    }
    swap(m_list[left], m_list[high]);
    return left;
}

void sortWithCost(vector<int> &m_list, int low, int high){
    if(low < high){
        int pi = partitionInt(m_list, low, high);
        sortWithCost(m_list, low, pi - 1);
        sortWithCost(m_list, pi + 1, high);
    }
}

/* bubble sort*/

int main(){
    vector<Time> mylist;
    Time s;
    for(int i = 0; i < 10; i++){
        cout << "Nhap phan tu thu " << i << " : ";
        cin >> s;
        mylist.push_back(s);
    }
    cout << endl << endl;
    sortWithTime(mylist, 0, mylist.size() - 1);
    for(auto i:mylist){
        cout << i << " " << endl;
    }
    return 0;
}