class Student:
    def __init__(self, name,korean, math, english, science):
        self.name=name
        self.korean=korean
        self.math = math
        self.english=english
        self.science=science

    def get_sum(self):
        return self.korean+self.math+self.english+self.science
        
    def get_avg(self):
        return self.get_sum()/4

    def to_string(self):
        return "{}\t{}\t{}".format(self.name, self.get_sum(), self.get_avg())

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
