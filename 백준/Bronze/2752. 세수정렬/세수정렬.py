arr = list(map(int, input().split()))

arr.sort()

print(' '.join(str(e) for e in arr))