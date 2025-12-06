/*
문제 설명
정수 num과 n이 매개 변수로 주어질 때, num이 n의 배수이면 1을 return n의 배수가 아니라면 0을 return하도록 solution 함수를 완성해주세요.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num, int n) {
    if(num%n!=0) return 0;
    else return 1;
}

int main() {
    
  
    int sol=solution(34, 3);

    printf("%d\n", sol);   
   
    return 0;
}