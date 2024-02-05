from heapq import heappush, heappop
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

V, E = map(int, input().split())
pointer = [i for i in range(V+1)]
heap = []
total = 0
for _ in range(E):
    A, B, C = map(int, input().split())
    heappush(heap, (C, A, B))

while heap:
    w, a, b = heappop(heap)
    if is_union(a, b): continue

    union(a, b)
    total += w

print(total)