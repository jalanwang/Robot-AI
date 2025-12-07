#include <iostream>

class DataWrapper {
public:
    int* m_data; // 동적으로 할당된 메모리를 가리키는 포인터 멤버

    // 1. 생성자: 메모리 동적 할당
    DataWrapper(int val) {
        m_data = new int(val);
        std::cout << "객체 생성 및 메모리 할당: " << *m_data << std::endl;
    }

    // 2. 소멸자: 할당된 메모리 해제
    ~DataWrapper() {
        if (m_data != nullptr) {
            delete m_data;
            m_data = nullptr;
            std::cout << "객체 소멸 및 메모리 해제" << std::endl;
        }
    }
};

void test_shallow_copy() {
    // 1. 원본 객체 생성
    DataWrapper original(100);
    // original.m_data는 메모리 주소 X를 가리키고, 그 안에 값 100이 있음.

    std::cout << "\n--- 얕은 복사 수행 (기본 복사 생성자 호출) ---\n";
    // 2. 복사 객체 생성 (복사 생성자 자동 호출)
    // 컴파일러가 기본 멤버별 복사를 수행:
    // original의 m_data 포인터 주소 값(X)이 copy의 m_data로 그대로 복사됨.
    // 두 포인터가 같은 메모리 주소(X)를 가리키게 됨.
    DataWrapper copy = original;
    
    std::cout << "Original 포인터 주소: " << original.m_data << ", 값: " << *original.m_data << std::endl;
    std::cout << "Copy 포인터 주소: " << copy.m_data << ", 값: " << *copy.m_data << std::endl;
    
    std::cout << "\n--- 복사본을 통해 값 변경 ---\n";
    // 3. 복사본을 통해 값 변경
    *copy.m_data = 200;

    // 원본과 복사본 모두 같은 메모리(X)를 가리키므로 값이 함께 변경됨.
    std::cout << "Original 값 확인: " << *original.m_data << std::endl; // 200 출력
    std::cout << "Copy 값 확인: " << *copy.m_data << std::endl;     // 200 출력
    
    std::cout << "\n--- 함수 종료 (소멸자 호출 시 문제 발생) ---\n";
} // 여기서 copy와 original의 소멸자가 순차적으로 호출됨

int main() {
    test_shallow_copy();
    // 프로그램이 비정상 종료되거나 런타임 오류가 발생할 가능성이 높음.
    return 0;
}