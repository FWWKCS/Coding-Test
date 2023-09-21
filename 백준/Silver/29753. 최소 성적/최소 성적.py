import sys
input = sys.stdin.readline

grade_dict = {
    'A+' : 4.50,
    'A0' : 4.00,
    'B+' : 3.50,
    'B0' : 3.00,
    'C+' : 2.50,
    'C0' : 2.00,
    'D+' : 1.50,
    'D0' : 1.00,
    'F' : 0.00
}

N, target = input().split()
credit = 0 # 학점
total_GP = 0 # 평점의 합

for _ in range(int(N)-1) :
    c, score = input().split()
    credit += int(c)
    total_GP += int(c) * grade_dict[score]

L = int(input())
credit += L # L

target_score = ''
for s in grade_dict.keys() :
    avg = (total_GP + (grade_dict[s] * L)) / credit

    if str(avg)[:4] > target : target_score = s

if target_score != '' : print(target_score)
else : print('impossible')