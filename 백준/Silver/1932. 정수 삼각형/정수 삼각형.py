import sys
input = sys.stdin.readline

N = int(input())
cost = [list(map(int, input().split())) for _ in range(N)]

dp = [[0 for _ in range(i)] for i in range(1,N+1)]
dp[0][0] = cost[0][0]

# dp 양쪽 끝 누적합 연산
for i in range(1,N) :
    dp[i][0] = cost[i][0] + dp[i-1][0]
    dp[i][-1] = cost[i][-1] + dp[i-1][-1]

# dp 중간영역 누적합 연산
for i in range(2, N) :
    for j in range(1,i) :
        dp[i][j] = max(cost[i][j] + dp[i-1][j-1], cost[i][j] + dp[i-1][j])

print(max(dp[N-1]))