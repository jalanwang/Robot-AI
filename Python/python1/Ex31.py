#4개 사칙연산 함수
def add(a, b):
    return (a+b)

def minus(a,b):
    return (a-b)

def multi(a,b):
    return (a*b)

def divide(a,b):
    if b==0:
        return -1
    return (a/b)

x=int(input("정수 입력하세요: >"))
y=int(input("정수를 입력하세요. >"))

print("{}+{}={}".format(x,y, add(x,y)))
print("{}-{}={}".format(x,y, minus(x,y)))
print("{}*{}={}".format(x,y, multi(x,y)))
print("{}/{}={}".format(x,y, divide(x,y)))

