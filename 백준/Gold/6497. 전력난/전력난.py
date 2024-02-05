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

while True:    
    m, n = map(int, input().split())
    if m == 0 and n == 0: exit()
    
    total = 0
    pointer = [i for i in range(m)]

    edges = []
    for _ in range(n):
        i, j, w = map(int, input().split())
        total += w
        edges.append((i, j, w))

    edges.sort(key = lambda x : x[2])

    for i, j, d in edges:
        if is_union(i, j): continue
        union(i, j)
        total -= d

    print(total)