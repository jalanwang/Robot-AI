// [학습 가이드] 아래 가이드를 따라 직접 코드를 작성해보세요.
// 1. 필요한 헤더 포함하기 (입출력, 스마트 포인터)
// #include <iostream>
// #include <memory>

// 2. Circle 클래스 설계하기
// - 멤버 변수: int radius
// - 멤버 함수: double getArea() { return 3.14 * radius * radius; }

// 3. main 함수 시작

// 3-1. 스택에 일반 객체 생성 (donut)하고 면적 출력하기

// 3-2. 포인터 변수 p를 만들어 donut의 주소값 저장하기
// - 화살표(->) 연산자와 역참조(*) 연산자 두 가지 방식으로 면적 출력해보기

// 3-3. 힙(Heap)에 동적 할당으로 donut2 생성하기 (new 이용)
// - 화살표와 역참조 방식으로 면적 출력해보기

// 3-4. 힙에 할당된 메모리 해제하기 (delete 이용)

// 4. [보너스] Modern C++ 스마트 포인터 사용해보기
// - auto donut3 = std::make_unique<Circle>(); 사용
// - 면적 출력해보기 (이건 delete가 필요 없음을 기억하세요!)

// 5. main 함수 종료

#include <iostream>
#include <memory>

class Circle {
    public:
    int m_radius=1;

    Circle(int radius){
        m_radius=radius;
    }
    Circle(){
        m_radius=0;
    }

    ~Circle(){
        std::cout << "도넛 소멸" << std::endl;
    }
    
    double getArea() {
        return 3.14*m_radius*m_radius;
    }
};

int main(){
    
    Circle donut;
    std::cout << "도넛 면적: " << donut.getArea() << std::endl;

    Circle* p = & donut;
    std::cout << "p의 면적: " << p->getArea() << std::endl;
    std::cout << "p의 면적: " << (*p).getArea() << std::endl;
    
    Circle* p2 = new Circle;
    p2->radius = 5;
    std::cout << "p2의 면적:" << p2->getArea() << std::endl;
    delete p2;

    auto dount3 = std::make_unique<Circle>();
    dount3->radius = 10;
    std::cout << "dount3의 면적" << dount3->getArea() << std::endl; 

    std::unique_ptr<Circle> donut4 = std::make_unique<Circle>();
    donut4->radius = 20;   
    std::cout << "dount4의 면적:" << donut4->getArea() << std::endl;
    //donut4.reset();

    return 0;
}
