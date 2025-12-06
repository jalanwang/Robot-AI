/*
문제 설명
연산 ⊕는 두 정수에 대한 연산으로 두 정수를 붙여서 쓴 값을 반환합니다. 예를 들면 다음과 같습니다.

12 ⊕ 3 = 123
3 ⊕ 12 = 312
양의 정수 a와 b가 주어졌을 때, a ⊕ b와 2 * a * b 중 더 큰 값을 return하는 solution 함수를 완성해 주세요.

단, a ⊕ b와 2 * a * b가 같으면 a ⊕ b를 return 합니다.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>


int solution(int a, int b) {
    int order_right = 0;
    int temp=b;
    int modified_value=a;
    while(temp > 0) { 
        temp/=10;
           if(b!=0) order_right++; 
           else break;     
    }
    

    for(int i=0;i<order_right;i++) {
       modified_value=modified_value*10;
    }
    
    int sum=modified_value+b;  
    
    return (sum>(2*a*b)) ? sum : (2*a*b);
}

int main() {
    
    int sol;
    sol=solution(91, 2);

    printf("%d\n", sol);   
   
    return 0;
}