import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6) 

def dfs(r,c): # (r,c)까지 갈 수 있는 경우의 수를 반환
    global memoization
    if memoization[r][c] > -1: # 기록된 위치 재사용, 연산 단축 
        return memoization[r][c]
    
    U, D, L, R = 0, 0, 0, 0
    # 위로 이동
    if r != 0 and target[r-1][c] > target[r][c]:
        U = dfs(r-1, c)
    # 아래로 이동
    if r < M-1 and target[r+1][c] > target[r][c]:
        D = dfs(r+1, c)
    # 왼쪽으로 이동
    if c != 0 and target[r][c-1] > target[r][c]:
        L = dfs(r, c-1)
    # 오른쪽으로 이동
    if c < N-1 and target[r][c+1] > target[r][c]:
        R = dfs(r, c+1)

    # 최종 경우의 수 기록
    memoization[r][c] = U+D+L+R
    return memoization[r][c]

M, N = map(int, input().split())
target = [list(map(int, input().split())) for _ in range(M)]

memoization= [[-1 for _ in range(N)] for _ in range(M)]
# [r][c]: (r,c) 까지의 경우의 수

memoization[0][0] = 1

print(dfs(M-1,N-1))