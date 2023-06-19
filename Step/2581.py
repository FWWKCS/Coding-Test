# https://www.acmicpc.net/problem/2581

# 입력의 첫째 줄에 M이, 둘째 줄에 N이 주어진다.

# M이상 N이하의 자연수 중 소수인 것을 모두 골라 
# 이들 소수의 합과 최솟값을 찾는 프로그램을 작성하시오

import math

def is_prime_number(x) :
    if x == 1 : return False # 1 제외
    for i in range(2, int(math.sqrt(x)) + 1) : # 중간 약수값을 기준으로 대칭을 이룸
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
