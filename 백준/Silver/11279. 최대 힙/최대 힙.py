import heapq
import sys
input = sys.stdin.readline

heap = []
N = int(input())

for _ in range(N) :
    order = int(input())
    if order == 0 :
        try :
            print(-heapq.heappop(heap))
        except : print(0)
    else :
        heapq.heappush(heap, -order)