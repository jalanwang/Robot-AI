#다음 빈칸을 채워 매개변수로 전달된 값들을 모두 곱해서 리턴하는
#가변 매개변수 함수를 만들어 보세요.

def mul(*values):
    sum=1
    for value in values:
        sum*=value
    return sum

print(mul(5,7,9,10))