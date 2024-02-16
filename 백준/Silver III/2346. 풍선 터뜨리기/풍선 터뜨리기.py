import collections

N = int(input())

line = collections.deque(list(map(int, input().split())))

for k in range(1,N+1) :
    line[k-1] = [k,line[k-1]]

while True :
    balloon = line[0]
    movement = balloon[1]

    print(balloon[0], end= ' ')

    line.popleft()
    if len(line) == 0 : break

    if movement > 0 :
        line.rotate(-(movement-1))
    elif movement < 0 :
        line.rotate(-movement) 

