import collections
import sys
input = sys.stdin.readline

count = int(input())
queue = collections.deque([])

for _ in range(count) :
    order = input().rstrip()

    if order.startswith('push') :
        queue.append(int(order[5:]))
    elif order == 'pop' :
        try :
            print(queue.popleft())
        except :
            print(-1)
    elif order == 'size' :
        print(len(queue))
    elif order == 'empty' :
        if len(queue) == 0 : print(1)
        else : print(0)
    elif order == 'front' :
        try :
            print(queue[0])
        except :
            print(-1)
    elif order == 'back' :
        try : 
            print(queue[-1])
        except :
            print(-1)