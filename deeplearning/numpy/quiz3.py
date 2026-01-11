#flip()함수를 이용한 정렬 결과 보여주기
#위의 결과를 수정하여 d배열의 값이 axis 1, axis 0 방향에 대하여
#각각 내림차순 정렬이 되도록 하고
#그 결괄를 출력하여라
#(힌트: 넘파이의 flip() 함수를 사용해보자)

#array([[55, 35, 24], [69, 19, 9], [11, 4, 1]])
import numpy as np

d=np.array([[55,35,24],[69,19,9],[11,4,1]])
sorted_axis1=np.sort(d, axis=1)
flipped_axis1=np.flip(sorted_axis1, axis=1)
print(sorted_axis1)
print(flipped_axis1)

sorted_axis0=np.sort(d, axis=0)
flipped_axis0=np.flip(sorted_axis0, axis=0)
print(sorted_axis0)
print(flipped_axis0)
flipped_axis1=np.flip(d, axis=1)









