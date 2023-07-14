def Tower(k, start, mid, goal) :
    global count, movement
    if k == 1 : 
        # 옮길 원반이 1개이면 A에서 C로 이동
        movement.append((start, goal))
        count += 1
    else :
        # 가장 큰 원판(K) 외 나머지 원판을 모두 B로 이동
        Tower(k-1, start, goal, mid)
        movement.append((start, goal))
        count += 1
        # 가장 큰 원판(K) 외 나머지 원판을 B에서 C로 이동
        Tower(k-1, mid, start, goal)
    

N = int(input())

count = 0
movement = []

Tower(N, 1, 2, 3)

print(count)
for log in movement :
    print(log[0], log[1])