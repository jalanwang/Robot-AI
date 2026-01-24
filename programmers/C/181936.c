/*
문제 설명
정수 number와 n, m이 주어집니다. number가 n의 배수이면서 m의 배수이면 1을 아니라면 0을 return하도록 solution 함수를 완성해주세요.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num, int n, int m) {
    if(num%n==0 && num%m==0) return 1;
    else return 0;
}

int main() {
    
  
    int sol=solution(55, 10, 5);

    printf("%d\n", sol);   
   
    return 0;
}