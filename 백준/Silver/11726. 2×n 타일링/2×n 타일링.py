import sys
input = sys.stdin.readline

n = int(input())

dp = [0 for _ in range(n+1)]

dp[1] = 1
if n > 1 :
    dp[2] = 2

for k in range(3,n+1) :
    dp[k] = ( dp[k-2] + dp[k-1] ) % 10007

print(dp[n] % 10007)