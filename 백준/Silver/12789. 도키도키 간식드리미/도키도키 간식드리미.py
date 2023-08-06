import collections

N = int(input())

line = collections.deque(list(map(int, input().split())))

waiting = [] # 대기
success = True

count = 1
while len(line) != 0 :
    if line[0] == count :
        line.popleft()
        count += 1
    elif len(waiting) > 0 and waiting[-1] == count :
        waiting.pop()
        count += 1

    else :
        waiting.append(line.popleft())

for k in waiting[-1::-1] :
    if k != count : 
        success = False
        break
    else : count += 1

if success : print('Nice')
else : print('Sad')