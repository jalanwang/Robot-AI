import cv2
from ultralytics import YOLO

model = YOLO('yolov8n.pt')
# yolo v8n 가중치를 사용한다.
# git 코드를 분석해보니 YOLO라는 함수안에서 yolov8n.pt가 default이고,
# string으로 넘겨준 모델이 없으면 git에서 download하여 사용한다.
# 잘못된 글자라면 에러가 출력됨

image = cv2.imread('images/airport.jpg')
image_resized=cv2.resize(image, (640, 480))

model = YOLO('yolov8n.pt')

results= model(image_resized)
person_detected = False

human =0
animal_classes = {15, 16, 17, 18, 19, 20, 21, 22, 23}

# 감지된 객체들에 박스 그리기
for result in results:
    for box in result.boxes:
        cls_id = int(box.cls[human])  # 클래스 ID

        # 사람인 경우에는
        if cls_id == human:
            x1, y1, x2, y2 = map(int, box.xyxy[0])
            confidence = box.conf[0]

            # 초록색 박스 그리기
            cv2.rectangle(image_resized, (x1, y1), (x2, y2), (0, 0, 255), 2)

            # 신뢰도 표시
            label = f"Human: {confidence:.2f}"
            cv2.putText(image_resized, label, (x1, y1 - 10),
                       cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 2)

        # 동물인 경우에 박스 그리기
        if cls_id in animal_classes:
            x1, y1, x2, y2 = map(int, box.xyxy[0])
            confidence = box.conf[0]

            # 초록색 박스 그리기 (동물만)
            cv2.rectangle(image_resized, (x1, y1), (x2, y2), (0, 255, 0), 2)

            # 신뢰도 표시
            label = f"Animal: {confidence:.2f}"
            cv2.putText(image_resized, label, (x1, y1 - 10),
                       cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)

cv2.imshow("detect", image_resized)

cv2.waitKey(0)


