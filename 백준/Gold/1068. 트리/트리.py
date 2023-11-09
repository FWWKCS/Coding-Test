import sys
input = sys.stdin.readline

N = int(input())
tree = list(map(int, input().split()))
cut_index = int(input())

tree[cut_index] = float('inf')

leaves = 0

def dfs(root):
    global leaves
    if root == float('inf'):
        return

    for k in range(len(tree)):
        if tree[k] == root:
            dfs(k)

    if root not in tree :
        leaves += 1
    
    return

if -1 in tree:
    dfs(tree.index(-1))

print(leaves)