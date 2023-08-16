num = list(map(int, input().split()))

total = 0

for n in num :
    total += n * n

print(total%10)