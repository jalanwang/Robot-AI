# 1부터 숫자를 하나씩 증가시키면서 더하는 경우를 생각해 봅시다.
# 몇을 더할 때 1000을 넘는지 구해 보세요.
# 그리고 그때의 값도 출력해 보세요.
# 다음은 10000이 넘는 경우를 보이는 예제입니다.


#1, 1+2=3, 1+2+3=6...

limit=1000
sum_value=0

for it in range(1, 10000, 1):
    sum_value=sum_value+it
    print(sum_value)
    if(sum_value>limit):
        break

print("{}을 더할 때 {}을 넘으며 그때의 값은 {}입니다.".format(it, limit, sum_value))