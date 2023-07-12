import sys
input = sys.stdin.readline

def merge_sort(arr, l, r) :
    if l < r :
        mid = (l+r) // 2
        merge_sort(arr, l, mid)
        merge_sort(arr, mid+1, r)
        merge(arr, l, mid, r)

def merge(arr, l, mid, r) :
    global savedLog
    i = l
    j = mid+1
    t = 0
    while (i <= mid and j <= r) :
        if arr[i] <= arr[j] :
            tmp[t] = arr[i]
            savedLog.append(arr[i])
            t += 1
            i += 1
        else : # arr[i] > arr[j]
            tmp[t] = arr[j]
            savedLog.append(arr[j])
            t += 1
            j += 1

    while i <= mid : # 왼쪽 배열 부분이 남은 경우
        tmp[t] = arr[i]
        savedLog.append(arr[i])
        t += 1
        i += 1
    
    while j <= r : # 오른쪽 배열 부분이 남은 경우
        tmp[t] = arr[j]
        savedLog.append(arr[j])
        t += 1
        j += 1
    
    # tmp에 저장했던 값을 arr에 덮어쓰기위해 t초기화/ arr의 시작인덱스부터 시작
    i = l
    t = 0
    
    while i <= r : # 결과를 arr에 저장
        arr[i] = tmp[t]
        i += 1
        t += 1

size, saveCount = map(int,input().split())
tmp = [0] * size
target = list(map(int, input().split()))
savedLog = [] # tmp 저장 값 기록

merge_sort(target, 0, size-1)

try :
    print(savedLog[saveCount-1])
except :
    print(-1)
