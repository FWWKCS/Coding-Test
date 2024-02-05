from decimal import Decimal
import sys
input = sys.stdin.readline

def find_parent(x):
    if x == idx_pointer[x]: return x

    idx_pointer[x] = find_parent(idx_pointer[x])
    return idx_pointer[x]

def union(a, b):
    x = find_parent(a)
    y = find_parent(b)

    if x < y: idx_pointer[y] = x
    else: idx_pointer[x] = y

def is_union(a, b):
    x = find_parent(a)
    y = find_parent(b)

    if x == y: return True
    else: return False

N = int(input())
pos = [tuple(map(Decimal, input().split())) for _ in range(N)]
idx_pointer = [i for i in range(N)]
edges = []
for i in range(N-1):
    for j in range(i+1, N):
        d = ((pos[i][0]-pos[j][0])**Decimal('2') + (pos[i][1]-pos[j][1])**Decimal('2')).sqrt()
        edges.append((d, i, j))

edges.sort(key = lambda x: x[0])

total = Decimal('0')
for d, i, j in edges:
    if find_parent(i) == find_parent(j): continue

    union(i, j)
    total += d

total = total.quantize(Decimal('0.01'))
print(total)