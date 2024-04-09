#include "System.h"

User* System::logInAccount(User &u1){
    cout << "Enter user_name and password: " << endl;
    cout << "Account: ";  u1.inputAccount();
    cout << "Password: "; u1.inputPassword();
    if(searchAccount(u1.getAccount()) && searchPassword(u1.getPassword())){
        auto it = std::find(users.begin(), users.end(), u1);
        return (it != users.end()) ? &u1 : nullptr;
    }
    return nullptr;
}
User* System::registerAccount(User &u1){
    while(1){
        cout << setw(10) << "user_name: ";
        u1.inputAccount();
        if(doubleCheckAccount(u1.getAccount())){
            cout << "Tai khoan da ton tai truoc do\n";
            cout << "Moi ban nhap lai tai khoan\n";
        }
        if(validateAccount(u1.getAccount()) == false){ // them check double
            cout << "Ten tai khoan khong dung dinh dang\n";
            cout << "Moi ban nhap lai\n";
        }
        else{
            break;
        }
    }
    while(1){
        cout << setw(11) << "password: ";
        u1.inputPassword();
        if(validatePassword(u1.getPassword()) == false){
            cout << "Moi ban nhap lai\n";
        }
        else{
            break;
        }
    }
    users.push_back(u1);    
    return &users.back();
}
bool System::searchAccount(const string &s){
    for(auto i:users){
        if(s == i.getAccount()){
            return true;
        }
    }
    return false;
}
bool System::searchPassword(const string &s){
    for(auto i:users){
        if(s == i.getPassword()){
            return true;
        }
    }
    return false;    
}
void System::signOut(){

}
void System::searchRoomByPlace(const string &s){
    // for(auto i:travels){
    //     if(i.getPlace() == s){
    //         for(auto j:i.getPlace()){
    //             cout << j.getName() << endl;
    //         }
    //     }
    // }
    // cout << "Cac Hotel tai " << s << " la: " << endl;
    
}
void System::searchVehicleByPlace(){

}
void System::listPlace(){

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
bool System::validateName(const string &s){
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
bool System::doubleCheckAccount(const string &s){
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

int main(){
    
    return 0;
}