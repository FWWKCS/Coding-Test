import collections

def move(position, K) :
    queue = collections.deque([(0,position)])
    visitedList = {position}

    while True :
        current = queue.popleft()
        dt = current[0]
        position = current[1]
        if position == K : return dt

        if position >= 0 and position <= 100000 :
            if position-1 not in visitedList :
                visitedList.add(position-1)
                queue.append((dt+1,position-1))

            if position+1 not in visitedList :
                visitedList.add(position+1)
                queue.append((dt+1,position+1))
                
            if position*2 not in visitedList :
                visitedList.add(position*2) 
                queue.append((dt+1,position*2))

N, K = map(int, input().split())

time = move(N, K) # 최소 시간 구하기

print(time)
