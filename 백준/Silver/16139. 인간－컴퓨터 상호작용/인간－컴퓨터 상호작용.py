import sys
input = sys.stdin.readline

word = input().rstrip()
q = int(input())

table = [[0 for _ in range(len(word))] for _ in range(26)]

# 누적합 테이블 생성
for r in range(26) :
    for c in range(len(word)) :
        if word[c] == chr(r+97) :
            table[r][c] = table[r][c-1] + 1
        elif c > 0 :
            table[r][c] = table[r][c-1]

for _ in range(q) :
    a, l, r = input().split()

    l, r = int(l), int(r)
    index = ord(a) - 97
    
    if l == 0 : # 반례 분기
        print(table[index][r]) # 0부터 r까지이므로 r의 누적합값만 출력
    else :   
        print(table[index][r] - table[index][l-1])