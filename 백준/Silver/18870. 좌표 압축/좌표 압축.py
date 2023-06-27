def binary_search (findValue, data) :
    start = 0
    end = len(data) - 1 
    while start <= end :
        pivot = (start + end) // 2
        if findValue == data[pivot] : return pivot
        elif findValue > data[pivot] : start = pivot + 1
        else : end = pivot - 1

    return -1

import sys
input = sys.stdin.readline

count = int(input())

data = list(map(int,input().split()))

dataSet = list(set(data))
# sorted()는 병합정렬을 기반으로 만들어지므로 최악에서도 O(NlogN) 의 시간을 가짐
dataSet = sorted(dataSet)

# 이진 탐색을 이용해 O(log_2 N)의 시간을 가짐
# dataSet.index(k)는 O(N)의 시간으로 시간이 더 걸림

start = 0
end = len(dataSet)
for i in data :
    print(binary_search(i, dataSet), end = ' ')