import cv2
cap = cv2.VideoCapture(0)
while cap.isOpened():
    success, image = cap.read()
    if not success:
      print("카메라를 찾을 수 없습니다.")
      # 동영상을 불러올 경우는 'continue' 대신 'break'를 사용합니다.
      continue
    grayImg = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    cascade_face_detector = cv2.CascadeClassifier('haarcascades/haarcascade_frontalface_default.xml')
    face_detections = cascade_face_detector.detectMultiScale(grayImg, scaleFactor=1.03, minNeighbors=2, minSize=(100,100))
    for (x, y, w, h) in face_detections:
        cv2.rectangle(image, (x, y), (x + w, y + h), (0, 255, 0), 2)

    cv2.imshow("detect",cv2.flip(image, 1))
    if cv2.waitKey(5) & 0xFF == 27:
            break
