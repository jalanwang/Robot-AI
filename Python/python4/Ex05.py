class Student:
    def __init__(self, name,korean, math, english, science):
        self.__name=name  ## private, 언더바가 한개면 프로텍트
        self.__korean=korean
        self.__math = math
        self.__english=english
        self.__science=science

    def get_sum(self):
        return self.__korean+self.__math+self.__english+self.__science
        
    def get_avg(self):
        return self.get_sum()/4

    def to_string(self):
        return "{}\t{}\t{}".format(self.__name, self.get_sum(), self.get_avg())

if __name__ =='__main__': # main()의 시작

    students=[
        Student('홍길동1', 100,100,100,100),
        Student('홍길동2', 99,99,99,99),
        Student('홍길동3', 88,88,88,88),
        Student('홍길동4', 77,77,77,77),
        Student('홍길동5', 66,66,66,66)
    ]

    print('이름', '총점', '평균', sep='\t')
    for person in students:
        print(person.to_string())
