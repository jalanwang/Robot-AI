#include <stdio.h>


int main(int argc, char* argv[])
{
    
    
    int ch;

    while(1) {
        ch=fgetc(stdin); //ch=getchar;
        if(ch==EOF) break;

        fputc(ch, stdout);
    }
 
    return 0;
}



