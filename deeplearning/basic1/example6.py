import numpy as np

#c=np.array([[1,2,3,],[4,5,6]])
#print(c)
#f=np.flip(c, axis=1)
#print(f)
#f=np.flip(c, axis=0)
#print(f)

cc=np.array([[10,10],[20,20],[30,30]])
print(cc)
f=np.insert(cc, 1, [1,2,3], axis=1)
print(f)