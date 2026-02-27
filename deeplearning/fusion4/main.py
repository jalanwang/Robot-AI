"""
Author : Byunghyun Ban
Date : 2020.07.24.
"""
from tensorflow import keras
import data_reader

# 몇 에포크 만큼 학습을 시킬 것인지 결정합니다.
EPOCHS = 50  # 예제 기본값은 50입니다.

# 데이터를 읽어옵니다.
dr1 = data_reader.DataReader(height)
dr2 = data_reader.DataReader(weight)

# 인공신경망을 제작합니다.
model_heigth = keras.Sequential([
    keras.layers.Dense(6),
    keras.layers.Dense(256, activation="relu"),
    keras.layers.Dense(256, activation="relu"),
    keras.layers.Dense(256, activation="relu"),
    keras.layers.Dense(256, activation="relu"),
    keras.layers.Dense(1, activation='sigmoid')
])

# 인공신경망을 제작합니다.
model_weight = keras.Sequential([
    keras.layers.Dense(6),
    keras.layers.Dense(256, activation="relu"),
    keras.layers.Dense(256, activation="relu"),
    keras.layers.Dense(256, activation="relu"),
    keras.layers.Dense(256, activation="relu"),
    keras.layers.Dense(1, activation='sigmoid')
])


# 인공신경망을 컴파일합니다.
model_hight.compile(optimizer="adam", loss="mse", metrics=['mae'])
model_weight.compile(optimizer="adam", loss="mse", metrics=['mae'])

# 인공신경망을 학습시킵니다.
print("\n\n************ TRAINING START for height ************ ")
early_stop = keras.callbacks.EarlyStopping(monitor='val_loss', patience=10)
history1 = model_height.fit(dr1.train_X, dr1.train_Y, epochs=EPOCHS,
                    validation_data=(dr1.test_X, dr1.test_Y),
                    callbacks=[early_stop])
print("\n\n************ TRAINING START2 for weight ************ ")
early_stop = keras.callbacks.EarlyStopping(monitor='val_loss', patience=10)
history2 = model_weight.fit(dr2.train_X, dr2.train_Y, epochs=EPOCHS,
                    validation_data=(dr2.test_X, dr2.test_Y),
                    callbacks=[early_stop])


# 학습 결과를 그래프로 출력합니다.
data_reader.draw_graph(model_height(dr1.test_X), dr1.test_Y, history1)
data_reader.draw_graph(model_weight(dr2.test_X), dr2.test_Y, history2)

# 모델 저장
model_height.save("model.height.keras")
model_weight.save("model_weight.keras")
