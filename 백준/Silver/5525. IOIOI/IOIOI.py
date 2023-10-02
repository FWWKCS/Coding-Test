import sys
input = sys.stdin.readline

N = int(input())
length = int(input())
S = input().rstrip()

count = 0
for l in range(2*N + 1, length+1) :
    start = l-(2*N+1)
    if S[start] == 'O' : continue
    
    find = 'IO' * N + 'I'
    if S[start:l] == find : count += 1

print(count)