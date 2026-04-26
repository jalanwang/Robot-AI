#include <iostream>
#include <cstdlib>
#include <memory>
#include <cmath>

class MathUtils {
public:
    static int abs(int a) {
        return (a>0) ? a : -a;
    }
    static int max(int a, int b) {
        return a>b ? a: b;
    }
    static int min(int a, int b) {
        return a<b ? a: b;
    }
};


// main() 함수
int main() {

    std::cout << MathUtils::abs(-5) << std::endl;
    std::cout << MathUtils::max(4,5) << std::endl;
    std::cout << MathUtils::min(-5, -6) << std::endl;
}
