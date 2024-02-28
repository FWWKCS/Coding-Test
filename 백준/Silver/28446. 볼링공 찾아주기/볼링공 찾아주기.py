import sys
input = sys.stdin.readline

M = int(input())
locker = {
    # 공 무게: 사물함 번호
}
for _ in range(M):
    command = list(map(int, input().split()))
    if len(command) == 3:
        x = command[1]
        w = command[2]
        locker[w] = x
    
    elif len(command) == 2:
        w = command[1]
        print(locker[w])