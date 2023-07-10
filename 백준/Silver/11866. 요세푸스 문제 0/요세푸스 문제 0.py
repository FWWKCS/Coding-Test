import collections
import sys
input = sys.stdin.readline

N, K = map(int,input().split())

queue = collections.deque([i+1 for i in range(N)])

josephusSqeunce = []

# 1. 남은 수가 K 미만이 될 때까지 반복
while len(queue) >= K :
    queue = list(queue)
    josephusSqeunce.append(queue.pop(K-1))
    queue = collections.deque(queue)
    queue.rotate(-(K-1))

# 2. 남은 queue의 값 나머지 연산
while len(queue) != 0 :
    index = ( K % len(queue) ) - 1
    queue = list(queue)
    josephusSqeunce.append(queue.pop(index))
    queue = collections.deque(queue)
    if -index < 0 : 
        queue.rotate(-index)

# 출력 형식
print('<', end = '')
for e in range(len(josephusSqeunce)) :
    print(josephusSqeunce[e], end = '')
    if e != len(josephusSqeunce)-1 :
        print(',', end = ' ')
print('>')
