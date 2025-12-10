def print_n_times(n=10, *values):
#def print_n_times(*values, n=3):    
    #n번 반복
    for i in range(n):
        for value in values:
            print(value)
        print()

#print_n_times(10, "안녕")
#print_n_times("안녕", "누구세요?", n=3)
print_n_times(3, "안녕", "누구세요?")