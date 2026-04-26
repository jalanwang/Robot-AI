#include <iostream>
using namespace std;

/**
 * Lecture 05: 스택 메모리 (Stack Memory)
 * - LIFO (Last In First Out)
 * - 함수 호출 시 스택 프레임(Stack Frame) 생성
 * - 자동 메모리 관리: 함수 종료 시 해당 스택 영역 포인터가 돌아감
 */

void func(int a) {
    int b = 20;
    cout << "  Inside func - a address: " << &a << endl;
    cout << "  Inside func - b address: " << &b << endl;
}

int main() {
    int x = 10;
    cout << "--- Lecture 05: Stack Memory ---" << endl;
    cout << "Main - x address: " << &x << endl;

    func(x);

    // func 종료 후 x의 주소는 그대로지만, func 내부의 a, b는 더 이상 유효하지 않음
    cout << "Back in Main" << endl;

    return 0;
}
