import sys
input = sys.stdin.readline

numCount = int(input())

numSet = set(map(int, input().split()))

searchCount = int(input())

searchList = list(map(int, input().split()))

for s in searchList :
    if s in numSet : print(1)
    else : print(0)