#include <iostream>
#include <cstdlib>
#include <cstdint>

int main()
{
using namespace std;
    
    uint64_t ui8;
    uint64_t *p = &ui8;

    cout << "p: " << endl;
//    cout << "*p: " << *p <<endl;
//    *p=5; //stack에 있는 정수형 상수
//    cout << "*p: " << *p <<endl;

    

    return 0;
}