import sys
input = sys.stdin.readline

N = int(input())

line = list(map(int, input().split()))

line.sort()

for i in range(1, len(line)) :
    line[i] = line[i-1] + line[i]

print(sum(line))