#include <stdio.h>
#include <string.h>

int main()
{
    FILE *in, *out;
    char str[80];
    char* res;

    in=fopen("a1.txt", "r");

    out=fopen("b1.txt", "w");

    while(1) {
        res=fgets(str, sizeof(str), in);
        if(res==NULL) break;

        str[strlen(str)-1]='\0'; //문자열 마지막에 널문자 삽입
        fputs(str, out);
        fputs(" ", out);



    }
    
    fclose(in);
    fclose(out);


}