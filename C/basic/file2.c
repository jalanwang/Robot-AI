#include <stdio.h>


int main(int argc, char* argv[])
{

    char* str="banana";

    FILE* fp;
    fp=fopen("b.txt", "w");
    if(fp==NULL)
    {
        printf("파일을 만들지 못했습니다.\n");
        return 1;
    }

    int i;
    while(str[i]!='\0');
    {
        fputc(str[i], fp); //fprintf(fp, "%c", str[i]);
        i++;
    }

    fputc('\n', fp);

    fclose(fp); //자원반납    


    return 0;
}


