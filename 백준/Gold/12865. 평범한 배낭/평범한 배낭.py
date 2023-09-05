import sys
input = sys.stdin.readline

N, K = map(int, input().split())
obj = [(0,0)] + [tuple(map(int, input().split())) for _ in range(N)]
# (weight, value)

dp = [[0 for _ in range(K+1)] for _ in range(N+1)]

for r in range(1,N+1) :
    for c in range(1, K+1) :
        if obj[r][0] <= c :
            # 이전 물건까지 가능했던 최대 가치와 비교
            dp[r][c] = max(dp[r-1][c], obj[r][1]+dp[r-1][c-obj[r][0]])
        else :
            dp[r][c] = dp[r-1][c]

print(dp[N][K])