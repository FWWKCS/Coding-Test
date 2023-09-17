import sys
input = sys.stdin.readline

N, M = map(int, input().split())

count = 0
burger = [] # (pa, ch)

while N != M+1 :
    if N <= M or N > M*2 :
        print('NO')
        sys.exit()
    
    burger.append((2, 1))
    N -= 2
    M -= 1

burger.append((N, M))
print('YES')
print(len(burger))

for b in burger :
    print('ab' * b[1] + 'a')