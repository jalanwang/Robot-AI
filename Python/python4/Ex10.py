class Student:

    #클래스 변수
    count=0
    Students=[]

    #클래스 메소드
    @classmethod
    def print(cls):
        print(' ----- 학생 목록 -----')
        print('이름\t총점\t평균')
        for student in cls.Students:
            print(str(student))
        print('--------------------------')
    
    def __init__(self, name, korean, math, english, science):
        self.name = name
        self.korean=korean
        self.math=math
        self.english=english
        self.science=science
        Student.count +=1
        Student.Students.append(self)        

    def get_sum(self):
        return self.korean+self.math+ self.english+self.science
    
    def get_average(self):
        return self.get_sum()/4
    
    def __str__(self):
        return "{}\t{}\t{}".format(self.name, self.get_sum(), self.get_average())
    
Student("윤인성", 99,33,33,33)
Student("윤인성1", 99,33,33,33)
Student("윤인성2", 99,33,33,33)
Student("윤인성3", 99,33,33,33)
Student("윤인성4", 99,33,33,33)
Student("윤인성5", 99,33,33,33)
Student("윤인성6", 99,33,33,33)
Student("윤인성7", 99,33,33,33)
Student("윤인성8", 99,33,33,33)
Student("윤인성9", 99,33,33,33)
Student("윤인성10", 99,33,33,33)    

Student.print()

