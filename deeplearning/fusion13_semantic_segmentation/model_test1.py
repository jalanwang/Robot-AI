import numpy as np
from PIL import Image
from tensorflow import keras
import os

# 1. 학습된 모델 로드
model = keras.models.load_model("model.keras")

# 2. 클래스 이름 정의 (순서가 학습 때와 동일해야 함)
labels = ["paper", "rock", "scissors"]

# 모델이 요구하는 입력 사이즈 추출 (Height, Width)
input_shape = model.input_shape[1:3]

def predict_image(img_path):
    try:
        # 이미지 로드 및 RGB 변환 (RGBA 등 예외 방지)
        img = Image.open(img_path).convert("RGB")

        # 모델 입력 사이즈에 맞게 리사이즈
        img = img.resize((input_shape[1], input_shape[0]))

        # 정규화 및 넘파이 배열 변환
        img_array = np.array(img, dtype=np.float32) / 255.0
        img_array = np.expand_dims(img_array, axis=0) # (1, H, W, 3)

        # 예측 실행
        predictions = model.predict(img_array, verbose=0)

        # 가장 높은 확률을 가진 인덱스 추출
        result_idx = np.argmax(predictions[0])
        confidence = predictions[0][result_idx]

        # 결과 출력
        print(f"{os.path.basename(img_path):20} → {labels[result_idx]} ({confidence*100:.2f}%)")

    except Exception as e:
        print(f"Error processing {img_path}: {e}")

# 3. 테스트할 이미지 폴더 순회
test_folder = "test_images"

# 폴더 존재 확인 후 실행
if os.path.exists(test_folder):
    print(f"Testing images in '{test_folder}'...\n")
    for file in os.listdir(test_folder):
        if file.lower().endswith(('.png', '.jpg', '.jpeg')):
            predict_image(os.path.join(test_folder, file))
else:
    print(f"Error: Folder '{test_folder}' not found.")
