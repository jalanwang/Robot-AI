import numpy as np

# 그레디언트 디센트
# 분산을 구하는 이유는 2차 함수이기 때문이다.

a=np.array([[1,2], [1,-3]])
b=np.array([6,1])
s=np.linalg.solve(a,b)
print(s)

a=np.array([[1,1,-1],[2,-1,3],[1,2,1]])
b=np.array([0,9,8])
s=np.linalg.solve(a,b)
print(s)

A=np.array([[1,1,-1],[2,-1,3],[1,2,1]], dtype='int32')
print(np.linalg.det(A).round(2))

