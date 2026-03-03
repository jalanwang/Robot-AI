import numpy as np
from PIL import Image
from tensorflow import keras
import os
import matplotlib.pyplot as plt

# 1. 학습된 모델 로드
model = keras.models.load_model("model.keras")

# 2. 클래스 이름 (데이터 로더의 폴더 순서와 일치해야 함)
labels = ["paper", "rock", "scissors"]

# 모델의 입력 사이즈 추출
input_shape = model.input_shape[1:3]  # (height, width)

def predict_image(img_path):
    # 이미지 로드 및 전처리
    img_raw = Image.open(img_path).convert("RGB")
    img_resized = img_raw.resize((input_shape[1], input_shape[0])) # width, height 순서

    img_array = np.asarray(img_resized) / 255.0
    img_input = np.expand_dims(img_array, axis=0)

    # 예측 실행
    predictions = model.predict(img_input, verbose=0)

    # Softmax 결과에서 가장 높은 확률의 인덱스 추출
    result_idx = np.argmax(predictions[0])
    confidence = predictions[0][result_idx]
    label_text = labels[result_idx]

    # 터미널 출력
    print(f"{img_path} → {label_text} ({confidence:.4f})")

    # --- 이미지 시각화 루틴 추가 ---
    plt.figure(figsize=(6, 6))
    plt.imshow(img_raw)
    plt.title(f"Predict: {label_text} ({confidence*100:.2f}%)", fontsize=15)
    plt.axis('off') # 격자 숨기기
    plt.show()
    # ------------------------------

# 테스트할 이미지 폴더
test_folder = "test_images"

if os.path.exists(test_folder):
    for file in os.listdir(test_folder):
        if file.lower().endswith(('.png', '.jpg', '.jpeg')):
            predict_image(os.path.join(test_folder, file))
else:
    print(f"폴더가 존재하지 않아: {test_folder}")
