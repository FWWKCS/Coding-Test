import sys
input = sys.stdin.readline

answer = []
N = int(input())
for _ in range(N):
    S, T = input().split()
    pos = -1

    for s in range(len(S)):
        if S[s].lower() == 'x':
            pos = s
            break

    answer.append(T[pos].upper())
print(''.join(answer))