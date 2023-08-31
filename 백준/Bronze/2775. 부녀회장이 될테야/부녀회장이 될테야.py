import sys
input = sys.stdin.readline

dp = [[0 for _ in range(15)] for _ in range(15)]
for i in range(1,15) :
    dp[0][i] = i

for k in range(1,15) :
    for j in range(1,15) :
        dp[k][j] = dp[k][j-1] + dp[k-1][j]

T = int(input())
for _ in range(T) :
    k = int(input())
    n = int(input())

    print(dp[k][n])