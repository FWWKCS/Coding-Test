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