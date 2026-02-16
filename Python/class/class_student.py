class Student:
    def __init__(self, name, korean, math, english, science): #생성자
        self.name=name
        self.Korean=korean
        self.math=math
        self.english=english
        self.science=science

    def score_sum(self):
        return self.Korean+self.math+self.english+self.science

    def score_average(self):
        return self.score_sum()/4

    def student_info(self):
        return f"{self.name}\t{self.score_sum()}\t{self.score_average()}"

students = [
    Student("윤이성", 87, 98, 88, 99),
    Student("연하진", 88, 99, 88, 100)
]

for student in students:
    print(student.student_info())


