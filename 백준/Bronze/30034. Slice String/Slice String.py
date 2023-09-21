N = int(input())
letter_division = list(set(input().split()))

M = int(input())
number_division = list(set(input().split()))

K = int(input()) # 병합자
merger = set(input().split())

S = int(input()) # 문자열
string = input()

# 구분자 병합
division = set(letter_division + number_division)

# 병합자 문자를 구분자에서 제거
for d in list(division) :
    if d in merger :
        division.remove(d)

# 남은 구분자로 문자열 분리
for d in list(division) :
    string = string.replace(d, ' ')

string = string.split()

for s in string :
    print(s)