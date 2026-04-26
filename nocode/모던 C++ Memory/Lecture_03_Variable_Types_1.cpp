#include <iostream>
using namespace std;

/**
 * Lecture 03: 변수 타입 in 메모리 #1
 * - sizeof 연산자: 타입의 크기 확인
 * - 쓰레기 값(Junk Value): 초기화되지 않은 지역 변수의 위험성
 * - 타입 해석: 같은 비트라도 타입에 따라 다르게 해석됨
 */

int main() {
    cout << "--- Lecture 03: Variable Types #1 ---" << endl;

    // 1. sizeof
    cout << "[Size check]" << endl;
    cout << "sizeof(char)   : " << sizeof(char) << " byte" << endl;
    cout << "sizeof(int)    : " << sizeof(int) << " bytes" << endl;
    cout << "sizeof(double) : " << sizeof(double) << " bytes" << endl;

    // 2. Junk Value (Warning!)
    int junk;
    // cout << "Junk value: " << junk << endl; // 컴파일러에 따라 에러 또는 쓰레기 값 출력

    // 3. Type Interpretation (Cast)
    float f = 3.14f;
    int* p = (int*)&f; // float의 비트 패턴을 int로 강제 해석
    
    cout << "\n[Type Interpretation]" << endl;
    cout << "Float value: " << f << endl;
    cout << "Interpretation as int (hex): 0x" << hex << *p << dec << endl;

    // 4. Pointer Arithmetic Unit
    int arr[2] = {0, 0};
    int* p_arr = arr;
    cout << "\n[Pointer Arithmetic]" << endl;
    cout << "p_arr     : " << p_arr << endl;
    cout << "p_arr + 1 : " << p_arr + 1 << " (Increased by " << (uint64_t)(p_arr + 1) - (uint64_t)p_arr << " bytes)" << endl;

    return 0;
}
