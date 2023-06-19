# https://www.acmicpc.net/problem/1978

count = int(input())
data = input().split()

total = 0
divisor = []
for d in data :
    d = int(d)
    if d == 1 : continue
    elif d != 2 and d % 2 == 0 : continue
    else : 
        Prime = True
        divisor = []
        for i in range(2, d) :
            if d % i == 0 : 
                Prime = False  
                break
        if Prime is False : continue
        total += 1

print(total)
