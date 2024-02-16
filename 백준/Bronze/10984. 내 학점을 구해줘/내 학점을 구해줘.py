import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N = int(input())
    total = 0
    sum_grade = 0
    for _ in range(N):
        C, G = input().split()
        total += int(C)
        sum_grade += int(C) * float(G)
    
    print(f'{total} {sum_grade / total:.1f}')