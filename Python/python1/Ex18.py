#1~10까지 출력하는데 3의 배수만 출력하세요.
#단 continue를 사용해야 합니다.
#루프는 while을 사용하세요.
# 3 6 9
i=0
while i<10:
    i+=1
    if (i%3)!=0:
        continue
    
    print(i, end=' ')
print()


