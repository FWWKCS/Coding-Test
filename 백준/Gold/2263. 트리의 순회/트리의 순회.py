import sys
sys.setrecursionlimit(10000000)
input = sys.stdin.readline

N = int(input())
inorder = list(map(int, input().split()))
in_idx = {
    # 값 : 인덱스
}
for i in range(N): in_idx[inorder[i]] = i
postorder = list(map(int, input().split()))

def preorder(s, e, i_s, i_e):
    # postorder 범위 내의 마지막 인덱스가 루트
    root = postorder[e]
    if root in visited: return

    print(root, end = ' ')
    visited.add(root)
    # inorder에서 루트의 위치 확인
    mid = in_idx[root]
    

    # inorder에서 i 범위내 좌우 개수 탐색
    L_count = mid - i_s

    # postorder의 개수를 구한 L, R 개수만큼 분할
    preorder(s, s+L_count-1, i_s, mid-1)
    preorder(s+L_count, e-1, mid+1, i_e)

visited = set()
preorder(0, N-1, 0, N-1)