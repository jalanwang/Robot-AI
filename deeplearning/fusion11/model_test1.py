import numpy as np
from PIL import Image
from tensorflow import keras
import os

# 학습된 모델 로드
model = keras.models.load_model("model.keras")

# 클래스 이름 (DataReader와 동일하게)
labels = ["horse", "human"]

input_shape = model.input_shape[1:3]  # (height, width)

def predict_image(img_path):
    img = Image.open(img_path)
    img = img.resize(input_shape)
    img = np.asarray(img) / 255.0
    img = np.expand_dims(img, axis=0)

    logit = model.predict(img)[0][0]
    prob = 1 / (1 + np.exp(-logit))
    human_prob = prob
    horse_prob = 1 - prob

    if human_prob > 0.5:
        print(f"{img_path} → human ({human_prob:.4f})")
    else:
        print(f"{img_path} → horse ({horse_prob:.4f})")

    #label = labels[1] if prob > 0.5 else labels[0]
    #print(f"{img_path} → 예측: {label} ({prob:.4f})")


# 테스트할 이미지 폴더
test_folder = "test_images"

for file in os.listdir(test_folder):
    predict_image(os.path.join(test_folder, file))
