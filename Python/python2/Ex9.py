#제너레이터
def test():
    print("A 지점 통과")
    yield 1

    print("B 지점 통과")
    yield 2

    print("C 지점 통과")
    yield 3

output=test()

print("D 지점 통과")
next(output)
next(output)
next(output)
test()