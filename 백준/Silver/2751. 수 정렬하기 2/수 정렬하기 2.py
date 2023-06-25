import sys
input = sys.stdin.readline

data = []

size = int(input())
for _ in range(size):
    data.append(int(input()))

data.sort()
for d in data:
    print(d)