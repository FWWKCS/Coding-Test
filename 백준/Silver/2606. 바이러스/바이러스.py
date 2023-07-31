import sys
input = sys.stdin.readline

def questGraph(start) :
    stack = [start]
    visitedAry = [start]
    visitedList.append(start)

    while len(stack) > 0 :
        visited = False
        current = stack[-1]
        for k in range(N) :
            if k+1 not in visitedAry and graph[current-1][k] == 1 :
                stack.append(k+1)
                visitedAry.append(k+1)
                visitedList.append(k+1)
                visited = True
        
        if visited : current = stack[-1]
        else : stack.pop()


N = int(input()) # 노드 개수
M = int(input()) # 간선 개수

graph = [[0 for _ in range(N)] for _ in range(N)]

for _ in range(M) :
    node1, node2 = map(int, input().split())

    graph[node1-1][node2-1] = 1
    graph[node2-1][node1-1] = 1

visitedList = []

start = 1
questGraph(start)

print(len(visitedList)-1)