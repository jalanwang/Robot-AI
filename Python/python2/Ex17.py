#NotImplementedError
try:
    number=int(input('정수 입력')) # 정수가 아닌값 입력 시 예외발생
    if number>0:
        raise NotImplementedError # 무조건 발생
    else:
        raise NotImplementedError # 무조건 발생
except: 
    print('예외가 발생했습니다')
