#try, except, else, finally 종합 연습
#with file

with open('test.txt', 'r') as file:
    try: 
        txt=file.read()
    except:
        print("파일이 없습니다.")
