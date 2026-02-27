# 이렇케 하면 안된다. 함수 안에 함수의 인자를 넣어서 전달이 안되네
# 람다로 표현하면 된다고 하는데 나중에 ...

def call_10_times(func):
    for i in range(10):
        func()


def say_hello(text):
    print(text)

call_10_times(say_hello("안녕하세요"))
    
