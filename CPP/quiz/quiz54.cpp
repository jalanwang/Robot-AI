#include <iostream>
#include <vector>

class Person 
{
private:
    int mId;   
    std::string mName;
    std::string mPhone;

public:
    Person(int id, const std::string& name, const std::string& phone)
        : mId(id), mName(name), mPhone(phone) {}

    int mGetId() const { return mId; }
    std::string mGetName() const { return mName; }
    std::string mGetPhone() const { return mPhone; }

    void printInfo() const 
    {   
        std::cout << "아이디: " << mId << " 이름: " << mName << " 전화번호: " << mPhone << std::endl;
    }


};

int main()
{
    std::vector<Person> addressbook;

    Person p1(1, "홍길동", "010-1234-5678");
    Person p2(2, "김철수", "010-8765-4321");
    addressbook.push_back(p1);
    addressbook.push_back(p2);

    int select = -1;
    do
    {
        std::cout << "---------------------------------------------------------------- -" << std::endl;
        std::cout << "1. 주소록 조회" << std::endl;
        std::cout << "2. 주소록 추가" << std::endl;
        std::cout << "3. 주소록 수정" << std::endl;
        std::cout << "4. 주소록 삭제" << std::endl;
        std::cout << "5. 종료" << std::endl;
        std::cout << " 메뉴 : ";
        std::cin >> select;
    
        int id=0;
        std::string name;
        std::string phone;

        switch (select)
        {
            case 1:
                for (const auto& person : addressbook) {
                    person.printInfo();
                }
                break;
            case 2:
                //주소록 추가 코드를 작성합니다.
                std::cout << "아이디: ";
                std::cin >> id;
                std::cout << "이름: ";
                std::cin >> name;
                std::cout << "전화번호: ";
                std::cin >> phone;
                addressbook.push_back(Person(id, name, phone));
                break;
            case 5:
                exit(1); 
                break;

            default:
                std::cout << "잘못된 입력입니다. 다시 입력해주세요." << std::endl;
                break;
        }
    
    } while (select != 5);



    return 0;
}