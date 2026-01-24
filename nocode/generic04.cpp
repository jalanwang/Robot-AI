#include <iostream>
#include <vector>

int main() {
    // 1. 선언 및 초기화 (C++11 초기화 리스트 사용)
    std::vector<int> v = {10, 20, 30};

    // 2. 요소 추가 (push_back)
    // 메모리가 부족하면 자동으로 재할당(Reallocation)이 일어남. 메모리 블록을 옮긴다는 의미.
    v.push_back(40); 
    v.push_back(50);

    // 3. 요소 접근 및 수정 (배열과 동일)
    // 시간 복잡도: O(1)
    v[0] = 999; 

    // 4. 크기 확인
    std::cout << "Size: " << v.size() << "\n"; // 출력: 5

    // 5. 순회 (Range-based for loop)
    std::cout << "Elements: ";
    for (int num : v) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}