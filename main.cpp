#include <asio.hpp>
#include <iostream>

asio::ip::address_v4 getNextIp(asio::ip::address_v4 ip_) {
    std::string next_ip_{};
    int i = 0;
    for (unsigned short b : ip_.to_bytes()) {
        if (i != 3) {
            next_ip_ += std::to_string(b) + ".";
        } else {
            b = b + 1;
            if (b == 255 || b == 0) {
                b = 1;
            }
            next_ip_ += std::to_string(b);
        }
        i++;
    }
    return asio::ip::address_v4::from_string(next_ip_);
}

int main(int argc, char* argv[]) {
    asio::ip::address_v4 ip_{asio::ip::address_v4::from_string("192.168.3.1")};
    for (int i = 0; i < 255; ++i) {
        ip_ = getNextIp(ip_);
        std::cout << ip_.to_string() << std::endl;
    }
    return 0;
}