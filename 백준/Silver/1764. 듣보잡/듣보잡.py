nhCount, nsCount = map(int,input().split())

total = {
    # name : info_stack (never heard or never seen)
}

for _ in range(nhCount) :
    neverHeard = input()
    total[neverHeard] = 1

for _ in range(nsCount) :
    neverSeen = input()
    if neverSeen in total :
        total[neverSeen] += 1
    else :
        total[neverSeen] = 1

result = []

for k in total.keys() :
    if total[k] == 2 : result.append(k)

result = sorted(result)

print(len(result))
for r in result : print(r)