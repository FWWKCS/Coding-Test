import sys
input = sys.stdin.readline

N, K = map(int, input().split())
cost = [int(input()) for _ in range(N)]

count = 0

for value in cost[-1::-1] :
    if K >= value :
        count += K // value
        K -= (K // value) * value

print(count)