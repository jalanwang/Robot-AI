/*
문제 설명
양의 정수 n이 매개변수로 주어질 때, n이 홀수라면 n 이하의 홀수인 모든 양의 정수의 합을 return 하고,
n이 짝수라면 n 이하의 짝수인 모든 양의 정수의 제곱의 합을 return 하는 solution 함수를 작성해 주세요.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer1=0;
    int answer2=0;
    int isOdd=0;
    if(n%2!=0) isOdd=1;
    else isOdd=0;

    if(isOdd) {
    for(int i=1; i<=n;i++) { 
        if(i%2!=0) answer1+=i;        
    }

    }
    else {
    for(int i=2;i<=n;i++) { 
        if(i%2==0) answer2=answer2+i*i;        
        }
    }
    return isOdd ? answer1 : answer2;
}

int main() {
    
  
    int sol1=solution(7);
    int sol2=solution(10);

    printf("%d\n", sol1);
    printf("%d\n", sol2);   
   
    return 0;
}