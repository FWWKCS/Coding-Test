import math

def define_PrimeNumber(n) :
    for i in range(2, int(math.sqrt(n))+1) :
        if n % i == 0 : return False
    
    return True

start, end = map(int,input().split())

for i in range(start, end+1) :
    isPrime = define_PrimeNumber(i)
    if isPrime and i not in (0,1) : print(i)