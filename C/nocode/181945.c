#include <stdio.h>
#include <string.h>

#define LEN_INPUT 11

int main(void) {
    char s1[LEN_INPUT];
    
    // 입력 길이 제한으로 버퍼 오버플로 방지
    if (scanf("%10s", s1) != 1) {
        fprintf(stderr, "입력 오류\n");
        return 1;
    }
    
    // strlen을 한 번만 호출
    size_t len = strlen(s1);
    for (size_t i = 0; i < len; i++) {
        printf("%c\n", s1[i]);
    }

    return 0;
}
