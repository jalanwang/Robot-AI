#클래스 private 설명 코드
# 

class Person:
    def __init__(self, name):
        self.__name=name
    #getter
    def getName(self):
        return self.__name
    #setter
    def setName(self, name):
        self.__name=name

#main
soonsin = Person('이순신')
print(soonsin.getName())
soonsin.setName('강감찬')
print(soonsin.getName())

