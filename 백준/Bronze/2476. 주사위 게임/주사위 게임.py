testCase = int(input())

maxPrize = 0
Prize = 0

for _ in range(testCase) :
    data = list(map(int, input().split()))
    data.sort()
    result = set(data)

    if len(result) == 1 : Prize = data[0] * 1000 + 10000
    elif len(result) == 3 : Prize = data[2] * 100
    elif len(result) == 2 :
        # 2개의 눈 값 찾기
        if data[0] == data[1] : Prize = data[0] * 100 + 1000
        else : Prize = data[1] * 100 + 1000

    if Prize > maxPrize : maxPrize = Prize

print(maxPrize)