# 특정 원소가 속한 집합을 찾기
def find_parent(parent, x) :
    # 루트 노드를 찾을 때까지 재귀 호출
    if parent[x] != x :
        # 부모 테이블 값을 바로 갱신 ( 경로 압축 )
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

# 두 원소가 속한 집합을 병합
def union_parent(parent, a, b) :
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    # 노드의 값이 더 작은 쪽이 두 노드에서 부모관계가 된다
    if a < b : parent[b] = a
    else : parent[a] = b

# 노드의 개수와 간선(Union 연산)의 개수 입력
N = int(input()) # 노드
M = int(input()) # 간선

# 부모 테이블상에서, 부모를 자기 자신으로 초기화
parent = [i for i in range(N+1)]

edges = []

for _ in range(M) :
    node1, node2, weight = map(int, input().split())
    edges.append((node1, node2, weight))

edges = sorted(edges, key = lambda x : x[2])

result = 0
for edge in edges :
    a, b, cost = edge
    # 사이클이 발생하지 않는 경우에만 집합에 포함
    if find_parent(parent, a) != find_parent(parent, b) :
        union_parent(parent, a, b)
        result += cost

print(result)