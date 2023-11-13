import collections
import sys
input = sys.stdin.readline

N = int(input())
edge_dict = {
    # 노드: [연결된 다른 노드]
}

parent = [0 for _ in range(N+1)] # 1 to N

for _ in range(N-1):
    x, y = map(int, input().split())

    if x not in edge_dict:
        edge_dict[x] = [y]
    else:
        edge_dict[x].append(y)

    if y not in edge_dict:
        edge_dict[y] = [x]
    else:
        edge_dict[y].append(x)

queue = collections.deque([1])
while queue:
    e = queue.popleft()

    for x in edge_dict[e]:
        if x == 1: continue
        if parent[x] == 0:
            parent[x] = e
            queue.append(x)

for p in parent[2:]: print(p)