import cv2
import numpy as np

# 이미지 로드
image = cv2.imread('images/trafficLight.jpg')

# BGR 색공간에서 HSV 색공간으로 변환
hsv_image = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)

# 색상 범위 정의
# 빨강 색상 범위
lower_red1 = np.array([0, 100, 100])
upper_red1 = np.array([10, 255, 255])
lower_red2 = np.array([160, 100, 100])
upper_red2 = np.array([180, 255, 255])

# 노랑 색상 범위
lower_yellow = np.array([20, 100, 100])
upper_yellow = np.array([30, 255, 255])

# 초록 색상 범위
lower_green = np.array([35, 100, 100])
upper_green = np.array([85, 255, 255])

# 마스크 생성
mask_red1 = cv2.inRange(hsv_image, lower_red1, upper_red1)
mask_red2 = cv2.inRange(hsv_image, lower_red2, upper_red2)
mask_red = cv2.add(mask_red1, mask_red2)

mask_yellow = cv2.inRange(hsv_image, lower_yellow, upper_yellow)
mask_green = cv2.inRange(hsv_image, lower_green, upper_green)

# 결과 이미지 생성
red_result = cv2.bitwise_and(image, image, mask=mask_red)
yellow_result = cv2.bitwise_and(image, image, mask=mask_yellow)
green_result = cv2.bitwise_and(image, image, mask=mask_green)

# 이미지 출력
cv2.imshow('Red Channel', red_result)
cv2.imshow('Yellow Channel', yellow_result)
cv2.imshow('Green Channel', green_result)

cv2.waitKey(0)
cv2.destroyAllWindows()
