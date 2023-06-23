import math

def is_prime_number(x) :
    if x == 1 : return False
    for i in range(2, int(math.sqrt(x)) + 1) :
        if x % i == 0 : return False
    return True

minimum = int(input())
maximum = int(input())

primeList = []
for k in range(minimum, maximum+1) :
    isPrime = is_prime_number(k)
    if isPrime : primeList.append(k)

if len(primeList) == 0 : print(-1)
else : 
    print(sum(primeList))
    print(min(primeList))