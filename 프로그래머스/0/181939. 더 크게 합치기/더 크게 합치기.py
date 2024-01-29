def solution(a, b):
    answer = 0
    x_a = str(a)+str(b)
    x_b = str(b)+str(a)
    
    answer = int(x_a) if int(x_a) >= int(x_b) else int(x_b)
    return answer