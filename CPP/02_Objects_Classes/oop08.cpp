/*
 사용자로부터 입력할 정수의 개수를 입력 받아 배열을 동적 할당 받고,
하나씩 정수를 입력 받은 후 합을 출력하는 프로그램을 작성하라.
*/

#include <iostream>
#include <cstdlib>

int main()
{
    using namespace std;
    
    cout << "입력할 정수의 갯수는? : ";
    int num;
    cin >> num;
    int* no= new int[num];
    int sum=0;
    for(int i=0;i<num;i++)
    {
        cin >> *(no+i);
        sum+=*(no+i);         
    }

    cout << "입력받은 숫자의 합은: " << sum;

    delete[] no;

    return 0;
}