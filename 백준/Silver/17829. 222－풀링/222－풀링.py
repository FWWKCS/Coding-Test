# n^2 행렬 (n은 2의 배수)
# 가장 작은 행렬(n=2)로 쪼개어 각 행렬의 2번째로 큰 수만 수합
# 이 과정을 값 하나를 출력할 때까지 반복
def minimalize(matrix, length, r, c) : # 행렬, 길이, 시작행 인덱스, 시작열 인덱스
    global n
    tmp = [] # 영역의 수 중 2번째로 큰 수를 판별할 리스트

    if length > 2 :
        # 2 사분면
        tmp.append(minimalize(matrix, length//2, r, c))
        # 1 사분면 
        tmp.append(minimalize(matrix, length//2, r, c+length//2))
        # 3 사분면
        tmp.append(minimalize(matrix, length//2, r+length//2, c))
        # 4 사분면
        tmp.append(minimalize(matrix, length//2, r+length//2, c+length//2))

        tmp = sorted(tmp) # 정렬
        # 길이가 length일때, 
        # 만들어진 tmp의 4개의 값 중 2번째로 큰 수를 2*length 행렬에 대한 tmp에게 전달
        # 반환 과정은 length = n 일때까지 진행  
        return tmp[-2]

    # 가장 작은 행렬에 도달하면 tmp의 2번쨰로 큰 값을 반환
    elif length == 2 :
        for i in range(r, r+length) :
            for j in range(c, c+length) :
                tmp.append(matrix[i][j])
        
        tmp = sorted(tmp) # 정렬
        return tmp[-2]

n  = int(input())
matrix = [list(map(int, input().split())) for _ in range(n)]

# for m in matrix : print(*m)

total = minimalize(matrix, n, 0, 0)
print(total)