import collections

N, K = map(int, input().split())

powerstrip = []

plug_off = 0

queue = collections.deque(list(map(int, input().split())))

while queue :
    turn = queue.popleft()
    if turn in powerstrip : continue
    elif len(powerstrip) < N : 
        powerstrip.append(turn)
        continue

    # 1순위 : 할당중인 제품 중에 일회성 사용인 것을 교체
    change = -1 # 인덱스
    for i in range(len(powerstrip)) :
        if powerstrip[i] not in queue : 
            change = i
            break

    if change > -1 :
        powerstrip[change] = turn
        plug_off += 1
        continue

    # 2순위 : 사용중인 제품 중 재사용 우선순위가 높은 것을 보류 
    # ( 단, 최초 N-1개의 제품만 보류 )

    hold = []
    for p in powerstrip :
        hold.append(queue.index(p))
        hold.sort()
    
    hold.pop()

    for h in range(len(hold)) :
        hold[h] = queue[hold[h]]

    # hold에 없는 번호는 교체
    for p in powerstrip :
        if p not in hold : 
            powerstrip[powerstrip.index(p)] = turn
            plug_off += 1
            break

print(plug_off)