import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    K = int(input())
    C = [0] + list(map(int, input().split()))

    prefix_sum = [0 for _ in range(K+1)]
    for i in range(1,K+1): 
        prefix_sum[i] = prefix_sum[i-1] + C[i]

    dp = [[float('inf') for _ in range(K+1)] for _ in range(K+1)]
    # dp[i][j]: i번 파일부터 j번 파일까지 모두 합칠때의 최소비용
    for r in range(1, K+1): # 갱신할 영역 주대각선의 upper triangle 부분 제외 0으로 초기화
        for c in range(1, r+1):
            dp[r][c] = 0
    
    # 초기값 설정; 각 인접한 파일 2개씩 합칠때의 비용
    for r in range(1, K):
        dp[r][r+1] = prefix_sum[r+1] - prefix_sum[r-1]
    
    row = 1
    x = 0
    col = row + 2 + x
    while col < K+1: 
        for m in range(row, col):
            dp[row][col] = min(dp[row][col], 
                               dp[row][m] + dp[m+1][col] + prefix_sum[col] - prefix_sum[row-1])

        if col == K:
            row = 1
            x += 1
            col = row + 2 + x
        else:
            row += 1
            col += 1

    print(dp[1][K])