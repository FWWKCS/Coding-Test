import collections
import sys
input = sys.stdin.readline

testCase = int(input())

for _ in range(testCase) :
    P = input().rstrip() # order
    # order 간소화, R이 짝수개가 들어오는 것은 의미없음
    P = P.replace('RR','')

    length = int(input())
    arr = input().rstrip() # array
    if arr == '[]' : queue = []
    else : queue = list(map(int, arr[1:len(arr)-1].split(',')))
    deque = collections.deque(queue)

    errorOccured = False
    reverse = 0 # popleft

    for o in P :
        if o == 'R' :
            if reverse == 0 : reverse = 1
            else : reverse = 0 
        elif o == 'D' :
            if len(deque) == 0 :
                errorOccured = True
                break
            else : 
                if reverse == 0 : deque.popleft()
                else : deque.pop()
    
    if errorOccured : print('error')
    else : 
        queue = list(deque)
        print('[', end = '')
        if reverse == 0 :
            for q in range(len(queue)) :
                if q != len(queue) - 1 :
                    print(queue[q], end=',')
                else : print(queue[q], end = '')
        else :
            for q in range(len(queue)-1, -1, -1) :
                if q != 0 :
                    print(queue[q], end = ',')
                else : print(queue[q], end = '')
        print(']')


