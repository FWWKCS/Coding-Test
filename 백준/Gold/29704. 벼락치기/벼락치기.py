import sys
input = sys.stdin.readline

N, T = map(int, input().split())
table = [[0 for _ in range(T+1)] for _ in range(N+1)]

assignment = [None]
total = 0
for _ in range(N):
    d, m = map(int, input().split())
    total += m
    assignment.append((d, m))

for r in range(1, N+1):
    for c in range(1, T+1):
        if c >= assignment[r][0]:
            table[r][c] = max(table[r][c], table[r-1][c-assignment[r][0]] + assignment[r][1])

        table[r][c] = max(table[r][c], table[r-1][c])

# for t in table: print(t)

print(total - table[-1][-1])