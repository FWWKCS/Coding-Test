A, B = map(int,input().split())

total = {
    # num : stack ( in A or in B )
}

setA = list(map(int,input().split()))
setB = list(map(int,input().split()))

for a in setA :
    total[a] = 1

for b in setB :
    if b in total : total[b] -= 1
    else :
        total[b] = 1

count = 0
for k in total.keys() :
    if total[k] == 1 : count += 1

print(count)
