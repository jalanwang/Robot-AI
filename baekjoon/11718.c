//입력받은 문자를 그대로 출력하시오.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int line_no = 0;
    int max_line_no = 100;
    char* str[100];

    for (int i = 0; i < max_line_no; i++) {
        str[i] = (char *)malloc(101 * sizeof(char));
        if (!str[i]) {
            fprintf(stdout, "메모리 할당 실패\n");
            return 1;
        }
    }
    while (line_no < max_line_no) {
        char *input = fgets(str[line_no], 101, stdin);
        if (input == NULL) break;
        str[line_no][strcspn(str[line_no], "\r\n")] = '\0';

        line_no++;
    }

        for (int line_no = 0; line_no < max_line_no; line_no++) {
        printf("%s\n", str[line_no]);
    }


    for (int i = 0; i < line_no; i++) {
        free(str[i]);
    }

    return 0;
}