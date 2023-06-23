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