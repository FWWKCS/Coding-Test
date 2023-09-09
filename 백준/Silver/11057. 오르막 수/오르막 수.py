import sys
input = sys.stdin.readline

N = int(input())
memoization = [[0 for _ in range(10)] for _ in range(N+1)]
# memoization[n][k] : n개로 이루어진 오르막 수에 대하여 n-1개의 오르막 수의 마지막 수가 j인 경우, 만들 수 있는 오르막 수

dp = [0 for _ in range(N+1)]
# dp[i] : i개의 오르막 수로 만들 수 있는 모든 경우의 수

for i in range(10) :
    memoization[1][i] = 1
# 1개로 이루어진 오르막 수는 무조건 1개씩 존재
dp[1] = sum(memoization[1])


for k in range(2, N+1) :
    memoization[k][0] = dp[k-1]
    for i in range(1, 10) :
        memoization[k][i] = memoization[k][i-1] - memoization[k-1][i-1]

    dp[k] = sum(memoization[k])

print(dp[N] % 10007)