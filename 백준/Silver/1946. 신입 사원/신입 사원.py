testCase = int(input())

for _ in range(testCase) :
    N = int(input()) # 지원자 수

    data = [] # (서류 성적 순위, 면접 성적 순위)

    for _ in range(N) :
        data.append(tuple(map(int, input().split())))

    data = sorted(data, key = lambda x : x[0])

    success = 1 # 통과 지원자

    current = data[0]
    
    for k in data[1:] :
        interview = k[1]

        if interview > current[1] : continue
        else :
            current = k
            success += 1

    print(success)