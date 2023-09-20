import sys
input = sys.stdin.readline

K, N = map(int, input().split())
total_Length = 0 # 만든 랜선 개수

cable = []
max_Length = 0
for _ in range(K) :
    value = int(input())
    cable.append(value)
    max_Length = max(max_Length, value)

# 최대로 자를 수 있는 길이는 주어진 선 중 가장 긴 선의 길이
start = 1
end = max_Length

found = 0
def find_Cable(start, end) :
    global found
    if end < start : return
    make = 0
    pivot = (start + end) // 2

    for l in cable :
        make += l // pivot

    if make >= N : # 길이를 더 길게하여 자른다
        found = pivot
        find_Cable(pivot + 1, end)
    elif make < N : # 길이를 더 짧게하여 자른다
        find_Cable(start, pivot - 1)


find_Cable(1, max_Length)

print(found)