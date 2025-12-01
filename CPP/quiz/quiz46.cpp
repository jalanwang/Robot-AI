#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>


class Account {
 private: 
  int mId; //계좌번호
  std::string mName; //예금주이름
  int mBalance=0; //잔액

 public:
  Account(){}
  ~Account(){}

  Account(int id, const std::string& name, int initalBalance) {
    this->mId=id;
    this->mName=name;
    this->mBalance=initalBalance;
  }

  const int getId() {
    return this->mId;
  }

  const std::string getName() {
    return this->mName;
  }
  const int getBalance() {
    return this->mBalance;
  }
  bool deposit(int amount) { //입금
    this->mBalance=this->mBalance+amount;
    std::cout << "입금 완료: " << amount <<"원 입금됨" <<  std::endl;
    return 1;
  }
  bool withdraw(int amount) { //출금
    if(this->mBalance >= amount) {
     this->mBalance=this->mBalance-amount;
     std::cout << "출금 완료: " << amount << "원 출금됨" << std::endl;
     return 1;
  }
    else {
      std::cout << "잔액 부족: 출금 실패" << std::endl;
      return 0;
    }
  }
  void printInfo() { //계좌정보 출력
    std::cout << "계좌번호: "<< this->mId << " 예금주: "<< this->mName << " 잔액: " << this->mBalance << std::endl;
  }


};
int main() {

    // 1. 계좌 생성
    Account acc1(1001, "홍길동", 50000);
    Account acc2(1002, "이순신", 30000);

    // 2. 입금/출금 테스트
    acc1.deposit(20000);    // 정상 입금
    acc2.withdraw(5000);    // 정상 출금
    acc2.withdraw(50000);   // 실패 테스트 (잔액 부족)

    // 3. 계좌 정보 출력
    std::cout << "[계좌정보]" <<std::endl;
    acc1.printInfo();
    acc2.printInfo();

    // 4. vector로 여러 계좌 관리
    std::vector<Account> v;
    v.push_back(acc1);
    v.push_back(acc2);

    std::cout << "\n=== 전체 계좌 목록 ===\n";
    for (auto& acc : v) {
        acc.printInfo();
    }

    return 0;
}