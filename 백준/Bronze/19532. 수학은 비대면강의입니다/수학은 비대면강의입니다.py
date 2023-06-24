a,b,c,d,e,f = list(map(int,input().split()))

isFind = False
x = 0
y = 0

for kx in range(-999,1000,1) :
    x = kx
    for ky in range(-999,1000,1) :
        y = ky
        if a*x + b*y == c and d*x + e*y == f : 
            isFind = True
            break
    if isFind : break

print(x, y)