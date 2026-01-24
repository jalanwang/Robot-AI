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
    }
    
    fprintf(fp2, "%c", EOF);
    
    fclose(fp1);
    fclose(fp2);

    return 0;
}



