#include <stdio.h>

void my_gets(char* str, int size);

int main()
{
    char str[7];
    my_gets(str, sizeof(str));
    printf("%s", str);    

    return 0;
}

void my_gets(char* str, int size)
{
    int ch;
    int i=0;
    ch=getchar();

    while(i<size-1 && ch!='\n')
    {
        str[i]=ch;
        i++;
        ch=getchar();
    }
    str[i]='\0';
}