import sys
input = sys.stdin.readline
count = int(input())

for i in range(count):
    num = input().split()
    print(int(num[0])+int(num[1]))
    