import math

def isPalindrome(x) :
    x = str(x)
    start = 0
    end = len(x)-1

    while start <= end :
        if x[start] == x[end] :
            start += 1
            end -= 1
        else : return False
    
    return True

size = 1100000

# 에라토스테네스의 체
numList = [True] * (size + 1)
numList[0] = numList[1] = False

for i in range(2, int(math.sqrt(size)) + 1):
    if numList[i]:
        for j in range(i**2, size + 1, i):
            numList[j] = False

primes = [i for i in range(size + 1) if numList[i]]

val = int(input())

index = -1
while True :
    if val in primes :
        index = primes.index(val)
        break
    else : val += 1

while True :
    if isPalindrome(primes[index]) :
        print(primes[index])
        break
    else : index += 1
