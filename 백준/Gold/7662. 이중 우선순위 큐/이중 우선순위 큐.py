import heapq
import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    K = int(input())
    min_heap = []
    max_heap = []
    sync = {
        # 삽입한 값 : 힙에 포함된 개수
    }
    for _ in range(K) :
        order, value = input().split()
        value = int(value)

        if order == 'I':
            heapq.heappush(min_heap, value)
            heapq.heappush(max_heap, -value)
            if value not in sync : sync[value] = 1
            else : sync[value] += 1
        elif order == 'D' and value == 1:
            # 최댓값 pop
            while max_heap:
                value = -heapq.heappop(max_heap)
                if value in sync: 
                    if sync[value] == 1 : del sync[value]
                    else : sync[value] -= 1
                    break
        else :
            # 최솟값 pop
            while min_heap:
                value = heapq.heappop(min_heap)
                if value in sync:
                    if sync[value] == 1 : del sync[value]
                    else : sync[value] -= 1
                    break

    # 최종 이중 우선순위 큐의 최댓값, 최솟값 찾기
    if len(sync) == 0 : 
        print('EMPTY')
        continue
    elif len(sync) == 1 :
        max_value = list(sync.keys())[0]
        min_value = max_value
    else :  
        while max_heap:
            max_value = -heapq.heappop(max_heap)
            if max_value in sync:
                if sync[max_value] == 1 : del sync[max_value]
                else : sync[max_value] -= 1
                break
        
        while min_heap:
            min_value = heapq.heappop(min_heap)
            if min_value in sync:
                if sync[min_value] == 1 : del sync[min_value]
                else : sync[min_value] -= 1
                break
            
    print(max_value, min_value)