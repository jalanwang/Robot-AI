//대소문자, 특수문자, 숫자의 갯수를 출력하는 문제
#include <stdio.h>
#include <string.h>

int main()
{
    char str[80];
    int len;

    int big=0;
    int small=0;
    int num=0;
    int special=0;
    scanf("%s",str);

    len=strlen(str);
    for(int i=0;i<len;i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') big++;
        else if(str[i] >= 'a' && str[i] <= 'z') small++;
        else if(str[i] >= '0' && str[i] <= '9') num++;
        else special++;
    }
    printf("알파벳 대문자: %d\n", big);
    printf("알파벳 소문자: %d\n", small);
    printf("숫자: %d\n", num);
    printf("특수문자: %d\n", special);

    return 0;
}
