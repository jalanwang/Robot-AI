//2908 백준
//숫자를 거꾸로 읽는 동생 시뮬레이션
//1. 숫자를 모듈라10, rev의 100의 자리 차지하도록 한다.
//2. 다시 숫자를 모듈라 10, rev의 10의 자리 차지하도록 한다.
//3. 숫자를 100으로 나눈 정수 몫이 1의 자리를 차지하도록 한다.

#include <stdio.h>
#include <string.h>

int main()
{
    int num1, num2;
    int num1_rev=0, num2_rev=0;
    
    scanf("%d %d", &num1, &num2);
    
    while(num1>0) {
            num1_rev = num1_rev*10 + num1%10; //마지막 자릿수 추출 및 rev의 자리수 차지
                                                //초깃값이 그래서 0이어 한다.
            num1 = num1/10;  //마지막 자릿수 제거
    }   
    while(num2>0) {
            num2_rev = num2_rev*10 + num2%10;
            num2 = num2/10;  
    }
    

    printf("%d\n", (num1_rev>num2_rev)?num1_rev:num2_rev);
    return 0;
}