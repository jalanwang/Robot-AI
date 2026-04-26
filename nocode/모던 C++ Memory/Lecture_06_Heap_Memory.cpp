#include <iostream>
using namespace std;

/**
 * Lecture 06: 힙 메모리 (Heap Memory)
 * - 런타임에 크기가 결정될 때 사용 (Dynamic Allocation)
 * - new: 힙 영역에 메모리 할당 후 주소 반환
 * - delete: 사용이 끝난 메모리 해제 (해제 안 하면 Memory Leak)
 */

int main() {
    cout << "--- Lecture 06: Heap Memory ---" << endl;

    // 1. 단일 변수 할당
    int* p = new int;
    *p = 100;
    cout << "Heap int value: " << *p << ", address: " << p << endl;
    delete p; // 해제

    // 2. 배열 할당
    int size;
    cout << "Enter array size: ";
    // size = 5; // 예시
    if (!(cin >> size)) size = 5;

    int* arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = i * 10;

    cout << "Heap array[1]: " << arr[1] << endl;
    
    delete[] arr; // 배열 해제 시 [] 필수

    return 0;
}
