# https://www.acmicpc.net/problem/4344


# 첫째 줄 테스트 케이스 C
# 둘째 줄 각 테스트 케이스 
# 학생 수, 각 학생의 점수 (0 <= s <= 100)

# 각 케이스마다 평균을 넘는 학생들의 비율을 반올림하여
# 소수점 셋째 자리까지 출력

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
    
    