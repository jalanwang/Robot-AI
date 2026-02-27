import cv2
from ultralytics import YOLO

image = cv2.imread('images/whereismydobbi.jpg')
image_resized = cv2.resize(image, (755, 500))

# YOLOv8 모델 로드 (개, 고양이 등 동물 감지)
model = YOLO('yolov8n.pt')

# 이미지에서 객체 감지
results = model(image_resized)

# 동물 클래스 ID (COCO 데이터셋 기준)
# dog: 16, cat: 15, bird: 14, horse: 17, sheep: 18, cow: 19, elephant: 20, bear: 21, zebra: 22, giraffe: 23
animal_classes = {15, 16, 17, 18, 19, 20, 21, 22, 23}

# 감지된 객체들에 박스 그리기
for result in results:
    for box in result.boxes:
        cls_id = int(box.cls[0])  # 클래스 ID

        # 동물인 경우에만 박스 그리기
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

