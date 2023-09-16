A = int(input())
sequence = [10e3] + list(map(int, input().split()))

dp = [0 for _ in range(A+1)]
# dp[i] : i까지 가능한 최대 감소수열의 길이
dp[1] = 1

for k in range(2,A+1) :
    value = 0
    for i in range(k-1, -1, -1) :
        if sequence[i] > sequence[k] :
            value = max(value, dp[i])
    
    dp[k] = value + 1

print(max(dp))