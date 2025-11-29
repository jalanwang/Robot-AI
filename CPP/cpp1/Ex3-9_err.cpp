#include <iostream>

class  PrivateAccessError {
private:
    int a;
    void f();
    PrivateAccessError() {}
public:
    int b;
    PrivateAccessError(int x);
    void g();
};

PrivateAccessError::PrivateAccessError() {
    a = 1;
    b = 1;
}
PrivateAccessError::PrivateAccessError(int x) {
    a = x;
    b = x;
}

void PrivateAccessError::f() {
    std::cout << "a: " << a << std::endl;
}

void PrivateAccessError::g() {
    std::cout << "b: " << b << std::endl;
}

int main() {
    PrivateAccessError objA;  // 오류: 기본 생성자는 private이므로 접근 불가    
    PrivateAccessError objB(100); // 오류: 매개변수가 있는 생성자도 private이므로 접근 불가
    objB.a=10;
    objB.b=20;
    objB.f();
    objB.g();
    
    return 0;
}