import numpy as np
# reshape
#a=[1,2,3,4,5,6,7,8]
#b=[1,2,3,4,5,6,7,8]
#print(a)

#a1=np.reshape(a, (4,2))
#print(a1)

#b1=np.reshape(a,(2,-1))
#print(b1)

# quiz
# 1에서 9까지의 정수 값을 크기 순서대로 가지는 3*3 크기의 행렬 a를
# arrange()와 reshape()을 이용하여 생성하여라.
# 모든 성분의 값이 3인 3*3 크기의 행렬 b를 full() 함수를 사용하여
# 생성하여라. a와 b를 다음과 같이 출력하여라.

#a=[[1,2,3],[4,5,6],[7,8,9]]
#b= [[3,3,3],[3,3,3],[3,3,3]]

#for i in np.arange(10):

a=np.arange(1,10, 1)
print(np.reshape(a,(-1,3)))
