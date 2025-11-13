//문자열을 입력으로 주면 문자열의 첫 글자와 마지막 글자를
//출력하는 프로그램을 작성하시오.

#include <stdio.h>
#include <string.h>

int main()
{

    int test_case;
    
    scanf("%d", &test_case);
    char str[test_case][1000];
        
    for(int i=0;i<test_case;i++) { //hello, hi, ohi
        scanf("%s", str[i]);
        //printf("%5d", i);
    }    
    
    
    for(int i=0;i<test_case;i++) {
        printf("%c%c\n", str[i][0], str[i][strlen(str[i])-1]);
    }
    
    return 0;
}
