def solution(num_list, n):
    answer = []
    '''for i in num_list[n-1:]:
        answer.append(i)'''
    answer = num_list[n-1:]
    return answer

if __name__ == '__main__':
    print(solution([2, 1, 6], 2)) # [1, 6]
 