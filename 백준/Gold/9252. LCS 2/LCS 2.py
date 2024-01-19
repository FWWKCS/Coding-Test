A = '_' + input()
B = '_' + input()

dp = [[0 for _ in range(len(B))] for _ in range(len(A))]

for r in range(1, len(A)):
    for c in range(1, len(B)):
        if A[r] == B[c]:
            dp[r][c] = dp[r-1][c-1] + 1
        else:
            if dp[r-1][c] > dp[r][c-1]:
                dp[r][c] = dp[r-1][c]
            else:
                dp[r][c] = dp[r][c-1]

print(dp[-1][-1])

LCS = []
r = len(A)-1
c = len(B)-1
while r > 0 and c > 0:
    if A[r] == B[c]:
        LCS.append(A[r])
        r -= 1
        c -= 1
    else:
        if dp[r-1][c] == dp[r][c]: r -= 1
        else: c -= 1

print(''.join(reversed(LCS)))