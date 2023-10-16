import sys
input = sys.stdin.readline

def get_channel(length, found, available) :
    global pressed, N
    if length == 1 and int(found) == 0 :
        pressed = min(pressed, N+1)
        return
    elif length <= len(str(N))+1 :
        if length == len(str(N))+1 and found[length-1] != min(available) :  return
        pressed = min(pressed, length + abs(N - int(found)))
    else : return # length > 6

    for a in available :
        get_channel(length+1, found+a, available)

N = int(input())
M = int(input())
current = 100
pressed = abs(N - current) # 총 누른 최소 버튼 횟수
if M == 0 :
    print(min(len(str(N)),pressed))
    sys.exit()

limited = list(input().split())

if N == current :
    print(pressed)
    sys.exit()

available = [str(k) for k in range(10) if str(k) not in limited]
available = sorted(available, key = lambda x : abs(int(str(N)[0]) - (int(x))))

found = ''
# 이용가능한 버튼만으로 N과 가장 가까운 수 찾기
for a in available :
    get_channel(1, found+a, available)

print(pressed)