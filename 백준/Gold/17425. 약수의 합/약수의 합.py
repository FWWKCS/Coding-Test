import math
import sys
input = sys.stdin.readline

T = int(input())

f_x = [0] + ([1] * 1000000)

for k in range(2, 1000001) :
    for i in range(k, 1000001, k) :
        f_x[i] += k

for g in range(2,len(f_x)) :
    f_x[g] = f_x[g] + f_x[g-1]

for _ in range(T) :
    N = int(input())

    print(f_x[N])   