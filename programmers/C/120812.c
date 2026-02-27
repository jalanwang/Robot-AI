//문제설명
//최빈값은 주어진 값 중에서 가장 자주 나오는 값을 의미합니다.
//1. 정수 배열 array가 매개변수로 주어질 때, 최빈값을 return 하도록 solution 함수를 완성해보세요.
//2. 단, 최빈값이 여러 개면 -1을 return 합니다.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void bubble_sort(int array[], size_t array_len) {
    for(int j=0;j<array_len-1;j++) {
        for(int i=0;i<array_len-1;i++) {
            if(array[i]<array[i+1]) {
                int temp=array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
            }
        }   
    }
}

int solution(int array[], size_t array_len) {
    
    int* temp = (int*)malloc(sizeof(int) * array_len); //배열 복사
    for(int i=0; i<array_len; i++) {
        temp[i] = array[i];            
    }
    
    bubble_sort(temp, array_len); //버블정렬 콜
    
    // 3. 연속된 숫자의 개수(빈도)를 세서 최빈값 찾기
    int max_cnt = 0;      // 지금까지 발견한 최대 빈도수
    int max_freq = -999;    // 최빈값. 배열입력에 안들어 온다고 가정하는 숫자
    int current_cnt = 0;  // 현재 숫자의 빈도수
    int current_val = -999; // 현재 세고 있는 숫자. 배열입력에 안들어 온다고 가정하는 숫자
    bool two_heads = false;  // 최빈값이 한 개

    if (array_len > 0) {
        current_val = temp[0];
        current_cnt = 1; //하나를 발견했으므로 1값 셋팅
    }

    for(int i=1; i<array_len; i++) {
        if (temp[i] == current_val) {
            // 같은 숫자가 연속되면 카운트 증가
            current_cnt++;
        } else {
            // 숫자가 바뀌면, 이전 숫자의 빈도수 결산
            if (max_cnt < current_cnt) { //
                max_cnt = current_cnt;
                max_freq = current_val;
                two_heads = false; // 단독 1등 셋
            } else if (current_cnt == max_cnt) {
                two_heads = true;  // 공공 1등 셋
            }

            // 새로운 숫자 카운트 시작
            current_val = temp[i];
            current_cnt = 1;
        }
    }

    // 마지막 남은 그룹 처리 (파이썬 a[-1]과 a[-2]가 같은 값이라 루프가 else로 못 넘어갔음.
    if (max_cnt < current_cnt) {
        max_freq = current_val;
        two_heads = false;
    } else if (max_cnt == current_cnt) {
        two_heads = true;
    }

    free(temp); 

    if (two_heads) return -1;
    return max_freq;
}

int main() {
    int array[]={1,2,3,3,3,4};
    int ans=solution(array,sizeof(array)/sizeof(int));
    printf("%d", ans);
}