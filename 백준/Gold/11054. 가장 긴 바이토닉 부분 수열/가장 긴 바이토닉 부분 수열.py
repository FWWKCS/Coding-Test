import sys
input = sys.stdin.readline

n = int(input())
arr = [0] + list(map(int, input().split()))

dp = [[0 for _ in range(n+1)] for _ in range(3)]
# dp[0][i] : i번째까지 증가만 하는 가장 긴 부분수열
# dp[1][i] : i번째까지 감소만 하는 가장 긴 부분수열
# dp[2][i] : i번째까지 증가하다 감소할때 가장 긴 부분수열

dp[0][1] = 1
dp[1][1] = 1
if n > 1 :
    if arr[2] > arr[1] :    
        dp[0][2] = dp[0][1] + 1
    else : dp[0][2] = 1

    if arr[2] < arr[1] :
        dp[1][2] = dp[1][1] + 1
    else : dp[1][2] = 1

dp[2][1] = 0 # 증가 후 감소의 경우 수열의 최초 두 수에 의해 증가함을 보여야한다
if n > 1 :
    dp[2][2] = 0

for k in range(3, n+1) :
    maxIncrease = 0
    maxDecrease = 0
    maxChange = 0
    for i in range(k-1, -1, -1) :
        # 증가하는 경우
        # 자기자신보다 작은 값들 중에 dp값이 가장 큰 값 + 1
        if arr[i] < arr[k] :
            maxIncrease = max(maxIncrease, dp[0][i] + 1)
        
        if arr[i] > arr[k] :
            # case 1. 계속 감소하는 경우
            # 자기자신보다 큰 값들 중에 dp값이 가장 큰 값 + 1
            maxDecrease = max(maxDecrease, dp[1][i] + 1)

            # case 2. 증가를 멈추고 감소를 진행하는 경우
            # 자기자신보다 큰 값들 중에 dp값이 가장 큰 값 + 1
            maxChange = max(maxChange, dp[0][i]+1, dp[2][i]+1)

    dp[0][k] = maxIncrease
    dp[1][k] = maxDecrease
    dp[2][k] = maxChange

total = 0
for m in dp:
    total = max(total, max(m))

print(total)