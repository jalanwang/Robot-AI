import numpy as np

#a=np.array[1,3,4,5]
#print(a)
#print()
#np.insert(a,2,2)

b=[[1,1], [2,2], [3,3]]
b_pr1=np.insert(b, 1,4,axis=0)
print(b_pr1)
#[5,6]을 넣으려면
print(np.insert(b, 1, [5,6], axis=0))

print()
b_pr2=np.insert(b, 1, 4, axis=1)
print(b_pr2)
