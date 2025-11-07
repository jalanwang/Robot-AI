#include <stdio.h>
#include <stdlib.h>

int main()
{
   char str_age[10];
   char name[20];
   
   printf("나이 입력: ");
   fgets(str_age, sizeof(str_age), stdin);
   
   printf("이름 입력: ");
   fgets(name, 20, stdin);
  
   printf("나이: %d, 이름: %s\n", atoi(str_age), name);
   
    return 0;
}
