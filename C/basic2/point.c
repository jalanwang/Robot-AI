#include <stdio.h>
#include <string.h>

#include "./inc/point.h"

Point Gpoint={0,0};

int main()
{   
    printf("첫 좌표: %d , %d\n", Gpoint.x, Gpoint.y);
    Gpoint.x=10;
    Gpoint.y=20;
    printf("다음 좌표: %d , %d\n", Gpoint.x, Gpoint.y);
    
    return 0;

}
