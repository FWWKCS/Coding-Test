import sys
input = sys.stdin.readline

A = ' ' + input().rstrip()
B = ' ' + input().rstrip()

dp = [[0 for _ in range(len(A))] for _ in range(len(B))]

for r in range(1,len(B)) :
    for c in range(1, len(A)) :
        if B[r] == A[c] :
            # 좌측 대각부분까지 만들 수 있는 최대 LCS에서 
            # 두 문자열 공통으로 동일한 문자가 추가되었으므로 
            # LCS가 좌측 대각으로부터 1 증가한다
            dp[r][c] = dp[r-1][c-1]+1
        else :
            dp[r][c] = max(dp[r-1][c], dp[r][c-1])

print(dp[-1][-1])