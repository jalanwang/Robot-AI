import tensorflow as tf
import numpy as np
from PIL import Image

# 1. 모델 로드
model = tf.keras.models.load_model("model.keras")

# 2. 이미지 로드 및 전처리
img_path = 'data/human/human01-00.jpg' # 경로 수정
img = Image.open(img_path).convert("RGB") # RGB 변환
img = img.resize((128, 128)) # 학습 때와 동일한 크기로 리사이징

# 3. 넘파이 배열 변환 및 정규화
x = np.asarray(img) / 255.0

# 4. 차원 확장 (H, W, C) -> (1, H, W, C)
x = np.expand_dims(x, axis=0)

# 5. 예측
result = model.predict(x)

# 6. 결과 해석 (Sigmoid 사용 시 0.5 기준)
if result[0][0] > 0.5:
    print(f"결과: 사람 ({result[0][0]*100:.2f}%)")
else:
    print(f"결과: 말 ({(1-result[0][0])*100:.2f}%)")
