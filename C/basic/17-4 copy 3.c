#include <stdio.h>

int main()
{
    FILE *fp;

    fp=fopen("./17-2.c", "r");
    if(fp=NULL) 
    {
        printf("파일이 없습니다. ");
        return 1;
    }

    printf("파일을 잘 열었습니다. ");
    
    
    return 0;
}