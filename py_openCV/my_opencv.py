import numpy as np
import cv2

image1 = np.zeros((300, 400), np.uint8)
image1.fill(255)

image2 = np.zeros((300, 400), np.uint8)
image2.fill(127)

image3 = np.zeros((300, 400), np.uint8)
image3.fill(0)

cv2.imshow('Window title1', image1)
cv2.imshow('Window title2', image2)
cv2.imshow('Window title3', image3)

cv2.waitKey(0)
cv2.destroyAllWindows()
