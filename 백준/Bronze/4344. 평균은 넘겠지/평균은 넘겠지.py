testCase = int(input())

DB = [] # 학생수, 점수 데이터

for _ in range(testCase) :
    DB.append(list(map(int,input().split())))

for k in range(testCase) :
    upper = 0
    avg = (sum(DB[k][1:])/DB[k][0])
    for j in DB[k][1::1] :
        if j > avg : upper += 1

    print("{:.3f}".format((upper/DB[k][0])*100)+'%')