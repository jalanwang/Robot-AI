/*
주소록 관리 프로그램을 작성하시오.
주소록은 Person 클래스로 정의하며, 멤버 변수로 ID, 이름, 전화번호를 가집니다.
프로그램은 다음 메뉴를 제공합니다.
1. 주소록 조회
2. 주소록 추가
3. 주소록 수정
4. 주소록 삭제
5. 종료
각 메뉴에 대한 기능을 구현하시오.

*/

/*
소스 개정 방향
외부함수로 deletePersonById, updatePersonById 작성했는데 이걸 클래스로 넣을것.
클래스로 넣으면 좋아질것 같은데 왜 그런지는 잘 모르겠다.
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <memory>

class Person {
private:
    int mId;
    std::string mName;
    std::string mPnumber;

public:
    Person(int id, std::string name, std::string pnumber):mId(id),mName(name),mPnumber(pnumber) {}
    int getId() const{
        return this->mId;
    }
    std::string getName() const {
        return this->mName;

    }
    std::string getPnumber() const {
        return this->mPnumber;
    }


};

int deletePersonById(std::vector<Person>& addressbook, int id) {
    auto it = std::find_if(addressbook.begin(), addressbook.end(),
                           [id](const Person& p) { return p.getId() == id; });
    if (it != addressbook.end()) {
        addressbook.erase(it);
        std::cout << "ID " << id << " 삭제 완료." << std::endl;
    } else {
        std::cout << "ID " << id << "를 찾을 수 없습니다." << std::endl;
        return -1;

    }
    return 0;
}

void updatePersonById(std::vector<Person>& addressbook, int id) {
   if(deletePersonById(addressbook, id) != -1) {

     //주소록에 레코드 추가
    std::string name="";
    std::string pnumber="";
    std::cout << "ID : " ;
    std::cout << id << std::endl;
    std::cout << "새 이름 입력 : " ;
    std::cin >> name;
    std::cout << "새 전화번호 입력 : " ;
    std::cin >> pnumber;                

    addressbook.emplace_back(id, name, pnumber); //생성자를 이용해서 해도 될 것 같은데 왜 emplace_back을 썼지? 외부함수라서 그런가?   
   }

   else {
       std::cout << "그런 값은 없거든!" << std::endl;
   }

}


int main()
{
    std::vector<Person> addressbook;
    std::unique_ptr<Person> p = std::make_unique<Person>(1, "홍길동", "010-1111-1111");
    addressbook.push_back(*p);
    p = std::make_unique<Person>(2, "이순신", "010-2222-2222");
    addressbook.push_back(*p);

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
        std::string name="";
        std::string pnumber="";
        
        switch (select)
        {
            case 1:
                //주소록 조회 코드를 작성합니다.
                for(Person p : addressbook){
                    std::cout << "ID : " << p.getId() << " / ";
                    std::cout << "이름 : " << p.getName() <<" / ";
                    std::cout << "전화번호 : " << p.getPnumber() << std::endl;
                }
                break;
            case 2:
            {
                //주소록 추가 코드를 작성합니다.
                int id=0;
                std::string name="";
                std::string pnumber="";
                std::cout << "새 ID 입력 : " ;
                std::cin >> id;
                std::cout << "새 이름 입력 : " ;
                std::cin >> name;
                std::cout << "새 전화번호 입력 : " ;
                std::cin >> pnumber;     
                
                addressbook.emplace_back(id, name, pnumber);
                break;
            }
                       
            case 3:
            {
                int updateId = 0;
                std::cout << "수정할 ID 입력 : ";


                std::cin >> updateId;
                updatePersonById(addressbook, updateId);
                
                break;
            }
            
            case 4:
            {
                //주소록 삭제 코드를 작성합니다.
                int deleteId = 0;
                std::cout << "삭제할 ID 입력 : ";
                std::cin >> deleteId;
                deletePersonById(addressbook, deleteId);
                
                break;
            }

            case 5:
            {
                exit(1); 
                break;
            }
                
            default :
                std::cout << "잘못된 번호 입력, 다시 입력해 주세요." << std::endl;
                break;
        }
    
    } while (select != 0);
    
    return 0;
}