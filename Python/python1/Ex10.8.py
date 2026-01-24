computer={} #dictionary 초기화

computer['cpu']='Intel i7' #입력 방법
computer['ram']='DDR 5 64G'
computer['GPU']='Nvidia 5090 TI'

print(computer)
print(computer.keys()) #키만 출력
                       #dict_keys(['cpu', 'ram', 'GPU'])
print(type(computer.keys())) # 튜플인가?
                             # <class 'dict_keys'> 별도 클라스라고 하는데?
                             # 아니라고 함. 왜 보여줄 땐, 튜플처럼 보여줬을까?
print(computer.values()) #값만 출력

print(computer['cpu']) #키에 따른 값 출력

