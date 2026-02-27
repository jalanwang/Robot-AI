#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> //1970.1.1 00시

int main()
{
    srand((unsigned int)time(NULL)); //random의 초깃값을 잡는다.

    for(int i=0;i<6;i++) {
        int number=rand()%45+1;
        printf("%d\n", number);
    }


    return 0;
}

