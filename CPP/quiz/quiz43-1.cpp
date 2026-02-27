#include <iostream>
#include <string>

//string 
//getline으로 두 정수를 입력받아 
//삼각형의 넓이를 구하시오.
class Connected {
    private:
        int ipAddress;
        int portNumber;
    public:  
        std::string myNetStatus(int ipAddress, int portNumber) {
            std::cout << "ipAddress :" << ipAddress << ", "
            << "portNumber: " << portNumber << std::endl;
        }
};


int main() {

    std::string ipAddress, portNumber;
    std::getline(std::cin, ipAddress);
    std::getline(std::cin, portNumber);

    Connected con;
    int ipAddress = std::stoi(ipAddress);
    int portNumber = std::stoi(portNumber);

    int area = con.myNetStatus(ipAddress, portNumber);
    std::cout << "class 삼각형의 넓이: " << area << std::endl;
    
    return 0;
}
