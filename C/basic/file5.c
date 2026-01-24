#include <stdio.h>


int main(int argc, char* argv[])
{
    FILE* fp;
    int arr[10]={13, 10, 13, 13, 26
        , 3, 13, 10, 13, 10};
    int i, res;
    
    fp=fopen("a.txt", "wb");
    for(i=0;i<10;i++)
    {
        fputc(arr[i], fp);
    }
    
    fclose(fp);

    fp=fopen("a.txt", "rt");

    while(1)
    {
        res=fgetc(fp);
        if(res == EOF) break;
        printf("%4d", res);
    }

    fclose(fp);
 
    return 0;
}



