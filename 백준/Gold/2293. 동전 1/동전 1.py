import sys
input = sys.stdin.readline

n, k = map(int, input().split())
cost = [int(input()) for _ in range(n)]

dp = [0 for _ in range(k+1)]
# dp[i] : i를 만드는 경우의 수
dp[0] = 1 # 아무것도 선택하지 않는 경우

for c in cost :
    for i in range(c,k+1) :
        dp[i] += dp[i-c]

print(dp[k])