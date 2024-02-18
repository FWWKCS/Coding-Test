import sys
sys.setrecursionlimit(100000)
input = sys.stdin.readline

def find_child(x):
    if x == pointer[x]: return x
    pointer[x] = find_child(pointer[x])
    return pointer[x]

def union(a, b):
    x = find_child(a)
    y = find_child(b)

    next[x] = b
    pointer[x] = y

N = int(input())
next = [-1 for _ in range(N+1)] # 다음 학교 인덱스
pointer = [i for i in range(N+1)] # 최하위 자식 인덱스

school = [''] + [input().rstrip() for _ in range(N)]

target = []
name = []
for k in range(N-1):
    i, j = map(int, input().split())
    union(i, j)
    if k == N-2: 
        target.append(i)
        name.append(school[i])

# print(target, next, pointer)

current = target[-1]
while next[current] != -1:
    name.append(school[next[current]])
    current = next[current]

print(''.join(name))