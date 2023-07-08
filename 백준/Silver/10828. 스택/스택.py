import sys
input = sys.stdin.readline

test = int(input())

stack = []

for _ in range(test) :
    order = input().rstrip()
    if order.startswith('push') : 
        stack.append(int(order[5:]))
    elif order == 'pop' :
        if len(stack) == 0 :
            print(-1)
        else : print(stack.pop())
    elif order == 'size' : 
        print(len(stack))
    elif order == 'empty' :
        if len(stack) == 0 : print(1)
        else : print(0)
    elif order == 'top' :
        if len(stack) == 0 : print(-1)
        else : print(stack[-1])