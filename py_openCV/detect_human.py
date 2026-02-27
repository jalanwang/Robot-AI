import cv2

image = cv2.imread('images/whereismydobbi.jpg')
image_resized = cv2.resize(image, (755, 500))
cascade_face_detector = cv2.CascadeClassifier('haarcascades//haarcascade_frontalface_default.xml')
face_detections = cascade_face_detector.detectMultiScale(image_resized)
for (x, y, w, h) in face_detections:
    cv2.rectangle(image_resized, (x, y), (x + w, y + h), (0, 255, 0), 2)

cv2.imshow("detect",image_resized)

cv2.waitKey(0)
