import sys
input = sys.stdin.readline

# 점화식에 따른 Tabulation 생성
Tabulation = [1] * 100

# 점화식
for i in range(3,100) :
    Tabulation[i] = Tabulation[i-3] + Tabulation[i-2]

testCase = int(input())

for k in range(testCase) :
    N = int(input())

    print(Tabulation[N-1])