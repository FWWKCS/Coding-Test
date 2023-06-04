# https://www.acmicpc.net/problem/2720

# 테스트 케이스 개수 T
# 거스름돈 값 정수 C센트 (1달러 = 100센트)

# 0.25달러 = 1쿼터
# 0.10달러 = 1다임
# 0.05달러 = 1니켈
# 0.01달러 = 1페니

# 거스름돈 값이 1.24달러(124센트) 면 4쿼터, 2다임, 0니켈, 4페니

test = int(input())
testCase = []

for _ in range(test) :
    testCase.append(int(input()))

for t in range(test) :
    change = testCase[t]

    print(change // 25, end=" ")
    change -= 25 * (change // 25)

    print(change // 10, end=" ")
    change -= 10 * (change // 10)

    print(change // 5, end=" ")
    change -= 5 * (change // 5)

    print(change)
