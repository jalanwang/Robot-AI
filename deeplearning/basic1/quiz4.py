# 다차원 행렬의 생성과 활용
#1에서 9까지의 정수 값을 크기 순서대로 가지는 3*3 크기의 행렬 a를
#arrange()와 reshape()을 이용하여 생성하여라.
#모든 성분의 값이 3인 3*3 크기의 행렬 b를 full() 함수를 사용하여
#생성하여라. a와 b를 다음과 같이 출력하여라.

#a=[[ 1 2 3]    b=[[3 3 3]
#   [ 4 5 6]       [3 3 3]
#   [ 7 8 9]]      [3 3 3]

import numpy as np

np_a=np.arange(1,10,1)
new_np_a= np_a.reshape(3,3)
print(new_np_a)

np_b=np.full((3,3),3)
print(np_b)