import sys
input = sys.stdin.readline

def binary_search(value):
    s = 1
    e = N+1

    while s <= e:
        pivot = (s + e) // 2
        if prefix[pivot] == value: return pivot
        elif prefix[pivot] < value: 
            s = pivot + 1
        else: e = pivot - 1
    
    return s

N, Q = map(int, input().split())
prefix = [0 for _ in range(N+1)]
prefix[1] = int(input()) - 1

for x in range(2, N+1):
    prefix[x] = int(input()) + prefix[x-1]

# print(prefix)

for _ in range(Q):
    print(binary_search(int(input())))