import sys
input = sys.stdin.readline

N, M, K = map(int, input().split())
board = [list(input().rstrip()) for _ in range(N)]

# B를 시작으로 할때 수정해야 할 개수 계산
for r in range(N) :
    for c in range(M) :
        if ((r+c) % 2 == 0 and board[r][c] == 'B') or ((r+c) % 2 == 1 and board[r][c] == 'W') :
            board[r][c] = 0
        else :
            board[r][c] = 1
    

# 누적합
pa_B = [[0 for _ in range(M+1)] for _ in range(N+1)]
pa_W = [[0 for _ in range(M+1)] for _ in range(N+1)]

for r in range(1, N+1) :
    for c in range(1, M+1) :
            pa_B[r][c] = pa_B[r-1][c] + pa_B[r][c-1] + board[r-1][c-1] - pa_B[r-1][c-1]
            pa_W[r][c] = pa_W[r-1][c] + pa_W[r][c-1] + abs(board[r-1][c-1] - 1) - pa_W[r-1][c-1]

# K x K로 자르기
value =  10e8
for r in range(K, N+1) :
    for c in range(K, M+1) :
        redraw_B = pa_B[r][c] - pa_B[r-K][c] - pa_B[r][c-K] + pa_B[r-K][c-K]
        redraw_W = pa_W[r][c] - pa_W[r-K][c] - pa_W[r][c-K] + pa_W[r-K][c-K]
        value = min(value, redraw_B, redraw_W)

print(value)