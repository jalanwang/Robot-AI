//quiz32.cpp
//4칙연산

#include <iostream>

class Calc { 
    private:    
    
    public:
    Calc() {}
    int plus(int a, int b) {
        return a + b;
    }
    int minus(int a, int b) {
        return a - b;
    }
    int multiply(int a, int b) {
        return a * b;
    }  
    double divide(int a, int b) {
        return (double)a / b;
    }   
};

int main() {
    using namespace std;

    Calc calc;    
    
    cout << "1+1=" << calc.plus(1,1) << endl;
    cout << "5-3=" << calc.minus(5,3) << endl;
    cout << "2*1=" << calc.multiply(2,1) << endl;
    cout << "4/2=" << calc.divide(4,2) << endl;    

    return 0;
}