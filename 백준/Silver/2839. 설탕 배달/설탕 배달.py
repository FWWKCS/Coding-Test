def find_sugar() :
    for r in range(len(dp)) :
        for c in range(len(dp[r])) :
            dp[r][c] = 3*r + 5*c
            if dp[r][c] == N :
                return r+c
    
    return -1

N = int(input())

ROW = (N // 3) + 1
COL = (N // 5) + 1

dp = [[0 for _ in range(COL)] for _ in range(ROW)]

print(find_sugar())