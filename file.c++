#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Định nghĩa cấu trúc cho các phần tử trong travel
struct Transport
{
    std::string name;
    std::string brand;
    std::string from;
    std::string destination;
    int cost;
    std::string time;
};

struct Hotel
{
    std::string name;
    std::string address;
    std::string typeRoom;
    std::string startTime;
    std::string endTime;
    int cost;
};

struct MyTravel
{
    std::vector<Transport> transports;
    std::vector<Hotel> hotels;
};

struct User
{
    std::string account;
    std::string password;
    std::string fullname;
    int age;
    std::string address;
    int numMember;
    MyTravel myTravel;
};

// Hàm để ghi dữ liệu vào tệp văn bản dưới dạng JSON
void singlewriteJsonFile(const User &user, fstream &target_file)
{

    target_file << "{\n";
    target_file << "  \"account\": \"" << user.account << "\",\n";
    target_file << "  \"password\": \"" << user.password << "\",\n";
    target_file << "  \"fullname\": \"" << user.fullname << "\",\n";
    target_file << "  \"age\": " << user.age << ",\n";
    target_file << "  \"address\": \"" << user.address << "\",\n";
    target_file << "  \"numMember\": " << user.numMember << ",\n";
    target_file << "  \"myTravel\": {\n";
    target_file << "    \"transport\": [\n";
    for (size_t i = 0; i < user.myTravel.transports.size(); ++i)
    {
        const auto &transport = user.myTravel.transports[i];
        target_file << "      {\n";
        target_file << "        \"name\": \"" << transport.name << "\",\n";
        target_file << "        \"brand\": \"" << transport.brand << "\",\n";
        target_file << "        \"from\": \"" << transport.from << "\",\n";
        target_file << "        \"destination\": \"" << transport.destination << "\",\n";
        target_file << "        \"cost\": " << transport.cost << ",\n";
        target_file << "        \"time\": \"" << transport.time << "\"\n";
        target_file << "      }";
        if (i < user.myTravel.transports.size() - 1)
        {
            target_file << ",";
        }
        target_file << "\n";
    }
    target_file << "    ],\n";
    target_file << "    \"hotel\": [\n";
    for (size_t i = 0; i < user.myTravel.hotels.size(); ++i)
    {
        const auto &hotel = user.myTravel.hotels[i];
        target_file << "      {\n";
        target_file << "        \"name\": \"" << hotel.name << "\",\n";
        target_file << "        \"address\": \"" << hotel.address << "\",\n";
        target_file << "        \"typeRoom\": \"" << hotel.typeRoom << "\",\n";
        target_file << "        \"startTime\": \"" << hotel.startTime << "\",\n";
        target_file << "        \"endTime\": \"" << hotel.endTime << "\",\n";
        target_file << "        \"cost\": " << hotel.cost << "\n";
        target_file << "      }";
        if (i < user.myTravel.hotels.size() - 1)
        {
            target_file << ",";
        }
        target_file << "\n";
    }
    target_file << "    ]\n";
    target_file << "  }\n";
    target_file << "}";
}

void WriteJsonFile(vector<User> &users, string &filename)
{
    fstream target_file;
    target_file.open(filename, ios::app);
    for (int i = 0; i < users.size(); i++)
    {
        singlewriteJsonFile(users[i], target_file);
    }

    target_file.close();

}

int main()
{
    // Tạo một mảng chứa 10 đối tượng dữ liệu người dùng
    std::vector<User> users;
    for (int i = 0; i < 10; ++i)
    {
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
    string filename = "user_data.txt";
    WriteJsonFile(users, filename);
    return 0;
}
