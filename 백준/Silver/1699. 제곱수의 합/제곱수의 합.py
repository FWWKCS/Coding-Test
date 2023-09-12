import math
import sys
input = sys.stdin.readline

N = int(input())
dp = [10e4 for _ in range(N+1)]
# dp[i] : i까지 가능한 항의 최소값

# 전처리 : i**2 1로 초기화
for i in range(1, int(math.sqrt(N))+1) :
    dp[i**2] = 1

for k in range(1, N+1) :
    if dp[k] == 1 : continue

    for i in range(1, int(math.sqrt(k))+1) :
        dp[k] = min(dp[k], dp[i**2]+dp[k-(i**2)])

print(dp[N])