import sys
input = sys.stdin.readline

N, M = map(int, input().split())
table = [[0 for _ in range(N+1)]] + [[0] + list(map(int, input().split())) for _ in range(N)]

dp = [[0 for _ in range(N+1)] for _ in range(N+1)]
# dp[r][c] : (0,0)부터 (r,c)까지의 누적합

for r in range(1,N+1) :
    for c in range(1, N+1) :
        dp[r][c] = table[r][c] + dp[r-1][c] + dp[r][c-1] - dp[r-1][c-1]

for _ in range(M) :
    x1, y1, x2, y2 = map(int, input().split()) # (x, y)는 x행 y열을 의미한다
    print(dp[x2][y2] - (dp[x2][y1-1] + dp[x1-1][y2]) + dp[x1-1][y1-1])