class Student:
    def printName(self):
        print("안녕하세용")
        print()

if __name__=='__main__':
    # python ./thisfile.py 이러면 이 파일이 __name__ 변수가 __main__으로 바뀐다.
    # import ./thatfile이 있으면 thatfile은 __main__ 값을 가지지 못한다. __name__ == thatfile
    student=Student()
    student.printName()


    