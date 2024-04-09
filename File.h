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
    MyTravel myTravel;
};

// Hàm để ghi dữ liệu vào tệp văn bản dưới dạng JSON
void writeJsonFile(const User& user, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Không thể mở tệp để ghi\n";
        return;
    }

    file << "{\n";
    file << "  \"account\": \"" << user.account << "\",\n";
    file << "  \"password\": \"" << user.password << "\",\n";
    file << "  \"fullname\": \"" << user.fullname << "\",\n";
    file << "  \"age\": " << user.age << ",\n";
    file << "  \"address\": \"" << user.address << "\",\n";
    file << "  \"numMember\": " << user.numMember << ",\n";
    file << "  \"myTravel\": {\n";
    file << "    \"transport\": [\n";
    for (size_t i = 0; i < user.myTravel.transports.size(); ++i) {
        const auto& transport = user.myTravel.transports[i];
        file << "      {\n";
        file << "        \"name\": \"" << transport.name << "\",\n";
        file << "        \"brand\": \"" << transport.brand << "\",\n";
        file << "        \"from\": \"" << transport.from << "\",\n";
        file << "        \"destination\": \"" << transport.destination << "\",\n";
        file << "        \"cost\": " << transport.cost << ",\n";
        file << "        \"time\": \"" << transport.time << "\"\n";
        file << "      }";
        if (i < user.myTravel.transports.size() - 1) {
            file << ",";
        }
        file << "\n";
    }
    file << "    ],\n";
    file << "    \"hotel\": [\n";
    for (size_t i = 0; i < user.myTravel.hotels.size(); ++i) {
        const auto& hotel = user.myTravel.hotels[i];
        file << "      {\n";
        file << "        \"name\": \"" << hotel.name << "\",\n";
        file << "        \"address\": \"" << hotel.address << "\",\n";
        file << "        \"typeRoom\": \"" << hotel.typeRoom << "\",\n";
        file << "        \"startTime\": \"" << hotel.startTime << "\",\n";
        file << "        \"endTime\": \"" << hotel.endTime << "\",\n";
        file << "        \"cost\": " << hotel.cost << "\n";
        file << "      }";
        if (i < user.myTravel.hotels.size() - 1) {
            file << ",";
        }
        file << "\n";
    }
    file << "    ]\n";
    file << "  }\n";
    file << "}";
}

int main() {
    // Tạo một mảng chứa 10 đối tượng dữ liệu người dùng
    std::vector<User> users;
    for (int i = 0; i < 10; ++i) {
        User user;
        user.account = "ThanhNT176";
        user.password = "ThanhNT";
        user.fullname = "Nguyen Tien Thanh";
        user.age = 22;
        user.address = "Ha Nam";
        user.numMember = 3;
        // Thêm các thông tin về myTravel vào đối tượng dữ liệu
        user.myTravel.transports.push_back(Transport{"Car", "Honda", "Ha Nam", "Ha Noi", 100000, "(xx/yy/zz/gggg)-giờ ngày-tháng-năm: string"});
        user.myTravel.transports.push_back(Transport{"Flight", "Boeing", "Ha Noi", "HCM City", 2000000, "(xx/yy/zz/gggg)-giờ ngày-tháng-năm: string"});
        user.myTravel.hotels.push_back(Hotel{"Phuong Nam", "Ha Noi", "Vip", "(xx/yy/zz/gggg)", "(xx/yy/zz/gggg)", 3000000});
        user.myTravel.hotels.push_back(Hotel{"Phuong Bac", "Ha Nam", "normal", "(xx/yy/zz/gggg)", "(xx/yy/zz/gggg)", 4000000});
        users.push_back(user);
    }

    // Ghi dữ liệu từ mảng các đối tượng dữ liệu vào tệp văn bản dưới dạng JSON
    for (int i = 0; i < 10; ++i) {
        std::string filename = "text_" + std::to_string(i) + ".txt";
        writeJsonFile(users[i], filename);
        std::cout << "Dữ liệu đã được ghi vào tệp " << filename << "." << std::endl;
    }

    return 0;
}
