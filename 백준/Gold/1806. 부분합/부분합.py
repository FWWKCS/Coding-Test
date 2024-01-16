import sys
input = sys.stdin.readline

N, S = map(int, input().split())
sequence = [0] + list(map(int, input().split()))

prefix = [0 for _ in range(N+1)]

for i in range(1, N+1):
    prefix[i] = prefix[i-1] + sequence[i]

min_L = int(10e9)

s, e = 1, 1
while s <= N:
    if e > N:
        e = min(N, e)
        s += 1
    summary = prefix[e]-prefix[s-1]
    if summary < S: e += 1
    elif summary >= S: 
        min_L = min(min_L, e-s+1)
        s += 1

if min_L == int(10e9): print(0)
else: print(min_L)