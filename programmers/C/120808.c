#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>


int GCD(int num1, int num2) { //num1이 꼭 클 필요는 없다.
    while(num2!=0) { //나머지가 0이 될 때가지 동작. 유클리드호제법
        int temp = num1%num2;
        num1=num2;
        num2=temp;
    }
    return(num1);

}
int* solution(int numer1, int denom1, int numer2, int denom2) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int numer=numer1*denom2 + numer2*denom1;
    int denom=denom1*denom2;

    // printf("%d\n", numer);
    // printf("%d\n", denom);
    // 약분이 가능하다면 약분하시오 알고리즘을 여기에 구현할 것.
    // 분자가 분모의 배수인지 확인한다. 분모는 1이되고, 분자는 몫이된다.
    // 두 수의 최대공약수(공통 소인수 집합 중 가장 큰 공통약수: GCD)를 구한다.
    
    int gcd=GCD(numer, denom);

    
            numer=numer/gcd;
            denom=denom/gcd;

            // printf("%d\n", numer);
            // printf("%d\n", denom);
        
    int* answer = (int*)malloc(2*sizeof(int));
    answer[0]=numer;
    answer[1]=denom;
    
    return answer;
}

int main()
{
    int* sol = solution(1,2,3,4);
    
    printf("%d %d\n", sol[0], sol[1]);
    
    free(sol);
    
    sol = solution(9, 2, 1, 3);
    
    printf("%d %d", sol[0], sol[1]);
    
    free(sol);

    return 0;
}