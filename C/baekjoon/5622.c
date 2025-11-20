//다이얼톤 문자>숫자로 변환 후 최소시간 구하기
#include <stdio.h>
#include <string.h>

int main() {
    char str[20];
    int total_time = 0;
    
    fgets(str, sizeof(str), stdin); //string으로 최대 sizeof(str)이하의 문자열을 입력 받는다.
    str[strcspn(str, "\r\n")] = '\0'; // 엔터키를 만나면 엔터키 앞에 있는 문자의 갯수를 반환한다.
                                        // 그리고 엔터키의 위치에 널문자('\0')를 넣어준다.
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch >= 'A' && ch <= 'Z') {
            if (ch >= 'A' && ch <= 'C') total_time += 3;
            else if (ch >= 'D' && ch <= 'F') total_time += 4;
            else if (ch >= 'G' && ch <= 'I') total_time += 5;
            else if (ch >= 'J' && ch <= 'L') total_time += 6;
            else if (ch >= 'M' && ch <= 'O') total_time += 7;
            else if (ch >= 'P' && ch <= 'S') total_time += 8;
            else if (ch >= 'T' && ch <= 'V') total_time += 9;
            else if (ch >= 'W' && ch <= 'Z') total_time += 10;
        }
    }

    printf("%d\n", total_time);

    return 0;
}
