import sys
input = sys.stdin.readline

N = int(input())
sequence = [-1] + list(map(int, input().split()))

dp = [[-1 for _ in range(N+1)] for _ in range(N+1)]
# 초기 세팅
for x in range(1, N+1):
    # e - s = 0 인 단일 수열은 항상 팰린드롬
    dp[x][x] = 1

for x in range(1, N):
    # e - s = 1 인 두 수의 수열은 양끝이 같으면 팰린드롬
    if sequence[x] == sequence[x+1]: 
        dp[x][x+1] = 1
    else: dp[x][x+1] = 0

for r in range(1, N-1):
    for c in range(2+r, N+1):
        if dp[c-r][c-1] == 1 and sequence[c-r-1] == sequence[c]:
            dp[c-r-1][c] = 1
        else: dp[c-r-1][c] = 0

M = int(input())
for _ in range(M):
    S, E = map(int, input().split())
    print(dp[S][E])    