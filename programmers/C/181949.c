#include <stdio.h>
#include <string.h>

#define LEN_INPUT 21

int main(void) {
    char s1[LEN_INPUT];    
    int gap='a'-'A';
    scanf("%s", s1);
    for(int i=0;i<strlen(s1);i++) {
        if(s1[i]>='A' && s1[i]<='Z') {
            s1[i]=s1[i]+gap;
        }
        else if(s1[i]>='a' && s1[i]<='z') {
            s1[i]=s1[i]-gap;
        }
        else {
            printf("알파벳만 넣으세요.\n");
            return 1;
        }     
    }    
    printf("%s\n", s1);
    return 0;
}
