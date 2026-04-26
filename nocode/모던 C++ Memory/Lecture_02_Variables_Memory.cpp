#include <iostream>
using namespace std;

/**
 * Lecture 02: 변수와 메모리 (Variables & Memory)
 * - 변수는 메모리 주소에 대한 별명(Alias)입니다.
 * - 프로그램 실행 시 메모리 구조: Code, Data, Stack, Heap
 */

int global_var = 10; // Data 영역

int main() {
    int local_var = 20; // Stack 영역
    
    cout << "--- Lecture 02: Variables & Memory Layout ---" << endl;
    cout << "[Global Variable] Value: " << global_var << ", Address: " << &global_var << " (Data Segment)" << endl;
    cout << "[Local Variable]  Value: " << local_var << ", Address: " << &local_var << " (Stack Segment)" << endl;
    
    // 변수명은 컴파일러가 주소로 바꿔서 인식함
    // 주소값 출력 시 & 연산자 사용
    
    return 0;
}
