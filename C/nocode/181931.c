/*
문제 설명
두 정수 a, d와 길이가 n인 boolean 배열 included가 주어집니다.
첫째항이 a, 공차가 d인 등차수열에서 included[i]가 i + 1항을 의미할 때,
이 등차수열의 1항부터 n항까지 included가 true인 항들만 더한 값을 return 하는 solution 함수를 작성해 주세요.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// included_len은 배열 included의 길이입니다.


int solution(int a, int d, bool included[], size_t included_len) {
    int arr[included_len];
    int answer=0;
    for(int i=0; i<included_len; i++) {
        arr[i]=a+d*i;
        if(included[i]) answer+=arr[i];
    }
    return answer;
}    

int main() {
   
    bool included[]={true, false, false, true, true};
    int sol=solution(3,4, included, 5);
    
    printf("%d\n",sol);

    return 0;
}