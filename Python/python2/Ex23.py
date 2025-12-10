#lotto 번호 구하기
import random

list_a = range(1,46)
lucky = random.sample(list_a, k=7)
lotto=sorted(lucky[0:6])
bonus=lucky[-1]

print(f"로또번호: {*lotto,}, 보너스 번호: {bonus}")