import sys
sys.setrecursionlimit(100000)
input = sys.stdin.readline

preorder = []
while True:
    try:
        preorder.append(int(input()))
    except: # EOF
        break

def postorder(root_idx, e_idx):
    if root_idx > e_idx: return

    if root_idx == e_idx:
        print(preorder[root_idx])
        return
    elif e_idx - root_idx == 1:
        print(preorder[e_idx])
        print(preorder[root_idx])
        return

    R_idx = root_idx+1
    while R_idx < len(preorder) and preorder[root_idx] > preorder[R_idx]:
        R_idx += 1
    
    postorder(root_idx+1, R_idx-1)
    postorder(R_idx, e_idx)
    print(preorder[root_idx])

postorder(0, len(preorder)-1) 