import collections
import sys
input = sys.stdin.readline

deque = collections.deque([])

orderCase = int(input())

for _ in range(orderCase) :
    order = input().rstrip()

    if order.startswith('push_back') : 
        deque.append(int(order[10:]))
    elif order.startswith('push_front') :
        deque.appendleft(int(order[10:]))
    elif order.startswith('pop_front') :
        try :
            print(deque.popleft())
        except :    
            print(-1)
    elif order.startswith('pop_back') :
        try :
            print(deque.pop())
        except :
            print(-1)
    elif order == 'size' : print(len(deque))
    elif order == 'empty' :
        if len(deque) == 0 : print(1)
        else : print(0)
    elif order == 'front' :
        if len(deque) != 0 : print(deque[0])
        else : print(-1)
    elif order == 'back' :
        if len(deque) != 0 : print(deque[-1])
        else : print(-1)
    