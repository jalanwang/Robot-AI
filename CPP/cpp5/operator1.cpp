#include <iostream>


class Complex {
	int mReal;
	int mImag;
public:
	Complex(int rVal=0, int iVal=0) {
		mReal = rVal; mImag = iVal;
	}
	void show() {
       	if(mImag>0) 
            std::cout << mReal << '+' << mImag << 'i' << std::endl;
        else if(mImag<0)
            std::cout << mReal << '-' << -mImag << 'i' << std::endl;
        else 
            std::cout << mReal << std::endl;
    }
	Complex operator+(Complex other) { 
	    Complex tmp; // 임시 객체 생성
	    tmp.mReal = mReal + other.mReal; // Real 파트 더하기
	    tmp.mImag = mImag + other.mImag; // Imaginary 파트 더하기
	    return tmp; // 더한 결과 리턴
    }
    Complex operator-(Complex other) { 
	    Complex tmp; // 임시 객체 생성
	    tmp.mReal = mReal - other.mReal; // Real 파트 더하기
	    tmp.mImag = mImag - other.mImag; // Imaginary 파트 더하기
	    return tmp; // 뺀값 리턴
    }
};

int main() {
	Complex a(4,5), b(4,5), c, d;
	c = a + b; // 복소수 덧셈 연산	
    d = a - b; // 복소수 뺄셈 연산
    a.show();
	b.show();
	c.show();
    d.show();
}
