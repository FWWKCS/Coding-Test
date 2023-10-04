import math
import sys
input = sys.stdin.readline

def find_year(M, N, x, y) :
    # M부분이 x인 경우는 M, N의 최소공배수를 M으로 나눈 값
    LCM = (M*N) // math.gcd(M, N)
    for k in range(LCM // M) :
        x_s = (x + (M * k)) % M
        if x_s == 0 : x_s = M
        y_s = (x + (M * k)) % N
        if y_s == 0 : y_s = N

        # x, y가 모두 일치하면
        if x_s == x and y_s == y :
            return x + (M * k)
    
    # 만족하는 경우가 없으면
    return -1

T = int(input())
for _ in range(T) :
    M, N, x, y = map(int, input().split())

    print(find_year(M, N, x, y))