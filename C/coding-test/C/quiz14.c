//무한루프를 만들어 주세요.


#include <stdio.h>
#include <stdlib.h>

enum func {
    insert=1, delete, search, update, terminate
};

int main()
{
    enum func select;
    int sel;

    while(1) {
        printf("1. 데이터 삽입\n");
        printf("2. 데이터 삭제\n");
        printf("3. 데이터 조회\n");
        printf("4. 데이터 수정\n");
        printf("5. 프로그램 종료\n\n");

        printf("메뉴: ");
        scanf("%d", &sel);           
        select=sel;

        switch(select) {
            case insert:
            break;

            case delete:
            break;

            case search:
            break;

            case update:
            break;

            case terminate: 
            printf("프로그램이 종료됩니다.");
            exit(2); //작동안함
        }                 
    }

    return 0;
}
    