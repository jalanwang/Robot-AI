#제너레이터 테스트
#정수를 만드는 것이 필요해
#
import random

def func1():
    while True:
        yield random.randint(1,100)
        print(random.randint(1,100))
print()
print()
int_gen = func1()

for _ in range(5):
    print(next(int_gen))