def solution(arr, queries):
    answer = []
    for q in queries :
        s, e, k = q
        value = 1000001
        for i in range(s, e+1) :
            if arr[i] > k :
                value = min(arr[i], value)
        
        if value > 1000000 :
            value = -1
        answer.append(value)
    return answer