import sys
input = sys.stdin.readline

def heap_sort(array) : # A[1:n]을 정렬
    global K, count
    # n은 array의 마지막 인덱스
    n = len(array)-1
    build_min_heap(array, n)
    for i in range(n, 1, -1) :
        array[i], array[1] = array[1], array[i]
        count += 1
        if count == K : 
            print(*array[1:])
            sys.exit()
        heapify(array, 1, i-1)

def build_min_heap(array, n) :
    for i in range(n//2, 0, -1) :
        heapify(array, i, n)

# A[k]를 루트로 하는 트리를 최소 힙 성질을 만족하도록 수정한다.
# A[k]의 두 자식을 루트로 하는 서브 트리는 최소 힙 성질을 만족하고 있다.
# n은 배열 A의 전체 크기이며 최대 인덱스를 나타낸다.
def heapify(array, k, n) :
    global K, count
    left = 2*k
    right = 2*k + 1
    if right <= n :
        if array[left] < array[right] :
            smaller = left
        else :
            smaller = right
    elif left <= n :
        smaller = left
    else : return array

    # 최소 힙 성질을 만족하지 못하는 경우 재귀적으로 수정한다.
    if array[smaller] < array[k] :
        array[smaller], array[k] = array[k], array[smaller]
        count += 1
        if count == K : 
            print(*array[1:])
            sys.exit()
        heapify(array, smaller, n)

N, K = map(int, input().split())
array = [None] + list(map(int, input().split()))
count = 0

heap_sort(array)
print(-1)