import collections

N, W, L = map(int, input().split())
trucks = collections.deque(list(map(int, input().split())))

times = 0

bridge = collections.deque([0 for _ in range(W)]) # 다리위 트럭의 값
current = 0 # 다리 위의 총합 하중

while trucks:
    if current - bridge[0] + trucks[0] <= L :
        current += trucks[0]
        current -= bridge.popleft()
        bridge.append(trucks.popleft())
        times += 1
    else :
        # 다리 끝으로 옮기기
        while bridge[0] == 0 and not all(bridge[x] == 0 for x in range(W)):
            bridge.popleft()
            bridge.append(0)
            times += 1

        # 다리에서 하나를 빼도 여전히 불가능하면
        if current - bridge[0] + trucks[0] > L:
            # 트럭 하나를 보내고
            current -= bridge.popleft()
            bridge.append(0)
            times += 1
            # 다리 끝으로 옮기기
            while bridge[0] == 0 and not all(bridge[x] == 0 for x in range(W)):
                bridge.popleft()
                bridge.append(0)
                times += 1

last = 0
for k in range(W-1, -1, -1) :
    if bridge[k] != 0 : 
        last = k+1
        break

print(times + last)