dp = [0 for _ in range(46)]

dp[1] = 1
dp[2] = 1

for i in range(3,46) :
    dp[i] = dp[i-1] + dp[i-2]

n = int(input())
print(dp[n])