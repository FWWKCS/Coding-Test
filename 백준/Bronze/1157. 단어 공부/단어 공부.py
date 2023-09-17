import sys
input = sys.stdin.readline

value = input().rstrip()
count = [0 for _ in range(26)]

for v in value :
    if ord(v) > 90 : # 소문자인 경우
        count[ord(v)-97] += 1
    elif ord(v) <= 90 : # 대문자인 경우
        count[ord(v)-65] += 1

maxCount = max(count)
index = 0 # 가장 많이 사용된 문자 인덱스
found = False

for k in range(26) :
    if not found and count[k] == maxCount :
        found = True
        index = k
    elif found and count[k] == maxCount :
        print('?')
        sys.exit()

if found : print(chr(index+65))     