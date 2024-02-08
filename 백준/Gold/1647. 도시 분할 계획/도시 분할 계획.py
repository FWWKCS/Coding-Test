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

def is_union(a, b):
    x = find_parent(a)
    y = find_parent(b)
    if x == y: return True
    else: return False

N, M = map(int, input().split())
pointer = [i for i in range(N+1)]
edges = [tuple(map(int, input().split())) for _ in range(M)]
edges.sort(key = lambda x : x[2])
selected = []

total = 0
for a, b, w in edges:
    if is_union(a, b): continue
    union(a, b)
    total += w
    selected.append((a, b, w))

print(total-selected[-1][2])