// 문제 설명
// 머쓱이는 선생님이 몇 년도에 태어났는지 궁금해졌습니다.
// 2022년 기준 선생님의 나이 age가 주어질 때,
// 선생님의 출생 연도를 return 하는 solution 함수를 완성해주세요

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int age) {
    int answer = 0;
    answer=2022-age+1;
    return answer;

}


int main() {
    int age =22;
    int sol=solution(age);
    printf("선생님의 출생 연도는: %d", sol);

    return 0;
}