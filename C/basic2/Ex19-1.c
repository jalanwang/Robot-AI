#include <stdio.h>
#include <string.h>
#include "./inc/student.h"


int main()
{
    Student hong={315, "홍길동"};

    printf("학번: %d,  이름: %s\n", hong.num, hong.name);
        
    return 0;

}