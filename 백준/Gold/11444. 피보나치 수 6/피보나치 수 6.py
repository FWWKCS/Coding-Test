N = int(input())
MOD = 1000000007
A = [[1,1],[1,0]]

def cal_matrix(A, B):
    X = [[0,0],[0,0]]
    for r in range(2):
        for c in range(2):
            for x in range(2):
                X[r][c] += A[r][x] * B[x][c]
    return X

def split_exponent(A, K):
    if K == 1:
        return A
    
    tmp = split_exponent(A, K//2)
    if K % 2 != 0:
        X = cal_matrix(cal_matrix(tmp, tmp), A)
    else:
        X =  cal_matrix(tmp, tmp)
    
    for r in range(2):
        for c in range(2):
            X[r][c] %= MOD

    return X

M = split_exponent(A, N)
print(M[1][0])