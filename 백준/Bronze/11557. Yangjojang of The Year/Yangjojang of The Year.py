testCase = int(input())

maxL = 0
target = ''

for _ in range(testCase) :
    count = int(input())
    for _ in range(count) :
        univ, L = input().split()
        L = int(L)
        if L > maxL : 
            maxL = L
            target = univ
    
    print(target)