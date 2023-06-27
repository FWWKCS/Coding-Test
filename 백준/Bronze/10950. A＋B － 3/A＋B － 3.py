testCase = int(input())

DB = [] # 학생수, 점수 데이터

for _ in range(testCase) :
    DB.append(list(map(int,input().split())))

for k in range(testCase) :
    print(sum(DB[k]))