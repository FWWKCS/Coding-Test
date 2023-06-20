# https://www.acmicpc.net/problem/11653

# 정수 N이 주어졌을 때, 소인수분해하는 프로그램을 작성하시오.


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