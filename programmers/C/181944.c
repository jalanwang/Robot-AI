/*
문제 설명
문자열 my_string, overwrite_string과 정수 s가 주어집니다.
문자열 my_string의 인덱스 s부터 overwrite_string의 길이만큼을
문자열 overwrite_string으로 바꾼 문자열을 return 하는 solution 함수를 작성해 주세요.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, const char* overwrite_string, int s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int size_my=strlen(my_string);
    int size_over=strlen(overwrite_string);
    
    int size = (size_my>=(size_over+s)) ? size_my :(size_over+s); //s의 크기를 고려    

    char* answer=(char*)malloc(size*sizeof(char)+sizeof(char));// 널 문자 공간 추가
    for(int i=0;i<size_my;i++) {
        answer[i]=my_string[i];
    }
        
    // s 위치부터 overwrite_string 길이만큼 덮어쓰기
    for(int i=0; i<size_over; i++) {
        answer[s+i]=overwrite_string[i];
    }

    answer[size]='\0'; //마지막 셀에 널 문자 삽입
    
    return answer;

    
}

int main() {
    char* my_string="He11oWor1d";
    char* overwrite_string="lloWorl";
    int s=2;

    char* sol=solution(my_string, overwrite_string, s);
    printf("%s\n", sol);
    free(sol);

    my_string="Program29b8UYP";
    overwrite_string="merS123";
    s=7;

    sol=solution(my_string, overwrite_string, s);
    printf("%s\n", sol);
    free(sol);

    return 0;

}