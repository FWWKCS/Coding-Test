import sys
input = sys.stdin.readline

N = int(input())

result = 0

for i in range(1,N+1) :
    result += i * (N // i)

print(result) 