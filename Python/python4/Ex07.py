#데코레이터가 무엇인지를 보여주는 코드

def test(function):
    def wrapper():
        print("인사가 시작되었습니다.")
        function()
        print("인사가 종료되었습니다.")
    
    return wrapper #이거 조금 수상한 코드인데???

@test #hello()가 test(function)의 function에 들어간다.
def hello():
    print('hello')

hello()
