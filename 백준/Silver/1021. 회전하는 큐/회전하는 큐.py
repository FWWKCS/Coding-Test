import collections
import sys
input = sys.stdin.readline

length, get = map(int,input().split())

deque = collections.deque([i+1 for i in range(length)])

target = list(map(int,input().split()))

shift = 0 # shift count, find minimum
current = 0 # target index

while current < len(target) :
    pivot = ( len(deque) - 1 ) // 2
    if deque[0] == target[current] : 
        deque.popleft()
        current += 1
    else :
        index = deque.index(target[current])

        if index > pivot : 
            shr = len(deque) - index
            deque.rotate(shr)
            shift += shr
        else : # index <= pivot
            shl = index
            deque.rotate(-shl)
            shift += shl

print(shift)