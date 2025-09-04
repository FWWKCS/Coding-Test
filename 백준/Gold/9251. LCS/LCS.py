A = ' ' + str(input())
B = ' ' + str(input())

dp = [[0 for _ in range(len(A))] for _ in range(len(B))]

for i in range(1, len(A)):
    if B[1] == A[i]: dp[1][i] = 1
    dp[1][i] = max(dp[1][i], dp[1][i-1])

for i in range(1, len(B)):
    if A[1] == B[i]: dp[i][1] = 1
    dp[i][1] = max(dp[i][1], dp[i-1][1])

for r in range(2, len(B)):
    for c in range(2, len(A)):
        if A[c] == B[r]:
            dp[r][c] = dp[r-1][c-1] + 1
        else:
            dp[r][c] = max(dp[r-1][c], dp[r][c-1])

print(dp[-1][-1])