import sys
input = sys.stdin.readline

N = int(input())
length = int(input())
S = input().rstrip()

count = 0
length = 0 # 만들어진 문자열 길이를 실시간 체크
flag = 1 
# 1이면 I를 필요로함, 0이면 O를 필요로함

for s in S :
    # 플래그 체크
    if (flag == 1 and s == 'I') :
        length += 1
        flag = 0
    elif flag == 0 and s == 'O' :
        length += 1
        flag = 1
    else : # 플래그와 일치하지 않는 경우 초기화
        if s == 'I' :
            flag = 0
            length = 1
        elif s == 'O' :
            flag = 1
            length = 0
        
    if length == 2*N + 1 : 
        count += 1
        length -= 2

print(count)