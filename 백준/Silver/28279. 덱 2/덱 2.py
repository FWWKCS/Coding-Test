import collections
import sys
input = sys.stdin.readline

orderCount = int(input())
deque = collections.deque([])

for _ in range(orderCount) :
    order = input().rstrip()

    if order[0] == '1' :
        deque.appendleft(int(order[2:]))
    elif order[0] == '2' : 
        deque.append(int(order[2:]))
    elif order == '3' :
        try :
            print(deque.popleft())
        except : print(-1)
    elif order == '4' :
        try :
            print(deque.pop())
        except : print(-1)
    elif order == '5' :
        print(len(deque))
    elif order == '6' :
        if len(deque) == 0 : print(1)
        else : print(0)
    elif order == '7' :
        if len(deque) == 0 : print(-1)
        else :
            print(deque[0])
    elif order == '8' :
        try :
            print(deque[-1])
        except :
            print(-1)

        