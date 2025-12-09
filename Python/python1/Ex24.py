#2의 거듭제곱을 리스트 표현식으로 만들어 보시오

#[2,4,8,16,.... 1024]

list_a = [2**i for i in range(1,11)]
print(list_a)


#구구단 3단의 결과만 리스트 표현식

list_b=[3*i for i in range(1, 10)]
print(list_b)