#include <iostream>

/*
 * Lecture 08: 메모리 릭 (Memory Leak)
 * 
 * 핵심 개념:
 * 1. 할당된 메모리의 주소를 잃어버리면 '메모리 릭' 발생.
 * 2. Valgrind를 사용하여 감지 가능.
 * 3. RAII와 스마트 포인터를 사용하여 예방 가능.
 */

void createLeak() {
    // 40바이트(int 10개) 할당
    int* leakPtr = new int[10];
    
    std::cout << "메모리를 할당했지만 해제하지 않고 함수를 종료합니다." << std::endl;
    // 함수가 종료되면 leakPtr(스택 변수)는 사라지지만, 
    // 힙에 할당된 40바이트는 여전히 점유된 상태로 남음 (Leak 발생)
}

int main() {
    std::cout << "메모리 릭 테스트 시작" << std::endl;
    
    for (int i = 0; i < 3; ++i) {
        createLeak();
    }

    std::cout << "프로그램 종료. (Valgrind로 실행하여 결과를 확인하세요)" << std::endl;
    std::cout << "명령어: valgrind --leak-check=full ./Lecture_08_Memory_Leak" << std::endl;
    
    return 0;
}
