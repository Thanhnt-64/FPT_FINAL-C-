#include "System.h"

User* System::logInAccount(User &u1){
    cout << "Enter user_name and password: " << endl;
    cout << "Account: ";  u1.inputAccount();
    cout << "Password: "; u1.inputPassword();
    if(searchAccount(u1) && searchPassword(u1)){
        return &u1;
    }
    return nullptr;
}
User* System::registerAccount(User &u1){
    while(1){
        cout << setw(10) << "user_name: ";
        u1.inputAccount();
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
void System::searchRoom(){

}
void System::searchVehicle(){

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
void System::run(){
    int choice;
    cout << "Menu:" << endl;
    cout << std::setw(20) << "1. Log In" << endl;
    cout << std::setw(21) << "2. Sign Up" << endl;
    cout << "Enter the number range 1-2: ";
    cin >> choice; cin.ignore();
    
    switch (choice)
    {
    case 1:
        logInAccount();
        break;
    case 2:
        
        registerAccount();
        break;
    default:
        break;
    }
}

int main(){
    System system;
    
    return 0;
}