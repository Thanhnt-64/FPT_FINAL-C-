#include <iostream>
#include <fstream>
#include <string>
#include <vector>


// Định nghĩa cấu trúc cho các phần tử trong travel
struct Transport {
    std::string name;
    std::string brand;
    std::string from;
    std::string destination;
    int cost;
    std::string time;
};

struct Hotel {
    std::string name;
    std::string address;
    std::string typeRoom;
    std::string startTime;
    std::string endTime;
    int cost;
};

struct MyTravel {
    std::vector<Transport> transports;
    std::vector<Hotel> hotels;
};

struct User {
    std::string account;
    std::string password;
    std::string fullname;
    int age;
    std::string address;
    int numMember;
    std::vector<MyTravel> myTravels;
};

// Hàm để ghi dữ liệu vào tệp văn bản dưới dạng JSON
void writeJsonFile(const std::vector<User>& users, const std::string& filename) {
    json j;
    for (const auto& user : users) {
        json userJson;
        userJson["account"] = user.account;
        userJson["password"] = user.password;
        userJson["fullname"] = user.fullname;
        userJson["age"] = user.age;
        userJson["address"] = user.address;
        userJson["numMember"] = user.numMember;

        std::vector<json> myTravelsJson;
        for (const auto& myTravel : user.myTravels) {
            json myTravelJson;
            std::vector<json> transportsJson;
            for (const auto& transport : myTravel.transports) {
                json transportJson;
                transportJson["name"] = transport.name;
                transportJson["brand"] = transport.brand;
                transportJson["from"] = transport.from;
                transportJson["destination"] = transport.destination;
                transportJson["cost"] = transport.cost;
                transportJson["time"] = transport.time;
                transportsJson.push_back(transportJson);
            }
            myTravelJson["transport"] = transportsJson;

            std::vector<json> hotelsJson;
            for (const auto& hotel : myTravel.hotels) {
                json hotelJson;
                hotelJson["name"] = hotel.name;
                hotelJson["address"] = hotel.address;
                hotelJson["typeRoom"] = hotel.typeRoom;
                hotelJson["startTime"] = hotel.startTime;
                hotelJson["endTime"] = hotel.endTime;
                hotelJson["cost"] = hotel.cost;
                hotelsJson.push_back(hotelJson);
            }
            myTravelJson["hotel"] = hotelsJson;

            myTravelsJson.push_back(myTravelJson);
        }
        userJson["myTravel"] = myTravelsJson;

        j.push_back(userJson);
    }

    std::ofstream file(filename);
    if (file.is_open()) {
        file << j.dump(4); // pretty print with 4 spaces indentation
        std::cout << "Dữ liệu đã được ghi vào tệp " << filename << "." << std::endl;
    } else {
        std::cerr << "Không thể mở tệp để ghi\n";
    }
}

// Hàm để đọc dữ liệu từ tệp văn bản dưới dạng JSON và lưu vào mảng Users
std::vector<User> readJsonFile(const std::string& filename) {
    std::vector<User> users;

    std::ifstream file(filename);
    if (file.is_open()) {
        json j;
        file >> j;

        for (const auto& userJson : j) {
            User user;
            user.account = userJson["account"];
            user.password = userJson["password"];
            user.fullname = userJson["fullname"];
            user.age = userJson["age"];
            user.address = userJson["address"];
            user.numMember = userJson["numMember"];

            for (const auto& myTravelJson : userJson["myTravel"]) {
                MyTravel myTravel;
                for (const auto& transportJson : myTravelJson["transport"]) {
                    Transport transport;
                    transport.name = transportJson["name"];
                    transport.brand = transportJson["brand"];
                    transport.from = transportJson["from"];
                    transport.destination = transportJson["destination"];
                    transport.cost = transportJson["cost"];
                    transport.time = transportJson["time"];
                    myTravel.transports.push_back(transport);
                }
                for (const auto& hotelJson : myTravelJson["hotel"]) {
                    Hotel hotel;
                    hotel.name = hotelJson["name"];
                    hotel.address = hotelJson["address"];
                    hotel.typeRoom = hotelJson["typeRoom"];
                    hotel.startTime = hotelJson["startTime"];
                    hotel.endTime = hotelJson["endTime"];
                    hotel.cost = hotelJson["cost"];
                    myTravel.hotels.push_back(hotel);
                }
                user.myTravels.push_back(myTravel);
            }

            users.push_back(user);
        }

        std::cout << "Dữ liệu đã được đọc từ tệp " << filename << "." << std::endl;
    } else {
        std::cerr << "Không thể mở tệp để đọc\n";
    }

    return users;
}

int main() {
    // Tạo một mảng chứa 1 đối tượng dữ liệu người dùng
    std::vector<User> users;
    User user;
    user.account = "ThanhNT176";
    user.password = "ThanhNT";
    user.fullname = "Nguyen Tien Thanh";
    user.age = 22;
    user.address = "Ha Nam";
    user.numMember = 3;

    MyTravel myTravel;
    Transport transport1;
    transport1.name = "Car";
    transport1.brand = "Honda";
    transport1.from = "Ha Nam";
    transport1.destination = "Ha Noi";
    transport1.cost = 100000;
    transport1.time = "(xx/yy/zz/gggg)-giờ ngày-tháng-năm: string";

    Transport transport2;
    transport2.name = "Flight";
    transport2.brand = "Boeing";
    transport2.from = "Ha Noi";
    transport2.destination = "HCM City";
    transport2.cost = 2000000;
    transport2.time = "(xx/yy/zz/gggg)-giờ ngày-tháng-năm: string";

    myTravel.transports.push_back(transport1);
    myTravel.transports.push_back(transport2);

    Hotel hotel1;
    hotel1.name = "Phuong Nam";
    hotel1.address = "Ha Noi";
    hotel1.typeRoom = "Vip";
    hotel1.startTime = "(xx/yy/zz/gggg)";
    hotel1.endTime = "(xx/yy/zz/gggg)";
    hotel1.cost = 3000000;

    Hotel hotel2;
    hotel2.name = "Phuong Bac";
    hotel2.address = "Ha Nam";
    hotel2.typeRoom = "normal";
    hotel2.startTime = "(xx/yy/zz/gggg)";
    hotel2.endTime = "(xx/yy/zz/gggg)";
    hotel2.cost = 4000000;

    myTravel.hotels.push_back(hotel1);
    myTravel.hotels.push_back(hotel2);

    user.myTravels.push_back(myTravel);
    users.push_back(user);

    // Ghi dữ liệu từ mảng các đối tượng dữ liệu vào tệp văn bản dưới dạng JSON
    std::string filename = "data.txt";
    writeJsonFile(users, filename);

    // Đọc dữ liệu từ tệp văn bản dưới dạng JSON và lưu vào mảng Users
    std::vector<User> readUsers = readJsonFile(filename);

    return 0;
}
