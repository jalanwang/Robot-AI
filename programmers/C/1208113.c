//문제 설명
//정수 n이 매개변수로 주어질 때, n 이하의 홀수가 오름차순으로 담긴 배열을 return하도록 solution 함수를 완성해주세요.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int num) {
    
    int* temp = (int*)malloc(sizeof(int) * num); //영역예약
    
    for(int i=0; i<(num+1)/2; i++) {
            temp[i]=2*i+1;    
    }
       
    return(temp);
}

int main() {
    int num;
    scanf("%d", &num);

    int* sol=solution(num);
    for(int i=0;i<(num+1)/2;i++) {
        printf("%d ", sol[i]);

    }

    return 0;
}