import sys
input = sys.stdin.readline

N = int(input())
cost = [0] + list(map(int, input().split()))

dp = [0 for _ in range(N+1)]
# dp[i] : i개의 카드를 얻는데 사용할 수 있는 최대비용
dp[1] = cost[1]

for k in range(2, N+1) :
    maxCost = cost[k] # 자기자신으로 초기세팅
    for i in range(1, k) :
        maxCost = max(dp[k-i]+cost[i], maxCost)

    dp[k] = maxCost

print(max(dp))