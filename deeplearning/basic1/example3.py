import numpy as np

img=np.ones((512,512))
print(img)
#img=img*255
#print(img)
#np.full((512,512),255,dtype=np.uint8)
#print(img*255)

#a=np.eye(4, 4)
#대각선을 그리려면
a=np.eye(512, dtype=np.uint8)
#a=np.eye(4)
a=a*255
print(a)






