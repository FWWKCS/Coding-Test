import sys
input = sys.stdin.readline

N, M = map(int, input().split())
arr = [0] + list(map(int, input().split()))

dp = [0 for _ in range(N+1)]
for k in range(1, N+1) :
    dp[k] = arr[k] + dp[k-1]

for _ in range(M) :
    i, j = map(int, input().split())
    print(dp[j]-dp[i-1])