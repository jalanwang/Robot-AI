#include <stdio.h>
#include <string.h>

void func();

int main()
{
    printf("컴파일 날짜와 시간: %s, %s\n\n", __DATE__, __TIME__);
    printf("파일명: %s\n", __FILE__);
    printf("함수명: %s\n", __FUNCTION__);
    printf("라인: %d\n", __LINE__);

#line 100 "Ex19-4.c"
    func();

    return 0;

}

void func()
{
    printf("\n");
    printf("파일명: %s\n", __FILE__);
    printf("함수명: %s\n", __FUNCTION__);
    printf("라인: %d\n", __LINE__);
}