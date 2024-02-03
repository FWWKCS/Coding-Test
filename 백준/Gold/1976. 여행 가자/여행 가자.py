import sys
sys.setrecursionlimit(100000)
input = sys.stdin.readline

def find_parent(x):
    if x == pointer[x]: return x

    pointer[x] = find_parent(pointer[x])
    return pointer[x]

def union(a, b):
    x = find_parent(a)
    y = find_parent(b)

    if x < y: pointer[y] = x
    else: pointer[x] = y

N = int(input())
M = int(input())
pointer = [i for i in range(N+1)]

for i in range(1, N+1):
    connected = [0] + list(map(int, input().split()))
    for n in range(1, N+1):
        if connected[n] == 1: union(i, n)

plan = list(map(int, input().split()))
parent = pointer[plan[0]]
for k in range(1, M):
    if pointer[plan[k]] != parent:
        print('NO')
        exit()

print('YES')