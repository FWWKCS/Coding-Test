import collections
import sys
input = sys.stdin.readline

def dfs(start) :
    stack = [start]
    visitedNode = [start]

    while len(stack) != 0 :
        visited = False
        start = stack[-1]

        for d in range(N) :
            if graph[start-1][d] == 1 and d+1 not in visitedNode :
                visited = True
                stack.append(d+1)
                visitedNode.append(d+1)
                break

        if not visited : stack.pop()

    for d in visitedNode :
        print(d, end = ' ')
    print()

def bfs(start) :
    queue = collections.deque([start])
    visitedNode = [start]

    while len(queue) != 0 :
        start = queue.popleft()

        for d in range(N) :
            if graph[start-1][d] == 1 and d+1 not in visitedNode :
                queue.append(d+1)
                visitedNode.append(d+1)

    for d in visitedNode :
        print(d, end = ' ')
    print()


N, M, V = map(int, input().split()) # 정점 수, 간선 수, 탐색 시작 노드

graph = [[0 for _ in range(N)] for _ in range(N)]

for _ in range(M) :
    node1, node2 = map(int, input().split())

    graph[node1-1][node2-1] = 1
    graph[node2-1][node1-1] = 1

dfs(V) 

bfs(V)