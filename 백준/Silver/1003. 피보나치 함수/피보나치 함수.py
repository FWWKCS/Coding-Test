import sys
input = sys.stdin.readline

dp = [0] + [1 for _ in range(40)]
for i in range(3, 41) :
    dp[i] = dp[i-2] + dp[i-1]

T = int(input())
for _ in range(T) :
    N = int(input())
    if N > 0 :
        print(dp[N-1], dp[N])
    else :
        print(1, 0)