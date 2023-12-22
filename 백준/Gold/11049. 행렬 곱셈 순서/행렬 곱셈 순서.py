import sys
input = sys.stdin.readline

N = int(input())
M = [0] + [tuple(map(int, input().split())) for _ in range(N)]

dp = [[float('inf') for _ in range(N+1)] for _ in range(N+1)]
# dp[i][j]: i부터 j행렬까지의 최소 연산
for r in range(1, N+1): # 주대각선 하향 삼각부분 inf로 미사용 처리
    for c in range(1, r+1):
        dp[r][c] = 0

memoization = [[float('inf') for _ in range(N+1)] for _ in range(N+1)]
# memoization[i][j]: i부터 j행렬까지 연산한 결과 행렬의 사이즈
for r in range(1, N+1):
    for c in range(r, N+1):
        if r == c:
            memoization[r][c] = M[r]
        x = M[r][0]
        z = M[c][1]

        memoization[r][c] = (x, z)

# 초기 각 인접 두 행렬 연산값 갱신
for r in range(1, N):
    x, y = M[r]
    y, z = M[r+1]

    dp[r][r+1] = x*y*z


row = 1
k = 0
col = row + 2 + k
while col <= N:
    for m in range(row, col):
        x, y = memoization[row][m]
        y, z = memoization[m+1][col]

        dp[row][col] = min(dp[row][col], 
                           dp[row][m] + dp[m+1][col] + (x*y*z))
    
    if col == N:
        row = 1
        k += 1
        col = row + 2 + k
    else:
        row += 1
        col += 1

print(dp[1][N])