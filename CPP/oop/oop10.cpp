/*
 사용자로부터 입력할 정수의 개수를 입력 받아 배열을 동적 할당 받고,
하나씩 정수를 입력 받은 후 합을 출력하는 프로그램을 작성하라.
*/

#include <iostream>
#include <cstdlib>
#include <memory>

class Circle
{
    public:
    void draw() {
        std::cout << "원을 그리다." << std::endl;
    }
};

int main()
{
    using namespace std;
    
    //동적할당
    int* p=new int;
    *p=5;
    delete p;

    //배열 동적 할당
    int* p2 = new int[3];
    p2[0]=1;
    p2[1]=2;
    delete[] p2;

    //스마트 포인터
    std::unique_ptr<int> p3 = std::make_unique<int>(5); //제너릭?
    std::unique_ptr<Circle> p4 = std::make_unique<Circle>();
    p4->draw();

    return 0;
}