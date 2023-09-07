import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T) :
    n = int(input())
    stickers = [[0] + list(map(int, input().split())) for _ in range(2)]

    dp = [[0 for _ in range(n+1)] for _ in range(2)]
    # dp[r][c] 
    # r : 가장 마지막으로 r행의 스티커를 선택
    # c : c번째 스티커까지 가질 수 있는 최댓값

    dp[0][1] = stickers[0][1]
    dp[1][1] = stickers[1][1]

    for k in range(2, n+1) :
        # 서로 교차하면서 스티커를 떼는 경우
        # 2칸 이전에서 한 칸을 넘고 둘 중 최댓값을 떼는 경우
        dp[0][k] = max(dp[1][k-1] + stickers[0][k],
                       dp[1][k-2] + stickers[0][k])
        
        dp[1][k] = max(dp[0][k-1] + stickers[1][k],
                       dp[0][k-2] + stickers[1][k])

    print(max(dp[0][-1], dp[1][-1]))    