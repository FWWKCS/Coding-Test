import sys
input = sys.stdin.readline

N, M = map(int, input().split())
memory = [0] + list(map(int, input().split()))
cost = [0] + list(map(int, input().split()))
total = sum(cost)

dp = [[0 for _ in range(total+1)] for _ in range(N+1)]
# dp[r][c]: r번째 앱까지 사용하여 c 비용으로 얻을 수 있는 최대 메모리

for r in range(1, N+1):
    for c in range(total+1):
        if c >= cost[r]:
            dp[r][c] = max(dp[r][c], memory[r]+dp[r-1][c-cost[r]])
        
        dp[r][c] = max(dp[r][c], dp[r-1][c])

answer = float('inf')
# M이상인 값의 cost중 최소를 탐색
for r in range(1, N+1):
    for c in range(total+1):
        if dp[r][c] >= M:
            answer = min(answer, c)

print(answer)