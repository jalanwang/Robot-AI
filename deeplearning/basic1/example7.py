import numpy as np

arr_2d=np.array([[1,2,3], [4,5,6],[7,8,9], [0,1,2]])
print(arr_2d)

print(arr_2d[2])
print(arr_2d[1,1]) #이걸 더 선호

print(arr_2d[2][0:2])
print(arr_2d[2,0:2]) #이걸 더 선호


print(arr_2d[1:,0:2]) #이건 차원을 그대로 가지고 온다.
print(arr_2d[1:,1]) #이건 차원을 그대로 가지고 온다.


a=np.array([[1,2,3],[4,5,6],[7,8,9],[0,1,2]])
s=a[1:, 0:2]
print(s)

zz=np.array([[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]])
rr=zz[zz%2==0]
print(rr)
