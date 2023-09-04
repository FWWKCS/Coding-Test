import sys
input = sys.stdin.readline

n = int(input())
dp = [0 for _ in range(n+1)]
dp[1] = 1 # 1자리수는 무조건 1

for k in range(2, n+1) :
    dp[k] = dp[k-1] + dp[k-2]

print(dp[n])