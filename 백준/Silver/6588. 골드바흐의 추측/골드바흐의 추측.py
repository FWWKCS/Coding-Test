import math
import sys
input = sys.stdin.readline

# 에라토스테네스의 체
num = [1] * 1000001
num[0], num[1] = 0, 0

for k in range(2, int(math.sqrt(1000000))+1) :
    if num[k] == 0 : continue

    for i in range(k*k, len(num), k) :
        num[i] = 0


while True :
    N = int(input())
    if N == 0 : break

    a, b = 0, 0
    solved = False

    for k in range(3, N-2, 2) :
        if num[k] != 0 and num[N-k] != 0 :
            a = k
            b = N-k
            solved = True
            break
    
    if solved :
        print(f'{N} = {a} + {b}')
    else :
        print('Goldbach\'s conjecture is wrong.')