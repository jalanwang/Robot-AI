//다이아몬드 게임
#include <stdio.h>
#include <string.h>

int main()
{
    int row;
    
    int star_no;
    int blank_no;

    scanf("%d", &row);

    int inc_to = (row+1)/2; //중간값 까지 증가한다.

    for(int i=0;i<inc_to;i++) {
        star_no=2*i+1;
        blank_no=(row-star_no)/2; //앞 뒤로 나눠서 입력할 것이다.
        
        for(int k=0; k<blank_no; k++) printf(" ");
        for(int k=0; k<star_no; k++) printf("*");
        for(int k=0; k<blank_no; k++) printf(" ");
        printf("\n");
    }

    for(int i=1;i<inc_to;i++) { //갯수가 중요
        star_no=row - 2*i;
        blank_no=(row-star_no)/2; //앞 뒤로 나눠서 입력할 것이다.
        
        for(int k=0; k<blank_no; k++) printf(" ");
        for(int k=0; k<star_no; k++) printf("*");
        for(int k=0; k<blank_no; k++) printf(" ");
        printf("\n");        
    }

    return 0;
}
    