import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    a, b = map(int, input().split())
    A = {a}
    B = {b}

    while a != 0:
        A.add(a // 2)
        a //= 2

    while b != 0:
        B.add(b // 2)
        b //= 2

    print(10 * max(A & B))