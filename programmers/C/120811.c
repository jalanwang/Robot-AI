//문제 설명
//중앙값은 어떤 주어진 값들을 크기의 순서대로 정렬했을 때
//가장 중앙에 위치하는 값을 의미합니다.
//예를 들어 1, 2, 7, 10, 11의 중앙값은 7입니다.
//정수 배열 array가 매개변수로 주어질 때, 중앙값을 return 하도록 solution 함수를 완성해보세요.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// array_len은 배열 array의 길이입니다.
int solution(int array[], size_t array_len) {
    int answer = 0;
    for(int j=0;j<array_len-1;j++) {
    for(int i=0;i<array_len-1;i++) {
        if(array[i]<array[i+1]) {
            int temp=array[i];
            array[i]=array[i+1];
            array[i+1]=temp;
        }
    }
}
    answer=array[(array_len-1)/2];
    return answer;
}

int main()
{
    int numbers1[]={1,2,7,10,11};
    int ans = solution(numbers1, 5);
    printf("%d\n", ans);

    int numbers2[]={9,-1, 0};
    ans = solution(numbers2, 3);

    printf("%d\n", ans);

    return 0;
}