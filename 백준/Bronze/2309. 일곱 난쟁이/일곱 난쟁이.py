height = []

for _ in range(9) :
    height.append(int(input()))

height.sort()

sum = 0
findDwarf = False

while not findDwarf :
    for a in range(9):
        for b in range(9) :
            if a == b : continue

            sum = 0
            
            for k in range(9) :
                if k in (a,b) : continue
                else : sum += height[k]
            
            if sum == 100 :
                findDwarf = True
                for k in range(9) :
                    if k in (a,b) : continue
                    else : print(height[k])
                break
        if findDwarf : break