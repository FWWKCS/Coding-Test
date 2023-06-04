# https://www.acmicpc.net/problem/10798

letterAry = [input() for _ in range(5)]

# 문자 최대길이 계산
maxLength = 0
for l in letterAry:
    if maxLength < len(l) : maxLength = len(l)

# 문자 나열
getLetter = ''
for c in range(maxLength) :
    for i in range(5) :
        getLetter += letterAry[i][c:c+1]

# 공백 제거
getLetter = getLetter.replace(' ','')

print(getLetter)