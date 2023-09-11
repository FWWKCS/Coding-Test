def solution(k, d):
    answer = 0
    y = d
    for a in range(d//k + 1) :
        x = a*k
        while True :
            if x**2 + y**2 <= d**2 :
                answer += y // k + 1
                break
            else :
                y -= 1
        
    return answer