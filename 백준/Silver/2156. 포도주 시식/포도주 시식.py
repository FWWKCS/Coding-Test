# 풀이참조
# https://blog.naver.com/occidere/220791788953

import sys
input = sys.stdin.readline

N = int(input())
wine = [0] + [int(input()) for _ in range(N)]
drink = 0 # 출력값

dp = [0 for _ in range(N+1)]
# index : N번쨰 와인까지 조건에 맞게 마실 수 있는 최댓값

dp[1] = wine[1]
if N > 1 :
    dp[2] = dp[1] + wine[2]

for i in range(3, N+1) :
    # 1. i번째 와인을 마시지 않는 경우
    #        이전 와인까지 마신 값이 된다
    # 2-1. i번째 와인을 마시되, 1연속째로 마시게 되는 경우
    #        i-2번째 와인까지 마시고 i번재 와인을 마신 값이 된다
    # 2-2. i번째 와인을 마시되, 2연속째로 마시게 되는 경우
    #        i-3번째 와인까지 마시고, i-1번째, i번째 와인을 마신 값이 된다

    dp[i] = max(dp[i-1], dp[i-2] + wine[i], dp[i-3] + wine[i-1] + wine[i])

print(max(dp))