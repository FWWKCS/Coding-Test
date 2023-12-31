N = int(input())
for _ in range(N):
    d, f, p = map(float, input().split())
    print(f'${d*f*p:.2f}')