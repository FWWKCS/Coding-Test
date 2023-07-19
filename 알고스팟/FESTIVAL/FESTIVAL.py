import sys
input = sys.stdin.readline

testCase = int(input())

for _ in range(testCase) :
    N, L = map(int, input().split()) # 주어진 최대 일수, 필요 공연 최소 일수

    schedule = list(map(int, input().split())

    expense = 999999

    # 누적합 계산
    for i in range(0, N-L+1) :
        sum = 0
        for j in range(i, N) :
            sum += schedule[j]
            if j-i+1 >= L : 
                expense = min(sum / (j-i+1), expense)

    print(expense)
