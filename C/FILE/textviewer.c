#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    
    char ch;
    
    if(argc==1)
    {
        printf("매개변수를 최소 한 개 입려해야 합니다.\n");
        printf("다음과 같이 입력하세요. %s\n", argv[0]);
        exit(2);
    }

    char* path=argv[1];
    
    FILE* fp =fopen(path, "r"); //~/work/basic/a.txt로 열면 안된다.

    if(fp==NULL) {
        printf("파일이 없네.\n");
        return 1;
    }

    
    while(1)
    {
        ch=fgetc(fp);
        if(ch==EOF) break; //File의 끝
        
        putchar(ch);
    }

    fclose(fp); //자원반납    


    return 0;
}


