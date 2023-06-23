data = int(input())

primeFactorization = []

opr = 2

while data != 1 :
    if data % opr == 0 : 
        primeFactorization.append(opr)
        data /= opr
        opr = 2
    else : opr += 1

primeFactorization.sort()
for p in primeFactorization : print(p)