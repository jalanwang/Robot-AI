#include <stdio.h>

int main() {
    // 1. 배열 (수정 가능)
    char arr[] = "Hello";
    arr[0] = 'h';       // OK: 배열 내부 값 변경
    // arr = "World";   // Error: 배열 이름에 대입 불가

    // 2. 포인터 (문자열 리터럴 가리킬 때 수정 불가)
    const char *ptr = "Hello";
    // ptr[0] = 'h';    // Error: 읽기 전용 메모리 쓰기 시도 (런타임 에러)
    ptr = "World";      // OK: 포인터가 가리키는 대상 변경

    printf("Size of arr: %zu\n", sizeof(arr)); // 문자열 길이 + 1 (6)
    printf("Size of ptr: %zu\n", sizeof(ptr)); // 포인터 크기 (4 또는 8)

    return 0;
}