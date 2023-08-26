import sys
input = sys.stdin.readline

N = int(input())
cost = [list(map(int, input().split())) for _ in range(N)]

dp = [cost[0]] + [[0, 0, 0] for _ in range(N-1)]

# 점화식 
# [R, G, B] 자신을 제외한 이전 라인의 누적합 중 최솟값과 합연산

for i in range(1,N) :
    # R을 선택했을때 이전값은 G, B중에서 선택
    dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0]

    # G
    dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1]

    # B
    dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2]

print(min(dp[-1])) 