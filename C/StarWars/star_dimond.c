/*
5단계 - 마름모
(홀수만가능)

N? 5
   *
  ***
 *****
  ***
   *
*/

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
   int num;
   

   int star_no;
   int space_no;
   
   printf("몇 행입니까? 단, 3이상의 홀수값만 넣으세요.:");
   scanf("%d", &num);
   
   int inc_to=(num+1)/2;
   
   
   int j;
   
   for(int i=0;i<inc_to;i++) {
       star_no=2*i+1;
       space_no=(num-star_no)/2;
       
       for(j=0;j<space_no;j++) printf(" ");
       for(int k=0;k<star_no;k++) printf("*");
       for(j=space_no;j<num;j++) printf("");
       printf("\n");
   }
   
    for(int i=1;i<inc_to;i++) {
       star_no=num-(2*i);
       space_no=(num-star_no)/2;
       
       for(j=0;j<space_no;j++) printf(" ");
       for(int k=0;k<star_no;k++) printf("*");
       for(j=space_no;j<num;j++) printf("");
       printf("\n");
    }
    return 0;
}
