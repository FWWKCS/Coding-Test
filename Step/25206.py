# https://www.acmicpc.net/problem/25206

# 전공평점은 전공과목별 (학점 × 과목평점)의 합을 학점의 총합으로 나눈 값


# P/F 과목의 경우 등급이 P또는 F로 표시되는데, 
# 등급이 P인 과목은 계산에서 제외

# 전공평점이 3.3 이상이면 통과

# 20줄에 걸쳐 치훈이가 수강한 전공과목의 과목명, 학점, 등급이 공백으로 구분

# 치훈이의 전공평점을 출력

# 정답과의 절대오차 또는 상대오차가 10^(-4) 이하이면 정답으로 인정

count = 20
setGrade = ['A+','A0','B+','B0','C+','C0','D+','D0','F']
setScore = [4.5, 4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0.0]

result = 0 # 학점 * 과목평점
devideValue = 0 # 학점의 총합

for _ in range(count):
    data = input().split()
    subject = data[0]
    score = float(data[1])
    try :
        grade = setGrade.index(data[2])
    except (ValueError) :
        continue
    
    result += setScore[grade] * score
    devideValue += score

print(result/devideValue)
