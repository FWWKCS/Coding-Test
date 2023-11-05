import sys

N, M, R = map(int, input().split())
A = sorted(list(map(int, input().split())))
B = sorted(list(map(int, input().split())))
pos = set()

# 최소 넓이 존재확인
# 최소 깃대와 최소의 좌표값의 곱이 2R보다 크면 -1
for i in range(N-1):
    for j in range(i+1, N):
        pos.add(abs(A[i]-A[j]))

pos = sorted(list(pos))
diff = pos[0]

B = list(filter(lambda x: (x*diff <= 2*R), B))
if not B :
    print(-1)
    sys.exit()

S = 0 # 최대 넓이 * 2
for p in pos:
    for m in B:
        if p * m > 2 * R: continue
        else :
            S = max(S, p*m)

S  = int((S / 2) * 10)
print(S/10)