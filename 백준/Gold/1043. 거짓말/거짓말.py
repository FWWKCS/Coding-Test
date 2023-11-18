from collections import deque
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
graph = [[0 for _ in range(N+1)] for _ in range(N+1)]

known = list(map(int, input().split()))
known = set(known[1:])

party = []

for _ in range(M):
    members = list(map(int, input().split()))
    party.append(members)
    if members[0] == 1 : continue

    for i in range(1, members[0]):
        for j in range(i+1, members[0]+1):
            graph[members[i]][members[j]] = 1
            graph[members[j]][members[i]] = 1

# 진실을 알고있는 사람과 연결된 다른 사람 찾기
for k in list(known):
    queue = deque([k])
    visited = {k}

    # bfs
    while queue:
        current = queue.popleft()
        for x in range(1, N+1):
            if graph[current][x] != 0 and x not in visited:
                visited.add(x)
                queue.append(x)

    # 진실을 아는 사람을 갱신
    known |= visited

# 진실을 아는 인원이 없는 파티만 참석
count = 0
attend = True
for p in party:
    for x in p[1:]:
        if x in known: 
            attend = False
            break

    if attend: count += 1
    attend = True

print(count)