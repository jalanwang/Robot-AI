//람다의 얕은 복사
#include <iostream>

int main() {
    int shared_x = 10; // 외부 공유 변수
    
    // 1. 람다 원본 (lambda_original) 생성
    // [&] : shared_x를 참조로 캡처. mutable은 참조 캡처에서는 불필요하지만,
    // 람다 내부에서 외부 변수(shared_x)를 직접 수정하고 있음에 주목.
    auto lambda_original = [&shared_x]() {
        // 원본과 복사본 모두 이 외부 변수를 직접 수정/참조함
        std::cout << "Original 람다 호출: shared_x 값: " << shared_x << std::endl;
        shared_x += 1; // 외부 변수의 값을 수정
        return shared_x; 
    };
    
    // 2. 람다 복사본 (lambda_copy) 생성
    // 람다 객체가 복사되지만, 캡처된 것은 shared_x의 주소(참조)이므로 주소만 복사됨.
    auto lambda_copy = lambda_original; 
    
    std::cout << "--- 함수 호출 전 ---" << std::endl;
    std::cout << "공유 외부 x 값 (shared_x): " << shared_x << std::endl; // 10
    
    // 3. lambda_original 호출
    std::cout << "\n--- Original 호출 ---" << std::endl;
    lambda_original(); // shared_x=10 출력 후 외부 shared_x가 11로 증가
    lambda_original(); // shared_x=11 출력 후 외부 shared_x가 12로 증가

    // 4. lambda_copy 호출
    // lambda_copy는 lambda_original이 수정한 현재 값(12)을 참조하여 시작함.
    std::cout << "\n--- Copy 호출 ---" << std::endl;
    lambda_copy(); // shared_x=12 출력 후 외부 shared_x가 13로 증가
    lambda_copy(); // shared_x=13 출력 후 외부 shared_x가 14로 증가
    
    // 5. Original 재호출 (변경된 값 확인)
    // lambda_original은 lambda_copy가 수정한 현재 상태(14)를 참조함.
    std::cout << "\n--- Original 재호출 ---" << std::endl;
    lambda_original(); // shared_x=14 출력 후 외부 shared_x가 15로 증가
    
    return 0;
}