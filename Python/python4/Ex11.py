# import math

# class Circle:
#     def __init__(self, radius=1):
#         self.__radius=radius

#     def getRadius(self):
#         #보안, 암호화, 복호화, 로그 ...
#         return self.__radius
    
#     def setRadius(self, radius):
#         #보안, 암호화, 복호화, 로그 ...
#         self.__radius = radius
    
# if __name__ == '__main__':
#     circle = Circle()
#     circle.radius=7 # 이건 안됨
#     circle.setRadius(7) # 이건 됨
    
#     print(circle.getRadius())

import math

class Circle:
    def __init__(self, radius=1):
        self.__radius=radius

    @property
    def radius(self):
        return self.__radius
    
    @radius.setter
    def radius(self, value):
        if value<0:
            raise TypeError('길이는 양의 숫자여야 합니다.')
        self.__radius=value
        

if __name__ == '__main__':
    circle = Circle()
    circle.radius=7 # 이건 되야 되는데????
    #circle.setRadius(8) # 이건 안됨. 없잖아.
    
    print(circle.radius)
    

