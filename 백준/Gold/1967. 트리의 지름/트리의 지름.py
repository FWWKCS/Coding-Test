import sys
sys.setrecursionlimit(100000)
input = sys.stdin.readline

N = int(input())
tree = {
    # 시작정점 : { (가중치, 도착정점), ... }
}

def dfs(s, cur_dist):
    global selected, dist, visited
    if len(visited) == N: return

    for w, x in list(tree[s]):
        if x not in visited:
            visited.add(x)
            dist[x] = cur_dist + w
            dfs(x, cur_dist+w)
            visited.remove(x)

for _ in range(N-1):
    p, c, w = map(int, input().split())
    if p not in tree:
        tree[p] = { (w, c) }
    else:
        tree[p].add((w, c))
    
    if c not in tree:
        tree[c] = { (w, p) }
    else:
        tree[c].add((w, p))

selected = 1 # 초기 노드
dist = [0 for _ in range(N+1)]
# 초기 노드로부터 가장 먼 노드를 찾는다
visited = {selected}

dfs(selected, 0)

selected = dist.index(max(dist))
visited = {selected}
# 찾은 노드로부터 각 노드까지의 거리 중 최대 거리가 답이 된다
dfs(selected, 0)
print(max(dist))