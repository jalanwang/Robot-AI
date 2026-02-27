import tensorflow as tf
import numpy as np

# 모델을 읽어 오는 루틴
model = tf.keras.models.load_model("model.keras")

# 정규화 값으로 변환하는 루틴
# 전역변수로 사용하는 방법을 적용해 볼 것

height = 172.0 / 194.2
weight = 60.5 / 130.7


x=np.array([[height, weight, 1]])

result = model.predict(x)
print(result)

