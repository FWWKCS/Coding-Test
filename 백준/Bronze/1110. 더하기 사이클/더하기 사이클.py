N = int(input())
cycle = 0

num = 0 # 갱신되는 새로운 숫자

p = N % 10
q = ((N // 10) + p) % 10
num = (10 * p) + q
cycle += 1

while num != N :
    p = num % 10
    q = ((num // 10) + p ) % 10

    num = (10 * p) + q
    cycle += 1

print(cycle)