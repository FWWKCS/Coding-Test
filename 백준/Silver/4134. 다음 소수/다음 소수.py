import math

def define_PrimeNumber(n) :
    for i in range(2, int(math.sqrt(n))+1) :
        if n % i == 0 : return False
    
    return True

count = int(input())
data = []

for _ in range(count) :
    data.append(int(input()))

prime = []

for n in data :
    while True :
        isPrime = define_PrimeNumber(n)
        if isPrime and n not in (0,1): 
            prime.append(n)
            break
        else : n += 1

for p in prime : print(p)