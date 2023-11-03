import sys
input = sys.stdin.readline

def cal_matrix(A, B):
    X = [[0 for _ in range(N)] for _ in range(N)]
    for r in range(N):
        for c in range(N):
            for t in range(N):
                X[r][c] += A[r][t] * B[t][c]
    return X

def split_exponent(K, A):
    if K == 1 : 
        for r in range(N):
            for c in range(N):
                A[r][c] %= MOD
        
        return A

    tmp = split_exponent(K//2, A)
    
    if K % 2 != 0:
        X = cal_matrix(cal_matrix(tmp, tmp), A)
    else :
        X = cal_matrix(tmp, tmp)
        
    for r in range(N):
        for c in range(N):
            X[r][c] %= MOD
            
    return X

MOD = 1000
N, K = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]

X = split_exponent(K, A)
for x in X : print(*x)