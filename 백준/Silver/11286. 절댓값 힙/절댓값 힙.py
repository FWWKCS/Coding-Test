import heapq
import sys
input = sys.stdin.readline

N = int(input())
absolute_heap = []
for _ in range(N) :
    order = int(input())

    if order != 0 :
        heapq.heappush(absolute_heap, (abs(order), order))
    else :
        try :
            print(heapq.heappop(absolute_heap)[1])
        except : print(0)