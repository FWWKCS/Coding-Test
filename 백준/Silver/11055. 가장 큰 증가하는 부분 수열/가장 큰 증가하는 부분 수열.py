import sys
input = sys.stdin.readline

N = int(input())
sequence = list(map(int, input().split()))
dp = [0 for _ in range(N)]
# dp[i] : sequence[i]까지 가질 수 있는 부분수열의 최대합
dp[0] = sequence[0]

for k in range(1, N) :
    dp[k] = sequence[k]
    for i in range(k-1, -1, -1) :
        if sequence[i] < sequence[k] :
            dp[k] = max(dp[i] + sequence[k], dp[k])

print(max(dp))