from abc import ABC, abstractmethod

class Vehicle(ABC):
    @abstractmethod
    def run(self):
        print('차는 움직입니다')

class Taxi:
    def run(self):
        print('택시는 사람을 옮깁니다.')
    
    def __str__(self):
        return '택시'
    
class Truck:
    def run(self):
        print('트럭은 짐을 옮깁니다')

    def __str__(self):
        return '트럭' ## 원래는 return super().xx 부모의 주소를 반환. 그런데 안보여주고 있는 것임


class Bus:
    def run(self):
        print('버스는 운행합니다.')

    def __str__(self):
        return '버스'

    

# main 함수
if __name__ == "__main__":
    # 부모 클래스 타입으로 자식 인스턴스를 관리 (C++의 Shape* 개념)
    vehicles: list[Taxi] = [ #: list[Shape] <<< 이건 타입을 보여주기 위해서. 없어도 된다.
        Taxi(),
        Truck(),
        Bus()
    ]

    # 다형성: 부모 타입으로 호출해서 자식 객체를 사용
    for v in vehicles:
        v.run()
    
    print()
    
    vehicles[0].run() # 인덱스로 받아서 사용.

    print('*'*20)
    print(Taxi()) #객체의 리턴값을 프린트

    