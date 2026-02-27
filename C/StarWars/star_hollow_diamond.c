/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/*
6단계- 빈마름모
(홀수만가능)

N? 5
   *
  * *
 *   *
  * *
   *
*/

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
   int num;
   int devi; //deviation
   
   printf("몇 행입니까? 단, 3이상의 홀수값만 넣으세요.:");
   scanf("%d", &num);
   
   int center=(num+1)/2; //바벨의 무게 중심
   // printf("%d\n", center);    

   for(int m=0;m<num;m++) { //m_loop
        if (m<center) { // 바벨이 커지는 단계의 시작
            devi=m; //중심에서 벗어나는 거리 

            for(int j=0;j<num;j++) { //j_loop
                if((j==(center-devi-1)) || (j==(center+devi-1))) {
                    printf("*");
                }
                else printf(" ");
            } //j_loop end
        printf("\n");    
        } //end_if
    
        if (m>=center) { //바벨이 줄어들어가는 단계의 시작
            devi=num-m-1; //중심에서 벗어나는 거리가 줄어듦.

            for(int j=0;j<num;j++) { //j_loop
                if((j==(center-devi-1)) || (j==(center+devi-1))) printf("*");
                else printf(" ");
            } //j_loop end
        printf("\n");
        } //end_if

        
    } //m_loop end

    return 0;
}
