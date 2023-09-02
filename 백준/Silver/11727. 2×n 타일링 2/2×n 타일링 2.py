import sys
input = sys.stdin.readline

n = int(input())

dp = [0] * 1001

dp[0] = 1
dp[1] = 1

for k in range(2, n+1) :
    # 점화식
    # n-1까지 완성된 문양에 2*1 1개를 추가하는 경우
    # n-2까지 완성된 문양에 1*2 2개를 추가하는 경우
    # n-2까지 완성된 문양에 2*2 1개를 추가하는 경우

    dp[k] = ( dp[k-1] + 2 * dp[k-2] ) % 10007 

print(dp[n] % 10007)