//람다의 깊은 복사 예제
#include <iostream>
#include <functional> // std::function을 사용하지 않고 auto 람다의 동작 원리 이해를 위해

int main() {
    int initial_x = 10;
    
    // 1. 람다 원본 (lambda_original) 생성
    // [x] : x를 값으로 캡처. mutable 키워드를 사용하여 람다 내부에서 캡처된 x를 수정 가능하게 함.
    auto lambda_original = [x = initial_x]() mutable {
        std::cout << "Original 람다 내부 x 값: " << x << std::endl;
        x += 1; // 캡처된 x의 복사본을 수정 (원본 x와는 무관)
        return x; 
    };
    
    // 2. 람다 복사본 (lambda_copy) 생성
    // 람다 객체와 캡처된 변수 x의 복사본이 생성됨.
    auto lambda_copy = lambda_original; 
    
    std::cout << "--- 함수 호출 전 ---" << std::endl;
    std::cout << "초기 외부 x 값 (initial_x): " << initial_x << std::endl; // 10
    
    // 3. lambda_original 호출
    std::cout << "\n--- Original 호출 ---" << std::endl;
    lambda_original(); // x=10 출력 후 내부 x가 11로 증가
    lambda_original(); // x=11 출력 후 내부 x가 12로 증가

    // 4. lambda_copy 호출
    // lambda_copy는 lambda_original과 독립적인 캡처 변수 x의 복사본(값 10)을 가지고 시작함.
    std::cout << "\n--- Copy 호출 ---" << std::endl;
    lambda_copy(); // x=10 출력 후 내부 x가 11로 증가
    lambda_copy(); // x=11 출력 후 내부 x가 12로 증가
    
    // 5. Original 재호출
    // lambda_original은 캡처 변수 x의 현재 상태(12)를 유지함.
    std::cout << "\n--- Original 재호출 ---" << std::endl;
    lambda_original(); // x=12 출력 후 내부 x가 13로 증가        

    return 0;
}