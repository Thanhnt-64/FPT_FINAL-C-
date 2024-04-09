#include "System.h"

User* System::logInAccount(vector<User> &users, User &u1){
    cout << "Enter user_name and password: " << endl;
    cout << "Account: ";  u1.inputAccount();
    cout << "Password: "; u1.inputPassword();
    if(searchAccount(users, u1.getAccount()) && searchPassword(users, u1.getPassword())){
        for(int i = 0; i < users.size(); i++){
            if(users[i].getAccount() == u1.getAccount()){
                return &users[i];
            }
        }
    }
    return nullptr;
}
User* System::registerAccount(vector<User> &users, User &u1){
    while(1){
        cout << setw(10) << "user_name: ";
        u1.inputAccount();
        if(doubleCheckAccount(users, u1.getAccount())){
            cout << "This account is exited before!\n";
            cout << "Please re-enter your account!\n";
        }
        if(validateAccount(u1.getAccount()) == false){ // them check double
            cout << "The account name is not in the correct format\n";
            cout << "Please re-enter your account!\n";
        }
        else{
            break;
        }
    }
    while(1){
        cout << setw(11) << "password: ";
        u1.inputPassword();
        if(validatePassword(u1.getPassword()) == false){
            cout << "Please re-enter your account!\n";
        }
        else{
            break;
        }
    }
    users.push_back(u1);    
    return &users.back();
}
bool System::searchAccount(vector<User> &users, const string &s){
    for(auto i:users){
        if(s == i.getAccount()){
            return true;
        }
    }
    return false;
}
bool System::searchPassword(vector<User> &users, const string &s){
    for(auto i:users){
        if(s == i.getPassword()){
            return true;
        }
    }
    return false;    
}
void System::signOut(){
    System::run();
}
void System::searchRoomByPlace(vector<Travel> &travels){
    cout << "Enter your place, which you want to search: " << endl;
    string place; getline(cin, place);
    for(int i = 0; i < travels.size(); i++){
        if(travels[i].getPlace() != place){
            continue;
        }
        cout << "In the " << place << " we have some rooms: " << endl;
        for(int j = 0; j < travels[i].getHotel().size(); j++){
            cout << setw(20) << j+1 << ". " << travels[i].getHotel()[j].getName() << endl;
            for(int k = 0; k < travels[i].getHotel()[j].getRooms().size(); k++){
                cout << setw(24) << k+1 << ". " << travels[i].getHotel()[j].getRooms()[k].getName() << endl;
            }
            cout << endl;
        }
        return;
    }
    cout << "We are updating new infomation for this place!\n";
    cout << "You can choose some similar places!\n";
}
    
void System::searchVehicleByPlace(vector<Travel> &travels){
    cout << "Enter your place, which you want to search: " << endl;
    string place; getline(cin, place);
    for(int i = 0; i < travels.size(); i++){
        if(travels[i].getPlace() != place){
            continue;
        }
        cout << "In the " << place << " we have some vehicles: " << endl;
        for(int j = 0; j < travels[i].getTransport().size(); j++){
            cout << setw(20) << j  << travels[i].getTransport()[j].get_name() << endl;
        }
        return;
    }
    cout << "We are updating new infomation for this place!\n";
    cout << "You can choose some similar places!\n";
}
void System::listPlace(vector<Travel> &travels){
    cout << "Our system support the following places: " << endl;
    for(int i = 0; i < travels.size(); i++){
        cout << setw(20) << i << travels[i].getPlace() << endl;
    }
    cout << "__________________________________________________\n";
}
bool System::validateAccount(const string &s){
    for (auto i : s){
        if((i < 48 || (i > 57 && i < 65) ||( i > 90 && i < 97 )|| i > 122)){
            return false;
        }
    }
    return true;
}
bool System::validatePassword(const string &s){
    int numNums = 0;
    int numLower = 0;
    int numUpper = 0;
    int numSpecial = 0;
    if(s.length() < 8){
        cout << "Password length is at least 8 characters\n";
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
    cout << "Password includes an uppercase, lowercase, number, and special character (! # $ % & @)!!\n";
    return false;    
}
bool System::validateName(const string &s){
    for(auto i:s){
        if(i == 32){
            continue;
        }
        if((i < 65 || (i > 90 && i < 97) || i > 122)){
            cout << "Invalid name!\n";
            return false;
        }
    }
    return true; 
}
bool System::doubleCheckAccount(vector<User> &users, const string &s){
    int r = users.size() - 1;
    int l = 0;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(s == users[mid].getAccount()){
            return true;
        }
        if(s < users[mid].getAccount()){
            r = mid - 1;
        }
        if(s > users[mid].getAccount()){
            l = mid + 1;
        }
    }
    return false;
}
void System::run(){
    
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


static int parition(vector<float> &m_list, int low, int high){
    float pivot = m_list[high];
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
void sortWithTime(vector<float> &m_list, int low, int high){
    if(low < high){
        int pi = parition(m_list, low, high);
        sortWithTime(m_list, low, pi - 1);
        sortWithTime(m_list, pi + 1, high);
    }
}

