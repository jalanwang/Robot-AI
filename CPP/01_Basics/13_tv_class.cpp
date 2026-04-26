#include <iostream>
#include <memory>
#include <cstdlib>

class TV {
private:
    int size; //스크린크기
public:
    TV() : size(20) {}
    TV(int s) : size(s) {}
    int getSize() const { return size; }  
};

class WideTV : public TV{
private:
    bool videoIn;
public: //constructor가 없음
    WideTV(int size, bool videoIN): TV(size) {
        this->videoIn = videoIN;
    }
    bool get_videoIn() {
        return videoIn;
    }
};

class SmartTV : public WideTV{
protected:
    std::string ipAddr;
public: //constructor가 없음
    SmartTV(std::string ipAddr, int size) : WideTV(size, true) {
        this->ipAddr = ipAddr;
    }
    std::string getipAddr() {
        return ipAddr;
    } 

};

int main() {
    SmartTV stv("192.168.0.1", 30);
    
    std::cout << "SmartTV의 IP주소: " << stv.getipAddr() << std::endl;
    std::cout << "SmartTV의 크기: " << stv.getSize() << "인치" << std::endl;
    std::cout << "SmartTV의 비디오 입력 여부: " << (stv.get_videoIn() ? "예" : "아니오") << std::endl;

    return 0;
}