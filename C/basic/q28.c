//quiz_file1.c
/*
    read.txt "I CAN DO IT!!"
    WRITE.TXT "I CAN DO IT!!"
*/
#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE* fp1;
    FILE* fp2;
    int ch;

    fp1=fopen("read.txt", "r");
    fp2=fopen("write.txt", "w");


    while((ch=fgetc(fp1))!=EOF) {
        fputc(ch, fp2);
        //printf("%c", ch);        
    }
    
    //fprintf(fp2, "%c", EOF); //공백이 하나 추가됨. 
    //논리상 EOF를 넣어야 된다고 생각했는데 아니네! 왜? 생각좀 해보자...
    
    fclose(fp1);
    fclose(fp2);

    return 0;
}