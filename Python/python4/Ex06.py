#클래스 private 설명 코드
# 

class Person:
    def __init__(self, name):
        self.__name=name
    #getter
    def getName(self):
        return self.__name

#main
soonsin = Person('이순신')
print(soonsin.getName())
