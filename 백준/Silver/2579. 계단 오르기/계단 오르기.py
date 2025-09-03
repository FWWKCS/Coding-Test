N = int(input())
stairs = [0] + [int(input()) for _ in range(N)]

dp = [[0 for _ in range(N+1)] for _ in range(3)]
dp[1][1] = stairs[1]

for idx in range(2, N+1):
    dp[1][idx] = max(dp[1][idx-2], dp[2][idx-2]) + stairs[idx]
    dp[2][idx] = dp[1][idx-1] + stairs[idx]

print(max(dp[1][N], dp[2][N]))