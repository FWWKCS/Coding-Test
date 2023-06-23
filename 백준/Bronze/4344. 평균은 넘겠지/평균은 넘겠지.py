case = int(input())

DB = []

for _ in range(case) :
    data = input().split()
    DB.append([int(d) for d in data])

for r in range(case):
    # 평균 초과 인원 수
    count = 0

    avg = sum(s for s in DB[r][1:])/(len(DB[r])-1)

    # 평균이상 학생만 계산
    for n in range(1, len(DB[r])) :
        if DB[r][n] > avg : count += 1

    # 평균 이상인 학생의 비율
    rate = count/(len(DB[r])-1) * 100
    print("{:.3f}".format(rate, 3),end="%\n")

    # 실수와 문자 % 사이의 간격이 없음에 유의할 것