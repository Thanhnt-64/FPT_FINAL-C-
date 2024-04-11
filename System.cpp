#include "Lib/System.h"
#include "Lib/File.h"

User* System::logInAccount(vector<User> &users, User &u1){
    cout << "Account: "; u1.inputAccount();
    cout << "Password: "; u1.inputPassword();
    if(searchAccount(users, u1.getAccount()) && searchPassword(users, u1.getPassword())){
        for(int i = 0; i < users.size(); i++){
            if(users[i].getAccount() == u1.getAccount()){
                return &users[i];
            }
        }
    }
    else{
        cout << "Wrong account or password!\n";
        logInAccount(users, u1);
    }
    return nullptr;
}
bool System::logInAccount(){
    string passsword;
    char chek;
    while(1){
        cout << "Enter admin password: ";
        getline(cin, passsword);
        if(passsword == "Amin1234@"){
            return true;
        }
        else{
            cout << "Wrong password!" << endl;
            cout << "Do you want to continue?(Y/N): ";
            cin >> chek; cin.ignore();
            if(chek == 'Y' || chek == 'y'){
                continue;
            }
            else{
                return false;
            }
        }
    }
}
User* System::registerAccount(vector<User> &users, User &u1){
    while(1){
        cout << setw(10) << (string)("user_name: ");
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
        cout << setw(10) << (string)("password: ");
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
    
}
void System::searchRoomByPlace(vector<Travel> &travels){
    char chark;
    cout << "Enter your place, which you want to search: " << endl;
    string place; getline(cin, place);
    for(int i = 0; i < travels.size(); i++){
        if(travels[i].getPlace() != place){
            continue;
        }
        cout << setw(20) << "In the " << place << " we have some rooms: " << endl;
        for(int j = 0; j < travels[i].getHotel().size(); j++){
            cout << setw(20) << j+1 << ". " << travels[i].getHotel()[j].getName() << endl;
            for(int k = 0; k < travels[i].getHotel()[j].getRooms().size(); k++){
                cout << setw(24) << k+1 << ". " << travels[i].getHotel()[j].getRooms()[k].getName() << endl;
            }
            cout << endl;
            cout << "Enter 0 to exit: ";
            cin >> chark; cin.ignore();
            if(chark == '0'){
                return;
            }
            else{
                searchRoomByPlace(travels);
            }
        }
        return;
    }    
}
    
void System::searchVehicleByPlace(vector<Travel> &travels){
    char chark;
    cout << setw(20) << "Enter your place, which you want to search: " << endl;
    string place; getline(cin, place);
    for(int i = 0; i < travels.size(); i++){
        if(travels[i].getPlace() != place){
            continue;
        }
        cout << setw(20) << "In the " << place << " we have some vehicles: " << endl;
        for(int j = 0; j < travels[i].getTransport().size(); j++){
            cout << setw(20) << j  << travels[i].getTransport()[j].get_name() << endl;
        }
        cout << endl;
        cout << "Enter 0 to exit: ";
        cin >> chark; cin.ignore();
        if(chark == '0'){
            return;
        }
        else{
            searchVehicleByPlace(travels);
        }
        return;
    }
}

void System::searchByPlace(vector<Travel> &travels){
    char choose;
    while(1){
        system("cls");
        cout << setw(20) << "1. Search room by place" << endl;
        cout << setw(20) << "2. Search vehicle by place" << endl;
        cout << "3. Back" << endl;
        cout << setw(20) << "Enter your choose: 1-3:__";
        cin >> choose; cin.ignore();
        switch(choose){
        case '1':
            searchRoomByPlace(travels);
            break;
        case '2':
            searchVehicleByPlace(travels);
            break;
        case '3':
            return;
        default:
            break;
        }
    }
}
void System::listPlace(vector<Travel> &travels){
    cout << setw(20) << "Our system support the following places: " << endl;
    for(int i = 0; i < travels.size(); i++){
        cout << setw(20) << i+1 << travels[i].getPlace() << endl;
        
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
        cout<< setw(20) << "Password length is at least 8 characters\n";
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
    cout << setw(20) << "Password includes an uppercase, lowercase, number, and special character (! # $ % & @)!!\n";
    return false;    
}
bool System::validateName(const string &s){
    for(auto i:s){
        if(i == 32){
            continue;
        }
        if((i < 65 || (i > 90 && i < 97) || i > 122)){
            cout << setw(20) << "Invalid name!\n";
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

void showChangeUserSwitch(vector<User> &users){
    system("cls");
    Admin &admin = Admin::getInstance();
    int choose;
    char chak;
    cout << setw(20) << (string)("1. Show Information") << endl;
    cout << setw(20) << (string)("2. Change Information") << endl;
    cout << setw(20) << (string)("3. Delete a specific user") << endl;
    cout << setw(20) << (string)("Enter your choose: 1-3:__");
    cin >> choose; cin.ignore();
    system("cls");
    switch (choose)
    {
    case 1:
        admin.showListInfoUser(users);
        break;
    case 2:
        admin.changeUser(users);
        break;
    case 3:
        admin.deleteAccountUser(users);
        break;
    default:
        cout << setw(20) << (string)("Choose wrong, Enter again!") << endl;
        showChangeUserSwitch(users);
    }
    cout << (string)("Enter any key to continue:\n");
    cin >> chak; cin.ignore();
}

void showChangeServiceSwitch(vector<Travel> &travels){
    system("cls");
    Admin &admin = Admin::getInstance();
    int choose; char chak;
    cout << setw(20) << "1. Show Information" << endl;
    cout << setw(20) << "2. Change Transport Information" << endl;
    cout << setw(20) << "3. Change Room Information" << endl;
    cout << setw(20) << "Enter your choose: 1-3:__";
    cin >> choose; cin.ignore();
    system("cls");
    switch (choose)
    {
    case 1:
        admin.viewServiceInfo(travels);
        break;
    case 2:
        admin.editTransportInfo(travels);
        break;
    case 3:
        admin.editHotelInfo(travels);
        break;
    default:
        cout << "Choose wrong, Enter again!" << endl;
        showChangeServiceSwitch(travels);
    }
    cout << (string)("Enter any key to continue:\n");
    cin >> chak; cin.ignore();
}

void System::runAdmin(vector<Travel> &travels, vector<User> &users){
    Admin &admin = Admin::getInstance();
    while(1){
        system("cls");
        listPlace(travels);
        int choose;
        cout << setw(20) << "0. Exit" << endl;
        cout << setw(20) << "1. Show/Change Users's infomation" << endl;
        cout << setw(20) << "2. Show/Change Service's infomation" << endl;
        cout << setw(20) << "3. Search room/vehicle by place" << endl;
        cout << setw(20) << "4. Sort data follow time and cost" << endl;
        cout << "Enter your choose: 1-5:__";
        cin >> choose; cin.ignore();
        system("cls");
        switch(choose){
            case 0:
                return;
            case 1:
                showChangeUserSwitch(users);
                break;
            case 2:
                showChangeServiceSwitch(travels);
                break;
            case 3:
                searchByPlace(travels);
                break;
            case 4:
                listPlace(travels);
                sortTravel(travels);
                break;
            default:
                cout << "Choose wrong, Enter again!" << endl;
                break;
        }
        admin.saveData(users, travels);
        admin.loadData(users, travels);
    }
}
void showChangeInfo(User *user){
    char a;
    user->changeInfo();
    user->showUserInfo();
    cout << "Enter any charactor (0 to exit)?__";
    cin >> a; cin.ignore();
    if(a == '0'){
        return;
    }
    else{
        showChangeInfo(user);
    }
}

void showChangeTravel(User *user){
    char chek;
    cout << "1. Show travel Infomation" << endl;
    cout << "2. Change travel Infomation" << endl;
    cout << "3. Back" << endl;
    cin >> chek; cin.ignore();
    switch (chek)
    {
    case '1':
        user->showTravelInfo();
        break;
    case '2':
        user->changeTravelInfo();
        break;
    case '3':
        return;
    default:
        system("cls");
        showChangeTravel(user);
    }
    showChangeTravel(user);
}

void System::run(vector<Travel> &travels, User *user){
    while(1){
        system("cls");
        listPlace(travels);
        int choose;
        cout << "0. Exit" << endl;
        cout << setw(20) << "1. Change your information" << endl;
        cout << setw(20) << "2. Show/Change current booking travel" << endl;
        cout << setw(20) << "3. Delete the travel" << endl;
        cout << setw(20) << "4. Search room/vehicle by place" << endl;
        cout << setw(20) << "5. Sort data follow time and cost" << endl;
        cout << "Enter your choose: 1-5:__";
        cin >> choose; cin.ignore();
        switch(choose){
            case 0: 
                return;
            case 1:
                showChangeInfo(user);
                break;
            case 2:
                showChangeTravel(user);
                break;
            case 3:
                user->cancelTravel();
                break;
            case 4:
                searchByPlace(travels);
                break;
            case 5:
                listPlace(travels);
                sortTravel(travels);
                break;
            default:
                cout << "Choose wrong, Enter again!" << endl;
                break;
        }
    }    
}
static int partitionInt(vector<Hotel> &hotel, int low, int high){
    int pivot = hotel[high].getTotalCost();
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && hotel[left].getTotalCost() < pivot) left++;
        while(left <= right && hotel[right].getTotalCost() > pivot) right--;
        if(left >= right) break;
        swap(hotel[left], hotel[right]);
        left++;
        right--;
    }
    swap(hotel[left], hotel[high]);
    return left;
}

void sortWithCost(vector<Hotel> &hotel, int low, int high){
    if(low < high){
        int pi = partitionInt(hotel, low, high);
        sortWithCost(hotel, low, pi - 1);
        sortWithCost(hotel, pi + 1, high);
    }
}

// static vector<Transport>& getAllTransport(vector<Travel> &travels){
//     static vector<Transport> allTransport;
//     allTransport.clear();
//     for(int i = 0; i < travels.size(); i++){
//         for(int j = 0; j < travels[i].getTransport().size(); j++){
//             allTransport.push_back(travels[i].getTransport()[j]);
//         }
//     }
//     return allTransport;
// }
static int paritionTime(vector<Transport> &trans, int low, int high){
    Transport pivot = trans[high];
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && trans[left] < pivot) left++;
        while(left <= right && trans[right] > pivot) right--;
        if(left >= right) break;
        swap(trans[left], trans[right]);
        left++;
        right--;
    }
    swap(trans[left], trans[high]);
    return left;
}
void sortWithTime(vector<Transport> &trans, int low, int high){
    if(low < high){
        int pi = paritionTime(trans, low, high);
        sortWithTime(trans, low, pi - 1);
        sortWithTime(trans, pi + 1, high);
    }
}

void sortTravel(vector<Travel> &travels){
    char chak;
    if (travels.empty()) {
        cout << "No travels to sort." << endl;
        return;
    }
    cout << "1. Sort hotel with cost" << endl;
    cout << "2. Sort transport with time" << endl;
    cin >> chak; cin.ignore();
    switch (chak)
    {
    case '1':
        for(int i = 0; i < travels.size(); i++){
            auto hotel = travels[i].getHotel();
            if(!hotel.empty()){
                cout << "Sort hotel in " << travels[i].getPlace() << endl;
                sortWithCost(hotel, 0, (hotel.size() - 1));
                for(auto i:hotel){
                    i.showRoomInfo();
                }
                cout << "___________________________________\n";
            }
        }
        break;
    case '2':
        for(int i = 0; i < travels.size(); i++){
            auto transports = travels[i].getTransport();
            cout << "Sort transport in " << travels[i].getPlace() << endl;
            if(transports.empty()){
                sortWithTime(transports, 0, (transports.size() - 1));
                for(auto i:transports){
                    i.output();
                }
                cout << "___________________________________\n";
            }
        }
        break;
    default:
        break;
    }
    cout << "Enter any key to Exit: ";
    cin >> chak; cin.ignore();
    if(chak == '0'){
        return;
    }
}