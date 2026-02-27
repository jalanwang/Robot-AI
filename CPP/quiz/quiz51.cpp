/*
quiz51) 단일책임원치에 맞게 다음 코드를 리팩토링해보세요.

*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// SRP(단일 책임 원칙)를 위반한 UserInfo 예제
// - 사용자 정보
// - 서버 정보 출력
// - 관리자 정보 저장
//   책임을 한 클래스에 모두 몰아넣음
class UserInfo {
private:
    // 사용자 정보
    std::string userName;
    std::string userEmail;
public:
    UserInfo(const string& userName,
             const string& userEmail)
        : userName(userName),
          userEmail(userEmail)
    {}
    // ① 사용자 정보 출력 책임
    void printUserInfo() const {
        cout << "[User] 이름: " << userName
             << ", 이메일: " << userEmail << endl;
    }
};

class ServerInfo {
private:
    std::string serverIp;
    int serverPort;
    
public:
    ServerInfo(const string& serverIp, int serverPort) : 
          serverIp(serverIp), serverPort(serverPort) {}


    void printServerInfo() const {
        cout << "[Server] IP: " << serverIp
             << ", Port: " << serverPort << endl;
    }
};

int main() {
    cout << "===== Example (SRP OK) =====" << endl;

    UserInfo user("홍길동", "hong@example.com");

    ServerInfo server("192.168.0.1", 8080);

    user.printUserInfo();
    server.printServerInfo();

    return 0;
}