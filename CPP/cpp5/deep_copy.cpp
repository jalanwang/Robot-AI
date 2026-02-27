#include <iostream>
using namespace std;

// ====================================
// 1. 얕은 복사 (Shallow Copy)
// 포인터 멤버가 있을 때, 주소값만 복사하는 방식
// ====================================
class TwinShallow {
private:
    int* data; // 포인터 멤버

public:
    TwinShallow(int val) {
        data = new int(val);
    }

    // 얕은 복사 생성자 (컴파일러 기본 생성자와 동일한 동작)
    // 단순히 주소값만 복사함 -> 두 객체가 하나의 메모리를 가리킴
    TwinShallow(const TwinShallow& other) {
        data = other.data; 
        cout << ">> [Shallow] 복사 생성자 호출: 주소만 복사됨 (Data 공유)\n";
    }

    void set(int val) {
        *data = val;
    }

    void print(const char* name) const {
        cout << name << " : 값=" << *data << " (주소: " << data << ")\n";
    }

    // 주의: 얕은 복사된 객체들이 소멸될 때, 
    // 동일한 메모리를 중복 해제(Double Free)하려다 런타임 에러가 발생할 수 있음.
    // 이 예제에서는 에러 방지를 위해 소멸자에서 메모리 해제를 생략함.
    // ~TwinShallow() { delete data; } 
};

// ====================================
// 2. 깊은 복사 (Deep Copy)
// 포인터 멤버가 있을 때, 실제 메모리를 새로 할당해서 값을 복사하는 방식
// ====================================
class TwinDeep {
private:
    int* data;

public:
    TwinDeep(int val) {
        data = new int(val);
    }

    // 깊은 복사 생성자
    // 새로운 메모리를 할당하고 값만 가져옴 -> 완전 독립
    TwinDeep(const TwinDeep& other) {
        data = new int(*other.data);
        cout << ">> [Deep] 복사 생성자 호출: 새 메모리 할당 (독립)\n";
    }

    ~TwinDeep() {
        delete data;
    }

    void set(int val) {
        *data = val;
    }

    void print(const char* name) const {
        cout << name << " : 값=" << *data << " (주소: " << data << ")\n";
    }
};

int main() {
    cout << "=== 1. 얕은 복사 테스트 (주소 공유) ===\n";
    {
        TwinShallow s1(10);
        TwinShallow s2 = s1; // 얕은 복사 발생

        s1.print("s1");
        s2.print("s2");

        cout << "\n[s2의 값을 999로 변경]\n";
        s2.set(999);

        s1.print("s1"); // s1도 같이 바뀜 (문제 발생)
        s2.print("s2");
    } 
    
    cout << "\n\n=== 2. 깊은 복사 테스트 (독립적) ===\n";
    {
        TwinDeep d1(10);
        TwinDeep d2 = d1; // 깊은 복사 발생

        d1.print("d1");
        d2.print("d2");

        cout << "\n[d2의 값을 999로 변경]\n";
        d2.set(999);

        d1.print("d1"); // d1은 그대로 10 유지
        d2.print("d2");
    } // d1, d2 소멸자 호출되면서 각각 메모리 정상 해제

    return 0;
}
