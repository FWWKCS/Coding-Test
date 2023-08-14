import sys
input = sys.stdin.readline

word = list(input().rstrip()) # 최종 출력 대상
stack = [] # word에서 pop한 값을 저장하거나 pop하여 word에 전달

count = int(input())

for _ in range(count) :
    order = input().rstrip()

    if order[0] == 'P' :
        word.append(order[-1])
    elif order[0] == 'L' :
        try :
            stack.append(word.pop())
        except :
            continue
    elif order[0] == 'D' :
        try :
            word.append(stack.pop())
        except : 
            continue
    elif order[0] == 'B' :
        try :
            del(word[-1])
        except :
            continue

print(''.join(word)+''.join(stack[-1::-1]))   