import sys
input = sys.stdin.readline

n = int(input())
schedule = [(0,0)] + [tuple(map(int, input().split())) for _ in range(n)] + [(0,0)] 
# ( 지속시간, 비용 )
# 마지막 n+1일차에 최종 정산을 받는다

dp = [0 for _ in range(n+2)]
# i번째 날짜까지 가능한 최대 이익

for k in range(1,n+2) :
    maxCost = 0
    for i in range(k-1, 0, -1) :
        if k-i == schedule[i][0] :
            # case 1. k - i일 동안 연속되는 상담 비용을 받는 경우
            maxCost = max(schedule[i][1]+dp[i], maxCost)
    
    # case 2. k일의 상담을 패싱하는 경우
    maxCost = max(dp[k-1], maxCost)

    dp[k] = maxCost

print(max(dp))