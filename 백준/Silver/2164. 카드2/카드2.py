import collections
import sys
input = sys.stdin.readline

N = int(input())

queue = collections.deque([i+1 for i in range(N)])

while len(queue) != 1 :
    queue.popleft()
    if len(queue) == 1 : break
    queue.rotate(-1)

print(queue[0])