# 생성자
# 멤버, private id:numeric, name:str, pnumber:str
# getter, setter를 @property로 만들자

class Student:
    def __init__(self, id=99999, name='학생'):
        self.__id =id
        self.__name=name

    def __str__(self):
        return '{} / {}'.format(self.__id, self.__name)
    
    @property
    def id(self):
        return self.__id

    @property    
    def name(self):
        return self.__name

    @id.setter            
    def id(self, id):
        if id<=0:
            raise TypeError('아이디는 1이상이어야 합니다.')
        self.__id=id
    
    @name.setter
    def name(self, name):
        self.__name=name

if __name__ == '__main__':    

    chulsoo=Student(1, '철수')

    chulsoo.id=2
    print(chulsoo.id, ':', chulsoo.name)

    chulsoo.name='철~~수'
    print(chulsoo, ':', chulsoo.name)