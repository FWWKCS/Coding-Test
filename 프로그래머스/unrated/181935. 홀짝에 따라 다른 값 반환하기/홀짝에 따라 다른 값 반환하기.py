def solution(n):
    answer = 0
    if n % 2 == 0 :
        for k in range(n, 0, -2) :
            answer += k ** 2
    else :
        for k in range(n, 0, -2) :
            answer += k
    
    return answer