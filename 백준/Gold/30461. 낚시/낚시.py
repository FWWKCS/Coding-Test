import sys
input = sys.stdin.readline

N, M, Q = map(int, input().split())
field = [[0]*(M+1)] + [[0] + list(map(int, input().split())) for _ in range(N)]

# 누적합
for r in range(2,N+1):
    for c in range(1, M+1):
        field[r][c] += field[r-1][c] + field[r-1][c-1] - field[r-2][c-1]

for _ in range(Q):
    R, C = map(int, input().split())
    print(field[R][C])