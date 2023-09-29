import math
import sys
input = sys.stdin.readline

def is_square(n) :
    k = int(math.sqrt(n))
    return k*k == n

def get_result(n) :
    # n이 완전 제곱수인 경우 (1)
    if is_square(n) : return 1

    # n이 두 완전 제곱수로 이루어지는 경우 (2)
    x = int(math.sqrt(n))
    for i in range(x, (x//2), -1) :
        if is_square(n - (i*i)) : return 2

    # n이 세 완전 제곱수로 이루어지는 경우 (3)
    for i in range(x, (x//2), -1) :
        y = int(math.sqrt(n-(i*i)))
        for j in range(y, (y//2), -1) :
            if is_square(n - (i*i) - (j*j)) : return 3

    # 그 외의 경우는 최대 제곱 항의 수 4
    return 4
n = int(input())
print(get_result(n))