import tensorflow as tf
import numpy as np

# 모델을 읽어 오는 루틴
model = tf.keras.models.load_model("model.keras")

# 정규화 값으로 변환하는 루틴
# 전역변수로 사용하는 방법을 적용해 볼 것

feat1 = 1
feat2 = 1
feat3 = 1
feat4 = 1

x=np.array([[feat1, feat2, feat3, feat4]])

result = model.predict(x)
print(result)

