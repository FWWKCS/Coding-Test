import sys
input = sys.stdin.readline

N = int(input())
cost = [0] + [int(input()) for _ in range(N)]

dp = [[0,0] for _ in range(N+1)]
# index 0 : 1칸 이동해서 얻을 수 있는 최댓값 
# index 1 : 2칸 이동해서 얻을 수 있는 최댓값

dp[1] = [cost[1], 0] # 1번째 계단에 도달한 경우 가질 수 있는 
if N > 1 :
    dp[2] = [cost[2] + dp[1][0], cost[2]] # 2번째 계단에 도달한 경우

    for k in range(3,N+1) :
        oneStep = dp[k-1] # 1칸 이전
        twoStep = dp[k-2] # 2칸 이전

        # 1칸 이동시 누적합
        dp[k][0] = cost[k] + oneStep[1]

        # 2칸 이동시 누적합
        dp[k][1] = max(cost[k] + twoStep[0], cost[k] + twoStep[1])

print(max(dp[-1]))