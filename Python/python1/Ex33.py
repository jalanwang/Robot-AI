def factorial(n):
    output=1

    for i in range(1, n+1):
        output*=i
    return output

print(factorial(5))


def fact_self(x):
    if x==0:
        return 1
    else:
        x*fact_self(x-1)

print(fact_self(5))
