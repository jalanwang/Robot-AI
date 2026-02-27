//구구단 9단부터 2단까지
#include <stdio.h>

int main()
{
    int i, j;

    for(int i=9;i>=2;i--) {
        for(int j=1;j<=9;j++) printf("%d * %d = %d\n", i, j, i*j);
    }
    
    return 0;
}
