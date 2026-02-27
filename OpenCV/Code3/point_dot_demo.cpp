#include <iostream>

// OpenCV의 Point_ 클래스를 흉내 낸 템플릿 클래스
template <typename _Tp>
class Point_ {
public:
    _Tp x, y;

    Point_(_Tp _x, _Tp _y) : x(_x), y(_y) {}

    // 내적(dot product) 계산 함수
    // 호출 형태: pt1.dot(pt2)
    _Tp dot(const Point_& pt) const {
        // this->x : 함수를 호출한 객체(pt1)의 x
        // pt.x    : 매개변수로 들어온 객체(pt2)의 x
        return (this->x * pt.x) + (this->y * pt.y);
    }
};

int main() {
    // 1. 객체 생성
    Point_<int> pt1(10, 20); // x=10, y=20
    Point_<int> pt2(30, 40); // x=30, y=40

    // 2. dot 함수 호출
    // pt1이 "주인"이 되어 함수를 실행하고, pt2를 "재료"로 넘겨줍니다.
    int d1 = pt1.dot(pt2);

    // 계산 과정: (10 * 30) + (20 * 40) = 300 + 800 = 1100
    std::cout << "Dot Product Result: " << d1 << std::endl;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
    return 0;
}