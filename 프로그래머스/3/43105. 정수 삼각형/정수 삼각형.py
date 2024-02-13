def solution(triangle):
    answer = []
    for i in range(len(triangle)):
        answer.append([0]*(i+1))
    answer[0][0] = triangle[0][0]
    
    for i in range(len(triangle)-1):
        for j in range(len(triangle[i])):
            answer[i+1][j] = max(answer[i+1][j], answer[i][j] + triangle[i+1][j])
            answer[i+1][j+1] = max(answer[i+1][j+1], answer[i][j] + triangle[i+1][j+1])
    
    return max(answer[-1])