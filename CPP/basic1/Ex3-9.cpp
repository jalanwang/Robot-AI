/*
 * 프로젝트: Person 클래스 재작성 (연습)
 * 목표: 캡슐화와 생성자, Getter/Setter의 올바른 구현 이해
 * 
 * [작업 지시서]
 * 1. 헤더 포함: 필요한 표준 입출력 및 문자열 헤더를 포함하세요.
 * 
 * 2. Person 클래스 설계:
 *    - private 멤버: 
 *        - id (정수형)
 *        - name (문자열)
 *    - public 멤버:
 *        - 기본 생성자: id는 0, name은 "NoName"으로 초기화
 *        - 매개변수가 있는 생성자: id와 name을 전달받아 초기화
 *        - Setter: setId(int id), setName(std::string name)
 *        - Getter: getId(), getName()
 * 
 * 3. main 함수 구현:
 *    - Person 객체 'sam' 생성
 *    - Setter를 사용하여 ID를 1888, 이름을 "Sam"으로 설정
 *    - Getter를 사용하여 설정된 정보를 콘솔에 출력
 */

#include <iostream>
#include <string>

class Person {
    private:
        int m_id;
        std::string m_name;
    public:
        Person() : m_id(0), m_name("No name") {};

        void setID(int id) {
            m_id=id;
        }
        void setName(std::string name) {
            m_name=name;            
        }

        int getID() {
            return m_id;
        }
        std::string getName() {
            return m_name;
        }
};

int main() {
    // 여기에 코드를 직접 작성해 보세요!
    Person sam;

    sam.setID(1888);
    sam.setName("Sam");

    std::cout << sam.getID() << std::endl;
    std::cout << sam.getName() << std::endl;

    return 0;
}