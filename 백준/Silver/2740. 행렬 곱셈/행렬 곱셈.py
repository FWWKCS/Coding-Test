import sys
input = sys.stdin.readline

N, M = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]
M, K = map(int, input().split())
B = [list(map(int, input().split())) for _ in range(M)]

X = [[0 for _ in range(K)] for _ in range(N)]

for r in range(N):
    for c in range(K):
        total = 0
        for x in range(M):
            total += A[r][x] * B[x][c]

        X[r][c] = total

for m in X: print(*m)