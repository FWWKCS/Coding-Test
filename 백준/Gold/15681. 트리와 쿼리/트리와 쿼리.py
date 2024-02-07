import sys
sys.setrecursionlimit(10000000)
input = sys.stdin.readline

def make_tree(currentNode, parentNode):
    for Node in connect[currentNode]:
        if Node != parentNode:
            child[currentNode].add(Node)
            parent[Node] = currentNode
            make_tree(Node, currentNode)

def count_subtree_nodes(currentNode):
    size[currentNode] = 1
    for Node in list(child[currentNode]):
        count_subtree_nodes(Node)
        size[currentNode] += size[Node]

N, R, Q = map(int, input().split())
connect = {
    # 정점 : [ 인접 정점, .. ]
}

child = [set() for _ in range(N+1)]
parent = [-1 for _ in range(N+1)]

for _ in range(N-1):
    U, V = map(int, input().split())
    if U not in connect:
        connect[U] = [V]
    else: connect[U].append(V)

    if V not in connect:
        connect[V] = [U]
    else: connect[V].append(U)

make_tree(R, parent[R])

size = [0 for _ in range(N+1)]
count_subtree_nodes(R)

for _ in range(Q): print(size[int(input())])