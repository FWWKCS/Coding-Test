import math

N = int(input())

value = str(math.factorial(N))[::-1]

count = 0
for l in value :
    if l != '0' :
        break

    count += 1

print(count)