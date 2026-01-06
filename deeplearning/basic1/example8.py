import numpy as np

a=[1,2,3,4,5,6]
maxNumber=max(a)
print(maxNumber)


a=np.array([1,2,3,4,5,6])
print(max(a))

print(a.mean())

print(a.astype(np.float64))


#24*24 gray 스케일은 flatten을 이용한 후 머신러닝에 넘겨준다.

b=np.array([[1,1], [2,2], [3,3]])
print(b)
f_b=b.flatten()
print(f'b: {f_b}')

print(b.T)
#pirnt(b.transpose()) 동일하다.

