//1152 Baekjoon
//단어의 갯수

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100000];
    int size;
    int word=0;

    fgets(str, sizeof(str), stdin);
    size=strlen(str);

    if(size>0 && str[size-1]=='\n') {
        str[size-1]='\0';//개행문자 이동해서 엔터문자 날림
        size--;
    }
    for(int i=1;i<size;i++) { //i=0으로 시작하면 널문자까지 체크하게 되는데 그럴 필요가 없음
        if(str[i-1]==' ' && str[i]!=' ')
            word++;
    }
    
    if (size > 0 && str[0] != ' ') //첫 문자의 시작이 일반 문자로 시작하는 경우 체크
        word++;    
    
    printf("%d\n", word);
    return 0;
}