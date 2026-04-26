#include <iostream>

/*
 * Lecture 07: 힙 메모리 실습 (Dynamic Allocation Practice)
 * 
 * 핵심 개념:
 * 1. new 연산자를 이용한 단일 객체 및 배열 할당.
 * 2. 할당된 메모리는 반드시 delete 또는 delete[]로 해제해야 함.
 * 3. 해제 후에는 포인터를 nullptr로 설정하여 Dangling Pointer 방지.
 */

class Player {
public:
    Player() { std::cout << "Player 생성자 호출" << std::endl; }
    ~Player() { std::cout << "Player 소멸자 호출" << std::endl; }
};

int main() {
    // 1. 단일 객체 할당
    std::cout << "--- 단일 객체 할당 ---" << std::endl;
    Player* p1 = new Player();
    delete p1; // 소멸자 호출 및 메모리 반환
    p1 = nullptr;

    // 2. 배열 할당
    std::cout << "\n--- 배열 할당 ---" << std::endl;
    int size;
    std::cout << "배열 크기를 입력하세요: ";
    // 실제 실행 시에는 입력을 받겠지만, 여기선 예시로 5를 설정
    size = 5; 
    
    int* arr = new int[size]; // 런타임에 크기 결정
    for (int i = 0; i < size; ++i) {
        arr[i] = i * 10;
    }

    // 배열 해제 시 반드시 delete[] 사용
    delete[] arr; 
    arr = nullptr;

    std::cout << "\n실습 완료" << std::endl;
    return 0;
}
