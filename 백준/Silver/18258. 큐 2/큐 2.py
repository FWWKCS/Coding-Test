import collections
import sys
input = sys.stdin.readline

orderCount = int(input())

queue = collections.deque([])

for _ in range(orderCount) :
    order = input().rstrip()
    if order.startswith('push') : 
        queue.append(int(order[5:]))
    elif order == 'pop' :
        try :
            print(queue.popleft())
        except :
            print(-1)
    elif order == 'size' : print(len(queue))
    elif order == 'empty' :
        if len(queue) > 0 : print(0)
        else : print(1)
    elif order == 'front' : 
        if len(queue) > 0 : print(queue[0])
        else : print(-1)
    elif order == 'back' : 
        if len(queue) > 0 : print(queue[len(queue)-1])
        else : print(-1)