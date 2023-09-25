import heapq
import sys
input = sys.stdin.readline

N = int(input())

heap = []
for _ in range(N) :
    value = int(input())

    if value > 0 :
        heapq.heappush(heap, value)
    else :
        try :
            print(heapq.heappop(heap)) # heap에서 가장 작은 원소를 pop, return
        except :
            print(0)