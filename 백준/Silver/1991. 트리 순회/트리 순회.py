import sys
input = sys.stdin.readline

# 전위 
def pre_order(root) :
    global tree_dict
    print(root, end = '')

    if tree_dict[root][0] != '.' :
        left = tree_dict[root][0]
        pre_order(left)

    if tree_dict[root][1] != '.' :
        right = tree_dict[root][1]
        pre_order(right)

# 중위
def in_order(root) :
    global tree_dict
    if tree_dict[root][0] != '.' :
        left = tree_dict[root][0]
        in_order(left)

    print(root, end = '')

    if tree_dict[root][1] != '.' :
        right = tree_dict[root][1]
        in_order(right)

# 후위
def post_order(root) :
    global tree_dict
    if tree_dict[root][0] != '.' :
        left = tree_dict[root][0]
        post_order(left)

    if tree_dict[root][1] != '.' :
        right = tree_dict[root][1]
        post_order(right)

    print(root, end = '')

tree_dict = {
    # 부모 노드 : (L 자식 노드, R 자식 노드)
}

N = int(input())
for _ in range(N) :
    root, left, right = input().split()
    tree_dict[root] = (left, right)

pre_order('A')
print()
in_order('A')
print()
post_order('A')