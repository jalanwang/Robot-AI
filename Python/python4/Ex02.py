class Student:
    def __init__(self, name,korean, math, english, science):
        self.name=name
        self.korean=korean
        self.math = math
        self.english=english
        self.science=science

if __name__ =='__main__':
    students=[
        Student('홍길동', 100,100,100, 100),
        Student('이순신', 99,99,99, 99)
    ]
    for person in students:
        print('{} {}'.format(person.name, person.korean))
    