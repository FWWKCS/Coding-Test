import sys
input = sys.stdin.readline

def custom_round(num):
    if num - int(num) >= 0.5:
        return (int(num) + 1) / 10
    else: return int(num) / 10

N = int(input())
pos = [[0 for _ in range(N+1)],[0 for _ in range(N+1)]]

for i in range(N):
    x, y = map(int, input().split())

    pos[0][i] = x
    pos[1][i] = y

    if i == 0:
        pos[0][-1] = x
        pos[1][-1] = y

L, R = 0, 0
for k in range(N):
    L += pos[0][k]*pos[1][k+1]
    R += pos[1][k]*pos[0][k+1]

total = custom_round((abs(L-R) / 2) * 10)
print(total)