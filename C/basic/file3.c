#include <stdio.h>


int main(int argc, char* argv[])
{
   

    if(argc==1) {
        printf("매개변수가 부족합니다. 만들 파일이름을 넣으세요.\n");
        return(-1);
    }

    char* file=argv[1];
    char* str="새 파일에 쓰고 있는 중...";

    FILE* fp;

    fp=fopen(file, "w");
    if(fp==NULL)
    {
        printf("파일을 만들지 못했습니다.\n");
        return 1;
    }

    int i=0;
    while(str[i] != '\0') {
        fputc(str[i], fp); //fprintf(fp, "%c", str[i]);
        i++;
    }

    fputc('\n', fp);

    fclose(fp); //자원반납    


    return 0;
}


