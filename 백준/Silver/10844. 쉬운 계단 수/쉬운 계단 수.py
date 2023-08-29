import sys
input = sys.stdin.readline

N = int(input())
dp = [[0 for _ in range(10)] for _ in range(N+1)]
for k in range(1,10) : # N = 1, 앞에 0은 올 수 없음
    dp[1][k] = 1

for i in range(2, N+1) :
    for j in range(10) :
        if j == 0 :
            dp[i][j] = dp[i-1][j+1] % 1000000000
        elif j == 9 :
            dp[i][j] = dp[i-1][j-1] % 1000000000
        else :
            dp[i][j] = ( dp[i-1][j-1] + dp[i-1][j+1] ) % 1000000000

print(sum(dp[-1]) % 1000000000)