//fread, fwirte함수

#include <stdio.h>
#include <stdio.h>

int main() 
{
    FILE* ifp;
    FILE* ofp;
    int res;

    int kor, eng, math;
    int total=0;
    double avg;
    char str[20];

    ifp=fopen("a2.txt", "r");
    if(ifp==NULL){
        printf("입력 파일이 없습니다");
        return 1;        
    }

    ofp=fopen("b2.txt", "w");
    if(ofp==NULL){
        printf("출력 파일을 만들 수 없습니다");        
        return 2;
    }

    while(1) {
        res=fscanf(ifp, "%s%d%d%d", str, &kor, &eng, &math);
        if(res==EOF) break;

        total=kor+eng+math;
        avg=total/3.0;
        
        fprintf(ofp, "%s %d %.2lf\n", str, total, avg);
    }

    fclose(ifp);
    fclose(ofp);


    return 0;
}