import sys
input = sys.stdin.readline

N, K = map(int, input().split())

dp = [[0 for _ in range(N+1)] for _ in range(N+1)]
# dp[r][c] : r choose c
dp[0][0] = 1
for i in range(1, N+1) :
    dp[i][0] = 1
    dp[i][1] = i

for r in range(2, N+1) :
    for c in range(2, r+1) :
        dp[r][c] = ( dp[r-1][c-1] + dp[r-1][c] ) % 10007

print(dp[N][K])