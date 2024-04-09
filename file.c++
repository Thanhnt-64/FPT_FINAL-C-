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



// Hàm để ghi dữ liệu vào tệp văn bản
void writeToFile(const std::vector<User>& users, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Can't open file to write\n";
        return;
    }

    for (const auto& user : users) {
        file << "{\n";
        file << "  \"account\": \"" << user.account << "\",\n";
        file << "  \"password\": \"" << user.password << "\",\n";
        file << "  \"fullname\": \"" << user.fullname << "\",\n";
        file << "  \"age\": " << user.age << ",\n";
        file << "  \"address\": \"" << user.address << "\",\n";
        file << "  \"numMember\": " << user.numMember << ",\n";
        file << "  \"myTravel\": {\n";
        file << "    \"transport\": [\n";
        for (const auto& transport : user.myTravel.transports) {
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

        for (const auto& hotel : user.myTravel.hotels) {
            file << "hotel\n";
            file << hotel.name << "\n";
            file << hotel.address << "\n";
            file << hotel.typeRoom << "\n";
            file << hotel.startTime << "\n";
            file << hotel.endTime << "\n";
            file << hotel.cost << "\n";
        }
    }

    std::cout << "Data is save to file: " << filename << "." << std::endl;
}

// Hàm để đọc dữ liệu từ tệp văn bản
std::vector<User> readFromFile(const std::string& filename) {
    std::vector<User> users;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "File can not open to read\n";
        return users;
    }
    User user;
    Transport transport;
    Hotel hotel;
    std::string line;
    while (std::getline(file, line)) {
        user.account = line;
        std::getline(file, user.password);
        std::getline(file, user.fullname);
        file >> user.age;
        file.ignore(); // Loại bỏ ký tự '\n'
        std::getline(file, user.address);
        file >> user.numMember;
        file.ignore(); // Loại bỏ ký tự '\n'

        while (std::getline(file, line)) {
            if (line == "transport") {
                Transport transport;
                std::getline(file, transport.name);
                std::getline(file, transport.brand);
                std::getline(file, transport.from);
                std::getline(file, transport.destination);
                file >> transport.cost;
                file.ignore(); // Loại bỏ ký tự '\n'
                std::getline(file, transport.time);
                user.myTravel.transports.push_back(transport);
            } else if (line == "hotel") {
                Hotel hotel;
                std::getline(file, hotel.name);
                std::getline(file, hotel.address);
                std::getline(file, hotel.typeRoom);
                std::getline(file, hotel.startTime);
                std::getline(file, hotel.endTime);
                file >> hotel.cost;
                file.ignore(); // Loại bỏ ký tự '\n'
                user.myTravel.hotels.push_back(hotel);
            }
        }

        users.push_back(user);
        user.myTravel.transports.clear();
        user.myTravel.hotels.clear();
    }

    std::cout << "Data is read from file: " << filename << "." << std::endl;
    return users;
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

    // Ghi dữ liệu vào tệp văn bản
    writeToFile(users, "text.txt");

    // Đọc dữ liệu từ tệp văn bản
    std::vector<User> readUsers = readFromFile("text.txt");

    return 0;
}
