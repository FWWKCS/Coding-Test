import sys

P, K = map(int, input().split())

found = False
for p in range(2, K):
    if P % p == 0:
        print("BAD", p)
        sys.exit()

print("GOOD")