//문자열을 입력받아 뒤집어서 출력해 주세요.
#include <stdio.h>
#include <string.h>

int main()
{
    char str[80];

    scanf("%s", str);

    for(int i=strlen(str);i>=0;i--) printf("%c", str[i]);

    return 0;
}
    