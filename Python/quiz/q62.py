# 생성자
# 멤버, private id:numeric, name:str, pnumber:str
class Student:
    def __init__(self, id=-1, name='학생', pnumber='000-00000-0000'):
        self.__id =id
        self.__name=name        
        self.__pnumber=pnumber


    def study(self):
        print(self.__name, "은 공부를 합니다")


    def __str__(self):
        return '{} / {} / {}'.format(self.__id, self.__name, self.__pnumber)
    
    def getId(self):
        return self.__id
        
    def getName(self):
        return self.__name
    
    def getPnumber(self):
        return self.__pnumber
        
    def setId(self, id):
        self.__id=id
    
    def setName(self, name):
        self.__name=name

    def setPnumber(self, pnumber):
        self.__pnumber=pnumber



if __name__ == '__main__':    

    james=Student(0, 'James', '000 0000 0000')
    print(james.getName())
    james.setName('Tomas')
    print(james.getName())

    ## tomas 학생이 공부를 합니다를 출력하시오.
    
    tomas=Student() #기본생성자로 생성
    tomas.setName('Tomas')

    tomas.study() ## 이젠되네!
    print(tomas.getName())

    print(tomas)    

