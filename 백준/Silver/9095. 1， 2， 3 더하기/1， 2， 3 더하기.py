import sys
input = sys.stdin.readline

dp = [0 for _ in range(11)]

dp[1] = 1 # 1을 만드는 방법의 수
dp[2] = dp[1] + 1 # 1에서 1을 더하거나, 자기자신을 사용
dp[3] = dp[2] + dp[1] + 1 # 2에서 1을 더하거나, 1에서 2를 더하거나, 자기자신을 사용 

for k in range(4,11) :
    # 점화식 
    # k-1 까지 만든 수에서 1을 더하는 경우 : k-1를 만드는 경우의 수가 축적됨
    # k-2, k-3 의 경우도 동일

    dp[k] = dp[k-1] + dp[k-2] + dp[k-3] 

T = int(input())
for _ in range(T) :
    print(dp[int(input())])