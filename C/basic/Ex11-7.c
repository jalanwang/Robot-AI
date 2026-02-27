#include <stdio.h>


int main()
{
    

    char str[80]="apple juice";
    const char *ps = "banana";
 
  
    fputs(ps, stdout);
    ps[0]='t';
    
    return 0;
}
