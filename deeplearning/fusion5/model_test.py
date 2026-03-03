import tensorflow as tf
import numpy as np

# 모델을 읽어 오는 루틴
model=te.keras.models.load_mode("model.keras")model_weight = tf.keras.models.load_model("model_weight.keras")

# 정규화 값으로 변환하는 루틴
# 전역변수로 사용하는 방법을 적용해 볼 것
idx=[137.7 , 99.6, 198.4, 160.,  103.7,  63.9,  34.2, 135. ]#

chest = 180/idx[0]
arm = 80/idx[1]
height = 180/idx[2]
waist=100/idx[3]
sat=90/idx[4]
head=90/idx[5]
feet=27/idx[6]

x=np.array([[chest, arm, feet, waist, sat, head]])
result1=model_height.predict(x) * 198.4
result2=mode_weight.predict(x) * 135.0