#include "System.h"

void System::logInAccount(){
    cout << "Enter user_name and password: " << endl;
    cout << setw(10) << "user_name: "; 
    cout << setw(11) << "password: ";
}
void System::registerAccount(){

}
void System::signOut(){

}
void System::searchRoom(){

}
void System::searchVehicle(){

}
void System::listPlace(){

}
void System::validateAccount(User u1){
    
}
void System::validatePassword(User u1){

}
void System::validateName(User u1){

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