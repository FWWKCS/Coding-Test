import sys
input = sys.stdin.readline

N = int(input())

tower = list(map(int, input().split()))
current = 0
pushed = 0 # 출력

for i in range(N) :
    if tower[i] >= current :
        pushed += 1
    current = tower[i]
print(pushed)