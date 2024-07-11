import sys
input = sys.stdin.readline

N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]
dp = [[0] * N for _ in range(N)]

def solve(board, dp):
    for r in range(N):
        for c in range(N):
            if (r == N-1 and c == N-1): return dp[r][c]

            delta = board[r][c]
            if delta + r < N : dp[r+delta][c] += dp[r][c]
            if delta + c < N : dp[r][c+delta] += dp[r][c]

dp[0][0] = 1
print(solve(board, dp))