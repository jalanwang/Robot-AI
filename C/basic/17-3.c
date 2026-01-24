#include <stdio.h>

struct address
{
    char name[20];
    int age;
    char tel[20];
    char addr[80];
};

int main()
{
    struct address list[5] =
    {
        {"홍길동", 23, "111-1111", "울릉도 독도"},
        {"이순실", 35, "222-2222", "바다의 왕자"},
        {"장보고", 19, "333-3333", "바다의 제왕"},
        {"유관순", 15, "444-4444", "민족의 언니"},
        {"안중근", 45, "555-4444", "민족의 자존심"}
    };

    printf("이름  , 나이,  전화번호,   주소'\n");

    for(int i=0; i<5; i++)
    {        
        printf("%s,\t %d,\t %s,\t %s\n", list[i].name, list[i].age, list[i].tel, list[i].addr);
    }   
    

    return 0;
}