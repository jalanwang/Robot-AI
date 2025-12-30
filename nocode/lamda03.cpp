#include <iostream>

int main() {
    // 1. Functor 클래스 정의 제거
    // 2. 람다의 '초기화 캡처'를 사용하여 상태(scaleFactor) 정의 및 초기화
    
    // ScaleAdder add10(10); 과 동일
    auto add10 = [scaleFactor = 10](int x) { 
        return x + scaleFactor; 
    };

    // ScaleAdder add20(20); 과 동일
    auto add20 = [scaleFactor = 20](int x) { 
        return x + scaleFactor; 
    };

    // 사용법은 기존 Functor와 100% 동일
    int result1 = add10(5); // 5 + 10 = 15
    int result2 = add20(5); // 5 + 20 = 25

    std::cout << result1 << ", " << result2 << std::endl;
    
    return 0;
}