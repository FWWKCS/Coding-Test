import sys
input = sys.stdin.readline

n = int(input())
words = [input().rstrip() for _ in range(n)]

groupedWords = 0 # 출력값

for word in words :
    grouped = True
    pre = ''
    current = ''
    visited = set() # 접한 문자
    # 최근에 접한 문자가 현재 문자와 다르면서 방문기록이 없어야 타당함
    for l in word :
        current = l
        if current != pre and current in visited : 
            grouped = False
        else : 
            visited.add(l)
            pre = l
        
    if not grouped : continue
    else : groupedWords += 1

print(groupedWords)