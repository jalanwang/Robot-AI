/*
문제 설명
정수 리스트 num_list와 정수 n이 주어질 때,
num_list의 첫 번째 원소부터 n 번째 원소까지의 모든 원소를 담은 리스트를 return하도록 solution 함수를 완성해주세요.
 */


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int* solution(int num_list[], size_t num_list_len, int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(n*sizeof(int)); //
    for(int i=0;i<n;i++) { //
    for(int i=0;i<n;i++) { //
        answer[i]=num_list[i]; // 첫 n개 원소 복사    
    }
    return answer;
}


int main() {
   
    int num_list[]={5, 2, 1, 7, 5};
    int* sol=solution(num_list, sizeof(num_list)/sizeof(int), 3); //
    int size=3; 
      for(int i=0;i<size;i++) { 
        printf("%d ", sol[i]); //
    }
    
    return 0;
}