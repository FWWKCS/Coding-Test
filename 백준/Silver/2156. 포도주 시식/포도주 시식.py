N = int(input())
wines = [0] + [int(input()) for _ in range(N)]

dp = [0 for _ in range(N+1)]
dp[1] = wines[1]
if N > 1: dp[2] = dp[1] + wines[2]

for i in range(3, N+1):
    dp[i] = max(dp[i-1], 
                    max(dp[i-2], dp[i-3]+wines[i-1]) + wines[i])

print(dp[N])