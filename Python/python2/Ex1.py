def call_10_times(func):
    for i in range(10):
        func()


def say_hello(text):
    print(text)

call_10_times(say_hello("안녕하세요"))
    
