// []배열] 문자열을 입력을 받아
// 입력된 글자 중 알파벳 대문자의 개수
// 소문자의 개수, 특수문자의 개수,
// 숫자의 개수를 출력하세요.

#include <stdio.h>


int main() {
    char str[100];
    int size=0;
    int f_cap=0, f_small=0, f_number=0, f_special=0;
    
    scanf("%s", str);
    
    for(int i=0;i<100;i++) {
        if(str[i]=='\0') break;
        size++;
    }
    
    for(int i=0;i<size;i++) {
        if (str[i]>='A' && str[i]<='Z') f_cap++;
        else if(str[i]>='a' && str[i]<='z') f_small++;
        else if(str[i]>='0' && str[i]<='9') f_number++;
        else f_special++;
    }
    
    printf("대문자의 갯수: %d\n", f_cap);
    printf("소문자의 갯수: %d\n", f_small);
    printf("숫자의 갯수: %d\n", f_number);
    printf("특수문자의 갯수: %d\n", f_special);
    
    return 0;

}
