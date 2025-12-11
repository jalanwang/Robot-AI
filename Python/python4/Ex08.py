class Student:
    def study(self):
        print('공부를 합니다.')

    def __init__(self):
        pass

class Teacher:
    def teach(self):
        print('학생을 가르칩니다')
    
    def __init__(self):
        pass

if __name__ == '__main__':
    classroom=[Student(), Student(),Teacher(),Student(),Student()]

    for person in classroom:
        if isinstance(person, Student):
            person.study()
    
        elif isinstance(person, Teacher):
            person.teach()

