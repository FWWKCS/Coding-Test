import sys
input = sys.stdin.readline

T = int(input())

# g_x 리스트 생성
g_x = [0] + ([1] * 1000000)

for k in range(2, 1000001) :
    for i in range(k, 1000001, k) :
        g_x[i] += k

# 동적 계획법
for g in range(2,len(g_x)) :
    g_x[g] = g_x[g] + g_x[g-1]

for _ in range(T) :
    N = int(input())

    print(g_x[N])