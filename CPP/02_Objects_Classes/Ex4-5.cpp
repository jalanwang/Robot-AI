#include <iostream>
#include <cstdlib>

int main()
{
using namespace std;
    int* p;

    p=new int;
    cout << "p: " << p <<endl;
    cout << "*p: " << *p <<endl;
    *p=5; //stack에 있는 정수형 상수
    cout << "*p: " << *p <<endl;

    int n;
    n=*p;
    cout << "n: " << n <<endl;

    delete p;

    return 0;
}